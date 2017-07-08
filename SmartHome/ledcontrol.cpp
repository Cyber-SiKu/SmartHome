#include "ledcontrol.h"

extern "C" {
#include "stdlib.h"
}

LedControl::LedControl(QObject *parent) : QObject(parent) {}

void LedControl::ledOn(int i) {
  QString sh(
      tr("echo 1 > /sys/devices/platform/leds-gpio/leds/led%1/brightness")
          .arg(i));
  system(sh.toLatin1().data());
}

void LedControl::ledOff(int i) {
  QString sh(
      tr("echo 0 > /sys/devices/platform/leds-gpio/leds/led%1/brightness")
          .arg(i));
  system(sh.toLatin1().data());
}

void LedControl::ledControl(int i, int state) {
  if (state) {
    ledOn(i);
  } else {
    ledOff(i);
  }
}
