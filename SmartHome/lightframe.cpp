#include "lightframe.h"
#include "ledcontrol.h"
#include "ui_lightframe.h"

extern "C" {
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
}

LightFrame::LightFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::LightFrame) {
  ui->setupUi(this);
  int fd;
  char led;

  fd = open("/sys/devices/platform/leds-gpio/leds/led2/brightness", O_RDONLY);
  read(fd, &led, 1);
  if (led == '1') {
    bedroom_light_ = true;
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
  } else {
    bedroom_light_ = false;
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
  }

  fd = open("/sys/devices/platform/leds-gpio/leds/led3/brightness", O_RDONLY);
  read(fd, &led, 1);
  if (led == '1') {
    parlour_light_ = true;
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
  } else {
    parlour_light_ = false;
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
  }

  fd = open("/sys/devices/platform/leds-gpio/leds/led4/brightness", O_RDONLY);
  read(fd, &led, 1);
  if (led == '1') {
    kitchen_light_ = true;
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
  } else {
    kitchen_light_ = false;
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
  }
}

LightFrame::~LightFrame() { delete ui; }

void LightFrame::on_bedroomPushButton_clicked() {
  LedControl led;
  if (bedroom_light_ == false) {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    led.ledOn(2);
  } else {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    led.ledOff(2);
  }
  bedroom_light_ = !bedroom_light_;
}

void LightFrame::on_parlourPushButton_clicked() {
  LedControl led;
  if (parlour_light_ == false) {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    led.ledOn(3);
  } else {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    led.ledOff(3);
  }
  parlour_light_ = !parlour_light_;
}

void LightFrame::on_kitchenPushButton_clicked() {
  LedControl led;
  if (kitchen_light_ == false) {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    led.ledOn(4);
  } else {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    led.ledOff(4);
  }
  kitchen_light_ = !kitchen_light_;
}
