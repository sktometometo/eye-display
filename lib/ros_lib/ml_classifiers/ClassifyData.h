#ifndef _ROS_SERVICE_ClassifyData_h
#define _ROS_SERVICE_ClassifyData_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ml_classifiers/ClassDataPoint.h"

namespace ml_classifiers
{

static const char CLASSIFYDATA[] = "ml_classifiers/ClassifyData";

  class ClassifyDataRequest : public ros::Msg
  {
    public:
      typedef const char* _identifier_type;
      _identifier_type identifier;
      uint32_t data_length;
      typedef ml_classifiers::ClassDataPoint _data_type;
      _data_type st_data;
      _data_type * data;

    ClassifyDataRequest():
      identifier(""),
      data_length(0), st_data(), data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_identifier = strlen(this->identifier);
      varToArr(outbuffer + offset, length_identifier);
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_identifier;
      arrToVar(length_identifier, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (ml_classifiers::ClassDataPoint*)realloc(this->data, data_lengthT * sizeof(ml_classifiers::ClassDataPoint));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(ml_classifiers::ClassDataPoint));
      }
     return offset;
    }

    virtual const char * getType() override { return CLASSIFYDATA; };
    virtual const char * getMD5() override { return "572733f6e77cd60bddc5c0b72307999c"; };

  };

  class ClassifyDataResponse : public ros::Msg
  {
    public:
      uint32_t classifications_length;
      typedef char* _classifications_type;
      _classifications_type st_classifications;
      _classifications_type * classifications;

    ClassifyDataResponse():
      classifications_length(0), st_classifications(), classifications(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->classifications_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->classifications_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->classifications_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->classifications_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->classifications_length);
      for( uint32_t i = 0; i < classifications_length; i++){
      uint32_t length_classificationsi = strlen(this->classifications[i]);
      varToArr(outbuffer + offset, length_classificationsi);
      offset += 4;
      memcpy(outbuffer + offset, this->classifications[i], length_classificationsi);
      offset += length_classificationsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t classifications_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      classifications_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      classifications_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      classifications_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->classifications_length);
      if(classifications_lengthT > classifications_length)
        this->classifications = (char**)realloc(this->classifications, classifications_lengthT * sizeof(char*));
      classifications_length = classifications_lengthT;
      for( uint32_t i = 0; i < classifications_length; i++){
      uint32_t length_st_classifications;
      arrToVar(length_st_classifications, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_classifications; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_classifications-1]=0;
      this->st_classifications = (char *)(inbuffer + offset-1);
      offset += length_st_classifications;
        memcpy( &(this->classifications[i]), &(this->st_classifications), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return CLASSIFYDATA; };
    virtual const char * getMD5() override { return "5ce145dc8157b011850524b4b0ffd0b7"; };

  };

  class ClassifyData {
    public:
    typedef ClassifyDataRequest Request;
    typedef ClassifyDataResponse Response;
  };

}
#endif
