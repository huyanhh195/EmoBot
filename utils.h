#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <driver/i2s.h>

#include "sounds/Emo_default_wav.h"

#define LED_PIN 8

#define SSD1306_SDA 6
#define SSD1306_SCL 7
#define SSD1306_ADDR 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

#define MAX98375A_BCLK        1         
#define MAX98375A_LRCLK       0         
#define MAX98375A_DOUT        2         
#define DMA_BUF_LEN 64

#define DELAY_FRAME 100

Adafruit_SSD1306 display(SSD1306_WIDTH, SSD1306_HEIGHT, &Wire);

#define SAMPLE_RATE     8000
#define NOTE_DURATION_MS 300
