#include <Arduino.h>
#include <math.h>

#include "eye.hpp"

#define TFT_BL 10

const int image_width = 139;
const int image_height = 120;
const char path_image_outline_right[] = "/eye_outline_right_resized.jpg";
const char path_image_pupil_right[] = "/eye_pupil_right_resized.jpg";
const char path_image_reflex_right[] = "/eye_reflex_right_resized.jpg";
const char path_image_outline_left[] = "/eye_outline_left_resized.jpg";
const char path_image_pupil_left[] = "/eye_pupil_left_resized.jpg";
const char path_image_reflex_left[] = "/eye_reflex_left_resized.jpg";

static Eye eye;

void setup()
{
  Serial.begin(115200);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  SPIFFS.begin();

  String mode = "right";
  if (mode == "right")
  {
    eye.init(path_image_outline_right, path_image_pupil_right, path_image_reflex_right, image_width, image_height, 3);
  }
  else
  {
    eye.init(path_image_outline_left, path_image_pupil_left, path_image_reflex_left, image_width, image_height, 1);
  }

  eye.update_look();
}

static int i = 0;

void loop()
{
  delay(100);
  i++;
  float look_x = 2. * sin(i * 0.1);
  float look_y = 2. * cos(i * 0.1) - 2.;
  eye.update_look(look_x, look_y);
  Serial.printf("look_x: %f, look_y: %f\n", look_x, look_y);
}
