#ifndef _ROS_SERVICE_ComputeEngagementZoneByAngularAndDistance_h
#define _ROS_SERVICE_ComputeEngagementZoneByAngularAndDistance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace naoqi_bridge_msgs
{

static const char COMPUTEENGAGEMENTZONEBYANGULARANDDISTANCE[] = "naoqi_bridge_msgs/ComputeEngagementZoneByAngularAndDistance";

  class ComputeEngagementZoneByAngularAndDistanceRequest : public ros::Msg
  {
    public:
      typedef float _x_angle_type;
      _x_angle_type x_angle;
      typedef float _y_angle_type;
      _y_angle_type y_angle;
      typedef float _distance_type;
      _distance_type distance;
      typedef geometry_msgs::Twist _camera_position_from_robot_frame_type;
      _camera_position_from_robot_frame_type camera_position_from_robot_frame;

    ComputeEngagementZoneByAngularAndDistanceRequest():
      x_angle(0),
      y_angle(0),
      distance(0),
      camera_position_from_robot_frame()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->y_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += this->camera_position_from_robot_frame.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += this->camera_position_from_robot_frame.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return COMPUTEENGAGEMENTZONEBYANGULARANDDISTANCE; };
    virtual const char * getMD5() override { return "adf34d014a4df260afc323fb39418d0d"; };

  };

  class ComputeEngagementZoneByAngularAndDistanceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _engagement_zone_type;
      _engagement_zone_type engagement_zone;

    ComputeEngagementZoneByAngularAndDistanceResponse():
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

    virtual const char * getType() override { return COMPUTEENGAGEMENTZONEBYANGULARANDDISTANCE; };
    virtual const char * getMD5() override { return "f85d2654d987882aa68000a5217f772b"; };

  };

  class ComputeEngagementZoneByAngularAndDistance {
    public:
    typedef ComputeEngagementZoneByAngularAndDistanceRequest Request;
    typedef ComputeEngagementZoneByAngularAndDistanceResponse Response;
  };

}
#endif
