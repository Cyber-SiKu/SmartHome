#include "lampops.h"

LampOps::LampOps(QObject *parent) : QObject(parent)
{

}

void LampOps::lampOn(int no)
{
    switch (no) {
    case 0:
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led1/brightness");
        break;
    case 1:
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
        break;
    case 2:
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
        break;
    case 3:
        system("echo 1 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
        break;
    default:
        break;
    }
}

void LampOps::lampOff(int no)
{
    switch (no) {
    case 0:
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led1/brightness");
        break;
    case 1:
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led2/brightness");
        break;
    case 2:
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led3/brightness");
        break;
    case 3:
        system("echo 0 > /sys/devices/platform/leds-gpio/leds/led4/brightness");
        break;
    default:
        break;
    }
}
