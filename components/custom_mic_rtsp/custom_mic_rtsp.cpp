#include "esphome/core/log.h"
#include "custom_mic_rtsp.h"

namespace esphome {
namespace custom_mic_rtsp {

static const char *TAG = "custom_mic_rtsp.component";

void custom_mic_rtsp::setup() {

    this->i2s = I2SStream();
    this->vol = VolumeStream(this->i2s);

    // setup Audioi2s input
    auto cfg = this->i2s.defaultConfig(RX_MODE);
    cfg.channels = this->channels;
    cfg.sample_rate = this->samples_per_second;
    cfg.use_apll = false;
    //cfg.auto_clear = true;
    cfg.buffer_size = 512;
    cfg.buffer_count = 16;
    cfg.pin_ws = 5; // WS
    cfg.pin_data = 6; // SD
    cfg.pin_bck = 7; // SCK
    this->i2s.begin(cfg);

    auto vcfg = this->vol.defaultConfig();
    vcfg.channels = 1;
    vcfg.allow_boost = true;
    vcfg.volume = this->volume;
    this->vol.begin(vcfg);

    this->rtsp.begin();

}

void custom_mic_rtsp::dump_config(){
    ESP_LOGCONFIG(TAG, "custom_mic_rtsp");
}


}  // namespace custom_mic_rtsp
}  // namespace esphome