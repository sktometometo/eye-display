#include <math.h>
#include <functional>

#include <Arduino.h>
#include <SPIFFS.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX_M5Stamp_SPI_GC9A01 : public lgfx::LGFX_Device
{
  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Bus_SPI _bus_instance; // SPIバスのインスタンス
  lgfx::Light_PWM _light_instance;

public:
  LGFX_M5Stamp_SPI_GC9A01(void)
  {
    {                                    // バス制御の設定を行います。
      auto cfg = _bus_instance.config(); // バス設定用の構造体を取得します。

      // SPIバスの設定
      cfg.spi_host =
          SPI2_HOST; // 使用するSPIを選択  ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
      // ※ ESP-IDFバージョンアップに伴い、VSPI_HOST ,
      // HSPI_HOSTの記述は非推奨になるため、エラーが出る場合は代わりにSPI2_HOST , SPI3_HOSTを使用してください。
      cfg.spi_mode = 0;          // SPI通信モードを設定 (0 ~ 3)
      cfg.freq_write = 40000000; // 送信時のSPIクロック (最大80MHz, 80MHzを整数で割った値に丸められます)
      cfg.freq_read = 16000000;  // 受信時のSPIクロック
      cfg.spi_3wire = true;      // 受信をMOSIピンで行う場合はtrueを設定
      cfg.use_lock = true;       // トランザクションロックを使用する場合はtrueを設定
      cfg.dma_channel =
          SPI_DMA_CH_AUTO; // 使用するDMAチャンネルを設定 (0=DMA不使用 / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=自動設定)
      // ※
      // ESP-IDFバージョンアップに伴い、DMAチャンネルはSPI_DMA_CH_AUTO(自動設定)が推奨になりました。1ch,2chの指定は非推奨になります。
      cfg.pin_sclk = 4;  // SPIのSCLKピン番号を設定
      cfg.pin_mosi = 6;  // SPIのMOSIピン番号を設定
      cfg.pin_miso = -1; // SPIのMISOピン番号を設定 (-1 = disable)
      cfg.pin_dc = 1;    // SPIのD/Cピン番号を設定  (-1 = disable)
      // SDカードと共通のSPIバスを使う場合、MISOは省略せず必ず設定してください。
      _bus_instance.config(cfg);              // 設定値をバスに反映します。
      _panel_instance.setBus(&_bus_instance); // バスをパネルにセットします。
    }

    {                                      // 表示パネル制御の設定を行います。
      auto cfg = _panel_instance.config(); // 表示パネル設定用の構造体を取得します。
      cfg.pin_cs = 7;                      // CSが接続されているピン番号   (-1 = disable)
      cfg.pin_rst = 0;                     // RSTが接続されているピン番号  (-1 = disable)
      cfg.pin_busy = -1;                   // BUSYが接続されているピン番号 (-1 = disable)
      // ※
      // 以下の設定値はパネル毎に一般的な初期値が設定されていますので、不明な項目はコメントアウトして試してみてください。
      cfg.memory_width = 240;   // ドライバICがサポートしている最大の幅
      cfg.memory_height = 240;  // ドライバICがサポートしている最大の高さ
      cfg.panel_width = 240;    // 実際に表示可能な幅
      cfg.panel_height = 240;   // 実際に表示可能な高さ
      cfg.offset_x = 0;         // パネルのX方向オフセット量
      cfg.offset_y = 0;         // パネルのY方向オフセット量
      cfg.offset_rotation = 0;  // 回転方向の値のオフセット 0~7 (4~7は上下反転)
      cfg.dummy_read_pixel = 8; // ピクセル読出し前のダミーリードのビット数
      cfg.dummy_read_bits = 1;  // ピクセル以外のデータ読出し前のダミーリードのビット数
      cfg.readable = true;      // データ読出しが可能な場合 trueに設定
      cfg.invert = true;        // パネルの明暗が反転してしまう場合 trueに設定
      cfg.rgb_order = false;    // パネルの赤と青が入れ替わってしまう場合 trueに設定
      cfg.dlen_16bit = false;   // データ長を16bit単位で送信するパネルの場合 trueに設定
      cfg.bus_shared = true;    // SDカードとバスを共有している場合 trueに設定(drawJpgFile等でバス制御を行います)

      _panel_instance.config(cfg);
    }
    {                                      // バックライト制御の設定を行います。（必要なければ削除）
      auto cfg = _light_instance.config(); // バックライト設定用の構造体を取得します。

      cfg.pin_bl = 10;     // バックライトが接続されているピン番号
      cfg.invert = false;  // バックライトの輝度を反転させる場合 true
      cfg.freq = 44100;    // バックライトのPWM周波数
      cfg.pwm_channel = 3; // 使用するPWMのチャンネル番号

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance); // バックライトをパネルにセットします。
    }
    setPanel(&_panel_instance); // 使用するパネルをセットします。
  }
};

class Eye
{
private:
  LGFX_M5Stamp_SPI_GC9A01 lcd;

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

