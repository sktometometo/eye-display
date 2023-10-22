#ifndef _ROS_naoqi_bridge_msgs_Chains_h
#define _ROS_naoqi_bridge_msgs_Chains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class Chains : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;
      enum { HEAD = 0 };
      enum { LARM = 1 };
      enum { RARM = 2 };
      enum { LLEG = 3 };
      enum { RLEG = 4 };
      enum { LEG = 5 };

    Chains():
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

    virtual const char * getType() override { return "naoqi_bridge_msgs/Chains"; };
    virtual const char * getMD5() override { return "1f38c6fba7ab2ccfbb1b627b17140ea1"; };

  };

}
#endif
