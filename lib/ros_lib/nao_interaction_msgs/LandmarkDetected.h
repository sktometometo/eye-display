#ifndef _ROS_nao_interaction_msgs_LandmarkDetected_h
#define _ROS_nao_interaction_msgs_LandmarkDetected_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "geometry_msgs/Pose.h"
#include "std_msgs/String.h"

namespace nao_interaction_msgs
{

  class LandmarkDetected : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t mark_ids_length;
      typedef std_msgs::Int32 _mark_ids_type;
      _mark_ids_type st_mark_ids;
      _mark_ids_type * mark_ids;
      uint32_t shape_alpha_length;
      typedef std_msgs::Float32 _shape_alpha_type;
      _shape_alpha_type st_shape_alpha;
      _shape_alpha_type * shape_alpha;
      uint32_t shape_beta_length;
      typedef std_msgs::Float32 _shape_beta_type;
      _shape_beta_type st_shape_beta;
      _shape_beta_type * shape_beta;
      uint32_t shape_sizex_length;
      typedef std_msgs::Float32 _shape_sizex_type;
      _shape_sizex_type st_shape_sizex;
      _shape_sizex_type * shape_sizex;
      uint32_t shape_sizey_length;
      typedef std_msgs::Float32 _shape_sizey_type;
      _shape_sizey_type st_shape_sizey;
      _shape_sizey_type * shape_sizey;
      typedef geometry_msgs::Pose _camera_local_pose_type;
      _camera_local_pose_type camera_local_pose;
      typedef geometry_msgs::Pose _camera_world_pose_type;
      _camera_world_pose_type camera_world_pose;
      typedef std_msgs::String _camera_name_type;
      _camera_name_type camera_name;

    LandmarkDetected():
      header(),
      mark_ids_length(0), st_mark_ids(), mark_ids(nullptr),
      shape_alpha_length(0), st_shape_alpha(), shape_alpha(nullptr),
      shape_beta_length(0), st_shape_beta(), shape_beta(nullptr),
      shape_sizex_length(0), st_shape_sizex(), shape_sizex(nullptr),
      shape_sizey_length(0), st_shape_sizey(), shape_sizey(nullptr),
      camera_local_pose(),
      camera_world_pose(),
      camera_name()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->mark_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mark_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mark_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mark_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mark_ids_length);
      for( uint32_t i = 0; i < mark_ids_length; i++){
      offset += this->mark_ids[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->shape_alpha_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shape_alpha_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shape_alpha_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shape_alpha_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shape_alpha_length);
      for( uint32_t i = 0; i < shape_alpha_length; i++){
      offset += this->shape_alpha[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->shape_beta_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shape_beta_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shape_beta_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shape_beta_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shape_beta_length);
      for( uint32_t i = 0; i < shape_beta_length; i++){
      offset += this->shape_beta[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->shape_sizex_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shape_sizex_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shape_sizex_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shape_sizex_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shape_sizex_length);
      for( uint32_t i = 0; i < shape_sizex_length; i++){
      offset += this->shape_sizex[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->shape_sizey_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shape_sizey_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shape_sizey_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shape_sizey_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shape_sizey_length);
      for( uint32_t i = 0; i < shape_sizey_length; i++){
      offset += this->shape_sizey[i].serialize(outbuffer + offset);
      }
      offset += this->camera_local_pose.serialize(outbuffer + offset);
      offset += this->camera_world_pose.serialize(outbuffer + offset);
      offset += this->camera_name.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t mark_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mark_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mark_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mark_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mark_ids_length);
      if(mark_ids_lengthT > mark_ids_length)
        this->mark_ids = (std_msgs::Int32*)realloc(this->mark_ids, mark_ids_lengthT * sizeof(std_msgs::Int32));
      mark_ids_length = mark_ids_lengthT;
      for( uint32_t i = 0; i < mark_ids_length; i++){
      offset += this->st_mark_ids.deserialize(inbuffer + offset);
        memcpy( &(this->mark_ids[i]), &(this->st_mark_ids), sizeof(std_msgs::Int32));
      }
      uint32_t shape_alpha_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shape_alpha_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shape_alpha_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shape_alpha_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shape_alpha_length);
      if(shape_alpha_lengthT > shape_alpha_length)
        this->shape_alpha = (std_msgs::Float32*)realloc(this->shape_alpha, shape_alpha_lengthT * sizeof(std_msgs::Float32));
      shape_alpha_length = shape_alpha_lengthT;
      for( uint32_t i = 0; i < shape_alpha_length; i++){
      offset += this->st_shape_alpha.deserialize(inbuffer + offset);
        memcpy( &(this->shape_alpha[i]), &(this->st_shape_alpha), sizeof(std_msgs::Float32));
      }
      uint32_t shape_beta_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shape_beta_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shape_beta_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shape_beta_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shape_beta_length);
      if(shape_beta_lengthT > shape_beta_length)
        this->shape_beta = (std_msgs::Float32*)realloc(this->shape_beta, shape_beta_lengthT * sizeof(std_msgs::Float32));
      shape_beta_length = shape_beta_lengthT;
      for( uint32_t i = 0; i < shape_beta_length; i++){
      offset += this->st_shape_beta.deserialize(inbuffer + offset);
        memcpy( &(this->shape_beta[i]), &(this->st_shape_beta), sizeof(std_msgs::Float32));
      }
      uint32_t shape_sizex_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shape_sizex_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shape_sizex_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shape_sizex_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shape_sizex_length);
      if(shape_sizex_lengthT > shape_sizex_length)
        this->shape_sizex = (std_msgs::Float32*)realloc(this->shape_sizex, shape_sizex_lengthT * sizeof(std_msgs::Float32));
      shape_sizex_length = shape_sizex_lengthT;
      for( uint32_t i = 0; i < shape_sizex_length; i++){
      offset += this->st_shape_sizex.deserialize(inbuffer + offset);
        memcpy( &(this->shape_sizex[i]), &(this->st_shape_sizex), sizeof(std_msgs::Float32));
      }
      uint32_t shape_sizey_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shape_sizey_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shape_sizey_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shape_sizey_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shape_sizey_length);
      if(shape_sizey_lengthT > shape_sizey_length)
        this->shape_sizey = (std_msgs::Float32*)realloc(this->shape_sizey, shape_sizey_lengthT * sizeof(std_msgs::Float32));
      shape_sizey_length = shape_sizey_lengthT;
      for( uint32_t i = 0; i < shape_sizey_length; i++){
      offset += this->st_shape_sizey.deserialize(inbuffer + offset);
        memcpy( &(this->shape_sizey[i]), &(this->st_shape_sizey), sizeof(std_msgs::Float32));
      }
      offset += this->camera_local_pose.deserialize(inbuffer + offset);
      offset += this->camera_world_pose.deserialize(inbuffer + offset);
      offset += this->camera_name.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "nao_interaction_msgs/LandmarkDetected"; };
    virtual const char * getMD5() override { return "4d97e85c0a306501da5d22b795cdac76"; };

  };

}
#endif
