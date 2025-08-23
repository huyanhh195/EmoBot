#include <stdint.h>
#include <Wire.h>
#include <Ticker.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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

#define DELAY_FRAME 150

Adafruit_SSD1306 display(SSD1306_WIDTH, SSD1306_HEIGHT, &Wire);

Ticker tickerTimer;
volatile bool flagFrame = false;
volatile bool flagBlinkLed = false;
volatile uint8_t cntBlinkLed = false;

uint8_t currentFrame = 0;
uint8_t currentGifIndex = 0;
const AnimatedGIF* gifs[] = {
  &EmoBot_Intro_gif,
  &Emobot_Default_gif,
  &EmoBot_Frustrated_gif,
  &EmoBot_Sleepy_gif
};


