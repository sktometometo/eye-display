#ifndef _ROS_ml_classifiers_ClassDataPoint_h
#define _ROS_ml_classifiers_ClassDataPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

  class ClassDataPoint : public ros::Msg
  {
    public:
      typedef const char* _target_class_type;
      _target_class_type target_class;
      uint32_t point_length;
      typedef float _point_type;
      _point_type st_point;
      _point_type * point;

    ClassDataPoint():
      target_class(""),
      point_length(0), st_point(), point(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_target_class = strlen(this->target_class);
      varToArr(outbuffer + offset, length_target_class);
      offset += 4;
      memcpy(outbuffer + offset, this->target_class, length_target_class);
      offset += length_target_class;
      *(outbuffer + offset + 0) = (this->point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_length);
      for( uint32_t i = 0; i < point_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->point[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_target_class;
      arrToVar(length_target_class, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_class-1]=0;
      this->target_class = (char *)(inbuffer + offset-1);
      offset += length_target_class;
      uint32_t point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_length);
      if(point_lengthT > point_length)
        this->point = (float*)realloc(this->point, point_lengthT * sizeof(float));
      point_length = point_lengthT;
      for( uint32_t i = 0; i < point_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_point));
        memcpy( &(this->point[i]), &(this->st_point), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "ml_classifiers/ClassDataPoint"; };
    virtual const char * getMD5() override { return "46bea2d2ef979a71ef0bfa470e5978ff"; };

  };

}
#endif
