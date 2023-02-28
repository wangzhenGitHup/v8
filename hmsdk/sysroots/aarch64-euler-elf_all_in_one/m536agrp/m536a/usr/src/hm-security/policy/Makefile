#This file is used to rebuild policies.

ifeq ($(HM_VERBOSE),1)
  Q =
else
  Q = @
endif

# Check that given variables are set and all have non-empty values,
# die with an error otherwise.
#
# Params:
#   1. Variable name(s) to test.
#   2. (optional) Error message to print.
check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))

$(call check_defined, BIN, build_policy.bin)
$(call check_defined, POLICY, user defined policies)
$(call check_defined, OUTPUT, output dir for policy.db)

ifeq ($(INSTALL),)
 INSTALL = install
endif

BUILD_POLICY_BIN = $(abspath $(BIN))

OUTPUT := $(abspath $(OUTPUT))

ifeq ($(MAC_TRANS), true)
  POLICY_BASE_DIR = ./mac_trans_policies
# if user doesn't specify a db file name, and it is MAC TRANS mode, name it to policy_bypass.db
ifeq ($(DB_NAME),)
  DB_NAME = policy_bypass.db
endif
else
  POLICY_BASE_DIR = ./policies
# if user doesn't specify a db file name, and it is not MAC TRANS mode, name it to policy.db
ifeq ($(DB_NAME),)
  DB_NAME = policy.db
endif
endif

POLICY_BASE_DIR := $(abspath $(POLICY_BASE_DIR))
POLICY_BASE_DIR := $(shell find $(POLICY_BASE_DIR) -maxdepth 32 -type d)
POLICY_BASE_SRC = $(foreach dir,$(POLICY_BASE_DIR),$(wildcard $(dir)/*.m4))
POLICY_BASE_SRC := $(sort $(POLICY_BASE_SRC))
POLICY_MACRO_DIR=./policy_macros

ifdef TEST_OFF
 POLICY_BASE_SRC := $(filter-out $(POLICY_BASE_DIR)/test.type.policy, $(POLICY_BASE_SRC))
endif

POLICY := $(abspath $(POLICY))
POLICY_USR_SRC = $(wildcard $(POLICY)/*.policy)
POLICY_USR_SRC += $(wildcard $(POLICY)/*.m4)
POLICY_USR_SRC := $(sort $(POLICY_USR_SRC))

default:
	$(Q) install -d $(OUTPUT)
	$(Q) ${POLICY_MACRO_DIR}/m4/build_policy_with_macro.sh -b ${BUILD_POLICY_BIN} \
		-w ${OUTPUT} -o $(DB_NAME) $(POLICY_BASE_SRC) $(POLICY_USR_SRC)

.PHONY: default
