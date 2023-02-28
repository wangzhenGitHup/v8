/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2020. All rights reserved.
 * Description: KEV definition template
 * Author: Huawei OS Kernel Lab
 * Create: Tue May 26 14:15:14 2020
 */

#include <hmkernel/types.h>
DEFINE_KEV(SCHED_SWITCH, sched_switch,
	   KEV_ARG(4,
		   struct tcb_s *, prev_tcb,
		   enum tcb_state_e, prev_tcb_state,
		   struct tcb_s *, next_tcb,
		   unsigned int, cpu),
	   KEV_STRUCT(10,
		      __u32, sequence,
		      char, __KEV_STRING(pname, 64),
		      char, __KEV_STRING(nname, 64),
		      __u32, pprio,
		      __u32, nprio,
		      __u64, pcref,
		      __u64, ncref,
		      __u32, pstate,
		      __u32, cpu,
		      __u64, timestamp),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      if (prev_tcb_state == TCB_STATE_INVALID) {
				str_cpy_p_to_a(evt->pname, "NULL");
				evt->pprio = 0;
				evt->pcref = 0;
		      } else {
				str_cpy_p_to_a(evt->pname, tcb_name_of(prev_tcb));
				evt->pprio = tcb_rq_of(prev_tcb);
				evt->pcref = tcb_cref_of(prev_tcb);
		      }
		      evt->pstate = prev_tcb_state;
		      str_cpy_p_to_a(evt->nname, tcb_name_of(next_tcb));
		      evt->nprio = tcb_rq_of(next_tcb);
		      evt->ncref = tcb_cref_of(next_tcb);
		      /* TODO: In some architectures currently do not support getting time in kernel
		       * fix the unified function interface to get time */
		      evt->timestamp = time_current_mono_nsec();
		      evt->cpu = cpu),
	   KEV_PRINT("[seq=%u] %llu.%06llu: prev_comm=%s prev_cref=0x%"__PRIx64" prev_prio=%u prev_state=%u ==> "
		     "next_comm=%s next_cref=0x%"__PRIx64" next_prio=%u cpu=%u\n",
		     evt->sequence, evt->timestamp / NSEC_PER_SEC, evt->timestamp % NSEC_PER_SEC / 1000ULL,
		     evt->pname, evt->pcref, evt->pprio, evt->pstate,
		     evt->nname, evt->ncref, evt->nprio, evt->cpu))

DEFINE_KEV(BLOCK, block,
	   KEV_ARG(2, struct tcb_s *, tcb, enum tcb_block_reason, reason),
	   KEV_STRUCT(3, __u32, sequence, char, __KEV_STRING(tname, 64), __u32, reason),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      str_cpy_p_to_a(evt->tname, tcb_name_of(tcb));
		      evt->reason = reason),
	   KEV_PRINT("[seq=%u] tcb='%s', reason=%u\n", evt->sequence, evt->tname, evt->reason))

DEFINE_KEV(UNBLOCK, unblock,
	   KEV_ARG(2, struct tcb_s *, tcb, enum tcb_block_reason, reason),
	   KEV_STRUCT(3, __u32, sequence, char, __KEV_STRING(tname, 64), __u32, reason),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      str_cpy_p_to_a(evt->tname, tcb_name_of(tcb));
		      evt->reason = reason),
	   KEV_PRINT("[seq=%u] tcb='%s', reason=%u\n", evt->sequence, evt->tname, evt->reason))

DEFINE_KEV(SYSCALL, syscall,
	   KEV_ARG(2, unsigned int, scno, unsigned int, is_fastpath),
	   KEV_STRUCT(3, __u32, sequence, __u32, scno, __u32, is_fastpath),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      evt->scno = scno; evt->is_fastpath = is_fastpath),
	   KEV_PRINT("[seq=%u] %u %s\n", evt->sequence, evt->scno,
		     (evt->is_fastpath ? "fastpath" : "slowpath")))

