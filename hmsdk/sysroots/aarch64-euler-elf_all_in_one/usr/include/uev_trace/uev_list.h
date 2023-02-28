/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2021. All rights reserved.
 * Description: uev list in uvmm
 * Author: Huawei OS Kernel Lab
 * Create: Tue Apr 27 16:31:48 2021
 */

UEV_POINT(uvmm, vcpu_vmexit,
	  UEV_ARG(2, const struct vcpu *, vcpu, uint64_t, esr_el2),
	  UEV_TRACE_FIELD(2, uint64_t, mpid, uint64_t, esr_el2),
	  UEV_TRACE_ASSIGN(uev_data_write_string(&trace_data, "vcpu_vmexit");
			   uev_data_write_u64(&trace_data, vcpu->mpid);
			   uev_data_write_u64(&trace_data, esr_el2);),
	  UEV_TRACE_EFMT_FIELD(TRACE_STRING(STRING, char *, event)
			       TRACE_FIELD(U64, uint64_t, mpid)
			       TRACE_FIELD(U64, uint64_t, esr_el2)))

UEV_POINT(uvmm, vcpu_start_raw,
	  UEV_ARG(1, const struct vcpu *, vcpu),
	  UEV_TRACE_FIELD(3, uint64_t, mpid, int, state, int, online_vcpus),
	  UEV_TRACE_ASSIGN(uev_data_write_string(&trace_data, "vcpu_start_raw");
			   uev_data_write_u64(&trace_data, vcpu->mpid);
			   uev_data_write_int(&trace_data, (int)vcpu->state);
			   uev_data_write_int(&trace_data, raw_atomic_int_read(&vcpu->vm->online_vcpus));),
	  UEV_TRACE_EFMT_FIELD(TRACE_STRING(STRING, char *, event)
			       TRACE_FIELD(U64, uint64_t, mpid)
			       TRACE_FIELD(INT, int, state)
			       TRACE_FIELD(INT, int, online_vcpus)))

UEV_POINT(uvmm, vcpu_stop_raw,
	  UEV_ARG(1, const struct vcpu *, vcpu),
	  UEV_TRACE_FIELD(3, uint64_t, mpid, int, state, int, online_vcpus),
	  UEV_TRACE_ASSIGN(uev_data_write_string(&trace_data, "vcpu_stop_raw");
			   uev_data_write_u64(&trace_data, vcpu->mpid);
			   uev_data_write_int(&trace_data, (int)vcpu->state);
			   uev_data_write_int(&trace_data, raw_atomic_int_read(&vcpu->vm->online_vcpus));),
	  UEV_TRACE_EFMT_FIELD(TRACE_STRING(STRING, char *, event)
			       TRACE_FIELD(U64, uint64_t, mpid)
			       TRACE_FIELD(INT, int, state)
			       TRACE_FIELD(INT, int, online_vcpus)))

UEV_POINT(uvmm, handle_hvc_begin,
	  UEV_ARG(3, uint32_t, vcpu_id, struct svc_hvc_handler *, hvc_handler, uint64_t, op),
	  UEV_TRACE_FIELD(0),
	  UEV_TRACE_ASSIGN(uev_data_write_int(&trace_data, (int)vcpu_id);
			   uev_data_write_string(&trace_data, "handle_hvc_begin");
			   uev_data_write_string(&trace_data, hvc_handler->name);
			   uev_data_write_u64(&trace_data, op);),
	  UEV_TRACE_EFMT_FIELD(TRACE_FIELD(INT, int, vcpu)
			       TRACE_STRING(STRING, char *, event)
			       TRACE_STRING(STRING, char *, name)
			       TRACE_FIELD(X64, uint64_t, op)))

UEV_POINT(uvmm, handle_hvc_end,
	  UEV_ARG(3, uint32_t, vcpu_id, struct svc_hvc_handler *, hvc_handler, uint64_t, op),
	  UEV_TRACE_FIELD(0),
	  UEV_TRACE_ASSIGN(uev_data_write_int(&trace_data, (int)vcpu_id);
			   uev_data_write_string(&trace_data, "handle_hvc_end  ");
			   uev_data_write_string(&trace_data, hvc_handler->name);
			   uev_data_write_u64(&trace_data, op);),
	  UEV_TRACE_EFMT_FIELD(TRACE_FIELD(INT, int, vcpu)
			       TRACE_STRING(STRING, char *, event)
			       TRACE_STRING(STRING, char *, name)
			       TRACE_FIELD(X64, uint64_t, op)))

UEV_POINT(uvmm, mmio_rw_begin,
	  UEV_ARG(3, uint32_t, vcpu_id, struct mem_region *, mr, uint32_t, rw),
	  UEV_TRACE_FIELD(0),
	  UEV_TRACE_ASSIGN(uev_data_write_int(&trace_data, (int)vcpu_id);
			   uev_data_write_string(&trace_data, (rw == 0) ?
					"mmio_read_begin " : "mmio_write_begin");
			   uev_data_write_u64(&trace_data, mr->addr);
			   uev_data_write_u64(&trace_data, mr->size);),
	  UEV_TRACE_EFMT_FIELD(TRACE_FIELD(INT, int, vcpu)
			       TRACE_STRING(STRING, char *, event)
			       TRACE_FIELD(X64, uint64_t, region_start)
			       TRACE_FIELD(U64, uint64_t, size)))

UEV_POINT(uvmm, mmio_rw_end,
	  UEV_ARG(3, uint32_t, vcpu_id, struct mem_region *, mr, uint32_t, rw),
	  UEV_TRACE_FIELD(0),
	  UEV_TRACE_ASSIGN(uev_data_write_int(&trace_data, (int)vcpu_id);
			   uev_data_write_string(&trace_data, (rw == 0) ?
					"mmio_read_end   " : "mmio_write_end  ");
			   uev_data_write_u64(&trace_data, mr->addr);
			   uev_data_write_u64(&trace_data, mr->size);),
	  UEV_TRACE_EFMT_FIELD(TRACE_FIELD(INT, int, vcpu)
			       TRACE_STRING(STRING, char *, event)
			       TRACE_FIELD(X64, uint64_t, region_start)
			       TRACE_FIELD(U64, uint64_t, size)))
