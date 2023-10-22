#ifndef _ROS_naoqi_bridge_msgs_MoveConfig_h
#define _ROS_naoqi_bridge_msgs_MoveConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class MoveConfig : public ros::Msg
  {
    public:
      typedef float _max_vel_xy_type;
      _max_vel_xy_type max_vel_xy;
      typedef float _max_vel_theta_type;
      _max_vel_theta_type max_vel_theta;
      typedef float _max_acc_xy_type;
      _max_acc_xy_type max_acc_xy;
      typedef float _max_acc_theta_type;
      _max_acc_theta_type max_acc_theta;
      typedef float _max_jerk_xy_type;
      _max_jerk_xy_type max_jerk_xy;
      typedef float _max_jerk_theta_type;
      _max_jerk_theta_type max_jerk_theta;
      typedef float _torso_wy_type;
      _torso_wy_type torso_wy;

    MoveConfig():
      max_vel_xy(0),
      max_vel_theta(0),
      max_acc_xy(0),
      max_acc_theta(0),
      max_jerk_xy(0),
      max_jerk_theta(0),
      torso_wy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_max_vel_xy;
      u_max_vel_xy.real = this->max_vel_xy;
      *(outbuffer + offset + 0) = (u_max_vel_xy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_vel_xy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_vel_xy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_vel_xy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_vel_xy);
      union {
        float real;
        uint32_t base;
      } u_max_vel_theta;
      u_max_vel_theta.real = this->max_vel_theta;
      *(outbuffer + offset + 0) = (u_max_vel_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_vel_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_vel_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_vel_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_vel_theta);
      union {
        float real;
        uint32_t base;
      } u_max_acc_xy;
      u_max_acc_xy.real = this->max_acc_xy;
      *(outbuffer + offset + 0) = (u_max_acc_xy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_acc_xy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_acc_xy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_acc_xy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_acc_xy);
      union {
        float real;
        uint32_t base;
      } u_max_acc_theta;
      u_max_acc_theta.real = this->max_acc_theta;
      *(outbuffer + offset + 0) = (u_max_acc_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_acc_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_acc_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_acc_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_acc_theta);
      union {
        float real;
        uint32_t base;
      } u_max_jerk_xy;
      u_max_jerk_xy.real = this->max_jerk_xy;
      *(outbuffer + offset + 0) = (u_max_jerk_xy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_jerk_xy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_jerk_xy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_jerk_xy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_jerk_xy);
      union {
        float real;
        uint32_t base;
      } u_max_jerk_theta;
      u_max_jerk_theta.real = this->max_jerk_theta;
      *(outbuffer + offset + 0) = (u_max_jerk_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_jerk_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_jerk_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_jerk_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_jerk_theta);
      union {
        float real;
        uint32_t base;
      } u_torso_wy;
      u_torso_wy.real = this->torso_wy;
      *(outbuffer + offset + 0) = (u_torso_wy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torso_wy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torso_wy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torso_wy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->torso_wy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_max_vel_xy;
      u_max_vel_xy.base = 0;
      u_max_vel_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_vel_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_vel_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_vel_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_vel_xy = u_max_vel_xy.real;
      offset += sizeof(this->max_vel_xy);
      union {
        float real;
        uint32_t base;
      } u_max_vel_theta;
      u_max_vel_theta.base = 0;
      u_max_vel_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_vel_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_vel_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_vel_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_vel_theta = u_max_vel_theta.real;
      offset += sizeof(this->max_vel_theta);
      union {
        float real;
        uint32_t base;
      } u_max_acc_xy;
      u_max_acc_xy.base = 0;
      u_max_acc_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_acc_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_acc_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_acc_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_acc_xy = u_max_acc_xy.real;
      offset += sizeof(this->max_acc_xy);
      union {
        float real;
        uint32_t base;
      } u_max_acc_theta;
      u_max_acc_theta.base = 0;
      u_max_acc_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_acc_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_acc_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_acc_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_acc_theta = u_max_acc_theta.real;
      offset += sizeof(this->max_acc_theta);
      union {
        float real;
        uint32_t base;
      } u_max_jerk_xy;
      u_max_jerk_xy.base = 0;
      u_max_jerk_xy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_jerk_xy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_jerk_xy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_jerk_xy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_jerk_xy = u_max_jerk_xy.real;
      offset += sizeof(this->max_jerk_xy);
      union {
        float real;
        uint32_t base;
      } u_max_jerk_theta;
      u_max_jerk_theta.base = 0;
      u_max_jerk_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_jerk_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_jerk_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_jerk_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_jerk_theta = u_max_jerk_theta.real;
      offset += sizeof(this->max_jerk_theta);
      union {
        float real;
        uint32_t base;
      } u_torso_wy;
      u_torso_wy.base = 0;
      u_torso_wy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_torso_wy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_torso_wy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_torso_wy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->torso_wy = u_torso_wy.real;
      offset += sizeof(this->torso_wy);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/MoveConfig"; };
    virtual const char * getMD5() override { return "80fa5284e305acbf7ba449759530376d"; };

  };

}
#endif
