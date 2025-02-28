#include <math.h>
#include <functional>
#include <vector>
#include <map>
#include <array>
#include <string>
#include <iostream>

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

#include "eye_assets.hpp"

#if defined(STAMPS3)
#include <lgfx_round_lcd_stamp_s3.hpp>
#elif defined(STAMPC3)
#include <lgfx_round_lcd_stamp_c3.hpp>
#endif

extern void print_log(const char *);


class EyeManager
{
private:
  LGFX_ROUND_LCD lcd;

  // Spriteを設定
  LGFX_Sprite sprite_eye;
  LGFX_Sprite sprite_outline;
  LGFX_Sprite sprite_iris;
  LGFX_Sprite sprite_pupil;
  LGFX_Sprite sprite_reflex;
  LGFX_Sprite sprite_upperlid;

  float zoom_ratio;
  int image_width;
  int image_height;

  float look_x = 0.0f;
  float look_y = 0.0f;
  float upperlid_y = 0.0f;

  int rotation;
  bool invert_rl;

  String path_jpg_outline;
  String path_jpg_iris;
  String path_jpg_pupil;
  String path_jpg_reflex;
  String path_jpg_upperlid;
  String path_jpg_iris_surprised;
  String path_jpg_pupil_surprised;
  String path_jpg_reflex_surprised;
  String path_jpg_reflex_happy;

  int upperlid_pivot_x;
  int upperlid_pivot_y;

  int upperlid_default_pos_x;
  int upperlid_default_pos_y;

  int upperlid_sad_pos_x;
  int upperlid_sad_pos_y;
  int upperlid_sad_theta;
  int upperlid_angry_pos_x;
  int upperlid_angry_pos_y;
  int upperlid_angry_theta;

public:

  const static int max_blink_level = 6;
  const static int max_surprised_level = 16;
  const static int max_sleepy_level = 10;
  const static int max_angry_level = 20;
  const static int max_sad_level = 20;
  const static int max_happy_level = 20;

  void init(
          const char *path_jpg_outline,
          const char *path_jpg_iris,
          const char *path_jpg_pupil,
          const char *path_jpg_reflex,
          const char *path_jpg_upperlid,
          const char *path_jpg_iris_surprised,
          const char *path_jpg_pupil_surprised,
          const char *path_jpg_reflex_surprised,
          const char *path_jpg_reflex_happy,
          const int image_width = 139,
          const int image_height = 139,
          const int rotation = 0,
          const bool invert_rl = false,
          const int upperlid_pivot_x = 75,
          const int upperlid_pivot_y = 139,
          const int upperlid_default_pos_x = 75,
          const int upperlid_default_pos_y = 19,
          const int upperlid_sad_pos_x = 100,
          const int upperlid_sad_pos_y = 40,
          const int upperlid_sad_theta = 30,
          const int upperlid_angry_pos_x = 50,
          const int upperlid_angry_pos_y = 40,
          const int upperlid_angry_theta = -30
          )
  {
    this->image_width = image_width;
    this->image_height = image_height;
    this->rotation = rotation;
    this->invert_rl = invert_rl;

    this->path_jpg_outline = path_jpg_outline;
    this->path_jpg_iris = path_jpg_iris;
    this->path_jpg_pupil = path_jpg_pupil;
    this->path_jpg_reflex = path_jpg_reflex;
    this->path_jpg_upperlid = path_jpg_upperlid;
    this->path_jpg_iris_surprised = path_jpg_iris_surprised;
    this->path_jpg_pupil_surprised = path_jpg_pupil_surprised;
    this->path_jpg_reflex_surprised = path_jpg_reflex_surprised;
    this->path_jpg_reflex_happy = path_jpg_reflex_happy;

    this->upperlid_pivot_x = upperlid_pivot_x;
    this->upperlid_pivot_y = upperlid_pivot_y;
    this->upperlid_default_pos_x = upperlid_default_pos_x;
    this->upperlid_default_pos_y = upperlid_default_pos_y;
    this->upperlid_sad_pos_x = upperlid_sad_pos_x;
    this->upperlid_sad_pos_y = upperlid_sad_pos_y;
    this->upperlid_sad_theta = upperlid_sad_theta;
    this->upperlid_angry_pos_x = upperlid_angry_pos_x;
    this->upperlid_angry_pos_y = upperlid_angry_pos_y;
    this->upperlid_angry_theta = upperlid_angry_theta;

    lcd.init();
    lcd.setRotation(rotation);

    // 目全体を描写するBufferとしてのSpriteを準備
    sprite_eye.createSprite(image_width, image_height);
    sprite_eye.fillScreen(TFT_WHITE);

    // 目の輪郭を描写するSpriteを準備
    sprite_outline.createSprite(image_width, image_height);
    if (invert_rl) sprite_outline.setRotation(6);

    // 虹彩を描写するSpriteを準備
    sprite_iris.createSprite(image_width, image_height);
    if (invert_rl) sprite_iris.setRotation(6);

    // 瞳孔を描写するSpriteを準備
    sprite_pupil.createSprite(image_width, image_height);
    if (invert_rl) sprite_pupil.setRotation(6);

    // 光の反射を描画するSpriteを準備
    sprite_reflex.createSprite(image_width, image_height);
    if (invert_rl) sprite_reflex.setRotation(6);

    // 上瞼を描写するSpriteを準備
    sprite_upperlid.createSprite(image_width, image_height);
    if (invert_rl) sprite_upperlid.setRotation(6);
    sprite_upperlid.setPivot(this->upperlid_pivot_x, this->upperlid_pivot_y);

    // Load images
    this->load_eye_images(path_jpg_outline, path_jpg_iris, path_jpg_pupil,
            path_jpg_reflex, path_jpg_upperlid);

    // lcdを準備
    lcd.setPivot(lcd.width() >> 1, lcd.height() >> 1);
    lcd.fillScreen(TFT_WHITE);

    // zoom率を指定
    zoom_ratio = (float)lcd.width() / image_width;
    float ztmp = (float)lcd.height() / image_height;

    if (zoom_ratio > ztmp)
    {
      zoom_ratio = ztmp;
    }
  }

