// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cargo.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_cargo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_cargo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007001 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_cargo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_cargo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_cargo_2eproto;
class PortoCargo;
class PortoCargoDefaultTypeInternal;
extern PortoCargoDefaultTypeInternal _PortoCargo_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::PortoCargo* Arena::CreateMaybeMessage<::PortoCargo>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class PortoCargo :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:PortoCargo) */ {
 public:
  PortoCargo();
  virtual ~PortoCargo();

  PortoCargo(const PortoCargo& from);
  PortoCargo(PortoCargo&& from) noexcept
    : PortoCargo() {
    *this = ::std::move(from);
  }

  inline PortoCargo& operator=(const PortoCargo& from) {
    CopyFrom(from);
    return *this;
  }
  inline PortoCargo& operator=(PortoCargo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const PortoCargo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PortoCargo* internal_default_instance() {
    return reinterpret_cast<const PortoCargo*>(
               &_PortoCargo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(PortoCargo* other);
  friend void swap(PortoCargo& a, PortoCargo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PortoCargo* New() const final {
    return CreateMaybeMessage<PortoCargo>(nullptr);
  }

  PortoCargo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<PortoCargo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const PortoCargo& from);
  void MergeFrom(const PortoCargo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PortoCargo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "PortoCargo";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_cargo_2eproto);
    return ::descriptor_table_cargo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);

  // string description = 3;
  void clear_description();
  static const int kDescriptionFieldNumber = 3;
  const std::string& description() const;
  void set_description(const std::string& value);
  void set_description(std::string&& value);
  void set_description(const char* value);
  void set_description(const char* value, size_t size);
  std::string* mutable_description();
  std::string* release_description();
  void set_allocated_description(std::string* description);

  // string relative_person = 7;
  void clear_relative_person();
  static const int kRelativePersonFieldNumber = 7;
  const std::string& relative_person() const;
  void set_relative_person(const std::string& value);
  void set_relative_person(std::string&& value);
  void set_relative_person(const char* value);
  void set_relative_person(const char* value, size_t size);
  std::string* mutable_relative_person();
  std::string* release_relative_person();
  void set_allocated_relative_person(std::string* relative_person);

  // string relative_geo_position = 8;
  void clear_relative_geo_position();
  static const int kRelativeGeoPositionFieldNumber = 8;
  const std::string& relative_geo_position() const;
  void set_relative_geo_position(const std::string& value);
  void set_relative_geo_position(std::string&& value);
  void set_relative_geo_position(const char* value);
  void set_relative_geo_position(const char* value, size_t size);
  std::string* mutable_relative_geo_position();
  std::string* release_relative_geo_position();
  void set_allocated_relative_geo_position(std::string* relative_geo_position);

  // uint64 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::uint64 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // uint64 prodece_area = 4;
  void clear_prodece_area();
  static const int kProdeceAreaFieldNumber = 4;
  ::PROTOBUF_NAMESPACE_ID::uint64 prodece_area() const;
  void set_prodece_area(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // double price = 5;
  void clear_price();
  static const int kPriceFieldNumber = 5;
  double price() const;
  void set_price(double value);

  // uint64 unit = 6;
  void clear_unit();
  static const int kUnitFieldNumber = 6;
  ::PROTOBUF_NAMESPACE_ID::uint64 unit() const;
  void set_unit(::PROTOBUF_NAMESPACE_ID::uint64 value);

  // @@protoc_insertion_point(class_scope:PortoCargo)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr description_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr relative_person_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr relative_geo_position_;
  ::PROTOBUF_NAMESPACE_ID::uint64 id_;
  ::PROTOBUF_NAMESPACE_ID::uint64 prodece_area_;
  double price_;
  ::PROTOBUF_NAMESPACE_ID::uint64 unit_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_cargo_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PortoCargo

// uint64 id = 1;
inline void PortoCargo::clear_id() {
  id_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PortoCargo::id() const {
  // @@protoc_insertion_point(field_get:PortoCargo.id)
  return id_;
}
inline void PortoCargo::set_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:PortoCargo.id)
}

// string name = 2;
inline void PortoCargo::clear_name() {
  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& PortoCargo::name() const {
  // @@protoc_insertion_point(field_get:PortoCargo.name)
  return name_.GetNoArena();
}
inline void PortoCargo::set_name(const std::string& value) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PortoCargo.name)
}
inline void PortoCargo::set_name(std::string&& value) {
  
  name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PortoCargo.name)
}
inline void PortoCargo::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PortoCargo.name)
}
inline void PortoCargo::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PortoCargo.name)
}
inline std::string* PortoCargo::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:PortoCargo.name)
  return name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PortoCargo::release_name() {
  // @@protoc_insertion_point(field_release:PortoCargo.name)
  
  return name_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PortoCargo::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:PortoCargo.name)
}

