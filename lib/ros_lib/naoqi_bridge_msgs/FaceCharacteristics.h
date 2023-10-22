#ifndef _ROS_naoqi_bridge_msgs_FaceCharacteristics_h
#define _ROS_naoqi_bridge_msgs_FaceCharacteristics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "naoqi_bridge_msgs/AgeProperties.h"
#include "naoqi_bridge_msgs/ExpressionProperties.h"
#include "naoqi_bridge_msgs/FacialPartsProperties.h"
#include "naoqi_bridge_msgs/GenderProperties.h"
#include "naoqi_bridge_msgs/SmileProperties.h"

namespace naoqi_bridge_msgs
{

  class FaceCharacteristics : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _people_id_type;
      _people_id_type people_id;
      typedef naoqi_bridge_msgs::AgeProperties _person_age_type;
      _person_age_type person_age;
      typedef naoqi_bridge_msgs::ExpressionProperties _person_expression_type;
      _person_expression_type person_expression;
      typedef naoqi_bridge_msgs::FacialPartsProperties _person_facial_parts_type;
      _person_facial_parts_type person_facial_parts;
      typedef naoqi_bridge_msgs::GenderProperties _person_gender_type;
      _person_gender_type person_gender;
      typedef naoqi_bridge_msgs::SmileProperties _person_smile_type;
      _person_smile_type person_smile;

    FaceCharacteristics():
      header(),
      people_id(0),
      person_age(),
      person_expression(),
      person_facial_parts(),
      person_gender(),
      person_smile()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_people_id;
      u_people_id.real = this->people_id;
      *(outbuffer + offset + 0) = (u_people_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_people_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_people_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_people_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_people_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_people_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_people_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_people_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->people_id);
      offset += this->person_age.serialize(outbuffer + offset);
      offset += this->person_expression.serialize(outbuffer + offset);
      offset += this->person_facial_parts.serialize(outbuffer + offset);
      offset += this->person_gender.serialize(outbuffer + offset);
      offset += this->person_smile.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_people_id;
      u_people_id.base = 0;
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_people_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->people_id = u_people_id.real;
      offset += sizeof(this->people_id);
      offset += this->person_age.deserialize(inbuffer + offset);
      offset += this->person_expression.deserialize(inbuffer + offset);
      offset += this->person_facial_parts.deserialize(inbuffer + offset);
      offset += this->person_gender.deserialize(inbuffer + offset);
      offset += this->person_smile.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FaceCharacteristics"; };
    virtual const char * getMD5() override { return "aee5fcb159493b6470f64f9fae10e8f2"; };

  };

}
#endif
