#include "mainwidget.h"
#include "QMessageBox"
#include "QPixmap"
#include "airconditionframe.h"
#include "alarmframe.h"
#include "framesetting.h"
#include "lightframe.h"
#include "mainframe.h"
#include "moistureframe.h"
#include "smokeframe.h"
#include "tempframe.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);

  delete ui->frame;
  ui->frame = new MainFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  connect(this, SIGNAL(PushButtonUpdate()), this, SLOT(updatePushButton()));
}

MainWidget::~MainWidget() { delete ui; }

void MainWidget::updatePushButton() {
  ui->tempButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/temp_btn.png)");
  ui->moistureButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/humidity_btn.png)");
  ui->smokeButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/smoke_btn.png)");
  ui->airConditionerButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/air_condition_btn.png)");
  ui->lightButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/lamp_btn.png)");
}

void MainWidget::on_tempButton_clicked() {
  emit PushButtonUpdate();
  ui->tempButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/temp_btn_select.png)");
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/temp_desk.png)");
  delete ui->frame;
  ui->frame = new TempFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_smokeButton_clicked() {
  emit PushButtonUpdate();
  ui->smokeButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/smoke_btn_select.png)");
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/temp_desk.png)");
  delete ui->frame;
  ui->frame = new SmokeFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_moistureButton_clicked() {
  emit PushButtonUpdate();
  ui->moistureButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/huminity_btn_select.png)");
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/humidity_desk.png)");
  delete ui->frame;
  ui->frame = new MoistureFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_airConditionerButton_clicked() {
  emit PushButtonUpdate();
  ui->airConditionerButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/air_condition_btn_select.png)");
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/air_condition_desk.png)");
  delete ui->frame;
  ui->frame = new AirConditionFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_lightButton_clicked() {
  emit PushButtonUpdate();
  ui->lightButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/lamp_btn_select.png)");
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/lamp_desk.png)");
  delete ui->frame;
  ui->frame = new LightFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_alarmButton_clicked() {
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/other_dev_desk.jpg)");
  delete ui->frame;
  ui->frame = new AlarmFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_returnButto_clicked() {
  ui->backgroundLabel->setStyleSheet(
      "background-image: url(:/mainWidget/image/maindesk.png)");
  delete ui->frame;
  ui->frame = new MainFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  ui->frame->show();
}

void MainWidget::on_exitButton_clicked() {
  QMessageBox::information(this, QString("正在退出"), QString("好再来您嫩!"));
  exit(0);
}
