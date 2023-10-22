#ifndef _ROS_naoqi_bridge_msgs_Arms_h
#define _ROS_naoqi_bridge_msgs_Arms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class Arms : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;
      enum { LARM = 0 };
      enum { RARM = 1 };
      enum { ARMS = 2 };

    Arms():
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

    virtual const char * getType() override { return "naoqi_bridge_msgs/Arms"; };
    virtual const char * getMD5() override { return "cd0984fe9fdc2e8dcae55a42d48f267d"; };

  };

}
#endif
