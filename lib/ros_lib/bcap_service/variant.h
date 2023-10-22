#ifndef _ROS_bcap_service_variant_h
#define _ROS_bcap_service_variant_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace bcap_service
{

  class variant : public ros::Msg
  {
    public:
      typedef int16_t _vt_type;
      _vt_type vt;
      typedef const char* _value_type;
      _value_type value;

    variant():
      vt(0),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_vt;
      u_vt.real = this->vt;
      *(outbuffer + offset + 0) = (u_vt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vt.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->vt);
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_vt;
      u_vt.base = 0;
      u_vt.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vt.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vt = u_vt.real;
      offset += sizeof(this->vt);
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    virtual const char * getType() override { return "bcap_service/variant"; };
    virtual const char * getMD5() override { return "0ff385ab5cb58d55d6c7b0d33e88693e"; };

  };

}
#endif
