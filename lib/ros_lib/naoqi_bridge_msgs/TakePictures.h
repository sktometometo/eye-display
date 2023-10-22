#ifndef _ROS_SERVICE_TakePictures_h
#define _ROS_SERVICE_TakePictures_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

static const char TAKEPICTURES[] = "naoqi_bridge_msgs/TakePictures";

  class TakePicturesRequest : public ros::Msg
  {
    public:
      typedef int16_t _number_type;
      _number_type number;
      typedef const char* _name_type;
      _name_type name;

    TakePicturesRequest():
      number(0),
      name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_number;
      u_number.real = this->number;
      *(outbuffer + offset + 0) = (u_number.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->number);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_number;
      u_number.base = 0;
      u_number.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->number = u_number.real;
      offset += sizeof(this->number);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
     return offset;
    }

    virtual const char * getType() override { return TAKEPICTURES; };
    virtual const char * getMD5() override { return "a46ac31e83050e2a77be40e7146d5094"; };

  };

  class TakePicturesResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TakePicturesResponse():
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

    virtual const char * getType() override { return TAKEPICTURES; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TakePictures {
    public:
    typedef TakePicturesRequest Request;
    typedef TakePicturesResponse Response;
  };

}
#endif
