// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: text.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_text_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_text_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_text_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_text_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_text_2eproto;
namespace AssetInspection {
class Check;
struct CheckDefaultTypeInternal;
extern CheckDefaultTypeInternal _Check_default_instance_;
class IPResponse;
struct IPResponseDefaultTypeInternal;
extern IPResponseDefaultTypeInternal _IPResponse_default_instance_;
class TCPResponse;
struct TCPResponseDefaultTypeInternal;
extern TCPResponseDefaultTypeInternal _TCPResponse_default_instance_;
}  // namespace AssetInspection
PROTOBUF_NAMESPACE_OPEN
template<> ::AssetInspection::Check* Arena::CreateMaybeMessage<::AssetInspection::Check>(Arena*);
template<> ::AssetInspection::IPResponse* Arena::CreateMaybeMessage<::AssetInspection::IPResponse>(Arena*);
template<> ::AssetInspection::TCPResponse* Arena::CreateMaybeMessage<::AssetInspection::TCPResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace AssetInspection {

// ===================================================================

class Check final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:AssetInspection.Check) */ {
 public:
  inline Check() : Check(nullptr) {}
  ~Check() override;
  explicit constexpr Check(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Check(const Check& from);
  Check(Check&& from) noexcept
    : Check() {
    *this = ::std::move(from);
  }

  inline Check& operator=(const Check& from) {
    CopyFrom(from);
    return *this;
  }
  inline Check& operator=(Check&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Check& default_instance() {
    return *internal_default_instance();
  }
  static inline const Check* internal_default_instance() {
    return reinterpret_cast<const Check*>(
               &_Check_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Check& a, Check& b) {
    a.Swap(&b);
  }
  inline void Swap(Check* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Check* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Check* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Check>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Check& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Check& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Check* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "AssetInspection.Check";
  }
  protected:
  explicit Check(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTargetFieldNumber = 1,
  };
  // string target = 1;
  void clear_target();
  const std::string& target() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_target(ArgT0&& arg0, ArgT... args);
  std::string* mutable_target();
  PROTOBUF_NODISCARD std::string* release_target();
  void set_allocated_target(std::string* target);
  private:
  const std::string& _internal_target() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_target(const std::string& value);
  std::string* _internal_mutable_target();
  public:

  // @@protoc_insertion_point(class_scope:AssetInspection.Check)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr target_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_text_2eproto;
};
// -------------------------------------------------------------------

class IPResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:AssetInspection.IPResponse) */ {
 public:
  inline IPResponse() : IPResponse(nullptr) {}
  ~IPResponse() override;
  explicit constexpr IPResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  IPResponse(const IPResponse& from);
  IPResponse(IPResponse&& from) noexcept
    : IPResponse() {
    *this = ::std::move(from);
  }

  inline IPResponse& operator=(const IPResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline IPResponse& operator=(IPResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const IPResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const IPResponse* internal_default_instance() {
    return reinterpret_cast<const IPResponse*>(
               &_IPResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(IPResponse& a, IPResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(IPResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(IPResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  IPResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<IPResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const IPResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const IPResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(IPResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "AssetInspection.IPResponse";
  }
  protected:
  explicit IPResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDelayFieldNumber = 1,
    kLossFieldNumber = 2,
  };
  // int32 delay = 1;
  void clear_delay();
  int32_t delay() const;
  void set_delay(int32_t value);
  private:
  int32_t _internal_delay() const;
  void _internal_set_delay(int32_t value);
  public:

  // int32 loss = 2;
  void clear_loss();
  int32_t loss() const;
  void set_loss(int32_t value);
  private:
  int32_t _internal_loss() const;
  void _internal_set_loss(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:AssetInspection.IPResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t delay_;
  int32_t loss_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_text_2eproto;
};
// -------------------------------------------------------------------

class TCPResponse final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:AssetInspection.TCPResponse) */ {
 public:
  inline TCPResponse() : TCPResponse(nullptr) {}
  ~TCPResponse() override;
  explicit constexpr TCPResponse(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TCPResponse(const TCPResponse& from);
  TCPResponse(TCPResponse&& from) noexcept
    : TCPResponse() {
    *this = ::std::move(from);
  }

  inline TCPResponse& operator=(const TCPResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline TCPResponse& operator=(TCPResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TCPResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const TCPResponse* internal_default_instance() {
    return reinterpret_cast<const TCPResponse*>(
               &_TCPResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(TCPResponse& a, TCPResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(TCPResponse* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TCPResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TCPResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TCPResponse>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TCPResponse& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TCPResponse& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TCPResponse* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "AssetInspection.TCPResponse";
  }
  protected:
  explicit TCPResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFlagFieldNumber = 1,
  };
  // bool flag = 1;
  void clear_flag();
  bool flag() const;
  void set_flag(bool value);
  private:
  bool _internal_flag() const;
  void _internal_set_flag(bool value);
  public:

  // @@protoc_insertion_point(class_scope:AssetInspection.TCPResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool flag_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_text_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Check

// string target = 1;
inline void Check::clear_target() {
  target_.ClearToEmpty();
}
inline const std::string& Check::target() const {
  // @@protoc_insertion_point(field_get:AssetInspection.Check.target)
  return _internal_target();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Check::set_target(ArgT0&& arg0, ArgT... args) {
 
 target_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:AssetInspection.Check.target)
}
inline std::string* Check::mutable_target() {
  std::string* _s = _internal_mutable_target();
  // @@protoc_insertion_point(field_mutable:AssetInspection.Check.target)
  return _s;
}
inline const std::string& Check::_internal_target() const {
  return target_.Get();
}
inline void Check::_internal_set_target(const std::string& value) {
  
  target_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Check::_internal_mutable_target() {
  
  return target_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Check::release_target() {
  // @@protoc_insertion_point(field_release:AssetInspection.Check.target)
  return target_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Check::set_allocated_target(std::string* target) {
  if (target != nullptr) {
    
  } else {
    
  }
  target_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), target,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (target_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    target_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:AssetInspection.Check.target)
}

// -------------------------------------------------------------------

// IPResponse

// int32 delay = 1;
inline void IPResponse::clear_delay() {
  delay_ = 0;
}
inline int32_t IPResponse::_internal_delay() const {
  return delay_;
}
inline int32_t IPResponse::delay() const {
  // @@protoc_insertion_point(field_get:AssetInspection.IPResponse.delay)
  return _internal_delay();
}
inline void IPResponse::_internal_set_delay(int32_t value) {
  
  delay_ = value;
}
inline void IPResponse::set_delay(int32_t value) {
  _internal_set_delay(value);
  // @@protoc_insertion_point(field_set:AssetInspection.IPResponse.delay)
}

// int32 loss = 2;
inline void IPResponse::clear_loss() {
  loss_ = 0;
}
inline int32_t IPResponse::_internal_loss() const {
  return loss_;
}
inline int32_t IPResponse::loss() const {
  // @@protoc_insertion_point(field_get:AssetInspection.IPResponse.loss)
  return _internal_loss();
}
inline void IPResponse::_internal_set_loss(int32_t value) {
  
  loss_ = value;
}
inline void IPResponse::set_loss(int32_t value) {
  _internal_set_loss(value);
  // @@protoc_insertion_point(field_set:AssetInspection.IPResponse.loss)
}

// -------------------------------------------------------------------

// TCPResponse

// bool flag = 1;
inline void TCPResponse::clear_flag() {
  flag_ = false;
}
inline bool TCPResponse::_internal_flag() const {
  return flag_;
}
inline bool TCPResponse::flag() const {
  // @@protoc_insertion_point(field_get:AssetInspection.TCPResponse.flag)
  return _internal_flag();
}
inline void TCPResponse::_internal_set_flag(bool value) {
  
  flag_ = value;
}
inline void TCPResponse::set_flag(bool value) {
  _internal_set_flag(value);
  // @@protoc_insertion_point(field_set:AssetInspection.TCPResponse.flag)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace AssetInspection

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_text_2eproto
