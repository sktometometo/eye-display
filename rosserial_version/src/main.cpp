#include <Arduino.h>
#include <math.h>

#if defined(USE_I2C)
#include <Wire.h>
#include <WireSlave.h>
#endif

#include "eye.hpp"

#if defined(STAMPS3)
#include "ArduinoHWCDCHardware.h"
#elif defined(STAMPC3)
#include "ArduinoHardware.h"
#endif

#include "ros/node_handle.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/UInt16.h"
#include "eye_display/EyeStatus.h"

#define TFT_BL 10

constexpr int SDA_PIN = 8;
constexpr int SCL_PIN = 9;
constexpr int I2C_SLAVE_ADDR = 0x42;

const int image_width = 139;
const int image_height = 139;

const char path_image_outline[] = "/outline.jpg";
const char path_image_iris[] = "/iris.jpg";
const char path_image_pupil[] = "/pupil.jpg";
const char path_image_reflex[] = "/reflex.jpg";
const char path_image_upperlid[] = "/upperlid.jpg";

const char path_image_iris_surprised[] = "/iris_surprised.jpg";
const char path_image_pupil_surprised[] = "/pupil_surprised.jpg";
const char path_image_reflex_surprised[] = "/reflex_surprised.jpg";

const char path_image_reflex_happy[] = "/reflex_happy.jpg";

// eye_status ... 0: 通常, 1: 瞬き, 2: 驚き, 3: 眠い, 4: 怒る, 5: 悲しむ・困る, 6: 嬉しい...
int eye_status = 0;
int pre_eye_status = 0;
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

void receiveEvent(int howMany);

ros::NodeHandle_<ArduinoHardware> nh;
ros::Subscriber<geometry_msgs::Point> sub_point("~look_at", &callback_look_at);
ros::Subscriber<std_msgs::UInt16> sub_eye_status("eye_status", &callback_emotion);


#if defined(USE_I2C)
void I2CTask(void *parameter) {
  bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);

  Serial.println("I2C slave start");
  if (!success) {
    Serial.println("I2C slave init failed");
    while (1) delay(100);
  }
  WireSlave.onReceive(receiveEvent);
  while (true) {
    WireSlave.update();
    delay(1);  // let I2C and other ESP32 peripherals interrupts work
  }
}
#endif

void callback_look_at(const geometry_msgs::Point &msg)
{
  look_x = (float)msg.x;
  look_y = (float)msg.y;
  char buf[128];
  snprintf(buf, sizeof(buf), "Look at (%f, %f)", look_x, look_y);
  nh.loginfo(buf);
}

void callback_emotion(const std_msgs::UInt16 &msg)
{
  eye_status = msg.data;
  char buf[128];
  snprintf(buf, sizeof(buf), "Status updated: %d", eye_status);
  nh.loginfo(buf);
}

void setup()
{
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  SPIFFS.begin();
  Serial.begin(115200);

#if defined(USE_I2C)
#if defined(EYE_RIGHT)
  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, 1, true);
#else
  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, 1, false);
#endif
  eye.update_look();
  xTaskCreatePinnedToCore(I2CTask, "I2C Task", 1024, NULL, 24, NULL, 0);
#else
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
  int direction = 1;
  nh.getParam("~mode_right", &mode_right);
  nh.getParam("~direction", &direction);
  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, direction, not mode_right);
  eye.update_look();
#endif
}

void loop()
{
  delay(20);

  char buf[128];
  snprintf(buf, sizeof(buf), "eye_status: %d, pre_eye_status :%d", eye_status, pre_eye_status);
  nh.loginfo(buf);

  if (eye_status == eye_display::EyeStatus::EYE_STATUS_NORMAL) { // 0
    // 通常
    if (pre_eye_status != eye_status) eye.ready_for_normal_eye();
    eye.update_look(look_x, look_y);
  } 

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_BLINK) { // 1
    // 瞬き
    if (pre_eye_status != eye_status) eye.ready_for_blink_eye();
    eye.blink_eye(look_x, look_y, blink_level);
    blink_level += 1;
    if (blink_level == max_blink_level){
      blink_level = 0;
    }
  }

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_SURPRISED) { // 2
    // 驚き
    if (pre_eye_status != eye_status) eye.ready_for_surprised_eye();
    eye.surprised(look_x, look_y, surprised_level);
    surprised_level += 1;
    if (surprised_level == max_surprised_level){
      surprised_level = 0;
    }
  }

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_SLEEPY) { // 3
    // 眠い
    if (pre_eye_status != eye_status) eye.ready_for_sleepy_eye();
    eye.sleepy(look_x, look_y, sleepy_level);
    sleepy_level += 1;
    if (sleepy_level == max_sleepy_level){
      sleepy_level = 0;
    }
  }

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_ANGRY){ // 4
    // 怒り
    if (pre_eye_status != eye_status) eye.ready_for_angry_eye();
    eye.angry(look_x, look_y, angry_level);
    angry_level += 1;
    if (angry_level == max_angry_level){
      angry_level = 0;
    }
  }

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_SAD) { // 5
    // 悲しむ・困る
    if (pre_eye_status != eye_status) eye.ready_for_sad_eye();
    eye.sad(look_x, look_y, sad_level);
    sad_level += 1;
    if (sad_level == max_sad_level){
      sad_level = 0;
    }
  }

  else if (eye_status == eye_display::EyeStatus::EYE_STATUS_HAPPY) { // 6
    // 喜ぶ
    if (pre_eye_status != eye_status) eye.ready_for_happy_eye();
    eye.happy(look_x, look_y, happy_level);
    happy_level += 1;
    if (happy_level == max_happy_level){
      happy_level = 0;
    }
  }

  pre_eye_status = eye_status;

  nh.spinOnce();
}

#if defined(USE_I2C)
void receiveEvent(int howMany) {
  // lastReceiveTime = millis();  // Update the last received time
  String str;
  while (0 < WireSlave.available()) {
    char c = WireSlave.read();  // receive byte as a character
    str += c;
  }
  if (str == "0") {eye_status = 0;}
  if (str == "1") {eye_status = 1;}
  if (str == "2") {eye_status = 2;}
  if (str == "3") {eye_status = 3;}
  if (str == "4") {eye_status = 4;}
  if (str == "5") {eye_status = 5;}
  if (str == "6") {eye_status = 6;}
}
#endif
