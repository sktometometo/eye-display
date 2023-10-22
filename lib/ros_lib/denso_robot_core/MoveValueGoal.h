#ifndef _ROS_denso_robot_core_MoveValueGoal_h
#define _ROS_denso_robot_core_MoveValueGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "denso_robot_core/PoseData.h"

namespace denso_robot_core
{

  class MoveValueGoal : public ros::Msg
  {
    public:
      typedef int32_t _comp_type;
      _comp_type comp;
      typedef denso_robot_core::PoseData _pose_type;
      _pose_type pose;
      typedef const char* _option_type;
      _option_type option;

    MoveValueGoal():
      comp(0),
      pose(),
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
      offset += this->pose.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return "denso_robot_core/MoveValueGoal"; };
    virtual const char * getMD5() override { return "4e338683af37ba2d25d0bc83ee3893a2"; };

  };

}
#endif
