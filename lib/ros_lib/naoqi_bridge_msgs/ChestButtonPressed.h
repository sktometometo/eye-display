#ifndef _ROS_naoqi_bridge_msgs_ChestButtonPressed_h
#define _ROS_naoqi_bridge_msgs_ChestButtonPressed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class ChestButtonPressed : public ros::Msg
  {
    public:
      typedef uint8_t _state_type;
      _state_type state;
      enum { stateReleased = 0 };
      enum { statePressed = 1 };

    ChestButtonPressed():
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/ChestButtonPressed"; };
    virtual const char * getMD5() override { return "802fb1ffacb333587b171a358e821a47"; };

  };

}
#endif