  bool draw_image_file(LGFX_Sprite& sprite, const char* filePath)
  {
    //return sprite.drawJpgFile(SPIFFS, filePath);
    std::string pathStr(filePath);
    std::string extension = pathStr.substr(pathStr.find_last_of('.') + 1);
    bool ret = false;

    if (extension == "jpg" || extension == "jpeg") {
      char log_msg[50];
      sprintf(log_msg, "loading jpeg: %s", filePath);
      print_log(log_msg);

      ret = sprite.drawJpgFile(SPIFFS, filePath);
    } else if (extension == "png") {
      char log_msg[50];
      sprintf(log_msg, "loading png: %s", filePath);
      print_log(log_msg);

      ret = sprite.drawPngFile(SPIFFS, filePath);
    } else {
      char log_msg[50];
      sprintf(log_msg, "invalid image extension %s", filePath);
      print_log(log_msg);
    }
    if (not ret) {
      char log_msg[50];
      sprintf(log_msg, "Failed to load %s", filePath);
      print_log(log_msg);
    }
    return ret;
  }

   // 視線方向を変更（値を設定するだけ）
  void set_gaze_direction(float look_x, float look_y)
  {
    this->look_x = look_x;
    this->look_y = look_y;
  }

  // まぶたの位置を変更（値を設定するだけ）
  void set_upperlid_position(float upperlid_y)
  {
    this->upperlid_y = upperlid_y;
  }

  // 目の状態を更新する
  void load_eye_images(
          const char *path_jpg_outline,
          const char *path_jpg_iris,
          const char *path_jpg_pupil,
          const char *path_jpg_reflex,
          const char *path_jpg_upperlid
          )
  {
    if (path_jpg_outline != NULL) {
        sprite_outline.fillScreen(TFT_WHITE);
        if (not draw_image_file(sprite_outline, path_jpg_outline)) {
            sprite_outline.fillScreen(TFT_WHITE);
        }
    }

    if (path_jpg_iris != NULL) {
        sprite_iris.fillScreen(TFT_WHITE);
        if (not draw_image_file(sprite_iris, path_jpg_iris)) {
            sprite_iris.fillScreen(TFT_WHITE);
        }
    }


    if (path_jpg_pupil != NULL) {
        sprite_pupil.fillScreen(TFT_WHITE);
        if (not draw_image_file(sprite_pupil, path_jpg_pupil)) {
            sprite_pupil.fillScreen(TFT_WHITE);
        }
    }

    if (path_jpg_reflex != NULL) {
        sprite_reflex.fillScreen(TFT_WHITE);
        if (not draw_image_file(sprite_reflex, path_jpg_reflex)) {
            sprite_reflex.fillScreen(TFT_WHITE);
        }
    }

    if (path_jpg_upperlid != NULL) {
        sprite_upperlid.fillScreen(TFT_WHITE);
        if (not draw_image_file(sprite_upperlid, path_jpg_upperlid)) {
            sprite_upperlid.fillScreen(TFT_WHITE);
        }
    }
  }

