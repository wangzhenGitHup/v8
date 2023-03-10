#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CONVERT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CONVERT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

TNode<Int32T> FromConstexpr_int31_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Int32T> FromConstexpr_int32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Int32T> FromConstexpr_int32_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i);
TNode<IntPtrT> FromConstexpr_intptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<IntPtrT> FromConstexpr_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i);
TNode<IntPtrT> FromConstexpr_intptr_constexpr_intptr_0(compiler::CodeAssemblerState* state_, intptr_t p_i);
TNode<UintPtrT> FromConstexpr_uintptr_constexpr_uintptr_0(compiler::CodeAssemblerState* state_, uintptr_t p_i);
TNode<Smi> FromConstexpr_Smi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Smi> FromConstexpr_PositiveSmi_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<String> FromConstexpr_String_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s);
TNode<Number> FromConstexpr_Number_constexpr_uint32_0(compiler::CodeAssemblerState* state_, uint32_t p_i);
TNode<Number> FromConstexpr_Number_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i);
TNode<Number> FromConstexpr_Number_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_f);
TNode<Number> FromConstexpr_Number_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Uint8T> FromConstexpr_uint8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Int8T> FromConstexpr_int8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Uint8T> FromConstexpr_char8_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Number> FromConstexpr_Number_constexpr_Smi_0(compiler::CodeAssemblerState* state_, Smi p_s);
TNode<Smi> FromConstexpr_Smi_constexpr_Smi_0(compiler::CodeAssemblerState* state_, Smi p_s);
TNode<Uint32T> FromConstexpr_uint32_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Uint8T> FromConstexpr_uint8_constexpr_uint8_0(compiler::CodeAssemblerState* state_, uint8_t p_i);
TNode<Uint32T> FromConstexpr_uint32_constexpr_uint32_0(compiler::CodeAssemblerState* state_, uint32_t p_i);
TNode<Uint64T> FromConstexpr_uint64_constexpr_uint64_0(compiler::CodeAssemblerState* state_, uint64_t p_i);
TNode<Uint64T> FromConstexpr_uint64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<UintPtrT> FromConstexpr_uintptr_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Float64T> FromConstexpr_float64_constexpr_int31_0(compiler::CodeAssemblerState* state_, int31_t p_i);
TNode<Float64T> FromConstexpr_float64_constexpr_float64_0(compiler::CodeAssemblerState* state_, double p_i);
TNode<BoolT> FromConstexpr_bool_constexpr_bool_0(compiler::CodeAssemblerState* state_, bool p_b);
TNode<Object> FromConstexpr_Object_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s);
TNode<Object> FromConstexpr_JSAny_constexpr_string_0(compiler::CodeAssemblerState* state_, const char* p_s);
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ContextSlot_0(compiler::CodeAssemblerState* state_, Context::Field p_c);
TNode<Smi> FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(compiler::CodeAssemblerState* state_, LanguageMode p_c);
TNode<Int32T> FromConstexpr_PromiseState_constexpr_PromiseState_0(compiler::CodeAssemblerState* state_, Promise::PromiseState p_c);
TNode<Uint16T> FromConstexpr_InstanceType_constexpr_InstanceType_0(compiler::CodeAssemblerState* state_, InstanceType p_c);
TNode<Uint32T> FromConstexpr_IterationKind_constexpr_IterationKind_0(compiler::CodeAssemblerState* state_, IterationKind p_c);
TNode<Uint32T> FromConstexpr_TrimMode_constexpr_TrimMode_0(compiler::CodeAssemblerState* state_, String::TrimMode p_c);
TNode<Oddball> Convert_Boolean_bool_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_b);
TNode<Int32T> Convert_int32_bool_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_b);
TNode<Number> Convert_Number_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i);
TNode<IntPtrT> Convert_intptr_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i);
TNode<IntPtrT> Convert_intptr_int31_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i);
TNode<IntPtrT> Convert_intptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i);
TNode<Smi> Convert_Smi_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i);
TNode<Number> Convert_Number_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui);
TNode<Smi> Convert_Smi_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui);
TNode<UintPtrT> Convert_uintptr_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui);
TNode<Uint64T> Convert_uint64_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui);
TNode<IntPtrT> Convert_intptr_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_ui);
TNode<IntPtrT> Convert_intptr_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_ui);
TNode<Uint8T> Convert_uint8_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<Int8T> Convert_int8_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<Int32T> Convert_int32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i);
TNode<Int32T> Convert_int32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i);
TNode<Int32T> Convert_int32_char8_OR_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i);
TNode<Int32T> Convert_int32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i);
TNode<Int32T> Convert_int32_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<Int32T> Convert_int32_int64_0(compiler::CodeAssemblerState* state_, TNode<Int64T> p_i);
TNode<Int32T> Convert_int32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<Smi> Convert_Smi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<Uint32T> Convert_uint32_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui);
TNode<IntPtrT> Convert_intptr_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s);
TNode<UintPtrT> Convert_uintptr_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_ps);
TNode<IntPtrT> Convert_intptr_TaggedIndex_0(compiler::CodeAssemblerState* state_, TNode<TaggedIndex> p_ti);
TNode<TaggedIndex> Convert_TaggedIndex_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<IntPtrT> Convert_intptr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui);
TNode<Smi> Convert_PositiveSmi_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<Smi> Convert_PositiveSmi_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui, compiler::CodeAssemblerLabel* label_IfOverflow);
TNode<Smi> Convert_PositiveSmi_intptr_1(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i, compiler::CodeAssemblerLabel* label_IfOverflow);
TNode<Smi> Convert_PositiveSmi_uint32_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_ui, compiler::CodeAssemblerLabel* label_IfOverflow);
TNode<Int32T> Convert_int32_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s);
TNode<Float64T> Convert_float64_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<HeapNumber> p_h);
TNode<Float64T> Convert_float64_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<UintPtrT> Convert_uintptr_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<Float64T> Convert_float64_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_f);
TNode<Float64T> Convert_float64_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_f);
TorqueStructfloat64_or_hole_0 Convert_float64_or_hole_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_f);
TorqueStructfloat64_or_hole_0 Convert_float64_or_hole_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<Float32T> Convert_float32_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_f);
TNode<Float32T> Convert_float32_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<Number> Convert_Number_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d);
TNode<Float64T> Convert_float64_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui);
TNode<Number> Convert_Number_uintptr_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_ui);
TNode<Number> Convert_Number_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<UintPtrT> Convert_uintptr_float64_0(compiler::CodeAssemblerState* state_, TNode<Float64T> p_d);
TNode<UintPtrT> Convert_uintptr_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_i);
TNode<UintPtrT> Convert_uintptr_RawPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r);
TNode<IntPtrT> Convert_intptr_RawPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_r);
TNode<IntPtrT> Convert_intptr_Number_0(compiler::CodeAssemblerState* state_, TNode<Number> p_n);
TNode<BInt> Convert_bint_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_v);
TNode<BInt> Convert_bint_intptr_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_v);
TNode<IntPtrT> Convert_intptr_bint_0(compiler::CodeAssemblerState* state_, TNode<BInt> p_v);
TNode<BInt> Convert_bint_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_v);
TNode<Smi> Convert_Smi_bint_0(compiler::CodeAssemblerState* state_, TNode<BInt> p_v);
TNode<Int32T> Convert_PromiseState_int32_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_s);
TNode<Uint32T> Convert_ScopeFlags_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_s);
TNode<I8x16T> Convert_I8X16_Simd128_0(compiler::CodeAssemblerState* state_, TNode<Simd128T> p_s);
TNode<Uint32T> Convert_uint32_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i);
TNode<Uint32T> Convert_uint32_uint16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i);
TNode<Uint32T> Convert_uint32_char8_OR_char16_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_i);
TNode<Uint32T> Convert_uint32_uint31_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_i);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_CONVERT_TQ_CSA_H_
