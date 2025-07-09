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

void heart() {
  display.clearDisplay();

  int x1 = 44;
  int y1 = 27;
  int radius1 = 10;

  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);

  int x2 = 84;
  int y2 = 27;
  int radius2 = 10;

  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);

  //smile
  display.fillCircle(64, 50, 12, WHITE);    // full smile
  display.fillRect(0, 38, 128, 12, BLACK);  // hide top half of smile

  display.display();
  delay(4000);

  //blink
  display.clearDisplay();

  //smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);

  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);
  display.display();
  delay(100);
  display.clearDisplay();

  //smile
  display.fillCircle(64, 50, 12, WHITE);    // full smile
  display.fillRect(0, 38, 128, 12, BLACK);  // hide top half of smile


  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);

  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);

  display.display();
  delay(4000);

  //blink
  display.clearDisplay();
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);

  //smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);

  display.display();
  delay(100);
  display.clearDisplay();

  // Draw the left heart
  display.fillTriangle(x1 - radius1, y1, x1, y1 + radius1, x1 + radius1, y1, WHITE);
  display.fillCircle(x1 - 5, y1, 5.5, WHITE);
  display.fillCircle(x1 + 5, y1, 5.5, WHITE);

  // Draw the right heart
  display.fillTriangle(x2 - radius2, y2, x2, y2 + radius2, x2 + radius2, y2, WHITE);
  display.fillCircle(x2 - 5, y2, 5.5, WHITE);
  display.fillCircle(x2 + 5, y2, 5.5, WHITE);

  //smile
  display.fillCircle(64, 50, 12, WHITE);    // full smile
  display.fillRect(0, 38, 128, 12, BLACK);  // hide top half of smile


  display.display();
  delay(4000);

  //blink
  display.clearDisplay();

  display.clearDisplay();
  display.fillRect(44, 28, 10, 4, WHITE);
  display.fillRect(76, 28, 10, 4, WHITE);

  //smallest mouth
  display.fillRect(54, 54, 22, 4, WHITE);

  display.display();
  delay(100);
  display.clearDisplay();
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
  heart();
}

