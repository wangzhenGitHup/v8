#!/usr/bin/env python
# coding:utf-8
# Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
# Author: Huawei OS Kernel Lab
# Create: Tus May 27 10:03:00 2021
import sys
import os
import time
import random
import subprocess
import argparse
import pexpect
import socket, getpass
from pexpect.pxssh import pxssh
"""
Usage:
    python ./signtool.py -s source_path -t target_path -f bootimage.elf
    -f, --filenm, "source file name"
    -s, --srcdir, "source dirctory"
    -t, --tgtdir, "target dirctory"
    crl and sig files will be generated, such as bootimage.elf.cms bootimage.elf.crl
    Only support debug mode, it does not support the same user of the same IP host to apply for signature at the same time.
"""
"""
    Class for interactive command
"""
class Expect_Task:
    def __init__(self, remoteHost, elfFile):
        self.server = remoteHost
        self.file = elfFile
        self.ssh = pxssh(timeout = 10)
        if self.ssh.login(self.server["ip"], self.server["user"], self.server["passwd"]) != True:
            raise AssertionError("self ssh.login failed")

    def __del__(self):
        self.ssh.logout()

    def sshRemoteTask(self, cmd, exp='$'):
        print("[sshRemoteTask] {}".format(cmd))
        self.ssh.sendline(cmd)
        if exp == '$':
           # have none expect hint, waiting for $
           self.ssh.prompt()
        else:
            # expect exp after send cmd
            ret = self.ssh.expect([exp, pexpect.TIMEOUT], timeout = 60)
            if ret != 0:
                print(ret, "{} failed".format(cmd))
                # try again, on high concurrency scenario, the time depends on the server performance.
                # debug cms-tool for cms signatrue is unsteadily on practice.
                time.sleep(random.randint(0, 20))
                self.ssh.sendline(cmd)
                ret = self.ssh.expect([exp, pexpect.TIMEOUT], timeout = 60)
                if ret != 0:
                    print(ret, "{} failed again".format(cmd))
                    raise AssertionError("{} failed".format(cmd))

    def scpCmdTaskInner(self, scpCmd, remotedir):
        task = pexpect.spawn(scpCmd)
        ret = task.expect(["assword", "sure you want to continue connecting", pexpect.TIMEOUT], timeout = 10)
        if ret == 0:
            task.sendline(self.server["passwd"])
        elif ret == 1:
            task.sendline("yes")
            ret = task.expect(["assword", pexpect.TIMEOUT], timeout = 10)
            if ret == 0:
                task.sendline(self.server["passwd"])
            else:
                raise AssertionError('scp wait for sending password failed')
        else:
            raise AssertionError('scp connect failed')
        ret = task.expect([pexpect.EOF, "100%", "No such file or directory", pexpect.TIMEOUT], timeout = 30)
        if ret > 1:
            # generate log on server machine, moreover cms-tool also generate log saved on *.tmp.log
            self.sshRemoteTask("echo {}:{} lacking: >> {}/{}.tmp.log".format(self.file, ret, remotedir, self.file))
            self.sshRemoteTask("ls {} | grep {} >> {}/{}.tmp.log".format(remotedir, self.file, remotedir, self.file))
            self.sshRemoteTask("date +%s >> {}/{}.tmp.log".format(remotedir, self.file))
            print("[scpCmdTask] " + task.before + task.after)
        task.close()
        return ret

    def scpCmdTask(self, scpCmd, remotedir):
        ret = self.scpCmdTaskInner(scpCmd, remotedir)
        if ret == 2:
            time.sleep(15)
            # try again
            ret = self.scpCmdTaskInner(scpCmd, remotedir)
            if ret > 1:
                print('scp wait for send cmd again error')

    def scpFromLocalTask(self, localList, remoteDir):
        remoteDestination = "{}@{}:{}".format(self.server["user"], self.server["ip"], remoteDir)
        sourceStr = ""
        for file in localList:
            sourceStr = sourceStr + " " + file
        scpCmd = "scp {} {}".format(sourceStr, remoteDestination)
        print("[scpFromLocalTask] {}".format(scpCmd))
        self.scpCmdTask(scpCmd, remoteDir)

    def scpToLocalTask(self, remoteList, localDir, userWorkSpace):
        remotePreffix = "{}@{}:".format(self.server["user"], self.server["ip"])
        for file in remoteList:
            remoteStr = remotePreffix + file
            scpCmd = "scp {} {}".format(remoteStr, localDir)
            print("[scpToLocalTask] {}".format(scpCmd))
            self.scpCmdTask(scpCmd, userWorkSpace)

