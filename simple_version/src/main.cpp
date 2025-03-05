#include <Arduino.h>
#include <math.h>

#include "eye.hpp"

#define TFT_BL 10

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

static EyeManager eye;

void print_log(const char* str){
  Serial.println(str);
}

void setup()
{
  Serial.begin(115200);
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
  SPIFFS.begin();
  Serial.println("Initialized.");

  delay(5000);

  eye.init(path_image_outline, path_image_iris, path_image_pupil,
          path_image_reflex, path_image_upperlid,
          path_image_iris_surprised, path_image_pupil_surprised, path_image_reflex_surprised,
          path_image_reflex_happy,
          image_width, image_height, 1);
  eye.update_look();

  Serial.println("Start.");
}

void loop()
{
  float look_x, look_y;

  // 通常
  for (int i=0; i<50; i++) {
      delay(20);
      look_x = 10.0 * sin(i * 0.1);
      look_y = 10.0 * cos(i * 0.1) ;
      eye.set_gaze_direction(look_x, look_y);
      eye.update_look(look_x, look_y);
  }
  look_x = 0;
  look_y = 0;
  eye.set_gaze_direction(look_x, look_y);
  eye.update_look(look_x, look_y);
  delay(1000);

}
