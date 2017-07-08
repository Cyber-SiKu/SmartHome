#include "buzzercontrol.h"
#include "devicessetting.h"

extern "C" {
#include <stdlib.h>
}

BuzzerControl::BuzzerControl(QObject *parent) : QObject(parent) {}

void BuzzerControl::buzzerOn() {
  system("echo 1 > /sys/devices/platform/x6818-beep/state");
}

void BuzzerControl::buzzerOff() {
  system("echo 0 > /sys/devices/platform/x6818-beep/state");
}

void BuzzerControl::buzzerControl(int state) {
  if (state == 1) {
    buzzerOn();
  } else {
    buzzerOff();
  }
}
