#ifndef _ROS_SERVICE_ClearClassifier_h
#define _ROS_SERVICE_ClearClassifier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

static const char CLEARCLASSIFIER[] = "ml_classifiers/ClearClassifier";

  class ClearClassifierRequest : public ros::Msg
  {
    public:
      typedef const char* _identifier_type;
      _identifier_type identifier;

    ClearClassifierRequest():
      identifier("")
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
     return offset;
    }

    virtual const char * getType() override { return CLEARCLASSIFIER; };
    virtual const char * getMD5() override { return "9c4b0f781baa7fd49cc9e186f2f56898"; };

  };

  class ClearClassifierResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ClearClassifierResponse():
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

    virtual const char * getType() override { return CLEARCLASSIFIER; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ClearClassifier {
    public:
    typedef ClearClassifierRequest Request;
    typedef ClearClassifierResponse Response;
  };

}
#endif
