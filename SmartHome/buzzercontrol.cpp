#include "buzzercontrol.h"

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
