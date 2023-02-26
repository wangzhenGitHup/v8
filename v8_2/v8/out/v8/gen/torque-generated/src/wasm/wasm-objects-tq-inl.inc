template <class D, class P>
Address TorqueGeneratedWasmCapiFunctionData<D, P>::call_target() const {
  Address value;
  value = this->template ReadField<Address>(kCallTargetOffset);
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_call_target(Address value) {
  this->template WriteField<Address>(kCallTargetOffset, value);
}

template <class D, class P>
Foreign TorqueGeneratedWasmCapiFunctionData<D, P>::embedder_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmCapiFunctionData::embedder_data(cage_base);
}
template <class D, class P>
Foreign TorqueGeneratedWasmCapiFunctionData<D, P>::embedder_data(PtrComprCageBase cage_base) const {
  Foreign value;
  value = TaggedField<Foreign>::load(cage_base, *this, kEmbedderDataOffset);
  DCHECK(value.IsForeign());
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_embedder_data(Foreign value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsForeign());
  WRITE_FIELD(*this, kEmbedderDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEmbedderDataOffset, value, mode);
}

template <class D, class P>
Code TorqueGeneratedWasmCapiFunctionData<D, P>::wrapper_code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmCapiFunctionData::wrapper_code(cage_base);
}
template <class D, class P>
Code TorqueGeneratedWasmCapiFunctionData<D, P>::wrapper_code(PtrComprCageBase cage_base) const {
  Code value;
  value = TaggedField<Code>::load(cage_base, *this, kWrapperCodeOffset);
  DCHECK(value.IsCode());
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_wrapper_code(Code value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCode());
  WRITE_FIELD(*this, kWrapperCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kWrapperCodeOffset, value, mode);
}

template <class D, class P>
PodArray<wasm::ValueType> TorqueGeneratedWasmCapiFunctionData<D, P>::serialized_signature() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmCapiFunctionData::serialized_signature(cage_base);
}
template <class D, class P>
PodArray<wasm::ValueType> TorqueGeneratedWasmCapiFunctionData<D, P>::serialized_signature(PtrComprCageBase cage_base) const {
  PodArray<wasm::ValueType> value;
  value = TaggedField<PodArray<wasm::ValueType>>::load(cage_base, *this, kSerializedSignatureOffset);
  DCHECK(value.IsByteArray());
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_serialized_signature(PodArray<wasm::ValueType> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsByteArray());
  WRITE_FIELD(*this, kSerializedSignatureOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSerializedSignatureOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmCapiFunctionData<D, P>::TorqueGeneratedWasmCapiFunctionData(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(IsWasmCapiFunctionData_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmCapiFunctionData<D, P>::TorqueGeneratedWasmCapiFunctionData(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || IsWasmCapiFunctionData_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(WasmCapiFunctionData)
template <class D, class P>
int TorqueGeneratedWasmExceptionTag<D, P>::index() const {
  int value;
  value = TaggedField<Smi>::load(*this, kIndexOffset).value();
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmExceptionTag<D, P>::set_index(int value) {
  WRITE_FIELD(*this, kIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmExceptionTag<D, P>::TorqueGeneratedWasmExceptionTag(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(IsWasmExceptionTag_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmExceptionTag<D, P>::TorqueGeneratedWasmExceptionTag(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || IsWasmExceptionTag_NonInline(*this));
}
template <class D, class P>
FixedArray TorqueGeneratedWasmTypeInfo<D, P>::supertypes() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTypeInfo::supertypes(cage_base);
}
template <class D, class P>
FixedArray TorqueGeneratedWasmTypeInfo<D, P>::supertypes(PtrComprCageBase cage_base) const {
  FixedArray value;
  value = TaggedField<FixedArray>::load(cage_base, *this, kSupertypesOffset);
  DCHECK(value.IsFixedArray());
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmTypeInfo<D, P>::set_supertypes(FixedArray value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsFixedArray());
  WRITE_FIELD(*this, kSupertypesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSupertypesOffset, value, mode);
}

template <class D, class P>
ArrayList TorqueGeneratedWasmTypeInfo<D, P>::subtypes() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTypeInfo::subtypes(cage_base);
}
template <class D, class P>
ArrayList TorqueGeneratedWasmTypeInfo<D, P>::subtypes(PtrComprCageBase cage_base) const {
  ArrayList value;
  value = TaggedField<ArrayList>::load(cage_base, *this, kSubtypesOffset);
  DCHECK(value.IsArrayList());
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmTypeInfo<D, P>::set_subtypes(ArrayList value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsArrayList());
  WRITE_FIELD(*this, kSubtypesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSubtypesOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmTypeInfo<D, P>::TorqueGeneratedWasmTypeInfo(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(IsWasmTypeInfo_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmTypeInfo<D, P>::TorqueGeneratedWasmTypeInfo(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || IsWasmTypeInfo_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmStruct<D, P>::TorqueGeneratedWasmStruct(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(IsWasmStruct_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmStruct<D, P>::TorqueGeneratedWasmStruct(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || IsWasmStruct_NonInline(*this));
}
template <class D, class P>
uint32_t TorqueGeneratedWasmArray<D, P>::length() const {
  uint32_t value;
  value = this->template ReadField<uint32_t>(kLengthOffset);
  return value;
}
template <class D, class P>
void TorqueGeneratedWasmArray<D, P>::set_length(uint32_t value) {
  this->template WriteField<uint32_t>(kLengthOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmArray<D, P>::TorqueGeneratedWasmArray(Address ptr)
  : P(ptr) {
  SLOW_DCHECK(IsWasmArray_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmArray<D, P>::TorqueGeneratedWasmArray(Address ptr, HeapObject::AllowInlineSmiStorage allow_smi)
  : P(ptr, allow_smi) {
  SLOW_DCHECK((allow_smi == HeapObject::AllowInlineSmiStorage::kAllowBeingASmi && this->IsSmi()) || IsWasmArray_NonInline(*this));
}
