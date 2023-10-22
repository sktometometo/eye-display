#ifndef _ROS_denso_robot_core_Joints_h
#define _ROS_denso_robot_core_Joints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class Joints : public ros::Msg
  {
    public:
      typedef int32_t _joint_type;
      _joint_type joint;
      typedef float _value_type;
      _value_type value;

    Joints():
      joint(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_joint;
      u_joint.real = this->joint;
      *(outbuffer + offset + 0) = (u_joint.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_joint.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_joint.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_joint.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint);
      offset += serializeAvrFloat64(outbuffer + offset, this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_joint;
      u_joint.base = 0;
      u_joint.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_joint.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_joint.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_joint.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->joint = u_joint.real;
      offset += sizeof(this->joint);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->value));
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/Joints"; };
    virtual const char * getMD5() override { return "f3296c44b7dd5760cc0f63c8b23c701f"; };

  };

}
#endif
