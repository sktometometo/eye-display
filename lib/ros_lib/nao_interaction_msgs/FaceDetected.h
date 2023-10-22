#ifndef _ROS_nao_interaction_msgs_FaceDetected_h
#define _ROS_nao_interaction_msgs_FaceDetected_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Pose.h"

namespace nao_interaction_msgs
{

  class FaceDetected : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Int32 _face_id_type;
      _face_id_type face_id;
      typedef std_msgs::Float32 _score_reco_type;
      _score_reco_type score_reco;
      typedef std_msgs::String _face_label_type;
      _face_label_type face_label;
      typedef std_msgs::Float32 _shape_alpha_type;
      _shape_alpha_type shape_alpha;
      typedef std_msgs::Float32 _shape_beta_type;
      _shape_beta_type shape_beta;
      typedef std_msgs::Float32 _shape_sizeX_type;
      _shape_sizeX_type shape_sizeX;
      typedef std_msgs::Float32 _shape_sizeY_type;
      _shape_sizeY_type shape_sizeY;
      typedef std_msgs::Float32 _right_eye_eyeCenter_x_type;
      _right_eye_eyeCenter_x_type right_eye_eyeCenter_x;
      typedef std_msgs::Float32 _right_eye_eyeCenter_y_type;
      _right_eye_eyeCenter_y_type right_eye_eyeCenter_y;
      typedef std_msgs::Float32 _right_eye_noseSideLimit_x_type;
      _right_eye_noseSideLimit_x_type right_eye_noseSideLimit_x;
      typedef std_msgs::Float32 _right_eye_noseSideLimit_y_type;
      _right_eye_noseSideLimit_y_type right_eye_noseSideLimit_y;
      typedef std_msgs::Float32 _right_eye_earSideLimit_x_type;
      _right_eye_earSideLimit_x_type right_eye_earSideLimit_x;
      typedef std_msgs::Float32 _right_eye_earSideLimit_y_type;
      _right_eye_earSideLimit_y_type right_eye_earSideLimit_y;
      typedef std_msgs::Float32 _right_eye_topLimit_x_type;
      _right_eye_topLimit_x_type right_eye_topLimit_x;
      typedef std_msgs::Float32 _right_eye_topLimit_y_type;
      _right_eye_topLimit_y_type right_eye_topLimit_y;
      typedef std_msgs::Float32 _right_eye_bottomLimit_x_type;
      _right_eye_bottomLimit_x_type right_eye_bottomLimit_x;
      typedef std_msgs::Float32 _right_eye_bottomLimit_y_type;
      _right_eye_bottomLimit_y_type right_eye_bottomLimit_y;
      typedef std_msgs::Float32 _right_eye_midTopEarLimit_x_type;
      _right_eye_midTopEarLimit_x_type right_eye_midTopEarLimit_x;
      typedef std_msgs::Float32 _right_eye_midTopEarLimit_y_type;
      _right_eye_midTopEarLimit_y_type right_eye_midTopEarLimit_y;
      typedef std_msgs::Float32 _right_eye_midTopNoseLimit_x_type;
      _right_eye_midTopNoseLimit_x_type right_eye_midTopNoseLimit_x;
      typedef std_msgs::Float32 _right_eye_midTopNoseLimit_y_type;
      _right_eye_midTopNoseLimit_y_type right_eye_midTopNoseLimit_y;
      typedef std_msgs::Float32 _left_eye_eyeCenter_x_type;
      _left_eye_eyeCenter_x_type left_eye_eyeCenter_x;
      typedef std_msgs::Float32 _left_eye_eyeCenter_y_type;
      _left_eye_eyeCenter_y_type left_eye_eyeCenter_y;
      typedef std_msgs::Float32 _left_eye_noseSideLimit_x_type;
      _left_eye_noseSideLimit_x_type left_eye_noseSideLimit_x;
      typedef std_msgs::Float32 _left_eye_noseSideLimit_y_type;
      _left_eye_noseSideLimit_y_type left_eye_noseSideLimit_y;
      typedef std_msgs::Float32 _left_eye_earSideLimit_x_type;
      _left_eye_earSideLimit_x_type left_eye_earSideLimit_x;
      typedef std_msgs::Float32 _left_eye_earSideLimit_y_type;
      _left_eye_earSideLimit_y_type left_eye_earSideLimit_y;
      typedef std_msgs::Float32 _left_eye_topLimit_x_type;
      _left_eye_topLimit_x_type left_eye_topLimit_x;
      typedef std_msgs::Float32 _left_eye_topLimit_y_type;
      _left_eye_topLimit_y_type left_eye_topLimit_y;
      typedef std_msgs::Float32 _left_eye_bottomLimit_x_type;
      _left_eye_bottomLimit_x_type left_eye_bottomLimit_x;
      typedef std_msgs::Float32 _left_eye_bottomLimit_y_type;
      _left_eye_bottomLimit_y_type left_eye_bottomLimit_y;
      typedef std_msgs::Float32 _left_eye_midTopEarLimit_x_type;
      _left_eye_midTopEarLimit_x_type left_eye_midTopEarLimit_x;
      typedef std_msgs::Float32 _left_eye_midTopEarLimit_y_type;
      _left_eye_midTopEarLimit_y_type left_eye_midTopEarLimit_y;
      typedef std_msgs::Float32 _left_eye_midTopNoseLimit_x_type;
      _left_eye_midTopNoseLimit_x_type left_eye_midTopNoseLimit_x;
      typedef std_msgs::Float32 _left_eye_midTopNoseLimit_y_type;
      _left_eye_midTopNoseLimit_y_type left_eye_midTopNoseLimit_y;
      typedef std_msgs::Float32 _right_eyebrow_noseSideLimit_x_type;
      _right_eyebrow_noseSideLimit_x_type right_eyebrow_noseSideLimit_x;
      typedef std_msgs::Float32 _right_eyebrow_noseSideLimit_y_type;
      _right_eyebrow_noseSideLimit_y_type right_eyebrow_noseSideLimit_y;
      typedef std_msgs::Float32 _right_eyebrow_center_x_type;
      _right_eyebrow_center_x_type right_eyebrow_center_x;
      typedef std_msgs::Float32 _right_eyebrow_center_y_type;
      _right_eyebrow_center_y_type right_eyebrow_center_y;
      typedef std_msgs::Float32 _right_eyebrow_earSideLimit_x_type;
      _right_eyebrow_earSideLimit_x_type right_eyebrow_earSideLimit_x;
      typedef std_msgs::Float32 _right_eyebrow_earSideLimit_y_type;
      _right_eyebrow_earSideLimit_y_type right_eyebrow_earSideLimit_y;
      typedef std_msgs::Float32 _left_eyebrow_noseSideLimit_x_type;
      _left_eyebrow_noseSideLimit_x_type left_eyebrow_noseSideLimit_x;
      typedef std_msgs::Float32 _left_eyebrow_noseSideLimit_y_type;
      _left_eyebrow_noseSideLimit_y_type left_eyebrow_noseSideLimit_y;
      typedef std_msgs::Float32 _left_eyebrow_center_x_type;
      _left_eyebrow_center_x_type left_eyebrow_center_x;
      typedef std_msgs::Float32 _left_eyebrow_center_y_type;
      _left_eyebrow_center_y_type left_eyebrow_center_y;
      typedef std_msgs::Float32 _left_eyebrow_earSideLimit_x_type;
      _left_eyebrow_earSideLimit_x_type left_eyebrow_earSideLimit_x;
      typedef std_msgs::Float32 _left_eyebrow_earSideLimit_y_type;
      _left_eyebrow_earSideLimit_y_type left_eyebrow_earSideLimit_y;
      typedef std_msgs::Float32 _nose_bottomCenterLimit_x_type;
      _nose_bottomCenterLimit_x_type nose_bottomCenterLimit_x;
      typedef std_msgs::Float32 _nose_bottomCenterLimit_y_type;
      _nose_bottomCenterLimit_y_type nose_bottomCenterLimit_y;
      typedef std_msgs::Float32 _nose_bottomLeftLimit_x_type;
      _nose_bottomLeftLimit_x_type nose_bottomLeftLimit_x;
      typedef std_msgs::Float32 _nose_bottomLeftLimit_y_type;
      _nose_bottomLeftLimit_y_type nose_bottomLeftLimit_y;
      typedef std_msgs::Float32 _nose_bottomRightLimit_x_type;
      _nose_bottomRightLimit_x_type nose_bottomRightLimit_x;
      typedef std_msgs::Float32 _nose_bottomRightLimit_y_type;
      _nose_bottomRightLimit_y_type nose_bottomRightLimit_y;
      typedef std_msgs::Float32 _mouth_leftLimit_x_type;
      _mouth_leftLimit_x_type mouth_leftLimit_x;
      typedef std_msgs::Float32 _mouth_leftLimit_y_type;
      _mouth_leftLimit_y_type mouth_leftLimit_y;
      typedef std_msgs::Float32 _mouth_rightLimit_x_type;
      _mouth_rightLimit_x_type mouth_rightLimit_x;
      typedef std_msgs::Float32 _mouth_rightLimit_y_type;
      _mouth_rightLimit_y_type mouth_rightLimit_y;
      typedef std_msgs::Float32 _mouth_topLimit_x_type;
      _mouth_topLimit_x_type mouth_topLimit_x;
      typedef std_msgs::Float32 _mouth_topLimit_y_type;
      _mouth_topLimit_y_type mouth_topLimit_y;
      typedef std_msgs::Float32 _mouth_bottomLimit_x_type;
      _mouth_bottomLimit_x_type mouth_bottomLimit_x;
      typedef std_msgs::Float32 _mouth_bottomLimit_y_type;
      _mouth_bottomLimit_y_type mouth_bottomLimit_y;
      typedef std_msgs::Float32 _mouth_midTopLeftLimit_x_type;
      _mouth_midTopLeftLimit_x_type mouth_midTopLeftLimit_x;
      typedef std_msgs::Float32 _mouth_midTopLeftLimit_y_type;
      _mouth_midTopLeftLimit_y_type mouth_midTopLeftLimit_y;
      typedef std_msgs::Float32 _mouth_midTopRightLimit_x_type;
      _mouth_midTopRightLimit_x_type mouth_midTopRightLimit_x;
      typedef std_msgs::Float32 _mouth_midTopRightLimit_y_type;
      _mouth_midTopRightLimit_y_type mouth_midTopRightLimit_y;
      typedef std_msgs::Float32 _mouth_midBottomRightLimit_x_type;
      _mouth_midBottomRightLimit_x_type mouth_midBottomRightLimit_x;
      typedef std_msgs::Float32 _mouth_midBottomRightLimit_y_type;
      _mouth_midBottomRightLimit_y_type mouth_midBottomRightLimit_y;
      typedef std_msgs::Float32 _mouth_midBottomLeftLimit_x_type;
      _mouth_midBottomLeftLimit_x_type mouth_midBottomLeftLimit_x;
      typedef std_msgs::Float32 _mouth_midBottomLeftLimit_y_type;
      _mouth_midBottomLeftLimit_y_type mouth_midBottomLeftLimit_y;
      typedef geometry_msgs::Pose _camera_0_pose_type;
      _camera_0_pose_type camera_0_pose;
      typedef geometry_msgs::Pose _camera_1_pose_type;
      _camera_1_pose_type camera_1_pose;
      typedef std_msgs::Int32 _camera_id_type;
      _camera_id_type camera_id;

