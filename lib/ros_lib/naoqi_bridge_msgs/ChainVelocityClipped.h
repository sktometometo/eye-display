#ifndef _ROS_naoqi_bridge_msgs_ChainVelocityClipped_h
#define _ROS_naoqi_bridge_msgs_ChainVelocityClipped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "naoqi_bridge_msgs/Chains.h"
#include "geometry_msgs/Vector3.h"

namespace naoqi_bridge_msgs
{

  class ChainVelocityClipped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef naoqi_bridge_msgs::Chains _chain_type;
      _chain_type chain;
      typedef geometry_msgs::Vector3 _obstacle_position_type;
      _obstacle_position_type obstacle_position;

    ChainVelocityClipped():
      header(),
      chain(),
      obstacle_position()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->chain.serialize(outbuffer + offset);
      offset += this->obstacle_position.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->chain.deserialize(inbuffer + offset);
      offset += this->obstacle_position.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/ChainVelocityClipped"; };
    virtual const char * getMD5() override { return "185d198d6ab705533bcb1652ddcba65f"; };

  };

}
#endif
