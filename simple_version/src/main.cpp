#include <Arduino.h>
#include <math.h>

#include "eye.hpp"

#define TFT_BL 10

const int image_width = 139;
const int image_height = 139;

const char path_image_eyeball[] = "/eyeball.jpg";
const char path_image_iris_right[] = "/iris_right.jpg";
const char path_image_surprised_iris_right[] = "/iris_surprised_right.jpg";
const char path_image_upperlid_right[] = "/upperlid.jpg";
const char path_image_angry_upperlid_right[] = "/upperlid_leftside_down.jpg";
const char path_image_sad_upperlid_right[] = "/upperlid_rightside_down.jpg";
const char path_image_happy_upperlid_right[] = "/upperlid_happy_right.jpg";

static Eye eye;

void setup()
{
  Serial.begin(115200);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  SPIFFS.begin();
  Serial.println("Initialized.");

  delay(5000);

  eye.init(path_image_eyeball, path_image_iris_right,  path_image_upperlid_right, image_width, image_height, 1);
  eye.update_look();

  Serial.println("Start.");
}

void loop()
{
  // 通常
  float look_x, look_y;
  eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      look_x = 0.3 * sin(i * 0.1);
      look_y = 0.3 * cos(i * 0.1) ;
      eye.update_look(look_x, look_y);
      eye.draw_updated_image();
  }
  look_x = 0;
  look_y = 0;
  eye.update_look(look_x, look_y);
  delay(1000);

  int blink_level = 0;
  eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      blink_level = i % Eye::max_blink_level;
      eye.blink_eye(look_x, look_y, blink_level);
      eye.draw_updated_image();
  }
  delay(1000);

  int surprised_level = 0;
  eye.ready_for_surprised_eye(path_image_surprised_iris_right);
  for (int i=0; i<50; i++) {
      delay(20);
      surprised_level = i % Eye::max_surprised_level;
      eye.surprised(look_x, look_y, surprised_level);
      eye.draw_updated_image();
  }
  delay(1000);

  int sleepy_level = 0;
  eye.ready_for_normal_eye(path_image_iris_right, path_image_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      sleepy_level = i & Eye::max_sleepy_level;
      eye.sleepy(look_x, look_y, sleepy_level);
      eye.draw_updated_image();
  }
  delay(1000);

  int angry_level = 0;
  eye.ready_for_angry_eye(path_image_angry_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      angry_level = i % Eye::max_angry_level;
      eye.angry(look_x, look_y, angry_level);
      eye.draw_updated_image();
  }
  delay(1000);

  int sad_level = 0;
  eye.ready_for_sad_eye(path_image_sad_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      sad_level = i % Eye::max_sad_level;
      eye.sad(look_x, look_y, sad_level);
      eye.draw_updated_image();
  }
  delay(1000);

  int happy_level = 0;
  eye.ready_for_happy_eye(path_image_happy_upperlid_right);
  for (int i=0; i<50; i++) {
      delay(20);
      happy_level = i % Eye::max_happy_level;
      eye.happy(look_x, look_y, happy_level);
      eye.draw_updated_image();
  }
}
