#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI 23
#define OLED_CLK  18
#define OLED_DC   17
#define OLED_CS   5
#define OLED_RESET 16
#define LED_PIN 2 

Adafruit_SSD1306 display(128, 64, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void blink_led(int time){
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}
void blinkEye(){
  int leftX = 40;
  int rightX = 88;
  int eyeY = 32;
  int eyeRadius = 10;

  display.clearDisplay();
  display.fillCircle(leftX, eyeY, eyeRadius, SSD1306_WHITE);
  display.fillCircle(rightX, eyeY, eyeRadius, SSD1306_WHITE);
  display.display();
  delay(2000);

  for (int r = eyeRadius; r >= 1; r--) {
    display.clearDisplay();
    display.fillRect(leftX - r, eyeY, 2 * r, 2, SSD1306_WHITE);  // mắt trái thành đường thẳng
    display.fillRect(rightX - r, eyeY, 2 * r, 2, SSD1306_WHITE); // mắt phải
    display.display();
    delay(30);
  }

  delay(300);

  display.clearDisplay();
  display.fillCircle(leftX, eyeY, eyeRadius, SSD1306_WHITE);
  display.fillCircle(rightX, eyeY, eyeRadius, SSD1306_WHITE);
  display.display();
  delay(2000);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(1000);

  while(!display.begin(SSD1306_SWITCHCAPVCC)){
    Serial.println("Waiting Monitor");
    blink_led(100);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
}


void loop() {
  blinkEye();
}

