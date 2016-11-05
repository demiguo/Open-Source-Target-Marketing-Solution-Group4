// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: model.proto

#ifndef PROTOBUF_model_2eproto__INCLUDED
#define PROTOBUF_model_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace open_bracket {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_model_2eproto();
void protobuf_AssignDesc_model_2eproto();
void protobuf_ShutdownFile_model_2eproto();

class Model;

// ===================================================================

class Model : public ::google::protobuf::Message {
 public:
  Model();
  virtual ~Model();

  Model(const Model& from);

  inline Model& operator=(const Model& from) {
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
  static const Model& default_instance();

  void Swap(Model* other);

  // implements Message ----------------------------------------------

  Model* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Model& from);
  void MergeFrom(const Model& from);
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

  // optional string model_name = 1;
  inline bool has_model_name() const;
  inline void clear_model_name();
  static const int kModelNameFieldNumber = 1;
  inline const ::std::string& model_name() const;
  inline void set_model_name(const ::std::string& value);
  inline void set_model_name(const char* value);
  inline void set_model_name(const char* value, size_t size);
  inline ::std::string* mutable_model_name();
  inline ::std::string* release_model_name();
  inline void set_allocated_model_name(::std::string* model_name);

  // @@protoc_insertion_point(class_scope:open_bracket.Model)
 private:
  inline void set_has_model_name();
  inline void clear_has_model_name();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* model_name_;
  friend void  protobuf_AddDesc_model_2eproto();
  friend void protobuf_AssignDesc_model_2eproto();
  friend void protobuf_ShutdownFile_model_2eproto();

  void InitAsDefaultInstance();
  static Model* default_instance_;
};
// ===================================================================


// ===================================================================

// Model

// optional string model_name = 1;
inline bool Model::has_model_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Model::set_has_model_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Model::clear_has_model_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Model::clear_model_name() {
  if (model_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    model_name_->clear();
  }
  clear_has_model_name();
}
inline const ::std::string& Model::model_name() const {
  // @@protoc_insertion_point(field_get:open_bracket.Model.model_name)
  return *model_name_;
}
inline void Model::set_model_name(const ::std::string& value) {
  set_has_model_name();
  if (model_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    model_name_ = new ::std::string;
  }
  model_name_->assign(value);
  // @@protoc_insertion_point(field_set:open_bracket.Model.model_name)
}
inline void Model::set_model_name(const char* value) {
  set_has_model_name();
  if (model_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    model_name_ = new ::std::string;
  }
  model_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:open_bracket.Model.model_name)
}
inline void Model::set_model_name(const char* value, size_t size) {
  set_has_model_name();
  if (model_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    model_name_ = new ::std::string;
  }
  model_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:open_bracket.Model.model_name)
}
inline ::std::string* Model::mutable_model_name() {
  set_has_model_name();
  if (model_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    model_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:open_bracket.Model.model_name)
  return model_name_;
}
inline ::std::string* Model::release_model_name() {
  clear_has_model_name();
  if (model_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = model_name_;
    model_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Model::set_allocated_model_name(::std::string* model_name) {
  if (model_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete model_name_;
  }
  if (model_name) {
    set_has_model_name();
    model_name_ = model_name;
  } else {
    clear_has_model_name();
    model_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:open_bracket.Model.model_name)
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

#endif  // PROTOBUF_model_2eproto__INCLUDED
