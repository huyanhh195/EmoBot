#include "utils.h"

void blink_led(int time);
void drawFrame(const AnimatedGIF* gif);
void IRAM_ATTR onTimer();

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  Wire.begin(SSD1306_SDA, SSD1306_SCL);
  while (!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_ADDR)) {
    Serial.println("Waiting Monitor");
    blink_led(100);
  }
  display.clearDisplay();

  tickerTimer.attach_ms(DELAY_FRAME, onTimer);
}

void IRAM_ATTR onTimer() {
  flagFrame = true;
  cntBlinkLed++;
  if (cntBlinkLed == 16) {
    cntBlinkLed = 0;
    flagBlinkLed = true;
  }
}

void loop() {
  if (flagFrame) {
    flagFrame = false;

    drawFrame(gifs[currentGifIndex], currentFrame);

    currentFrame++;

    if (currentFrame >= gifs[currentGifIndex]->frame_count) {
      currentFrame = 0;
      currentGifIndex++;

      if (currentGifIndex >= GIF_COUNT) {
        currentGifIndex = 1;
      }
    }
  }
  if (flagBlinkLed) {
    static bool status = true;
    flagBlinkLed = false;

    status = !status;
    digitalWrite(LED_PIN, status);
  }
}

void blink_led(int time) {
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}

void drawFrame(const AnimatedGIF* gif, uint8_t frame) {
  display.clearDisplay();

  for (uint16_t y = 0; y < gif->height; y++) {
    for (uint16_t x = 0; x < gif->width; x++) {
      uint16_t byteIndex = y * ((gif->width + 7) / 8) + (x / 8);
      uint8_t bitIndex = 7 - (x % 8);
      if (pgm_read_byte(&gif->frames[frame][byteIndex]) & (1 << bitIndex)) {
        display.drawPixel(x, y, SSD1306_WHITE);
      }
    }
  }

  display.display();
}