DEFINE_KEV(PAGEFAULT, pagefault,
	   KEV_ARG(2, unsigned long, faultpc, unsigned long, faultaddr),
	   KEV_STRUCT(3, __u32, sequence, __uptr_t, faultpc, __uptr_t, faultaddr),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      evt->faultpc = (u64)faultpc;
		      evt->faultaddr = (u64)faultaddr),
	   KEV_PRINT("[seq=%u] faultpc=0x%lx, faultaddr=%lx\n",
		     (evt->sequence),
		     (evt->faultpc),
		     (evt->faultaddr)))

DEFINE_KEV(IRQ, irq,
	   KEV_ARG(2,
		   unsigned int, irqno,
		   unsigned int, end),
	   KEV_STRUCT(4,
		      /* make sure irqno is the first field for filter */
		      __u32, irqno,
		      __u32, sequence,
		      __u32, end,
		      __u64, timestamp),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      evt->irqno = irqno;
		      evt->end = end;
		      /* TODO: In some architectures currently do not support getting time in kernel
		       * fix the unified function interface to get time */
		      evt->timestamp = time_current_mono_nsec()),
	   KEV_PRINT("[seq=%u] %llu.%06llu: irqno=0x%x %s\n", evt->sequence,
		     (evt->timestamp / NSEC_PER_SEC), (evt->timestamp % NSEC_PER_SEC / 1000ULL),
		     (evt->irqno),
		     (evt->end == 0U ? "begin" : "end")))

DEFINE_KEV(SAMPLE, sample,
	   KEV_ARG(2, const unsigned char *, s, size_t, len),
	   KEV_STRUCT(1, unsigned char, __KEV_STRING(data, PMU_SAMPLE_DATA_LEN)),
	   KEV_ASSIGN(mem_cpy_p_to_p(evt->data, PMU_SAMPLE_DATA_LEN, s, len)),
	   KEV_PRINT("sample=0x%llx\n", ((unsigned long long)(__uptr_t)(void *)evt->data)))

DEFINE_KEV(KLOG, klog,
	   KEV_ARG(4,
		   const char *, content_buffer,
		   size_t, content_size,
		   const char *, prefix_buffer,
		   size_t, prefix_size),
	   KEV_STRUCT(3,
		      __u32, sequence,
		      __u32, next_offset,
		      char, __KEV_STRING(data, 0)),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      evt->next_offset = -1U;
		      evt_arg.prefix_size = prefix_size;
		      evt_arg.content_size = content_size;
		      evt_arg.content_buffer = content_buffer;
		      evt_arg.prefix_buffer = prefix_buffer),
	   KEV_PRINT("[seq=%u] %s", evt->sequence, evt->data))

DEFINE_KEV(TAILCALL, tailcall,
	   KEV_ARG(1, unsigned int, tcno),
	   KEV_STRUCT(2, __u32, sequence, __u32, tcno),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence); evt->tcno = tcno),
	   KEV_PRINT("[seq=%u] %u\n", evt->sequence, evt->tcno))

DEFINE_KEV(KPREEMPT, kpreempt,
	   KEV_ARG(1, unsigned int, tcno),
	   KEV_STRUCT(2, __u32, sequence, __u32, tcno),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence); evt->tcno = tcno),
	   KEV_PRINT("[seq=%u] %u\n", evt->sequence, evt->tcno))

DEFINE_KEV(FIQ, fiq,
	   KEV_ARG(1, enum kev_fiq_text_id, text_id),
	   KEV_STRUCT(2, unsigned int, sequence, enum kev_fiq_text_id, text_id),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence); evt->text_id = text_id),
	   KEV_PRINT("[seq=%u] %s\n", evt->sequence, kev_fiq_text_of_id(evt->text_id)))

