#pragma once

#include "esphome/core/component.h"
#include "AudioTools.h"
#include "AudioTools/Communication/RTSP.h"

namespace esphome {
namespace custom_mic_rtsp {

class custom_mic_rtsp : public Component {
 public:
  int port = 554;
  int channels = 1;
  int samples_per_second = 16000;

  void setup() override;
  void dump_config() override;

  void set_volume(float volume) { this->volume = volume;}

protected:
  float volume;
  
};


}  // namespace custom_mic_rtsp
}  // namespace esphome