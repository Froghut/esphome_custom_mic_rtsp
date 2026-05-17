#include "esphome/core/log.h"
#include "custom_mic_rtsp.h"

namespace esphome {
namespace custom_mic_rtsp {

static const char *TAG = "custom_mic_rtsp.component";

void custom_mic_rtsp::doInit() {

    ESP_LOGD(TAG, "init 1");
    I2SStream i2s; // Access I2S as stream
    VolumeStream vol(i2s);
    RTSPAudioSource source(vol); // IAudioSource for RTSP
    RTSPAudioStreamer<RTSPPlatformWiFi> streamer(source); // Stream audio via RTSP
    RTSPServer<RTSPPlatformWiFi> rtsp(streamer, port, -1);

    
    ESP_LOGD(TAG, "init 2");
    delay(1);
    /*// setup Audioi2s input
    auto cfg = i2s.defaultConfig(RX_MODE);
    cfg.channels = this->channels;
    cfg.sample_rate = this->samples_per_second;
    cfg.use_apll = false;
    //cfg.auto_clear = true;
    cfg.buffer_size = 512;
    cfg.buffer_count = 16;
    cfg.pin_ws = 5; // WS
    cfg.pin_data = 6; // SD
    cfg.pin_bck = 7; // SCK
    //i2s.begin(cfg);

    ESP_LOGD(TAG, "init 3");    
    delay(1);
    auto vcfg = vol.defaultConfig();
    vcfg.channels = 1;
    vcfg.allow_boost = true;
    vcfg.volume = this->volume;
    vol.begin(vcfg);

    //rtsp.begin();

    ESP_LOGD(TAG, "init 4");
    delay(1);

    */
}

void custom_mic_rtsp::dump_config(){
    ESP_LOGCONFIG(TAG, "custom_mic_rtsp");
}

float custom_mic_rtsp::get_setup_priority() const {
    return -100;
}


}  // namespace custom_mic_rtsp
}  // namespace esphome