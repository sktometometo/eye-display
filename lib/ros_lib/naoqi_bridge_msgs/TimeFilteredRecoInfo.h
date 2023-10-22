#ifndef _ROS_naoqi_bridge_msgs_TimeFilteredRecoInfo_h
#define _ROS_naoqi_bridge_msgs_TimeFilteredRecoInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class TimeFilteredRecoInfo : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      uint32_t face_label_length;
      typedef char* _face_label_type;
      _face_label_type st_face_label;
      _face_label_type * face_label;

    TimeFilteredRecoInfo():
      status(0),
      face_label_length(0), st_face_label(), face_label(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->face_label_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->face_label_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->face_label_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->face_label_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->face_label_length);
      for( uint32_t i = 0; i < face_label_length; i++){
      uint32_t length_face_labeli = strlen(this->face_label[i]);
      varToArr(outbuffer + offset, length_face_labeli);
      offset += 4;
      memcpy(outbuffer + offset, this->face_label[i], length_face_labeli);
      offset += length_face_labeli;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t face_label_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      face_label_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      face_label_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      face_label_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->face_label_length);
      if(face_label_lengthT > face_label_length)
        this->face_label = (char**)realloc(this->face_label, face_label_lengthT * sizeof(char*));
      face_label_length = face_label_lengthT;
      for( uint32_t i = 0; i < face_label_length; i++){
      uint32_t length_st_face_label;
      arrToVar(length_st_face_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_face_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_face_label-1]=0;
      this->st_face_label = (char *)(inbuffer + offset-1);
      offset += length_st_face_label;
        memcpy( &(this->face_label[i]), &(this->st_face_label), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/TimeFilteredRecoInfo"; };
    virtual const char * getMD5() override { return "0f969d2b10591613be6d45fe99f7a2d8"; };

  };

}
#endif
