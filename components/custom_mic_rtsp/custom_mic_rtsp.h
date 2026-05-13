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

  I2SStream i2s; // Access I2S as stream
  VolumeStream vol(this->i2s);
  RTSPAudioSource source(this->vol); // IAudioSource for RTSP
  RTSPAudioStreamer<RTSPPlatformWiFi> streamer(this->source); // Stream audio via RTSP
  RTSPServer<RTSPPlatformWiFi> rtsp(this->streamer, port, -1);

  void setup() override;
  void dump_config() override;
  
};


}  // namespace custom_mic_rtsp
}  // namespace esphome