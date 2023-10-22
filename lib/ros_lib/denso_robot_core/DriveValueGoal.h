#ifndef _ROS_denso_robot_core_DriveValueGoal_h
#define _ROS_denso_robot_core_DriveValueGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "denso_robot_core/Joints.h"

namespace denso_robot_core
{

  class DriveValueGoal : public ros::Msg
  {
    public:
      uint32_t pose_length;
      typedef denso_robot_core::Joints _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      typedef int32_t _pass_type;
      _pass_type pass;
      typedef const char* _option_type;
      _option_type option;

    DriveValueGoal():
      pose_length(0), st_pose(), pose(nullptr),
      pass(0),
      option("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->pose[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_option = strlen(this->option);
      varToArr(outbuffer + offset, length_option);
      offset += 4;
      memcpy(outbuffer + offset, this->option, length_option);
      offset += length_option;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (denso_robot_core::Joints*)realloc(this->pose, pose_lengthT * sizeof(denso_robot_core::Joints));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(denso_robot_core::Joints));
      }
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
      uint32_t length_option;
      arrToVar(length_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_option-1]=0;
      this->option = (char *)(inbuffer + offset-1);
      offset += length_option;
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/DriveValueGoal"; };
    virtual const char * getMD5() override { return "52550839b00a7359fb2ca9004e5bc7c2"; };

  };

}
#endif
