#ifndef _ROS_jsk_recognition_msgs_PanoramaInfo_h
#define _ROS_jsk_recognition_msgs_PanoramaInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class PanoramaInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _projection_model_type;
      _projection_model_type projection_model;
      typedef uint32_t _image_height_type;
      _image_height_type image_height;
      typedef uint32_t _image_width_type;
      _image_width_type image_width;
      typedef float _theta_min_type;
      _theta_min_type theta_min;
      typedef float _theta_max_type;
      _theta_max_type theta_max;
      typedef float _phi_min_type;
      _phi_min_type phi_min;
      typedef float _phi_max_type;
      _phi_max_type phi_max;

    PanoramaInfo():
      header(),
      projection_model(""),
      image_height(0),
      image_width(0),
      theta_min(0),
      theta_max(0),
      phi_min(0),
      phi_max(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_projection_model = strlen(this->projection_model);
      varToArr(outbuffer + offset, length_projection_model);
      offset += 4;
      memcpy(outbuffer + offset, this->projection_model, length_projection_model);
      offset += length_projection_model;
      *(outbuffer + offset + 0) = (this->image_height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_height);
      *(outbuffer + offset + 0) = (this->image_width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_width);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta_min);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta_max);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi_min);
      offset += serializeAvrFloat64(outbuffer + offset, this->phi_max);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_projection_model;
      arrToVar(length_projection_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_projection_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_projection_model-1]=0;
      this->projection_model = (char *)(inbuffer + offset-1);
      offset += length_projection_model;
      this->image_height =  ((uint32_t) (*(inbuffer + offset)));
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_height);
      this->image_width =  ((uint32_t) (*(inbuffer + offset)));
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_width);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta_min));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta_max));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi_min));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->phi_max));
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/PanoramaInfo"; };
    virtual const char * getMD5() override { return "340435d77351bcae6fd5d846323c4a05"; };

  };

}
#endif
