#ifndef _ROS_naoqi_bridge_msgs_FaceDetectionExtraInfo_h
#define _ROS_naoqi_bridge_msgs_FaceDetectionExtraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/EyePoints.h"
#include "naoqi_bridge_msgs/NosePoints.h"
#include "naoqi_bridge_msgs/MouthPoints.h"

namespace naoqi_bridge_msgs
{

  class FaceDetectionExtraInfo : public ros::Msg
  {
    public:
      typedef int64_t _face_id_type;
      _face_id_type face_id;
      typedef float _recognition_score_type;
      _recognition_score_type recognition_score;
      typedef const char* _face_label_type;
      _face_label_type face_label;
      typedef naoqi_bridge_msgs::EyePoints _left_eye_type;
      _left_eye_type left_eye;
      typedef naoqi_bridge_msgs::EyePoints _right_eye_type;
      _right_eye_type right_eye;
      typedef naoqi_bridge_msgs::NosePoints _nose_type;
      _nose_type nose;
      typedef naoqi_bridge_msgs::MouthPoints _mouth_type;
      _mouth_type mouth;

    FaceDetectionExtraInfo():
      face_id(0),
      recognition_score(0),
      face_label(""),
      left_eye(),
      right_eye(),
      nose(),
      mouth()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_face_id;
      u_face_id.real = this->face_id;
      *(outbuffer + offset + 0) = (u_face_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_face_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_face_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_face_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_face_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_face_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_face_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_face_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->face_id);
      offset += serializeAvrFloat64(outbuffer + offset, this->recognition_score);
      uint32_t length_face_label = strlen(this->face_label);
      varToArr(outbuffer + offset, length_face_label);
      offset += 4;
      memcpy(outbuffer + offset, this->face_label, length_face_label);
      offset += length_face_label;
      offset += this->left_eye.serialize(outbuffer + offset);
      offset += this->right_eye.serialize(outbuffer + offset);
      offset += this->nose.serialize(outbuffer + offset);
      offset += this->mouth.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_face_id;
      u_face_id.base = 0;
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_face_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->face_id = u_face_id.real;
      offset += sizeof(this->face_id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->recognition_score));
      uint32_t length_face_label;
      arrToVar(length_face_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_face_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_face_label-1]=0;
      this->face_label = (char *)(inbuffer + offset-1);
      offset += length_face_label;
      offset += this->left_eye.deserialize(inbuffer + offset);
      offset += this->right_eye.deserialize(inbuffer + offset);
      offset += this->nose.deserialize(inbuffer + offset);
      offset += this->mouth.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/FaceDetectionExtraInfo"; };
    virtual const char * getMD5() override { return "577fd9287bc89ab915e6adfd75cc99bd"; };

  };

}
#endif
