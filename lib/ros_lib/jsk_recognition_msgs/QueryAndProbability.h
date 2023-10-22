#ifndef _ROS_jsk_recognition_msgs_QueryAndProbability_h
#define _ROS_jsk_recognition_msgs_QueryAndProbability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class QueryAndProbability : public ros::Msg
  {
    public:
      typedef const char* _query_type;
      _query_type query;
      typedef float _probability_type;
      _probability_type probability;

    QueryAndProbability():
      query(""),
      probability(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_query = strlen(this->query);
      varToArr(outbuffer + offset, length_query);
      offset += 4;
      memcpy(outbuffer + offset, this->query, length_query);
      offset += length_query;
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.real = this->probability;
      *(outbuffer + offset + 0) = (u_probability.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probability.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_probability.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_probability.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probability);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_query;
      arrToVar(length_query, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_query-1]=0;
      this->query = (char *)(inbuffer + offset-1);
      offset += length_query;
      union {
        float real;
        uint32_t base;
      } u_probability;
      u_probability.base = 0;
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_probability.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->probability = u_probability.real;
      offset += sizeof(this->probability);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/QueryAndProbability"; };
    virtual const char * getMD5() override { return "32c813a28098765a725fe0e559bc6983"; };

  };

}
#endif
