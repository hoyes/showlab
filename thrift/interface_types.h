/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef interface_TYPES_H
#define interface_TYPES_H

#include <Thrift.h>
#include <TApplicationException.h>
#include <protocol/TProtocol.h>
#include <transport/TTransport.h>





typedef struct _CueData__isset {
  _CueData__isset() : number(false), name(false) {}
  bool number;
  bool name;
} _CueData__isset;

class CueData {
 public:

  static const char* ascii_fingerprint; // = "07A9615F837F7D0A952B595DD3020972";
  static const uint8_t binary_fingerprint[16]; // = {0x07,0xA9,0x61,0x5F,0x83,0x7F,0x7D,0x0A,0x95,0x2B,0x59,0x5D,0xD3,0x02,0x09,0x72};

  CueData() : number(""), name("") {
  }

  virtual ~CueData() throw() {}

  std::string number;
  std::string name;

  _CueData__isset __isset;

  void __set_number(const std::string& val) {
    number = val;
  }

  void __set_name(const std::string& val) {
    name = val;
  }

  bool operator == (const CueData & rhs) const
  {
    if (!(number == rhs.number))
      return false;
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const CueData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CueData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};



#endif