"""
    Execute command without interaction
    @param    cmd
    @return   None
    @note	None
"""
def execNonInteractiveCmd(cmd):
    r = os.popen(cmd)
    text = r.read()
    print(text)
    r.close()
    return text.replace('\n', '').replace('\r', '')

"""
    Calculate for getting user identify string
    @param    None
    @return   Identify of current users
    @note	None
"""
def calUserIdentify():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s.connect(('8.8.8.8', 80))
        ip = s.getsockname()[0]
        s.close()
    except:
        hostname = socket.gethostname()
        ip = socket.gethostbyname(hostname)
    user_name = getpass.getuser()
    curIdentify = "{}_{}".format(user_name, ip)
    print("[calUserIdentify] {}".format(curIdentify))
    return curIdentify

"""
    Task for signature by debug tools
    @param    remoteHost        Information of remote server
    @param    userWorkSpace     WorkSpace on remote server
    @return   None
    @note     None
"""
def signForDebug(remoteHost, userWorkSpace):
    # ng builds aim file with the same name on one compile process
    genHashValueCmd = "sha256sum {} | cut -b 1-4".format(args.srcdir + "/" + args.filenm)
    hashValue = execNonInteractiveCmd(genHashValueCmd)
    # create Expect_Task object
    signTask = Expect_Task(remoteHost, args.filenm)
    # initialize environment
    cleanCmd = "find {} -cmin +5 -name \"{}*\" | xargs rm -rf && mkdir -p {}".format(
        userWorkSpace, args.filenm, userWorkSpace + "/" + args.filenm + hashValue)
    userWorkSpace = userWorkSpace + "/" + args.filenm + hashValue
    signTask.sshRemoteTask(cleanCmd)
    # upload file that would be signed
    localList = [args.srcdir + "/" + args.filenm]
    signTask.scpFromLocalTask(localList, userWorkSpace)
    # sign by ssh on remote server and it's worthless to delete user workspace
    # generate signature file and crl file
    fileBeSigned = "{}/{}".format(userWorkSpace, args.filenm)
    signCmd = "~/tools/cms-tool/sign_data.sh {}".format(fileBeSigned)
    signTask.sshRemoteTask(signCmd, "remote signatrue success")
    # download the signature files
    remoteList = ["{}.cms".format(fileBeSigned), "{}.crl".format(fileBeSigned)]
    signTask.scpToLocalTask(remoteList, args.tgtdir, userWorkSpace)

"""
    Main function
"""
if __name__ == '__main__':
    # parse inout parameter
    parser = argparse.ArgumentParser(description = "parse")
    parser.add_argument("-f", "--filenm", type=str, help="elf source file")
    parser.add_argument("-s", "--srcdir", type=str, help="source dirctory")
    parser.add_argument("-t", "--tgtdir", type=str, help="target dirctory")
    parser.add_argument("-m", "--mode", type=str, help="cms signatrue mode, debug or release")
    args = parser.parse_args()

    try:
        # ip + username
        identify = calUserIdentify()
        userWorkSpace = "~/user_workspace/{}".format(identify)
        # signature by debug tools
        remoteHost =  {"ip":"10.113.189.208", "user":"signer", "passwd":"huawei"}
        signForDebug(remoteHost, userWorkSpace)
    except AssertionError as err:
        print("generate signature failed: {}".format(err))
        raise RuntimeError
    except:
        print("generate signature failed, compile error")
        raise RuntimeError
