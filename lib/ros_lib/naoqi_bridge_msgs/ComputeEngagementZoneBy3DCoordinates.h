#ifndef _ROS_SERVICE_ComputeEngagementZoneBy3DCoordinates_h
#define _ROS_SERVICE_ComputeEngagementZoneBy3DCoordinates_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace naoqi_bridge_msgs
{

static const char COMPUTEENGAGEMENTZONEBY3DCOORDINATES[] = "naoqi_bridge_msgs/ComputeEngagementZoneBy3DCoordinates";

  class ComputeEngagementZoneBy3DCoordinatesRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point _coordinate_type;
      _coordinate_type coordinate;

    ComputeEngagementZoneBy3DCoordinatesRequest():
      coordinate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->coordinate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->coordinate.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return COMPUTEENGAGEMENTZONEBY3DCOORDINATES; };
    virtual const char * getMD5() override { return "c5f0f40e1d62e657514bb1433636e966"; };

  };

  class ComputeEngagementZoneBy3DCoordinatesResponse : public ros::Msg
  {
    public:
      typedef uint8_t _engagement_zone_type;
      _engagement_zone_type engagement_zone;

    ComputeEngagementZoneBy3DCoordinatesResponse():
      engagement_zone(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->engagement_zone >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engagement_zone);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->engagement_zone =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->engagement_zone);
     return offset;
    }

    virtual const char * getType() override { return COMPUTEENGAGEMENTZONEBY3DCOORDINATES; };
    virtual const char * getMD5() override { return "f85d2654d987882aa68000a5217f772b"; };

  };

  class ComputeEngagementZoneBy3DCoordinates {
    public:
    typedef ComputeEngagementZoneBy3DCoordinatesRequest Request;
    typedef ComputeEngagementZoneBy3DCoordinatesResponse Response;
  };

}
#endif
