#include <Arduino.h>
#include <math.h>

#include "eye.hpp"
#include "emotion.hpp"

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
const int image_height = 139;

static EyeManager eye;
static EmotionManager emotion(eye);

float look_x = 0;
float look_y = 0;

void callback_look_at(const geometry_msgs::Point &msg);
void callback_emotion(const std_msgs::UInt16 &msg);

ros::NodeHandle_<ArduinoHardware> nh;
ros::Subscriber<geometry_msgs::Point> sub_point("~look_at", &callback_look_at);
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
  emotion.set_emotion(msg.data);
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
  if (nh.getParam("~mode_right", &mode_right)) {
    nh.loginfo(mode_right ? "mode_right is true" : "mode_right is false");
  } else {
    nh.loginfo("Failed to get mode_right parameter");
  }

  if (mode_right)
  {
    // 右目
    nh.loginfo("get mode_right is true");
    eye.init(image_width, image_height, 1);
  }
  else
  {
    // 左目
    nh.loginfo("get !mode_right is false");
    eye.init(image_width, image_height, 1);
  }
  eye.set_gaze_direction(look_x, look_y);
  emotion.set_emotion(); // emotionの初期化
  emotion.update_emotion();
}

void loop()
{
  delay(100);

  eye.set_gaze_direction(look_x, look_y);
  emotion.update_emotion();
  nh.spinOnce();
  char log_msg[50];
  sprintf(log_msg, "Eye status: %d", emotion.get_emotion());
  nh.loginfo(log_msg);
}