  // 通常の目を描画する準備
  void ready_for_normal_eye(const char *path_jpg_iris = NULL, const char *path_jpg_upperlid = NULL)
  {
    this->load_eye_images(NULL, NULL, NULL, NULL, NULL);
    return ;
    // this->load_eye_images("/outline.jpg",
    //                       "/iris.jpg",
    //                       "/pupil.jpg",
    //                       "/reflex.jpg",
    //                       "/upperlid.jpg");
    // return ;
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            path_jpg_iris == NULL ? this->path_jpg_iris.c_str() : path_jpg_iris,
            this->path_jpg_pupil.c_str(),
            this->path_jpg_reflex.c_str(),
            path_jpg_upperlid == NULL ? this->path_jpg_upperlid.c_str() : path_jpg_upperlid
            );
  }

  //
  void ready_for_blink_eye(const char *path_jpg_iris = NULL, const char *path_jpg_upperlid = NULL)
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            path_jpg_iris == NULL ? this->path_jpg_iris.c_str() : path_jpg_iris,
            this->path_jpg_pupil.c_str(),
            this->path_jpg_reflex.c_str(),
            path_jpg_upperlid == NULL ? this->path_jpg_upperlid.c_str() : path_jpg_upperlid
            );
  }

  // 驚いた目を描画する準備
  void ready_for_surprised_eye(const char *path_jpg_surprised_iris = NULL)
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            path_jpg_surprised_iris == NULL ? this->path_jpg_iris_surprised.c_str() : path_jpg_surprised_iris,
            this->path_jpg_pupil_surprised.c_str(),
            this->path_jpg_reflex_surprised.c_str(),
            this->path_jpg_upperlid.c_str()
            );
  }

  //
  void ready_for_sleepy_eye()
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            this->path_jpg_iris.c_str(),
            this->path_jpg_pupil.c_str(),
            this->path_jpg_reflex.c_str(),
            this->path_jpg_upperlid.c_str()
            );
  }

  // 怒った目を描画する準備
  void ready_for_angry_eye(const char *path_jpg_angry_upperlid = NULL)
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            this->path_jpg_iris.c_str(),
            this->path_jpg_pupil.c_str(),
            this->path_jpg_reflex.c_str(),
            this->path_jpg_upperlid.c_str()
            );
  }

  // 悲しい目を描画する準備
  void ready_for_sad_eye(const char *path_jpg_sad_upperlid = NULL)
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            this->path_jpg_iris.c_str(),
            this->path_jpg_pupil.c_str(),
            this->path_jpg_reflex.c_str(),
            this->path_jpg_upperlid.c_str()
            );
  }

  // 喜んでいる目を描画する準備
  void ready_for_happy_eye(const char *path_jpg_happy_reflex = NULL)
  {
    this->load_eye_images(
            this->path_jpg_outline.c_str(),
            "",
            "",
            path_jpg_happy_reflex == NULL ? this->path_jpg_reflex_happy.c_str() : path_jpg_happy_reflex,
            ""
            );
  }

  // 通常の目の描画
  void update_look(float dx = 0.0, float dy = 0.0,
          int dx_upperlid = 0.0, int dy_upperlid = 0.0, float dtheta_upperlid = 0.0,
          float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_outline.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, dx, dy, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, dx, dy, TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, dx + rx, dy + ry, TFT_WHITE); // 光の反射をランダムに動かす
    sprite_upperlid.pushRotateZoom(&sprite_eye,
            this->upperlid_default_pos_x + dx_upperlid,
            this->upperlid_default_pos_y + dy_upperlid,
            dtheta_upperlid, 1.0, 1.0, TFT_WHITE); 

    draw_updated_image();
  }

  void draw_updated_image()
  {
    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio);
  }
};
