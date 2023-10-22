#ifndef _ROS_SERVICE_FadeLeds_h
#define _ROS_SERVICE_FadeLeds_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/FadeRGB.h"

namespace naoqi_bridge_msgs
{

static const char FADELEDS[] = "naoqi_bridge_msgs/FadeLeds";

  class FadeLedsRequest : public ros::Msg
  {
    public:
      typedef naoqi_bridge_msgs::FadeRGB _fade_rgb_type;
      _fade_rgb_type fade_rgb;

    FadeLedsRequest():
      fade_rgb()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->fade_rgb.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->fade_rgb.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return FADELEDS; };
    virtual const char * getMD5() override { return "82ca3bfdbee839dccab0c2d9549e858d"; };

  };

  class FadeLedsResponse : public ros::Msg
  {
    public:

    FadeLedsResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return FADELEDS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class FadeLeds {
    public:
    typedef FadeLedsRequest Request;
    typedef FadeLedsResponse Response;
  };

}
#endif
