#ifndef _ROS_naoqi_bridge_msgs_Frames_h
#define _ROS_naoqi_bridge_msgs_Frames_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class Frames : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;
      enum { FRAME_TORSO = 0 };
      enum { FRAME_WORLD = 1 };
      enum { FRAME_ROBOT = 2 };

    Frames():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/Frames"; };
    virtual const char * getMD5() override { return "65bdd9c9e9a67c39a2a8d90ca52bb8e7"; };

  };

}
#endif
