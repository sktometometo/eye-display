#include <Arduino.h>
#include <math.h>

#include "eye.hpp"

#if defined(STAMPS3)
#include "ArduinoHWCDCHardware.h"
#elif defined(STAMPC3)
#include "ArduinoHardware.h"
#endif

#include "ros/node_handle.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/UInt16.h"

#define TFT_BL 10

const int image_width = 139;
// const int image_height = 120;
const int image_height = 139;

const char path_image_eyeball[] = "/eyeball.jpg";

const char path_image_iris_right[] = "/iris_right.jpg";
const char path_image_surprised_iris_right[] = "/iris_surprised_right.jpg";
const char path_image_upperlid_right[] = "/upperlid.jpg";
const char path_image_angry_upperlid_right[] = "/upperlid_leftside_down.jpg";
const char path_image_sad_upperlid_right[] = "/upperlid_rightside_down.jpg";
const char path_image_happy_upperlid_right[] = "/upperlid_happy_right.jpg";

const char path_image_iris_left[] = "/iris_left.jpg";
const char path_image_surprised_iris_left[] = "/iris_surprised_left.jpg";
const char path_image_upperlid_left[] = "/upperlid.jpg";
const char path_image_angry_upperlid_left[] = "/upperlid_rightside_down.jpg";
const char path_image_sad_upperlid_left[] = "/upperlid_leftside_down.jpg";
const char path_image_happy_upperlid_left[] =  "/upperlid_happy_left.jpg";

// eye_status ... 0: 通常, 1: 瞬き, 2: 驚き, 3: 眠い, 4: 怒る, 5: 悲しむ・困る, 6: 嬉しい...
int eye_status = 0;
int blink_level = 0; int max_blink_level = 6;
int surprised_level = 0; int max_surprised_level = 16;
int sleepy_level = 0; int max_sleepy_level = 10;
int angry_level = 0; int max_angry_level = 20;
int sad_level = 0; int max_sad_level = 20;
int happy_level = 0; int max_happy_level = 20;


static Eye eye;

float look_x = 0;
float look_y = 0;

void callback_look_at(const geometry_msgs::Point &msg);
void callback_emotion(const std_msgs::UInt16 &msg);

ros::NodeHandle_<ArduinoHardware> nh;
ros::Subscriber<geometry_msgs::Point> sub_point("~look_at", &callback_look_at);
// ros::Subscriber<std_msgs::UInt16> sub_eye_status("eye_status", &callback_emotion);
ros::Subscriber<std_msgs::UInt16> sub_eye_status("eye_status", &callback_emotion);


void callback_look_at(const geometry_msgs::Point &msg)
{
  look_x = (float)msg.x;
  look_y = (float)msg.y;
  nh.loginfo("in the callback look_at func");
}

void callback_emotion(const std_msgs::UInt16 &msg)
{
  nh.loginfo("in the callback emotion func");
  eye_status = msg.data;
}

void setup()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  SPIFFS.begin();
  Serial.begin(115200);

  nh.initNode();
  nh.subscribe(sub_point);
  nh.subscribe(sub_eye_status);
  nh.spinOnce();

  while (not nh.connected())
  {
    nh.spinOnce();
    delay(1000);
  }

  bool mode_right;
  nh.getParam("~mode_right", &mode_right);
  // bool mode_right;
  // if (not nh.getParam("~mode_right", &mode_right))
  if (mode_right)
  {
    // 右目
    eye.init(path_image_eyeball, path_image_iris_right,  path_image_upperlid_right, image_width, image_height, 1);
    // nh.loginfo("right eye mode_right: %s", &mode_right);
  }
  else
  {
    // 左目
    eye.init(path_image_eyeball, path_image_iris_right,  path_image_upperlid_right, image_width, image_height, 1);
    // nh.loginfo("left eye mode_right: %s", &mode_right);
  }
  eye.update_look();
}

static int i = 0;

void loop()
{
  delay(100);
  i++;
  
  // float look_x = 0.3 * sin(i * 0.1);
  // float look_y = 0.3 * cos(i * 0.1) ;

  if (eye_status == 0) {
    // 通常
	eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    eye.update_look(look_x, look_y);
  } 

  else if (eye_status == 1){
    // 瞬き
    eye.blink_eye(look_x, look_y, blink_level);
    blink_level += 1;
    if (blink_level == max_blink_level){
      blink_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  else if (eye_status == 2){
    // 驚き
    if (surprised_level == 0){
      eye.ready_for_surprised_eye(path_image_surprised_iris_right);
    }
    eye.surprised(look_x, look_y, surprised_level);
    surprised_level += 1;
    if (surprised_level == max_surprised_level){
      surprised_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  else if (eye_status == 3){
    // 眠い
    eye.sleepy(look_x, look_y, sleepy_level);
    sleepy_level += 1;
    if (sleepy_level == max_sleepy_level){
      sleepy_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  else if (eye_status == 4){
    // 怒り
    if (angry_level == 0){
      eye.ready_for_angry_eye(path_image_angry_upperlid_right);
    }
    eye.angry(look_x, look_y, angry_level);
    angry_level += 1;
    if (angry_level == max_angry_level){
      angry_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  else if (eye_status == 5){
    // 悲しむ・困る
    if (sad_level == 0){
      eye.ready_for_sad_eye(path_image_sad_upperlid_right);
    }
    eye.sad(look_x, look_y, sad_level);
    sad_level += 1;
    if (sad_level == max_sad_level){
      sad_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  else if (eye_status == 6) {
    // 喜ぶ
    if (happy_level == 0){
      eye.ready_for_happy_eye(path_image_happy_upperlid_right);
    }
    eye.happy(look_x, look_y, happy_level);
    happy_level += 1;
    if (happy_level == max_happy_level){
      happy_level = 0;
      eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
    }
  }

  // nh.loginfo("look_x: %f, look_y: %f\n", look_x, look_y);
  // nh.loginfo()

  nh.spinOnce();
}
