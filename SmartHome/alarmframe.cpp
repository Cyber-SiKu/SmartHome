#include "alarmframe.h"
#include "buzzercontrol.h"
#include "ui_alarmframe.h"

AlarmFrame::AlarmFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::AlarmFrame) {
  ui->setupUi(this);
}

AlarmFrame::~AlarmFrame() { delete ui; }

void AlarmFrame::on_pushButton_pressed() {
  ui->pushButton->setStyleSheet(
      "border-image: url(:/alarmFrame/image/buzzer_on.ico)");
  BuzzerControl buzzer;
  buzzer.buzzerOn();
}

void AlarmFrame::on_pushButton_released() {
  ui->pushButton->setStyleSheet(
      "border-image: url(:/alarmFrame/image/buzzer_off.ico)");
  BuzzerControl buzzer;
  buzzer.buzzerOff();
}
