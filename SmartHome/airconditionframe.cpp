#include "airconditionframe.h"
#include "ui_airconditionframe.h"

AirConditionFrame::AirConditionFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::AirConditionFrame) {
  ui->setupUi(this);
}

AirConditionFrame::~AirConditionFrame() { delete ui; }

void AirConditionFrame::ShowTime() {
  show();
  timeoutSlot();
}

void AirConditionFrame::timeoutSlot() {
  //更新数据
}

void AirConditionFrame::on_bedroomPushButton_clicked() {
  static bool statues = false;
  if (statues == false) {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_on.png)");
  } else {
    ui->bedroomPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_off.png)");
  }
  statues = !statues;
}

void AirConditionFrame::on_parlourPushButton_clicked() {
  static bool statues = false;
  if (statues == false) {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_on.png)");
  } else {
    ui->parlourPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_off.png)");
  }
  statues = !statues;
}

void AirConditionFrame::on_kitchenPushButton_clicked() {
  static bool statues = false;
  if (statues == false) {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_on.png)");
  } else {
    ui->kitchenPushButton->setStyleSheet(
        "border-image: url(:/airConditionFrame/image/air_condition_off.png)");
  }
  statues = !statues;
}
