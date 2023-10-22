#ifndef _ROS_naoqi_bridge_msgs_GazeAnalysis_h
#define _ROS_naoqi_bridge_msgs_GazeAnalysis_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace naoqi_bridge_msgs
{

  class GazeAnalysis : public ros::Msg
  {
    public:
      uint32_t eye_opening_degree_length;
      typedef float _eye_opening_degree_type;
      _eye_opening_degree_type st_eye_opening_degree;
      _eye_opening_degree_type * eye_opening_degree;
      uint32_t gaze_direction_length;
      typedef float _gaze_direction_type;
      _gaze_direction_type st_gaze_direction;
      _gaze_direction_type * gaze_direction;
      uint32_t head_angles_length;
      typedef float _head_angles_type;
      _head_angles_type st_head_angles;
      _head_angles_type * head_angles;
      typedef bool _is_looking_at_robot_type;
      _is_looking_at_robot_type is_looking_at_robot;
      typedef float _looking_at_robot_score_type;
      _looking_at_robot_score_type looking_at_robot_score;

    GazeAnalysis():
      eye_opening_degree_length(0), st_eye_opening_degree(), eye_opening_degree(nullptr),
      gaze_direction_length(0), st_gaze_direction(), gaze_direction(nullptr),
      head_angles_length(0), st_head_angles(), head_angles(nullptr),
      is_looking_at_robot(0),
      looking_at_robot_score(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->eye_opening_degree_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->eye_opening_degree_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->eye_opening_degree_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->eye_opening_degree_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->eye_opening_degree_length);
      for( uint32_t i = 0; i < eye_opening_degree_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->eye_opening_degree[i]);
      }
      *(outbuffer + offset + 0) = (this->gaze_direction_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gaze_direction_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gaze_direction_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gaze_direction_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaze_direction_length);
      for( uint32_t i = 0; i < gaze_direction_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->gaze_direction[i]);
      }
      *(outbuffer + offset + 0) = (this->head_angles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->head_angles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->head_angles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->head_angles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->head_angles_length);
      for( uint32_t i = 0; i < head_angles_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->head_angles[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_looking_at_robot;
      u_is_looking_at_robot.real = this->is_looking_at_robot;
      *(outbuffer + offset + 0) = (u_is_looking_at_robot.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_looking_at_robot);
      offset += serializeAvrFloat64(outbuffer + offset, this->looking_at_robot_score);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t eye_opening_degree_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      eye_opening_degree_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      eye_opening_degree_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      eye_opening_degree_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->eye_opening_degree_length);
      if(eye_opening_degree_lengthT > eye_opening_degree_length)
        this->eye_opening_degree = (float*)realloc(this->eye_opening_degree, eye_opening_degree_lengthT * sizeof(float));
      eye_opening_degree_length = eye_opening_degree_lengthT;
      for( uint32_t i = 0; i < eye_opening_degree_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_eye_opening_degree));
        memcpy( &(this->eye_opening_degree[i]), &(this->st_eye_opening_degree), sizeof(float));
      }
      uint32_t gaze_direction_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gaze_direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gaze_direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gaze_direction_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gaze_direction_length);
      if(gaze_direction_lengthT > gaze_direction_length)
        this->gaze_direction = (float*)realloc(this->gaze_direction, gaze_direction_lengthT * sizeof(float));
      gaze_direction_length = gaze_direction_lengthT;
      for( uint32_t i = 0; i < gaze_direction_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_gaze_direction));
        memcpy( &(this->gaze_direction[i]), &(this->st_gaze_direction), sizeof(float));
      }
      uint32_t head_angles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      head_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      head_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      head_angles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->head_angles_length);
      if(head_angles_lengthT > head_angles_length)
        this->head_angles = (float*)realloc(this->head_angles, head_angles_lengthT * sizeof(float));
      head_angles_length = head_angles_lengthT;
      for( uint32_t i = 0; i < head_angles_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_head_angles));
        memcpy( &(this->head_angles[i]), &(this->st_head_angles), sizeof(float));
      }
      union {
        bool real;
        uint8_t base;
      } u_is_looking_at_robot;
      u_is_looking_at_robot.base = 0;
      u_is_looking_at_robot.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_looking_at_robot = u_is_looking_at_robot.real;
      offset += sizeof(this->is_looking_at_robot);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->looking_at_robot_score));
     return offset;
    }

    virtual const char * getType() override { return "naoqi_bridge_msgs/GazeAnalysis"; };
    virtual const char * getMD5() override { return "ed0121d1f72821f93cee086b3399e1b2"; };

  };

}
#endif
