#include "utils.h"

void blink_led(int time);

void playGIF(const AnimatedGIF* gif) {
  for (uint8_t frame = 0; frame < gif->frame_count; frame++) {
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
    delay(gif->delays[frame]);
  }
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_PIN, OUTPUT);
  
  delay(1000);


  Wire.begin(SSD1306_SDA, SSD1306_SCL);
  while(!display.begin(SSD1306_SWITCHCAPVCC, SSD1306_ADDR)){
    Serial.println("Waiting Monitor");
    blink_led(100);
  }

  display.clearDisplay();
  display.display();
}

void loop() {
  playGIF(&EmoBot_Sleepy_gif);
  delay(500);
  playGIF(&EmoBot_Frustrated_gif);
  delay(500);
}

void blink_led(int time){
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}