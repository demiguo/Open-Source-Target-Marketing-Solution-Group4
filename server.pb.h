// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: server.proto

#ifndef PROTOBUF_server_2eproto__INCLUDED
#define PROTOBUF_server_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "unit.pb.h"
// @@protoc_insertion_point(includes)

namespace open_bracket {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_server_2eproto();
void protobuf_AssignDesc_server_2eproto();
void protobuf_ShutdownFile_server_2eproto();

class Request;
class Response;

// ===================================================================

class Request : public ::google::protobuf::Message {
 public:
  Request();
  virtual ~Request();

  Request(const Request& from);

  inline Request& operator=(const Request& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Request& default_instance();

  void Swap(Request* other);

  // implements Message ----------------------------------------------

  Request* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Request& from);
  void MergeFrom(const Request& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:open_bracket.Request)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_server_2eproto();
  friend void protobuf_AssignDesc_server_2eproto();
  friend void protobuf_ShutdownFile_server_2eproto();

  void InitAsDefaultInstance();
  static Request* default_instance_;
};
// -------------------------------------------------------------------

class Response : public ::google::protobuf::Message {
 public:
  Response();
  virtual ~Response();

  Response(const Response& from);

  inline Response& operator=(const Response& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Response& default_instance();

  void Swap(Response* other);

  // implements Message ----------------------------------------------

  Response* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Response& from);
  void MergeFrom(const Response& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .open_bracket.Unit unit = 1;
  inline int unit_size() const;
  inline void clear_unit();
  static const int kUnitFieldNumber = 1;
  inline const ::open_bracket::Unit& unit(int index) const;
  inline ::open_bracket::Unit* mutable_unit(int index);
  inline ::open_bracket::Unit* add_unit();
  inline const ::google::protobuf::RepeatedPtrField< ::open_bracket::Unit >&
      unit() const;
  inline ::google::protobuf::RepeatedPtrField< ::open_bracket::Unit >*
      mutable_unit();

  // @@protoc_insertion_point(class_scope:open_bracket.Response)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::open_bracket::Unit > unit_;
  friend void  protobuf_AddDesc_server_2eproto();
  friend void protobuf_AssignDesc_server_2eproto();
  friend void protobuf_ShutdownFile_server_2eproto();

  void InitAsDefaultInstance();
  static Response* default_instance_;
};
// ===================================================================


// ===================================================================

// Request

// -------------------------------------------------------------------

// Response

// repeated .open_bracket.Unit unit = 1;
inline int Response::unit_size() const {
  return unit_.size();
}
inline void Response::clear_unit() {
  unit_.Clear();
}
inline const ::open_bracket::Unit& Response::unit(int index) const {
  // @@protoc_insertion_point(field_get:open_bracket.Response.unit)
  return unit_.Get(index);
}
inline ::open_bracket::Unit* Response::mutable_unit(int index) {
  // @@protoc_insertion_point(field_mutable:open_bracket.Response.unit)
  return unit_.Mutable(index);
}
inline ::open_bracket::Unit* Response::add_unit() {
  // @@protoc_insertion_point(field_add:open_bracket.Response.unit)
  return unit_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::open_bracket::Unit >&
Response::unit() const {
  // @@protoc_insertion_point(field_list:open_bracket.Response.unit)
  return unit_;
}
inline ::google::protobuf::RepeatedPtrField< ::open_bracket::Unit >*
Response::mutable_unit() {
  // @@protoc_insertion_point(field_mutable_list:open_bracket.Response.unit)
  return &unit_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace open_bracket

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_server_2eproto__INCLUDED