DEFINE_KEV(SCHED_MIGRATE_TASK, sched_migrate_task,
	   KEV_ARG(2, struct tcb_s *, tcb, unsigned int, dest_cpu),
	   KEV_STRUCT(6,
		      unsigned int, sequence,
		      char, __KEV_STRING(name, 64),
		      __u64, cref,
		      __u32, prio,
		      __u32, orig_cpu,
		      __u32, dest_cpu),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      str_cpy_p_to_a(evt->name, tcb_name_of(tcb));
		      evt->cref = tcb_cref_of(tcb);
		      evt->prio = tcb_rq_of(tcb);
		      evt->orig_cpu = tcb_cpu_of(tcb);
		      evt->dest_cpu = dest_cpu),
	   KEV_PRINT("[seq=%u] comm=%s cref=0x%"__PRIx64" prio=%u orig_cpu=%u dest_cpu=%u\n",
		     evt->sequence, evt->name, evt->cref, evt->prio, evt->orig_cpu, evt->dest_cpu))

DEFINE_KEV(AUDIT, audit,
	   KEV_ARG(2, void *, audit_data, size_t, len),
	   KEV_STRUCT(1, unsigned char , __KEV_STRING(data, __AUDIT_DATA_LEN)),
	   KEV_ASSIGN(mem_cpy_p_to_p(evt->data, __AUDIT_DATA_LEN, audit_data, len)),
	   KEV_PRINT("audit type=0x%x\n", (*(unsigned int *)(void *)(&(evt->data[0])))))

/* the definition of kev arg and kev struct must be the same as that in el2 */
DEFINE_KEV(TRAP_EL2, trap_el2,
	   KEV_ARG(5,
		   enum kev_trap_el2_type, type,
		   __u64, call_id,
		   __u64, x0,
		   __u64, x1,
		   __u64, x2),
	   KEV_STRUCT(8,
		      enum kev_trap_el2_type, type, /* trap in or out */
		      __u64, call_id,
		      __u64, x0,
		      __u64, x1,
		      __u64, x2,
		      __u64, tock_start,
		      __u64, tock,
		      __u64, freq),
	   KEV_ASSIGN(), /* set empty is ok, kev assign in el2 */
	   KEV_PRINT("[%llu.%06llu]%s: call_id=%"__PRIu64", x0=0x%"__PRIx64", x1=0x%"__PRIx64", x2=0x%"__PRIx64", "
		     "tock=%"__PRIu64", tock_start=%"__PRIu64", freq=%"__PRIu64"\n",
		     (kev_tock2time(evt->tock, evt->tock_start, evt->freq) / NSEC_PER_SEC),
		     ((kev_tock2time(evt->tock, evt->tock_start, evt->freq) % NSEC_PER_SEC) / NSEC_PER_USEC),
		     (evt->type == KEV_EL2_ENTER ? "enter" : "exit "),
		     evt->call_id, evt->x0, evt->x1, evt->x2,
		     evt->tock, evt->tock_start, evt->freq)) /* kev print in el1 */

DEFINE_KEV(EL2_LOG, el2_log,
	   KEV_ARG(4,
		   const char *, content_buffer,
		   size_t, content_size,
		   const char *, prefix_buffer,
		   size_t, prefix_size),
	   KEV_STRUCT(1,
		      char, __KEV_STRING(data, 0)),
	   KEV_ASSIGN(), /* set empty is ok, kev assign in el2 */
	   KEV_PRINT("%s", evt->data)) /* kev print in el1 */