    FaceDetected():
      header(),
      face_id(),
      score_reco(),
      face_label(),
      shape_alpha(),
      shape_beta(),
      shape_sizeX(),
      shape_sizeY(),
      right_eye_eyeCenter_x(),
      right_eye_eyeCenter_y(),
      right_eye_noseSideLimit_x(),
      right_eye_noseSideLimit_y(),
      right_eye_earSideLimit_x(),
      right_eye_earSideLimit_y(),
      right_eye_topLimit_x(),
      right_eye_topLimit_y(),
      right_eye_bottomLimit_x(),
      right_eye_bottomLimit_y(),
      right_eye_midTopEarLimit_x(),
      right_eye_midTopEarLimit_y(),
      right_eye_midTopNoseLimit_x(),
      right_eye_midTopNoseLimit_y(),
      left_eye_eyeCenter_x(),
      left_eye_eyeCenter_y(),
      left_eye_noseSideLimit_x(),
      left_eye_noseSideLimit_y(),
      left_eye_earSideLimit_x(),
      left_eye_earSideLimit_y(),
      left_eye_topLimit_x(),
      left_eye_topLimit_y(),
      left_eye_bottomLimit_x(),
      left_eye_bottomLimit_y(),
      left_eye_midTopEarLimit_x(),
      left_eye_midTopEarLimit_y(),
      left_eye_midTopNoseLimit_x(),
      left_eye_midTopNoseLimit_y(),
      right_eyebrow_noseSideLimit_x(),
      right_eyebrow_noseSideLimit_y(),
      right_eyebrow_center_x(),
      right_eyebrow_center_y(),
      right_eyebrow_earSideLimit_x(),
      right_eyebrow_earSideLimit_y(),
      left_eyebrow_noseSideLimit_x(),
      left_eyebrow_noseSideLimit_y(),
      left_eyebrow_center_x(),
      left_eyebrow_center_y(),
      left_eyebrow_earSideLimit_x(),
      left_eyebrow_earSideLimit_y(),
      nose_bottomCenterLimit_x(),
      nose_bottomCenterLimit_y(),
      nose_bottomLeftLimit_x(),
      nose_bottomLeftLimit_y(),
      nose_bottomRightLimit_x(),
      nose_bottomRightLimit_y(),
      mouth_leftLimit_x(),
      mouth_leftLimit_y(),
      mouth_rightLimit_x(),
      mouth_rightLimit_y(),
      mouth_topLimit_x(),
      mouth_topLimit_y(),
      mouth_bottomLimit_x(),
      mouth_bottomLimit_y(),
      mouth_midTopLeftLimit_x(),
      mouth_midTopLeftLimit_y(),
      mouth_midTopRightLimit_x(),
      mouth_midTopRightLimit_y(),
      mouth_midBottomRightLimit_x(),
      mouth_midBottomRightLimit_y(),
      mouth_midBottomLeftLimit_x(),
      mouth_midBottomLeftLimit_y(),
      camera_0_pose(),
      camera_1_pose(),
      camera_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->face_id.serialize(outbuffer + offset);
      offset += this->score_reco.serialize(outbuffer + offset);
      offset += this->face_label.serialize(outbuffer + offset);
      offset += this->shape_alpha.serialize(outbuffer + offset);
      offset += this->shape_beta.serialize(outbuffer + offset);
      offset += this->shape_sizeX.serialize(outbuffer + offset);
      offset += this->shape_sizeY.serialize(outbuffer + offset);
      offset += this->right_eye_eyeCenter_x.serialize(outbuffer + offset);
      offset += this->right_eye_eyeCenter_y.serialize(outbuffer + offset);
      offset += this->right_eye_noseSideLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_noseSideLimit_y.serialize(outbuffer + offset);
      offset += this->right_eye_earSideLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_earSideLimit_y.serialize(outbuffer + offset);
      offset += this->right_eye_topLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_topLimit_y.serialize(outbuffer + offset);
      offset += this->right_eye_bottomLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_bottomLimit_y.serialize(outbuffer + offset);
      offset += this->right_eye_midTopEarLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_midTopEarLimit_y.serialize(outbuffer + offset);
      offset += this->right_eye_midTopNoseLimit_x.serialize(outbuffer + offset);
      offset += this->right_eye_midTopNoseLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_eyeCenter_x.serialize(outbuffer + offset);
      offset += this->left_eye_eyeCenter_y.serialize(outbuffer + offset);
      offset += this->left_eye_noseSideLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_noseSideLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_earSideLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_earSideLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_topLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_topLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_bottomLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_bottomLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_midTopEarLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_midTopEarLimit_y.serialize(outbuffer + offset);
      offset += this->left_eye_midTopNoseLimit_x.serialize(outbuffer + offset);
      offset += this->left_eye_midTopNoseLimit_y.serialize(outbuffer + offset);
      offset += this->right_eyebrow_noseSideLimit_x.serialize(outbuffer + offset);
      offset += this->right_eyebrow_noseSideLimit_y.serialize(outbuffer + offset);
      offset += this->right_eyebrow_center_x.serialize(outbuffer + offset);
      offset += this->right_eyebrow_center_y.serialize(outbuffer + offset);
      offset += this->right_eyebrow_earSideLimit_x.serialize(outbuffer + offset);
      offset += this->right_eyebrow_earSideLimit_y.serialize(outbuffer + offset);
      offset += this->left_eyebrow_noseSideLimit_x.serialize(outbuffer + offset);
      offset += this->left_eyebrow_noseSideLimit_y.serialize(outbuffer + offset);
      offset += this->left_eyebrow_center_x.serialize(outbuffer + offset);
      offset += this->left_eyebrow_center_y.serialize(outbuffer + offset);
      offset += this->left_eyebrow_earSideLimit_x.serialize(outbuffer + offset);
      offset += this->left_eyebrow_earSideLimit_y.serialize(outbuffer + offset);
      offset += this->nose_bottomCenterLimit_x.serialize(outbuffer + offset);
      offset += this->nose_bottomCenterLimit_y.serialize(outbuffer + offset);
      offset += this->nose_bottomLeftLimit_x.serialize(outbuffer + offset);
      offset += this->nose_bottomLeftLimit_y.serialize(outbuffer + offset);
      offset += this->nose_bottomRightLimit_x.serialize(outbuffer + offset);
      offset += this->nose_bottomRightLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_leftLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_leftLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_rightLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_rightLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_topLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_topLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_bottomLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_bottomLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_midTopLeftLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_midTopLeftLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_midTopRightLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_midTopRightLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_midBottomRightLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_midBottomRightLimit_y.serialize(outbuffer + offset);
      offset += this->mouth_midBottomLeftLimit_x.serialize(outbuffer + offset);
      offset += this->mouth_midBottomLeftLimit_y.serialize(outbuffer + offset);
      offset += this->camera_0_pose.serialize(outbuffer + offset);
      offset += this->camera_1_pose.serialize(outbuffer + offset);
      offset += this->camera_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->face_id.deserialize(inbuffer + offset);
      offset += this->score_reco.deserialize(inbuffer + offset);
      offset += this->face_label.deserialize(inbuffer + offset);
      offset += this->shape_alpha.deserialize(inbuffer + offset);
      offset += this->shape_beta.deserialize(inbuffer + offset);
      offset += this->shape_sizeX.deserialize(inbuffer + offset);
      offset += this->shape_sizeY.deserialize(inbuffer + offset);
      offset += this->right_eye_eyeCenter_x.deserialize(inbuffer + offset);
      offset += this->right_eye_eyeCenter_y.deserialize(inbuffer + offset);
      offset += this->right_eye_noseSideLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_noseSideLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eye_earSideLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_earSideLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eye_topLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_topLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eye_bottomLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_bottomLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eye_midTopEarLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_midTopEarLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eye_midTopNoseLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eye_midTopNoseLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_eyeCenter_x.deserialize(inbuffer + offset);
      offset += this->left_eye_eyeCenter_y.deserialize(inbuffer + offset);
      offset += this->left_eye_noseSideLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_noseSideLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_earSideLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_earSideLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_topLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_topLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_bottomLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_bottomLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_midTopEarLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_midTopEarLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eye_midTopNoseLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eye_midTopNoseLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_noseSideLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_noseSideLimit_y.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_center_x.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_center_y.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_earSideLimit_x.deserialize(inbuffer + offset);
      offset += this->right_eyebrow_earSideLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_noseSideLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_noseSideLimit_y.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_center_x.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_center_y.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_earSideLimit_x.deserialize(inbuffer + offset);
      offset += this->left_eyebrow_earSideLimit_y.deserialize(inbuffer + offset);
      offset += this->nose_bottomCenterLimit_x.deserialize(inbuffer + offset);
      offset += this->nose_bottomCenterLimit_y.deserialize(inbuffer + offset);
      offset += this->nose_bottomLeftLimit_x.deserialize(inbuffer + offset);
      offset += this->nose_bottomLeftLimit_y.deserialize(inbuffer + offset);
      offset += this->nose_bottomRightLimit_x.deserialize(inbuffer + offset);
      offset += this->nose_bottomRightLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_leftLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_leftLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_rightLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_rightLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_topLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_topLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_bottomLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_bottomLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_midTopLeftLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_midTopLeftLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_midTopRightLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_midTopRightLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_midBottomRightLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_midBottomRightLimit_y.deserialize(inbuffer + offset);
      offset += this->mouth_midBottomLeftLimit_x.deserialize(inbuffer + offset);
      offset += this->mouth_midBottomLeftLimit_y.deserialize(inbuffer + offset);
      offset += this->camera_0_pose.deserialize(inbuffer + offset);
      offset += this->camera_1_pose.deserialize(inbuffer + offset);
      offset += this->camera_id.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "nao_interaction_msgs/FaceDetected"; };
    virtual const char * getMD5() override { return "3b3868bc92bb74386686642b1cf73f53"; };

  };

}
#endif
