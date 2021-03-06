// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: unit.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "unit.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace open_bracket {

namespace {

const ::google::protobuf::Descriptor* Unit_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Unit_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_unit_2eproto() {
  protobuf_AddDesc_unit_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "unit.proto");
  GOOGLE_CHECK(file != NULL);
  Unit_descriptor_ = file->message_type(0);
  static const int Unit_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Unit, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Unit, display_name_),
  };
  Unit_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Unit_descriptor_,
      Unit::default_instance_,
      Unit_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Unit, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Unit, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Unit));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_unit_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Unit_descriptor_, &Unit::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_unit_2eproto() {
  delete Unit::default_instance_;
  delete Unit_reflection_;
}

void protobuf_AddDesc_unit_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nunit.proto\022\014open_bracket\"(\n\004Unit\022\n\n\002id"
    "\030\001 \001(\003\022\024\n\014display_name\030\002 \001(\t", 68);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "unit.proto", &protobuf_RegisterTypes);
  Unit::default_instance_ = new Unit();
  Unit::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_unit_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_unit_2eproto {
  StaticDescriptorInitializer_unit_2eproto() {
    protobuf_AddDesc_unit_2eproto();
  }
} static_descriptor_initializer_unit_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Unit::kIdFieldNumber;
const int Unit::kDisplayNameFieldNumber;
#endif  // !_MSC_VER

Unit::Unit()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:open_bracket.Unit)
}

void Unit::InitAsDefaultInstance() {
}

Unit::Unit(const Unit& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:open_bracket.Unit)
}

void Unit::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = GOOGLE_LONGLONG(0);
  display_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Unit::~Unit() {
  // @@protoc_insertion_point(destructor:open_bracket.Unit)
  SharedDtor();
}

void Unit::SharedDtor() {
  if (display_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete display_name_;
  }
  if (this != default_instance_) {
  }
}

void Unit::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Unit::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Unit_descriptor_;
}

const Unit& Unit::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_unit_2eproto();
  return *default_instance_;
}

Unit* Unit::default_instance_ = NULL;

Unit* Unit::New() const {
  return new Unit;
}

void Unit::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    id_ = GOOGLE_LONGLONG(0);
    if (has_display_name()) {
      if (display_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        display_name_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Unit::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:open_bracket.Unit)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int64 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_display_name;
        break;
      }

      // optional string display_name = 2;
      case 2: {
        if (tag == 18) {
         parse_display_name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_display_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->display_name().data(), this->display_name().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "display_name");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:open_bracket.Unit)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:open_bracket.Unit)
  return false;
#undef DO_
}

void Unit::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:open_bracket.Unit)
  // optional int64 id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->id(), output);
  }

  // optional string display_name = 2;
  if (has_display_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->display_name().data(), this->display_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "display_name");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->display_name(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:open_bracket.Unit)
}

::google::protobuf::uint8* Unit::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:open_bracket.Unit)
  // optional int64 id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->id(), target);
  }

  // optional string display_name = 2;
  if (has_display_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->display_name().data(), this->display_name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "display_name");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->display_name(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:open_bracket.Unit)
  return target;
}

int Unit::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int64 id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->id());
    }

    // optional string display_name = 2;
    if (has_display_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->display_name());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Unit::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Unit* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Unit*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Unit::MergeFrom(const Unit& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_display_name()) {
      set_display_name(from.display_name());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Unit::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Unit::CopyFrom(const Unit& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Unit::IsInitialized() const {

  return true;
}

void Unit::Swap(Unit* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(display_name_, other->display_name_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Unit::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Unit_descriptor_;
  metadata.reflection = Unit_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace open_bracket

// @@protoc_insertion_point(global_scope)
