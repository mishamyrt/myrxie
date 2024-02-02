#pragma once

#include <MyrtIO.h>
#include <platform.h>
#include <Timer.h>
#include "interfaces/features.h"

class ClockFeature : public IOFeature {
public:

  ClockFeature();

  // Handles the primary tasks
  void onTask();

  uint8_t code();

  // Handles action requests
  bool onAction(IOActionRequest* request);

private:
  LEDPlatform* leds_ = IO_INJECT(LEDPlatform);
  RTCPlatform* rtc_ = IO_INJECT(RTCPlatform);

  bool handleSetTime_(IOActionRequest* request);
};
