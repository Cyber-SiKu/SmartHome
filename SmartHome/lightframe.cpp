#include "lightframe.h"
#include "devicessetting.h"
#include "getstatuethread.h"
#include "ledcontrol.h"
#include "ui_lightframe.h"

extern "C" {
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
}

LightFrame::LightFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::LightFrame) {
  ui->setupUi(this);
  // 更新界面:使得灯状态变换图片变换
  show();
}

LightFrame::~LightFrame() { delete ui; }

void LightFrame::on_bedroomPushButton_clicked() {
  //  int fd;
  //  char led;
  LedControl lc;

  //  fd = open("/sys/devices/platform/leds-gpio/leds/led2/brightness",
  //  O_RDONLY);
  //  read(fd, &led, 1);
  //  if (led == '1') {
  //    bedroom_light_ = true;
  //  } else if (led == '0') {
  //    bedroom_light_ = false;
  //  } else {
  //    // run in pc not arm
  //  }

  if (bedroom_light_ == false) {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    lc.ledOn(BEDROOMLED);
  } else {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    lc.ledOff(BEDROOMLED);
  }
  bedroom_light_ = !bedroom_light_;
}

void LightFrame::on_parlourPushButton_clicked() {
  //  int fd;
  //  char led;
  LedControl lc;

  //  fd = open("/sys/devices/platform/leds-gpio/leds/led3/brightness",
  //  O_RDONLY);
  //  read(fd, &led, 1);
  //  if (led == '1') {
  //    parlour_light_ = true;
  //  } else if (led == '0') {
  //    parlour_light_ = false;
  //  } else {
  //    // run in pc not arm
  //  }
  if (parlour_light_ == false) {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    lc.ledOn(PARLOURLED);
  } else {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    lc.ledOff(PARLOURLED);
  }
  parlour_light_ = !parlour_light_;
}

void LightFrame::on_kitchenPushButton_clicked() {
  //  int fd;
  //  char led;
  LedControl lc;

  //  fd = open("/sys/devices/platform/leds-gpio/leds/led4/brightness",
  //  O_RDONLY);
  //  read(fd, &led, 1);
  //  if (led == '1') {
  //    kitchen_light_ = true;
  //  } else if (led == '0') {
  //    kitchen_light_ = false;
  //  } else {
  //    // run in pc not arm
  //  }

  if (kitchen_light_ == false) {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_on.png)");
    lc.ledOn(KITCHENLED);
  } else {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/lightFrame/image/lamp_off.png)");
    lc.ledOff(KITCHENLED);
  }
  kitchen_light_ = !kitchen_light_;
}

void LightFrame::update() {
  init();
  QFrame::update();
}

void LightFrame::init() {
  fprintf(stdout, "%s \n", __FUNCTION__);
  fflush(stdout);
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
        "border-image: url(:/lightFrame/image/lamp_off.png)");
  }
}

void LightFrame::show() {
  init();
  QFrame::show();
}
