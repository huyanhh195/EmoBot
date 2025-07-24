#include "utils.h"

void blink_led(int time);
void playGIF(const AnimatedGIF* gif); 

void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = true,
    .fixed_mclk = 0
  };

  i2s_pin_config_t pin_config = {
    .bck_io_num = MAX98375A_BCLK,
    .ws_io_num = MAX98375A_LRCLK,
    .data_out_num = MAX98375A_DOUT,
    .data_in_num = I2S_PIN_NO_CHANGE
  };

  i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM, &pin_config);
  i2s_zero_dma_buffer(I2S_NUM);
}

void playTone(float frequency, int duration_ms) {
  if (frequency <= 0) {
    delay(duration_ms);
    return;
  }

  int samples_per_cycle = SAMPLE_RATE / frequency;
  int cycles = (SAMPLE_RATE * duration_ms) / 1000 / samples_per_cycle;

  int16_t sample_high = 16000;
  int16_t sample_low = -16000;

  size_t bytes_written;

  for (int i = 0; i < cycles; ++i) {
    for (int j = 0; j < samples_per_cycle; ++j) {
      int16_t sample = (j < samples_per_cycle / 2) ? sample_high : sample_low;
      i2s_write(I2S_NUM, (const char*)&sample, sizeof(sample), &bytes_written, portMAX_DELAY);
    }
  }
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  setupI2S();

}

void loop() {
  for (int i = 0; melody[i].freq >= 0; i++) {
    playTone(melody[i].freq, NOTE_DURATION_MS);
    delay(50);  
  }
  delay(1000);
}

void blink_led(int time){
  digitalWrite(LED_PIN, HIGH);
  delay(time);
  digitalWrite(LED_PIN, LOW);
  delay(time);
}

void playGIF(const AnimatedGIF* gif, uint16_t delays) {
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
    delay(delays);
  }
}