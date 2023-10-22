#ifndef _ROS_naoqi_bridge_msgs_PeoplePerception_h
#define _ROS_naoqi_bridge_msgs_PeoplePerception_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "naoqi_bridge_msgs/PeopleDetected.h"
#include "naoqi_bridge_msgs/FaceCharacteristics.h"
#include "naoqi_bridge_msgs/GazeAnalysis.h"

namespace naoqi_bridge_msgs
{

  class PeoplePerception : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef naoqi_bridge_msgs::PeopleDetected _people_detected_type;
      _people_detected_type people_detected;
      typedef naoqi_bridge_msgs::FaceCharacteristics _face_characteristics_type;
      _face_characteristics_type face_characteristics;
      typedef naoqi_bridge_msgs::GazeAnalysis _gaze_analysis_type;
      _gaze_analysis_type gaze_analysis;
      typedef uint8_t _engagement_zone_of_person_type;
      _engagement_zone_of_person_type engagement_zone_of_person;

    PeoplePerception():
      header(),
      people_detected(),
      face_characteristics(),
      gaze_analysis(),
      engagement_zone_of_person(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->people_detected.serialize(outbuffer + offset);
      offset += this->face_characteristics.serialize(outbuffer + offset);
      offset += this->gaze_analysis.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->engagement_zone_of_person >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engagement_zone_of_person);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->people_detected.deserialize(inbuffer + offset);
      offset += this->face_characteristics.deserialize(inbuffer + offset);
      offset += this->gaze_analysis.deserialize(inbuffer + offset);
      this->engagement_zone_of_person =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->engagement_zone_of_person);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/PeoplePerception"; };
    virtual const char * getMD5() override { return "d68489292b0db6a55ec56f09e49cbf1c"; };

  };

}
#endif
