#ifndef _ROS_denso_robot_core_MoveStringGoal_h
#define _ROS_denso_robot_core_MoveStringGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class MoveStringGoal : public ros::Msg
  {
    public:
      typedef int32_t _comp_type;
      _comp_type comp;
      typedef const char* _pose_type;
      _pose_type pose;
      typedef const char* _option_type;
      _option_type option;

    MoveStringGoal():
      comp(0),
      pose(""),
      option("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_comp;
      u_comp.real = this->comp;
      *(outbuffer + offset + 0) = (u_comp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_comp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_comp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_comp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->comp);
      uint32_t length_pose = strlen(this->pose);
      varToArr(outbuffer + offset, length_pose);
      offset += 4;
      memcpy(outbuffer + offset, this->pose, length_pose);
      offset += length_pose;
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
      union {
        int32_t real;
        uint32_t base;
      } u_comp;
      u_comp.base = 0;
      u_comp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_comp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_comp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_comp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->comp = u_comp.real;
      offset += sizeof(this->comp);
      uint32_t length_pose;
      arrToVar(length_pose, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pose; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pose-1]=0;
      this->pose = (char *)(inbuffer + offset-1);
      offset += length_pose;
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

    virtual const char * getType() override { return "denso_robot_core/MoveStringGoal"; };
    virtual const char * getMD5() override { return "b7823e2161908d80035b12b37a1e31c2"; };

  };

}
#endif
