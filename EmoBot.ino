#include "utils.h"

void blink_led(int time);
void setupI2S();

const int wav_data_start = 44;
const int wav_data_len = sizeof(Emo_default_wav) - wav_data_start;


void playWav(const unsigned char* wav, unsigned int len,  float volume_factor = 5.0) {
  size_t bytes_written = 0;
  unsigned int pos = 44;
  const int chunk = DMA_BUF_LEN;

  while (pos < len) {
    int to_write = (len - pos) > chunk ? chunk : (len - pos);
    int16_t temp_buf[DMA_BUF_LEN / 2]; 

    for (int i = 0; i < to_write / 2; i++) {
      int16_t sample = ((int16_t*)wav)[(pos / 2) + i]
      int32_t amplified = (int32_t)(sample * volume_factor);
      if (amplified > 32767) amplified = 32767;
      if (amplified < -32768) amplified = -32768;
      temp_buf[i] = (int16_t)amplified;
    }

    i2s_write(I2S_NUM_0, temp_buf, to_write, &bytes_written, portMAX_DELAY);

    pos += bytes_written;
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  setupI2S();

  playWav(Emo_default_wav, Emo_default_wav_len, 10);
}

void loop() {

}

void setupI2S() {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S_MSB,
    .intr_alloc_flags = 0,
    .dma_buf_count = 8,
    .dma_buf_len = DMA_BUF_LEN,
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

  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
  i2s_zero_dma_buffer(I2S_NUM_0);
}