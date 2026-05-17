#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "AudioTools.h"
#include "AudioTools/Communication/RTSP.h"


namespace esphome {
namespace custom_mic_rtsp {

class custom_mic_rtsp : public Component {
 public:
  int port = 554;
  int channels = 1;
  int samples_per_second = 16000;

  void dump_config() override;
  void doInit();

  void set_volume(float volume) { this->volume = volume;}

  float get_setup_priority() const override;
  
protected:
  float volume;
  RTSPServerTaskless<RTSPPlatformWiFi> *_rtsp;
};

template<typename... Ts> class DoInitAction : public Action<Ts...> {
 public:
  explicit DoInitAction(custom_mic_rtsp *ea) : ea_(ea) {}

  void play(Ts... x) override {
    this->ea_->doInit();
  }

 protected:
  custom_mic_rtsp *ea_;
};

}  // namespace custom_mic_rtsp
}  // namespace esphome