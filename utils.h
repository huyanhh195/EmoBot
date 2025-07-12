#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "frames/EmoBot_Sleepy.h"
#include "frames/EmoBot_Frustrated.h"

#define LED_PIN 8

#define SSD1306_SDA 6
#define SSD1306_SCL 7
#define SSD1306_ADDR 0x3C
#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64

Adafruit_SSD1306 display(SSD1306_WIDTH, SSD1306_HEIGHT, &Wire);

// AnimatedGIF sleepyGIF = {
//   EMOBOT_SLEEPY_FRAME_COUNT,
//   EMOBOT_SLEEPY_WIDTH,
//   EMOBOT_SLEEPY_HEIGHT,
//   EmoBot_Sleepy_delays,
//   EmoBot_Sleepy_frames
// };
  
// AnimatedGIF frusGIF = {
//   EMOBOT_FRUSTRATED_FRAME_COUNT,
//   EMOBOT_FRUSTRATED_WIDTH,
//   EMOBOT_FRUSTRATED_HEIGHT,
//   EmoBot_Frustrated_delays,
//   EmoBot_Frustrated_frames
// };
