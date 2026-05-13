#pragma once

#include "esphome/core/component.h"

namespace esphome {
namespace custom_mic_rtsp {

class custom_mic_rtsp : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace custom_mic_rtsp
}  // namespace esphome