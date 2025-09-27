#include <stdint.h>
#include <Wire.h>
#include <Ticker.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "frames/Emobot_Bee.h"
#include "frames/EmoBot_Happy.h"
#include "frames/EmoBot_Sneeze.h"
#include "frames/EmoBot_Hehe.h"
#include "frames/EmoBot_Yawn.h"
#include "frames/EmoBot_Pong.h"
#include "frames/EmoBot_Sakura.h"
#include "frames/EmoBot_Sleepy.h"
#include "frames/EmoBot_Speed.h"
#include "frames/EmoBot_LookRight.h"
#include "frames/EmoBot_Loading.h"
#include "frames/Emobot_Squint.h"
#include "frames/EmoBot_Water_Gun.h"
#include "frames/EmoBot_Smoke.h"
#include "frames/Emobot_Turbo.h"
#include "frames/Emobot_Egg.h"
#include "frames/EmoBot_Dizzy.h"
#include "frames/EmoBot_UpSizeDown.h"
#include "frames/EmoBot_HeadLight.h"
#include "frames/EmoBot_Nothing.h"
#include "frames/EmoBot_LookDown.h"
#include "frames/EmoBot_UwU.h"
#include "frames/EmoBot_Intro.h"

#define LED_PIN 8

#define SSD1306_SDA 6
#define SSD1306_SCL 7
#define SSD1306_ADDR 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

#define DELAY_FRAME 66

Adafruit_SSD1306 display(SSD1306_WIDTH, SSD1306_HEIGHT, &Wire);

Ticker tickerTimer;
volatile bool flagFrame = false;
volatile bool flagBlinkLed = false;
volatile uint8_t cntBlinkLed = false;

uint8_t currentFrame = 0;
uint8_t currentGifIndex = 0;

const AnimatedGIF* gifs[] = {
  &EmoBot_Loading_gif,     
  &EmoBot_Intro_gif,
  &EmoBot_Happy_gif,
  &Emobot_LookRight_gif,
  &EmoBot_Bee_gif,     
  &EmoBot_Sneeze_gif,
  &Emobot_Hehe_gif,
  &Emobot_Squint_gif,
  &EmoBot_Egg_gif,
  &EmoBot_Dizzy_gif,
  &EmoBot_HeadLight_gif,
  &EmoBot_UpSizeDown_gif,
  &EmoBot_Nothing_gif,
  &EmoBot_Yawn_gif,
  &Emobot_Sleepy_gif,
  &Emobot_Sakura_gif,
  &EmoBot_LookDown_gif,
  &EmoBot_Water_Gun_gif,
  &EmoBot_Smoke_gif,
  &Emobot_Turbo_gif,
  &Emobot_Speed_gif,
  &Emobot_Pong_gif,
  &EmoBot_UwU_gif
};

#define GIF_COUNT (sizeof(gifs) / sizeof(gifs[0]))



