#ifndef _ROS_SERVICE_LoadClassifier_h
#define _ROS_SERVICE_LoadClassifier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

static const char LOADCLASSIFIER[] = "ml_classifiers/LoadClassifier";

  class LoadClassifierRequest : public ros::Msg
  {
    public:
      typedef const char* _identifier_type;
      _identifier_type identifier;
      typedef const char* _class_type_type;
      _class_type_type class_type;
      typedef const char* _filename_type;
      _filename_type filename;

    LoadClassifierRequest():
      identifier(""),
      class_type(""),
      filename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_identifier = strlen(this->identifier);
      varToArr(outbuffer + offset, length_identifier);
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      uint32_t length_class_type = strlen(this->class_type);
      varToArr(outbuffer + offset, length_class_type);
      offset += 4;
      memcpy(outbuffer + offset, this->class_type, length_class_type);
      offset += length_class_type;
      uint32_t length_filename = strlen(this->filename);
      varToArr(outbuffer + offset, length_filename);
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_identifier;
      arrToVar(length_identifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
      uint32_t length_class_type;
      arrToVar(length_class_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_class_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_class_type-1]=0;
      this->class_type = (char *)(inbuffer + offset-1);
      offset += length_class_type;
      uint32_t length_filename;
      arrToVar(length_filename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
     return offset;
    }

    virtual const char * getType() override { return LOADCLASSIFIER; };
    virtual const char * getMD5() override { return "7f9e97a50616de1070817fa85606e7a5"; };

  };

  class LoadClassifierResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    LoadClassifierResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return LOADCLASSIFIER; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class LoadClassifier {
    public:
    typedef LoadClassifierRequest Request;
    typedef LoadClassifierResponse Response;
  };

}
#endif
