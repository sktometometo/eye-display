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
  void set_picture_files_asset(const std::array<const char*, 5>& image_paths)
  {    
    sprite_eyeball.fillScreen(TFT_WHITE);
    draw_image_file(sprite_eyeball, image_paths[0]);  // eyeball
    sprite_iris.fillScreen(TFT_WHITE);
    draw_image_file(sprite_iris, image_paths[1]);  // iris
    sprite_pupil.fillScreen(TFT_WHITE);
    draw_image_file(sprite_pupil, image_paths[2]);  // pupil
    sprite_reflex.fillScreen(TFT_WHITE);
    draw_image_file(sprite_reflex, image_paths[3]);  // reflex
    sprite_upperlid.fillScreen(TFT_WHITE);
    draw_image_file(sprite_upperlid, image_paths[4]);  // upperlid
  }

  // 画像の位置を確定する
  // 画像の位置が変わらないときは実行しない
  void set_picture_position(float eyeball_x, float eyeball_y, float iris_x, float iris_y, float pupil_x, float pupil_y, float reflex_x, float reflex_y, float upperlid_x, float upperlid_y){
    // sprite_eye.clear();
    // sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, eyeball_x, eyeball_y, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, iris_x, iris_y, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, pupil_x, pupil_y, TFT_WHITE);
    sprite_reflex.pushSprite(&sprite_eye, reflex_x, reflex_y, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, upperlid_x, upperlid_y, TFT_WHITE);
  }  
  
  // 視線方向を変更する
  void set_gaze_direction(float look_x = 0.0, float look_y = 0.0, float scale = 10.0, float random_scale = 5.0 ){
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_iris.pushSprite(&sprite_eye, look_x, look_y, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, look_x, look_y, TFT_WHITE); 
    sprite_reflex.pushSprite(&sprite_eye, look_x + rx, look_y + ry, TFT_WHITE);
  }

  // まぶたの位置を変更する
  void set_upperlid_position(float upperlid_y){
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y, TFT_WHITE);
  }

  void draw_updated_image(){
    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }
};

class EmotionManager
{
private:
    EyeManager& eyeManager; // EyeManager の参照を保持

    static constexpr const char* path_image_eyeball = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris = "/normal_kxr_iris.jpg";
    static constexpr const char* path_image_pupil = "/normal_kxr_pupil.png";
    static constexpr const char* path_image_reflex = "/normal_kxr_reflex.png";
    static constexpr const char* path_image_upperlid = "/normal_kxr_upperlid.jpg";

    static constexpr const char* path_image_eyeball_1 = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris_1 = "/normal_kxr_iris.jpg";
    static constexpr const char* path_image_pupil_1 = "/normal_kxr_pupil.png";
    static constexpr const char* path_image_reflex_1 = "/normal_kxr_reflex.png";
    static constexpr const char* path_image_upperlid_1 = "/normal_kxr_upperlid.jpg";

    static constexpr const char* path_image_eyeball_2 = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris_2 = "/normal_kxr_iris_surprised.jpg";
    static constexpr const char* path_image_pupil_2 = "/normal_kxr_pupil_surprised.png";
    static constexpr const char* path_image_reflex_2 = "/normal_kxr_reflex_surp.png"; //  
    static constexpr const char* path_image_upperlid_2 = "/normal_kxr_upperlid.jpg";

    static constexpr const char* path_image_eyeball_3 = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris_3 = "/normal_kxr_iris_sleepy.png";
    static constexpr const char* path_image_pupil_3 = "/normal_kxr_pupil_sleepy.png"; // 
    static constexpr const char* path_image_reflex_3 = "/white.jpg";
    static constexpr const char* path_image_upperlid_3 = "/normal_kxr_upperlid.jpg";

    static constexpr const char* path_image_eyeball_4 = "/normal_kxr_eyeball.jpg"; 
    static constexpr const char* path_image_iris_4 = "/normal_kxr_iris.jpg"; 
    static constexpr const char* path_image_pupil_4 = "/normal_kxr_pupil.png"; 
    static constexpr const char* path_image_reflex_4 = "/normal_kxr_reflex.png";
    static constexpr const char* path_image_upperlid_4 = "/normal_kxr_upperlid_ldown.jpg";
    
    static constexpr const char* path_image_eyeball_5 = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris_5 = "/normal_kxr_iris.jpg";
    static constexpr const char* path_image_pupil_5 = "/normal_kxr_pupil.png";
    static constexpr const char* path_image_reflex_5 = "/normal_kxr_reflex.png";
    static constexpr const char* path_image_upperlid_5 = "/normal_kxr_upperlid_rdown.jpg";

    static constexpr const char* path_image_eyeball_6 = "/normal_kxr_eyeball.jpg";
    static constexpr const char* path_image_iris_6 = "/white.jpg";
    static constexpr const char* path_image_pupil_6 = "/white.png";
    static constexpr const char* path_image_reflex_6 = "/white.png";
    static constexpr const char* path_image_upperlid_6 = "/normal_kxr_upperlid_happy.jpg";

    using image_path_set = std::array<const char*, 5>;
    std::map<int, image_path_set> image_path_map;
    std::map<int, std::vector<float>> upperlid_position_map;
    

public:
    // コンストラクタで EyeManager の参照を受け取る
    EmotionManager(EyeManager& manager) : eyeManager(manager) {
      image_path_map = {
        {0, {path_image_eyeball, path_image_iris, path_image_pupil, path_image_reflex, path_image_upperlid}},
        {1, {path_image_eyeball_1, path_image_iris_1, path_image_pupil_1, path_image_reflex_1, path_image_upperlid_1}},
        {2, {path_image_eyeball_2, path_image_iris_2, path_image_pupil_2, path_image_reflex_2, path_image_upperlid_2}},
        {3, {path_image_eyeball_3, path_image_iris_3, path_image_pupil_3, path_image_reflex_3, path_image_upperlid_3}},
        {4, {path_image_eyeball_4, path_image_iris_4, path_image_pupil_4, path_image_reflex_4, path_image_upperlid_4}},
        {5, {path_image_eyeball_5, path_image_iris_5, path_image_pupil_5, path_image_reflex_5, path_image_upperlid_5}},
        {6, {path_image_eyeball_6, path_image_iris_6, path_image_pupil_6, path_image_reflex_6, path_image_upperlid_6}}
      };

      upperlid_position_map = {
        {0, {-130,}},
        {1, {-130, -130, 0, 0, -130, -130}},
        {2, {- 130, - 130, -130, -130, 0, 0, -130, -130, -130, -130, 0, -130, -130, 0, -130, -130}},
        {3, {- 70, - 70, -60, 0, 0, 0, -60, -70, -70, - 70}},
        {4, {- 10}},
        {5, {0}},
        {6, {0}},
      };  
    }
    
    int frame_index = 0;

    // 感情ごとの表示設定
    void set_emotion(int eye_status, bool& emotion_changed_flag, int frame = 0){
      if (emotion_changed_flag){
        const image_path_set& image_paths = image_path_map[eye_status];
        eyeManager.set_picture_files_asset(image_paths);
        emotion_changed_flag = false;
      };
      
      auto& upperlid_positions = upperlid_position_map[eye_status];
      int frame_count = upperlid_positions.size();
      int current_frame = frame % frame_count;
      float upperlid_y = upperlid_positions[current_frame];

      eyeManager.set_upperlid_position(upperlid_y);
      eyeManager.draw_updated_image();
    };
};