#ifndef _ROS_denso_robot_core_PoseData_h
#define _ROS_denso_robot_core_PoseData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "denso_robot_core/ExJoints.h"

namespace denso_robot_core
{

  class PoseData : public ros::Msg
  {
    public:
      uint32_t value_length;
      typedef float _value_type;
      _value_type st_value;
      _value_type * value;
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _pass_type;
      _pass_type pass;
      typedef denso_robot_core::ExJoints _exjoints_type;
      _exjoints_type exjoints;

    PoseData():
      value_length(0), st_value(), value(nullptr),
      type(0),
      pass(0),
      exjoints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_valuei;
      u_valuei.real = this->value[i];
      *(outbuffer + offset + 0) = (u_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_valuei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_valuei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_pass;
      u_pass.real = this->pass;
      *(outbuffer + offset + 0) = (u_pass.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pass.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pass.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pass.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pass);
      offset += this->exjoints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (float*)realloc(this->value, value_lengthT * sizeof(float));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_value;
      u_st_value.base = 0;
      u_st_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_value = u_st_value.real;
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_pass;
      u_pass.base = 0;
      u_pass.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pass.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pass.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pass.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pass = u_pass.real;
      offset += sizeof(this->pass);
      offset += this->exjoints.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/PoseData"; };
    virtual const char * getMD5() override { return "9b62dc5261dfb262aa32713ca52458d1"; };

  };

}
#endif
