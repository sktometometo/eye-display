#ifndef _ROS_denso_robot_core_DriveStringGoal_h
#define _ROS_denso_robot_core_DriveStringGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class DriveStringGoal : public ros::Msg
  {
    public:
      typedef const char* _pose_type;
      _pose_type pose;
      typedef const char* _option_type;
      _option_type option;

    DriveStringGoal():
      pose(""),
      option("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return "denso_robot_core/DriveStringGoal"; };
    virtual const char * getMD5() override { return "9de8d255efc68542d1bc35e67afbfca4"; };

  };

}
#endif
