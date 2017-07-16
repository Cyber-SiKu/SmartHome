#include "mainwidget.h"
#include "QMessageBox"
#include "QPixmap"
#include "airconditionframe.h"
#include "alarmframe.h"
#include "buzzercontrol.h"
#include "framesetting.h"
#include "getstatuethread.h"
#include "getstatuethread.h"
#include "ledcontrol.h"
#include "lightframe.h"
#include "mainframe.h"
#include "moistureframe.h"
#include "smokeframe.h"
#include "tempframe.h"
#include "ui_mainwidget.h"

#include <QDebug>
#include <typeinfo>

extern "C" {
#include <stdio.h>
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);

  delete ui->frame;
  ui->frame = new MainFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
  connect(this, SIGNAL(PushButtonUpdate()), this, SLOT(updatePushButton()));

  GetStatueThread *gt = new GetStatueThread();
  gt->start();
  connect(gt, SIGNAL(statueSignal(int, int)), this,
          SLOT(getSatesSignalHandler(int, int)));
  yc = new YeelinkConnect(this);
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));
  timer->start(1000);
  QObject::connect(yc->networkAccessManager, SIGNAL(finished(QNetworkReply *)),
                   yc, SLOT(getSensorStatusValue(QNetworkReply *)));
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

void MainWidget::getSatesSignalHandler(int id, int state) {
  BuzzerControl bc;
  LedControl lc;
  switch (id) {
  case BUZZER:
    bc.buzzerControl(state);
    break;
  case BEDROOMLED:
  case PARLOURLED:
  case KITCHENLED:
    lc.ledControl(id, state);
    break;
  default:
    fprintf(stderr, "%s\n", "undefined device!");
    fflush(stderr);
    break;
  }

  //动态类型检查 判断当前界面是否为照明界面
  try {
    LightFrame &lf = dynamic_cast<LightFrame &>(*ui->frame);
    lf.update();
    qDebug() << "照明界面";
  } catch (std::bad_cast &) {
  }
}

void MainWidget::timerHandler() {
  /*
"118.190.25.51", "359635", "410077",
                              "b36d241909a3db268eef175b26d40e23"
*/
  yc->getSensorStatus("b36d241909a3db268eef175b26d40e23", "359635", "410077");
  yc->networkAccessManager->get(yc->request);
  //  qDebug() << __FUNCTION__ << yc->devices_status_;
}