DEFINE_KEV(VCPU_EXIT, vcpu_exit,
	   KEV_ARG(4,
		   __u8, vcpu_id,
		   __u64, exit_reason,
		   __u64, esr_el2,
		   __u64, x0),
	   KEV_STRUCT(10,
		      __u32, idx,
		      __u32, esr_iss,
		      __u8, esr_ec,
		      __u8, esr_il,
		      __u8, vcpu_id,
		      char, __KEV_STRING(reason, 8),
		      __u64, x0,
		      __u64, tock_start,
		      __u64, freq,
		      __u64, tock),
	   KEV_ASSIGN(), /* set empty is ok, kev assign in el2 */
	   KEV_PRINT("[%llu.%06llu][idx=%u]: vcpu_id=%d, exit_reason=%s, "
		     "esr.ec=0x%02x, esr.il=%u, esr.iss=0x%07x, x0=0x%016"__PRIx64", "
		     "tock=%"__PRIu64"\n",
		     (kev_tock2time(evt->tock, evt->tock_start, evt->freq) / NSEC_PER_SEC),
		     ((kev_tock2time(evt->tock, evt->tock_start, evt->freq) % NSEC_PER_SEC) / NSEC_PER_USEC),
		     evt->idx, evt->vcpu_id, evt->reason,
		     evt->esr_ec, evt->esr_il, evt->esr_iss, evt->x0, evt->tock)) /* kev print in el1 */

DEFINE_KEV(VCPU_ENTER, vcpu_enter,
	   KEV_ARG(4,
		   __u8, vcpu_id,
		   __u64, exit_reason,
		   __u64, esr_el2,
		   __u64, data),
	   KEV_STRUCT(9,
		      __u32, idx,
		      __u32, esr,
		      __u8, vcpu_id,
		      char, __KEV_STRING(reason, 8),
		      __u64, data,
		      __u64, tock_start,
		      __u64, tock,
		      __u64, duration,
		      __u64, freq),
	   KEV_ASSIGN(), /* set empty is ok, kev assign in el2 */
	   KEV_PRINT("[%llu.%06llu][idx=%u]: vcpu_id=%d, exit_reason=%s, "
		     "esr=0x%08x, data=0x%016"__PRIx64", "
		     "tock=%"__PRIu64", duration=%"__PRIu64"\n",
		     (kev_tock2time(evt->tock, evt->tock_start, evt->freq) / NSEC_PER_SEC),
		     ((kev_tock2time(evt->tock, evt->tock_start, evt->freq) % NSEC_PER_SEC) / NSEC_PER_USEC),
		     evt->idx, evt->vcpu_id, evt->reason, evt->esr, evt->data,
		     evt->tock, kev_tock2time(evt->duration, 0, evt->freq))) /* kev print in el1 */


DEFINE_KEV(EL2_IRQ, el2_irq,
	   KEV_ARG(2,
		   enum kev_el2_irq_type, type,
		   __u64, irq),
	   KEV_STRUCT(5,
		   enum kev_el2_irq_type, type,
		   __u64, irq,
		   __u64, tock_start,
		   __u64, tock,
		   __u64, freq),
	   KEV_ASSIGN(), /* set empty is ok, kev assign in el2 */
	   KEV_PRINT("[%llu.%06llu]%-10s: irq=%03"__PRIu64", tock=%"__PRIu64"\n",
		     (kev_tock2time(evt->tock, evt->tock_start, evt->freq) / NSEC_PER_SEC),
		     ((kev_tock2time(evt->tock, evt->tock_start, evt->freq) % NSEC_PER_SEC) / NSEC_PER_USEC),
		     el2_irq_type_str(evt->type), evt->irq, evt->tock)) /* kev print in el1 */

#ifdef __HOST_LLT__
/*
 * On 64 bit system,
 * sizeof(struct kev_test1) should be 253 * 8
 * Let's set RB_SIZE to 4096 (512 * 8) for testing.
 *
 * On 32 bit system,
 * sizeof(struct kev_test1) should be 511 * 4
 * Let's set RB_SIZE to 4096 (1024 * 4) for testing.
 */
DEFINE_KEV(TEST1, test1,
	   KEV_ARG(1, int, val),
	   KEV_STRUCT(2, unsigned int, sequence, char, __KEV_STRING(string,
#if (__SIZEOF_LONG__ == 8)
			   2000
#else
			   2028
#endif
		)),
	   KEV_ASSIGN(KEV_READ_SEQ(evt->sequence);
		      mem_zero_s(evt->string); evt->string[0] = '\0'),
	   KEV_PRINT("%d", (int)evt->string[0]))
#endif
