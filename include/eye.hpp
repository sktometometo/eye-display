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

class EyeManager
{
private:
  LGFX_ROUND_LCD lcd;

  // Spriteを設定
  LGFX_Sprite sprite_eye;
  LGFX_Sprite sprite_eyeball;
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

public:
  void init(const int image_width, const int image_height, int rotation = 0)
  {
    this->image_width = image_width;
    this->image_height = image_height;

    lcd.init();
    lcd.setRotation(rotation);

    // 目の部位を描写するSpriteを準備
    sprite_eye.createSprite(image_width, image_height);
    sprite_eye.fillScreen(TFT_WHITE);

    // 目玉を描写するSpriteを準備
    sprite_eyeball.createSprite(image_width, image_height);
    sprite_eyeball.fillScreen(TFT_WHITE);

    // 上瞼を描写するSpriteを準備
    sprite_upperlid.createSprite(image_width, image_height);
    sprite_upperlid.fillScreen(TFT_WHITE);

    // 虹彩を描写するSpriteを準備
    sprite_iris.createSprite(image_width, image_height);
    sprite_iris.fillScreen(TFT_WHITE);

    // 瞳孔を描写するSpriteを準備
    sprite_pupil.createSprite(image_width, image_height);
    sprite_pupil.fillScreen(TFT_WHITE);
    
    // 光の反射を描画するSpriteを準備
    sprite_reflex.createSprite(image_width, image_height);
    sprite_reflex.fillScreen(TFT_WHITE);
    
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

  void draw_image_file(LGFX_Sprite& sprite, const char* filePath)
{
    std::string pathStr(filePath);
    std::string extension = pathStr.substr(pathStr.find_last_of('.') + 1);

    if (extension == "jpg" || extension == "jpeg") {
        sprite.drawJpgFile(SPIFFS, filePath);
    } else if (extension == "png") {
        sprite.drawPngFile(SPIFFS, filePath);
    } 
}

  // 画像ファイルのセットを決定する
  // 画像が変わらないときはこれは実行しない
  void set_picture_files_asset(const EyeAsset& eye_asset)
  {    
    sprite_eyeball.fillScreen(TFT_WHITE);
    draw_image_file(sprite_eyeball, eye_asset.eyeball);  // eyeball
    sprite_iris.fillScreen(TFT_WHITE);
    draw_image_file(sprite_iris, eye_asset.iris);  // iris
    sprite_pupil.fillScreen(TFT_WHITE);
    draw_image_file(sprite_pupil, eye_asset.pupil);  // pupil
    sprite_reflex.fillScreen(TFT_WHITE);
    draw_image_file(sprite_reflex, eye_asset.reflex);  // reflex
    sprite_upperlid.fillScreen(TFT_WHITE);
    draw_image_file(sprite_upperlid, eye_asset.upperlid);  // upperlid
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
  void update(float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, look_x, look_y, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, look_x, look_y, TFT_WHITE); 
    sprite_reflex.pushSprite(&sprite_eye, look_x + rx, look_y + ry, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }
};