    // 虹彩を描写するSpriteを準備
    sprite_iris.createSprite(image_width, image_height);
    sprite_iris.fillScreen(TFT_WHITE);
    const bool success_load_iris_image = sprite_iris.drawJpgFile(SPIFFS, path_jpg_iris);
    Serial.println(success_load_iris_image);

    // 瞳孔を描写するSpriteを準備
    sprite_pupil.createSprite(image_width, image_height);
    sprite_pupil.fillScreen(TFT_WHITE);
    sprite_pupil.fillCircle(50, 50, 30, TFT_BLACK);
    
    // 光の反射を描画するSpriteを準備
    sprite_reflex.createSprite(image_width, image_height);
    sprite_reflex.fillScreen(TFT_WHITE);
    sprite_reflex.fillCircle(40, 40, 6, TFT_LIGHTGRAY);
    
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

  void ready_for_normal_eye(const char *path_jpg_iris = "/white.jpg", const char *path_jpg_upperlid = "/white.jpg")
  {
    sprite_iris.fillScreen(TFT_WHITE);
    const bool success_load_iris_image = sprite_iris.drawJpgFile(SPIFFS, path_jpg_iris);
    Serial.println(success_load_iris_image);

    sprite_pupil.fillScreen(TFT_WHITE);
    sprite_pupil.fillCircle(50, 50, 30, TFT_BLACK);
    
    sprite_reflex.fillScreen(TFT_WHITE);
    sprite_reflex.fillCircle(40, 40, 6, TFT_LIGHTGRAY);

    sprite_upperlid.fillScreen(TFT_WHITE);
    sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_upperlid); 
    
  }

  void update_look(float dx = 0.0, float dy = 0.0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE); // 光の反射をランダムに動かす
    sprite_upperlid.pushSprite(&sprite_eye, 0, -130, TFT_WHITE); 

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE); // sprite_eye をlcdに一括転送
  }

  void blink_eye(float dx = 0.0, float dy = 0.0, int blink_level = 0 /*何コマ目か*/, float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {-130, -130, 0, 0, -130, -130}; // 上瞼のコマ送り時のy座標の配列
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[blink_level], TFT_WHITE); // 上瞼を動かす

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE); // sprite_eye をlcdに一括転送
  }

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

  void surprised(float dx = 0.0, float dy = 0.0, int surprised_level = 0 /*何コマ目か*/,  float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {- 130, - 130, -130, -130, 0, 0, -130, -130, -130, -130, 0, -130, -130, 0, -130, -130};
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);

    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_iris.pushSprite(&sprite_eye, 0, 5, TFT_WHITE);
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE);
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[surprised_level], TFT_WHITE);
    
    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  void sleepy(float dx = 0.0, float dy = 0.0, int sleepy_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    int upperlid_y_arr[] = {- 70, - 70, -60, 0, 0, 0, -60, -70, -70, - 70};
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, -10, 15, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx) - 10, (int)(scale * dy) + 15, TFT_WHITE);
    sprite_upperlid.pushSprite(&sprite_eye, 0, upperlid_y_arr[sleepy_level]);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  void ready_for_angry_eye(const char *path_jpg_angry_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_angry_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_angry_upperlid);
    Serial.println("angry_eye");
    Serial.println(success_load_angry_upperlid_image);
  }

  void angry(float dx = 0.0, float dy = 0.0, int angry_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry + 10, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, -10, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  void ready_for_sad_eye(const char *path_jpg_sad_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_sad_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_sad_upperlid);
    Serial.println("sad_eye");
    Serial.println(success_load_sad_upperlid_image);
  }

  void sad(float dx = 0.0, float dy = 0.0, int sad_level = 0, float scale = 10.0, float random_scale = 5.0)
  {
    long rx = (int)(random_scale * random(100) / 100);
    long ry = (int)(random_scale * random(100) / 100);
    
    sprite_eye.clear();
    sprite_eye.fillScreen(TFT_WHITE);
    sprite_eyeball.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    sprite_iris.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);
    
    sprite_pupil.pushSprite(&sprite_eye, (int)(scale * dx), (int)(scale * dy), TFT_WHITE); // 瞳孔をランダムに動かす
    sprite_reflex.pushSprite(&sprite_eye, (int)(scale * dx) + rx, (int)(scale * dy) + ry + 10, TFT_WHITE); // 光の反射をランダムに動かす
    
    sprite_upperlid.pushSprite(&sprite_eye, 0, 0, TFT_WHITE);

    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }

  void ready_for_happy_eye(const char *path_jpg_happy_upperlid = "/white.jpg")
  {
    sprite_upperlid.fillScreen(TFT_WHITE);
    const bool success_load_happy_upperlid_image = sprite_upperlid.drawJpgFile(SPIFFS, path_jpg_happy_upperlid);
    Serial.println("happy_eye");
    Serial.println(success_load_happy_upperlid_image);
  }

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


  void draw_updated_image()
  {
    sprite_eye.pushRotateZoom(&lcd, lcd.width() >> 1, lcd.height() >> 1, 0, zoom_ratio, zoom_ratio, TFT_WHITE);
  }
};
