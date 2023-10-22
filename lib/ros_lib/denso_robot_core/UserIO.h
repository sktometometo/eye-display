#ifndef _ROS_denso_robot_core_UserIO_h
#define _ROS_denso_robot_core_UserIO_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class UserIO : public ros::Msg
  {
    public:
      typedef int32_t _offset_type;
      _offset_type offset;
      typedef int32_t _size_type;
      _size_type size;
      uint32_t value_length;
      typedef uint8_t _value_type;
      _value_type st_value;
      _value_type * value;
      enum { MIN_USERIO_OFFSET = 128 };
      enum { USERIO_ALIGNMENT = 8 };

    UserIO():
      offset(0),
      size(0),
      value_length(0), st_value(), value(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_offset;
      u_offset.real = this->offset;
      *(outbuffer + offset + 0) = (u_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.real = this->size;
      *(outbuffer + offset + 0) = (u_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      *(outbuffer + offset + 0) = (this->value[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_offset;
      u_offset.base = 0;
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset = u_offset.real;
      offset += sizeof(this->offset);
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.base = 0;
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->size = u_size.real;
      offset += sizeof(this->size);
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (uint8_t*)realloc(this->value, value_lengthT * sizeof(uint8_t));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      this->st_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/UserIO"; };
    virtual const char * getMD5() override { return "eff77a868fe4ad5d8084dd8ba2f71ce3"; };

  };

}
#endif
