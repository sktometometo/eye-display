#pragma once

#define LGFX_USE_V1

#include <LovyanGFX.hpp>

// Copied from
// And modified based on https://cdn.shopify.com/s/files/1/1217/2104/files/RoundyPi_Schematic_PDF.pdf?v=1652770448

const int PIN_SPI_DC = 8;
const int PIN_SPI_CS = 9;
const int PIN_SPI_CLK = 10;
const int PIN_SPI_DIN = 11;
const int PIN_SPI_RST = 12;
const int PIN_SPI_BL = 13;

class LGFX : public lgfx::LGFX_Device
{
    lgfx::Panel_GC9A01 _panel_instance;
    lgfx::Bus_SPI _bus_instance;
    //    lgfx::Light_PWM _light_instance;

public:
    LGFX(void)
    {
        {
            auto cfg = _bus_instance.config();
            cfg.spi_host = 1;
            cfg.spi_mode = 0;
            cfg.freq_write = 80000000;
            cfg.pin_sclk = PIN_SPI_CLK;
            cfg.pin_miso = -1;
            cfg.pin_mosi = PIN_SPI_DIN;
            cfg.pin_dc = PIN_SPI_DC;
            _bus_instance.config(cfg);
            _panel_instance.setBus(&_bus_instance);
        }

        {
            auto cfg = _panel_instance.config();
            cfg.pin_cs = PIN_SPI_CS;
            cfg.pin_rst = PIN_SPI_RST;
            cfg.panel_width = 240;
            cfg.panel_height = 240;
            cfg.offset_x = 0;
            cfg.offset_y = 0;
            // cfg.offset_rotation = 0;
            cfg.invert = true;
            cfg.rgb_order = false;
            _panel_instance.config(cfg);
        }

        // {
        //     auto cfg = _light_instance.config();
        //     cfg.pin_bl = PIN_SPI_BL;
        //     cfg.pwm_channel = 1;
        //     _light_instance.config(cfg);
        //     _panel_instance.setLight(&_light_instance);
        // }

        setPanel(&_panel_instance);
    }
};

typedef LGFX LGFX_ROUND_LCD;