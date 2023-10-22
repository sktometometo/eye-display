#ifndef _ROS_denso_robot_core_MoveStringFeedback_h
#define _ROS_denso_robot_core_MoveStringFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace denso_robot_core
{

  class MoveStringFeedback : public ros::Msg
  {
    public:
      uint32_t pose_length;
      typedef float _pose_type;
      _pose_type st_pose;
      _pose_type * pose;

    MoveStringFeedback():
      pose_length(0), st_pose(), pose(nullptr)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->pose[i]);
      }
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
        this->pose = (float*)realloc(this->pose, pose_lengthT * sizeof(float));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_pose));
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "denso_robot_core/MoveStringFeedback"; };
    virtual const char * getMD5() override { return "76249fb45cba333e6a82c7f91cfe1879"; };

  };

}
#endif
