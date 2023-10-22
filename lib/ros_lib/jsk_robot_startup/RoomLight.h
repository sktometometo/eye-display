#ifndef _ROS_jsk_robot_startup_RoomLight_h
#define _ROS_jsk_robot_startup_RoomLight_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_robot_startup
{

  class RoomLight : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _light_on_type;
      _light_on_type light_on;
      typedef float _relative_luminance_type;
      _relative_luminance_type relative_luminance;

    RoomLight():
      header(),
      light_on(0),
      relative_luminance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_light_on;
      u_light_on.real = this->light_on;
      *(outbuffer + offset + 0) = (u_light_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->light_on);
      union {
        float real;
        uint32_t base;
      } u_relative_luminance;
      u_relative_luminance.real = this->relative_luminance;
      *(outbuffer + offset + 0) = (u_relative_luminance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_relative_luminance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_relative_luminance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_relative_luminance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->relative_luminance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_light_on;
      u_light_on.base = 0;
      u_light_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->light_on = u_light_on.real;
      offset += sizeof(this->light_on);
      union {
        float real;
        uint32_t base;
      } u_relative_luminance;
      u_relative_luminance.base = 0;
      u_relative_luminance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_relative_luminance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_relative_luminance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_relative_luminance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->relative_luminance = u_relative_luminance.real;
      offset += sizeof(this->relative_luminance);
     return offset;
    }

    virtual const char * getType() override { return "jsk_robot_startup/RoomLight"; };
    virtual const char * getMD5() override { return "5a00c244217f94055d8fe707c167381d"; };

  };

}
#endif
