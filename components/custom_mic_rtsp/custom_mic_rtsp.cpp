#include "esphome/core/log.h"
#include "custom_mic_rtsp.h"

namespace esphome {
namespace custom_mic_rtsp {

static const char *TAG = "custom_mic_rtsp.component";

void custom_mic_rtsp::setup() {

}

void custom_mic_rtsp::loop() {

}

void custom_mic_rtsp::dump_config(){
    ESP_LOGCONFIG(TAG, "custom_mic_rtsp");
}


}  // namespace custom_mic_rtsp
}  // namespace esphome