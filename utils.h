#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <driver/i2s.h>

#include "frames/EmoBot_Intro.h"
#include "frames/Emobot_Default.h"
#include "frames/EmoBot_Sleepy.h"
#include "frames/EmoBot_Frustrated.h"

#define LED_PIN 8

#define SSD1306_SDA 6
#define SSD1306_SCL 7
#define SSD1306_ADDR 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

#define I2S_NUM         I2S_NUM_0  
#define MAX98375A_BCLK        1         
#define MAX98375A_LRCLK       0         
#define MAX98375A_DOUT        2         

#define DELAY_FRAME 100

Adafruit_SSD1306 display(SSD1306_WIDTH, SSD1306_HEIGHT, &Wire);

#define SAMPLE_RATE     44100
#define NOTE_DURATION_MS 300

struct Note {
  const char* name;
  float freq;
};
Note melody[] = {
  {"C4",  261.63},
  {"E4",  329.63},
  {"G4",  392.00},
  {"C5",  523.25},
  {"E5",  659.25},
  {"G5",  783.99},
  {"REST", 0}
};
