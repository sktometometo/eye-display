#ifndef _ROS_SERVICE_ControlBilateral_h
#define _ROS_SERVICE_ControlBilateral_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_panda_teleop
{

static const char CONTROLBILATERAL[] = "jsk_panda_teleop/ControlBilateral";

  class ControlBilateralRequest : public ros::Msg
  {
    public:
      typedef bool _pose_connecting_type;
      _pose_connecting_type pose_connecting;
      typedef bool _force_connecting_type;
      _force_connecting_type force_connecting;
      typedef bool _reset_phantom_type;
      _reset_phantom_type reset_phantom;
      typedef float _wait_type;
      _wait_type wait;

    ControlBilateralRequest():
      pose_connecting(0),
      force_connecting(0),
      reset_phantom(0),
      wait(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pose_connecting;
      u_pose_connecting.real = this->pose_connecting;
      *(outbuffer + offset + 0) = (u_pose_connecting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pose_connecting);
      union {
        bool real;
        uint8_t base;
      } u_force_connecting;
      u_force_connecting.real = this->force_connecting;
      *(outbuffer + offset + 0) = (u_force_connecting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->force_connecting);
      union {
        bool real;
        uint8_t base;
      } u_reset_phantom;
      u_reset_phantom.real = this->reset_phantom;
      *(outbuffer + offset + 0) = (u_reset_phantom.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reset_phantom);
      union {
        float real;
        uint32_t base;
      } u_wait;
      u_wait.real = this->wait;
      *(outbuffer + offset + 0) = (u_wait.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wait.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wait.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wait.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wait);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_pose_connecting;
      u_pose_connecting.base = 0;
      u_pose_connecting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pose_connecting = u_pose_connecting.real;
      offset += sizeof(this->pose_connecting);
      union {
        bool real;
        uint8_t base;
      } u_force_connecting;
      u_force_connecting.base = 0;
      u_force_connecting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force_connecting = u_force_connecting.real;
      offset += sizeof(this->force_connecting);
      union {
        bool real;
        uint8_t base;
      } u_reset_phantom;
      u_reset_phantom.base = 0;
      u_reset_phantom.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reset_phantom = u_reset_phantom.real;
      offset += sizeof(this->reset_phantom);
      union {
        float real;
        uint32_t base;
      } u_wait;
      u_wait.base = 0;
      u_wait.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wait.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wait.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wait.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wait = u_wait.real;
      offset += sizeof(this->wait);
     return offset;
    }

    virtual const char * getType() override { return CONTROLBILATERAL; };
    virtual const char * getMD5() override { return "b1623864fa9fabf32d9b4c30ec9c0b49"; };

  };

  class ControlBilateralResponse : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    ControlBilateralResponse():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    virtual const char * getType() override { return CONTROLBILATERAL; };
    virtual const char * getMD5() override { return "6f6da3883749771fac40d6deb24a8c02"; };

  };

  class ControlBilateral {
    public:
    typedef ControlBilateralRequest Request;
    typedef ControlBilateralResponse Response;
  };

}
#endif