// string description = 3;
inline void PortoCargo::clear_description() {
  description_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& PortoCargo::description() const {
  // @@protoc_insertion_point(field_get:PortoCargo.description)
  return description_.GetNoArena();
}
inline void PortoCargo::set_description(const std::string& value) {
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PortoCargo.description)
}
inline void PortoCargo::set_description(std::string&& value) {
  
  description_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PortoCargo.description)
}
inline void PortoCargo::set_description(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PortoCargo.description)
}
inline void PortoCargo::set_description(const char* value, size_t size) {
  
  description_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PortoCargo.description)
}
inline std::string* PortoCargo::mutable_description() {
  
  // @@protoc_insertion_point(field_mutable:PortoCargo.description)
  return description_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PortoCargo::release_description() {
  // @@protoc_insertion_point(field_release:PortoCargo.description)
  
  return description_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PortoCargo::set_allocated_description(std::string* description) {
  if (description != nullptr) {
    
  } else {
    
  }
  description_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), description);
  // @@protoc_insertion_point(field_set_allocated:PortoCargo.description)
}

// uint64 prodece_area = 4;
inline void PortoCargo::clear_prodece_area() {
  prodece_area_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PortoCargo::prodece_area() const {
  // @@protoc_insertion_point(field_get:PortoCargo.prodece_area)
  return prodece_area_;
}
inline void PortoCargo::set_prodece_area(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  prodece_area_ = value;
  // @@protoc_insertion_point(field_set:PortoCargo.prodece_area)
}

// double price = 5;
inline void PortoCargo::clear_price() {
  price_ = 0;
}
inline double PortoCargo::price() const {
  // @@protoc_insertion_point(field_get:PortoCargo.price)
  return price_;
}
inline void PortoCargo::set_price(double value) {
  
  price_ = value;
  // @@protoc_insertion_point(field_set:PortoCargo.price)
}

// uint64 unit = 6;
inline void PortoCargo::clear_unit() {
  unit_ = PROTOBUF_ULONGLONG(0);
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 PortoCargo::unit() const {
  // @@protoc_insertion_point(field_get:PortoCargo.unit)
  return unit_;
}
inline void PortoCargo::set_unit(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  unit_ = value;
  // @@protoc_insertion_point(field_set:PortoCargo.unit)
}

// string relative_person = 7;
inline void PortoCargo::clear_relative_person() {
  relative_person_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& PortoCargo::relative_person() const {
  // @@protoc_insertion_point(field_get:PortoCargo.relative_person)
  return relative_person_.GetNoArena();
}
inline void PortoCargo::set_relative_person(const std::string& value) {
  
  relative_person_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PortoCargo.relative_person)
}
inline void PortoCargo::set_relative_person(std::string&& value) {
  
  relative_person_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PortoCargo.relative_person)
}
inline void PortoCargo::set_relative_person(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  relative_person_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PortoCargo.relative_person)
}
inline void PortoCargo::set_relative_person(const char* value, size_t size) {
  
  relative_person_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PortoCargo.relative_person)
}
inline std::string* PortoCargo::mutable_relative_person() {
  
  // @@protoc_insertion_point(field_mutable:PortoCargo.relative_person)
  return relative_person_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PortoCargo::release_relative_person() {
  // @@protoc_insertion_point(field_release:PortoCargo.relative_person)
  
  return relative_person_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PortoCargo::set_allocated_relative_person(std::string* relative_person) {
  if (relative_person != nullptr) {
    
  } else {
    
  }
  relative_person_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), relative_person);
  // @@protoc_insertion_point(field_set_allocated:PortoCargo.relative_person)
}

// string relative_geo_position = 8;
inline void PortoCargo::clear_relative_geo_position() {
  relative_geo_position_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& PortoCargo::relative_geo_position() const {
  // @@protoc_insertion_point(field_get:PortoCargo.relative_geo_position)
  return relative_geo_position_.GetNoArena();
}
inline void PortoCargo::set_relative_geo_position(const std::string& value) {
  
  relative_geo_position_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:PortoCargo.relative_geo_position)
}
inline void PortoCargo::set_relative_geo_position(std::string&& value) {
  
  relative_geo_position_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:PortoCargo.relative_geo_position)
}
inline void PortoCargo::set_relative_geo_position(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  relative_geo_position_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:PortoCargo.relative_geo_position)
}
inline void PortoCargo::set_relative_geo_position(const char* value, size_t size) {
  
  relative_geo_position_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:PortoCargo.relative_geo_position)
}
inline std::string* PortoCargo::mutable_relative_geo_position() {
  
  // @@protoc_insertion_point(field_mutable:PortoCargo.relative_geo_position)
  return relative_geo_position_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* PortoCargo::release_relative_geo_position() {
  // @@protoc_insertion_point(field_release:PortoCargo.relative_geo_position)
  
  return relative_geo_position_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void PortoCargo::set_allocated_relative_geo_position(std::string* relative_geo_position) {
  if (relative_geo_position != nullptr) {
    
  } else {
    
  }
  relative_geo_position_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), relative_geo_position);
  // @@protoc_insertion_point(field_set_allocated:PortoCargo.relative_geo_position)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_cargo_2eproto
