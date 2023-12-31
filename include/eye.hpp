#include <math.h>
#include <functional>

#include <Arduino.h>
#include <SPIFFS.h>

#if defined(STAMPS3)
#include <lgfx_round_lcd_stamp_s3.hpp>
#elif defined(STAMPC3)
#include <lgfx_round_lcd_stamp_c3.hpp>
#endif

class Eye
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

public:
  void init(const char *path_jpg_eyeball, const char *path_jpg_iris, const char *path_jpg_upperlid, 
            const int image_width, const int image_height, int rotation = 0)

  {
    this->image_width = image_width;
    this->image_height = image_height;

    lcd.init();
    lcd.setRotation(rotation);

    // 目の部位を描写するSpriteを準備
    sprite_eye.createSprite(image_width, image_height);
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eye.drawJpgFile(SPIFFS, path_jpg_eyeball);

    // 目玉を描写するSpriteを準備
    sprite_eyeball.createSprite(image_width, image_height);
    sprite_eyeball.fillScreen(TFT_WHITE);
    sprite_eyeball.drawJpgFile(SPIFFS, path_jpg_eyeball);

    // 上瞼を描写するSpriteを準備
    sprite_upperlid.createSprite(image_width, image_height);
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_upperlid); 
    Serial.println(success_load_upperlid_image); // 上瞼の画像がloadできていることを確認

    /*    // 虹彩を描写するSpriteを準備
    sprite_iris.createSprite(image_width, image_height);
    sprite_iris.fillScreen(TFT_WHITE);
    const bool success_load_iris_image = sprite_iris.drawJpgFile(SPIFFS, path_jpg_iris);
    Serial.println(success_load_iris_image);
    */
    // 瞳孔を描写するSpriteを準備
    sprite_pupil.createSprite(image_width, image_height);
    sprite_pupil.fillScreen(TFT_WHITE);
    //sprite_pupil.fillCircle(50, 50, 30, TFT_BLACK);
    sprite_pupil.fillCircle(image_width / 2, image_height / 2, 30, TFT_BLACK);

    // 光の反射を描画するSpriteを準備
    sprite_reflex.createSprite(image_width, image_height);
    sprite_reflex.fillScreen(TFT_WHITE);
    sprite_reflex.fillCircle(50, 50, 6, TFT_LIGHTGRAY);
    
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

  // 通常の目を描画する準備
  void ready_for_normal_eye(const char *path_jpg_iris = "/white.jpg", const char *path_jpg_upperlid = "/white.jpg")
  {
    /*sprite_iris.fillScreen(TFT_WHITE);
      const bool success_load_iris_image = sprite_iris.drawJpgFile(SPIFFS, path_jpg_iris);
      Serial.println(success_load_iris_image);
    */
    
    sprite_pupil.fillScreen(TFT_WHITE);
    //    sprite_pupil.fillCircle(50, 50, 30, TFT_BLACK);
    sprite_pupil.fillCircle(image_width / 2, image_height / 2, 30, TFT_BLACK);


    
    sprite_reflex.fillScreen(TFT_WHITE);
    sprite_reflex.fillCircle(50, 50, 6, TFT_LIGHTGRAY);
    
    sprite_upperlid.fillScreen(TFT_WHITE);
    sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_upperlid); 
    
  }

  // 驚いた目を描画する準備
  void ready_for_surprised_eye(const char *path_jpg_surprised_iris = "/white.jpg")
  {
    sprite_iris.fillScreen(TFT_WHITE);
    const bool success_load_iris_image = sprite_iris.drawJpgFile(SPIFFS, path_jpg_surprised_iris);
    Serial.println(success_load_iris_image);

    sprite_pupil.fillScreen(TFT_WHITE);
    sprite_pupil.fillCircle(image_height / 2, image_width / 2, 15, TFT_BLACK);
      
    sprite_reflex.fillScreen(TFT_WHITE);
    sprite_reflex.fillCircle(image_height / 2, image_width / 2, 7, TFT_LIGHTGRAY);
  }

  // 怒った目を描画する準備
  void ready_for_angry_eye(const char *path_jpg_angry_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_angry_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_angry_upperlid);
    Serial.println("angry_eye");
    Serial.println(success_load_angry_upperlid_image);
  }

  // 悲しい目を描画する準備
  void ready_for_sad_eye(const char *path_jpg_sad_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_sad_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_sad_upperlid);
    Serial.println("sad_eye");
    Serial.println(success_load_sad_upperlid_image);
  }

  // 喜んでいる目を描画する準備
  void ready_for_happy_eye(const char *path_jpg_happy_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_happy_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_happy_upperlid);
    Serial.println("happy_eye");
    Serial.println(success_load_happy_upperlid_image);
  }

  // 通常の目の描画
  void update_look(float dx = 0.0, float dy = 0.0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    //    sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    
 
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE); // 光の反射をランダムに動かす
    sprite_upperlid.pushSprite(&sprite_eye, 0, -130, TFT_WHITE); 

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE); // sprite_eye をlcdに一括転送
  }

  // 瞬きの描画
  void blink_eye(float dx = 0.0, float dy = 0.0, int blink_level = 0 /*何コマ目か*/, float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {-130, -130, 0, 0, -130, -130}; // 上瞼のコマ送り時のy座標の配列
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    //sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[blink_level], TFT_WHITE); // 上瞼を動かす

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE); // sprite_eye をlcdに一括転送
  }


  // 驚きの目の描画
  void surprised(float dx = 0.0, float dy = 0.0, int surprised_level = 0 /*何コマ目か*/,  float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {- 130, - 130, -130, -130, 0, 0, -130, -130, -130, -130, 0, -130, -130, 0, -130, -130};
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    //sprite_iris.pushSprite(&sprite_eye, 0, 5, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE);
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[surprised_level], TFT_WHITE);
    
    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  // 眠い目の描画
  void sleepy(float dx = 0.0, float dy = 0.0, int sleepy_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {- 70, - 70, -60, 0, 0, 0, -60, -70, -70, - 70};
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    //sprite_iris.pushSprite(&sprite_eye, -10, 15, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx) - 10, (int)(scale * dy) + 15, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[sleepy_level]);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  // 怒った目の描画
  void angry(float dx = 0.0, float dy = 0.0, int angry_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    //sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry + 10, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, -10, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  // 悲しい目の描画
  void sad(float dx = 0.0, float dy = 0.0, int sad_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    //sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry + 10, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  // 嬉しい目の描画
  void happy(float dx = 0.0, float dy = 0.0, int happy_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_upperlid.pushSprite(&sprite_eye, rx, ry, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }
};
