#ifndef _ROS_naoqi_bridge_msgs_MoveConfigNames_h
#define _ROS_naoqi_bridge_msgs_MoveConfigNames_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class MoveConfigNames : public ros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;
      enum { MAX =  0 };
      enum { MIN =  1 };
      enum { DEFAULT =  2 };

    MoveConfigNames():
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

    virtual const char * getType() override { return "naoqi_bridge_msgs/MoveConfigNames"; };
    virtual const char * getMD5() override { return "3c5bb26b8eb46cdc2b506a386861fe18"; };

  };

}
#endif
