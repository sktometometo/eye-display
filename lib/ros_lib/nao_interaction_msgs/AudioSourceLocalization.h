#ifndef _ROS_nao_interaction_msgs_AudioSourceLocalization_h
#define _ROS_nao_interaction_msgs_AudioSourceLocalization_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Pose.h"

namespace nao_interaction_msgs
{

  class AudioSourceLocalization : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Float32 _azimuth_type;
      _azimuth_type azimuth;
      typedef std_msgs::Float32 _elevation_type;
      _elevation_type elevation;
      typedef std_msgs::Float32 _confidence_type;
      _confidence_type confidence;
      typedef std_msgs::Float32 _energy_type;
      _energy_type energy;
      typedef geometry_msgs::Pose _head_pose_type;
      _head_pose_type head_pose;

    AudioSourceLocalization():
      header(),
      azimuth(),
      elevation(),
      confidence(),
      energy(),
      head_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->azimuth.serialize(outbuffer + offset);
      offset += this->elevation.serialize(outbuffer + offset);
      offset += this->confidence.serialize(outbuffer + offset);
      offset += this->energy.serialize(outbuffer + offset);
      offset += this->head_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->azimuth.deserialize(inbuffer + offset);
      offset += this->elevation.deserialize(inbuffer + offset);
      offset += this->confidence.deserialize(inbuffer + offset);
      offset += this->energy.deserialize(inbuffer + offset);
      offset += this->head_pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "nao_interaction_msgs/AudioSourceLocalization"; };
    virtual const char * getMD5() override { return "5c65a283c3f4c0f07561982b3d8c4f13"; };

  };

}
#endif
