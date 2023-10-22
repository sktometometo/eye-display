#ifndef _ROS_jsk_recognition_msgs_HandPose_h
#define _ROS_jsk_recognition_msgs_HandPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace jsk_recognition_msgs
{

  class HandPose : public ros::Msg
  {
    public:
      typedef float _hand_score_type;
      _hand_score_type hand_score;
      uint32_t finger_names_length;
      typedef char* _finger_names_type;
      _finger_names_type st_finger_names;
      _finger_names_type * finger_names;
      uint32_t poses_length;
      typedef geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t point_scores_length;
      typedef float _point_scores_type;
      _point_scores_type st_point_scores;
      _point_scores_type * point_scores;

    HandPose():
      hand_score(0),
      finger_names_length(0), st_finger_names(), finger_names(nullptr),
      poses_length(0), st_poses(), poses(nullptr),
      point_scores_length(0), st_point_scores(), point_scores(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_hand_score;
      u_hand_score.real = this->hand_score;
      *(outbuffer + offset + 0) = (u_hand_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hand_score);
      *(outbuffer + offset + 0) = (this->finger_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->finger_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->finger_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->finger_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finger_names_length);
      for( uint32_t i = 0; i < finger_names_length; i++){
      uint32_t length_finger_namesi = strlen(this->finger_names[i]);
      varToArr(outbuffer + offset, length_finger_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->finger_names[i], length_finger_namesi);
      offset += length_finger_namesi;
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->point_scores_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_scores_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_scores_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_scores_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_scores_length);
      for( uint32_t i = 0; i < point_scores_length; i++){
      union {
        float real;
        uint32_t base;
      } u_point_scoresi;
      u_point_scoresi.real = this->point_scores[i];
      *(outbuffer + offset + 0) = (u_point_scoresi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_point_scoresi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_point_scoresi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_point_scoresi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_scores[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_hand_score;
      u_hand_score.base = 0;
      u_hand_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hand_score = u_hand_score.real;
      offset += sizeof(this->hand_score);
      uint32_t finger_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      finger_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      finger_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      finger_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->finger_names_length);
      if(finger_names_lengthT > finger_names_length)
        this->finger_names = (char**)realloc(this->finger_names, finger_names_lengthT * sizeof(char*));
      finger_names_length = finger_names_lengthT;
      for( uint32_t i = 0; i < finger_names_length; i++){
      uint32_t length_st_finger_names;
      arrToVar(length_st_finger_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_finger_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_finger_names-1]=0;
      this->st_finger_names = (char *)(inbuffer + offset-1);
      offset += length_st_finger_names;
        memcpy( &(this->finger_names[i]), &(this->st_finger_names), sizeof(char*));
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
      uint32_t point_scores_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_scores_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_scores_length);
      if(point_scores_lengthT > point_scores_length)
        this->point_scores = (float*)realloc(this->point_scores, point_scores_lengthT * sizeof(float));
      point_scores_length = point_scores_lengthT;
      for( uint32_t i = 0; i < point_scores_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_point_scores;
      u_st_point_scores.base = 0;
      u_st_point_scores.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_point_scores.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_point_scores.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_point_scores.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_point_scores = u_st_point_scores.real;
      offset += sizeof(this->st_point_scores);
        memcpy( &(this->point_scores[i]), &(this->st_point_scores), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/HandPose"; };
    virtual const char * getMD5() override { return "851f5f45f1726b63464e90b860be75d5"; };

  };

}
#endif
