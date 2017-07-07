#include "mainwidget.h"
#include "QPixmap"
#include "framesetting.h"
#include "mainframe.h"
#include "moistureframe.h"
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

void MainWidget::on_tempButton_clicked() {
  emit PushButtonUpdate();
  ui->tempButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/temp_btn_select.png);");
  delete ui->frame;
  ui->frame = new TempFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
}

void MainWidget::on_smokeButton_clicked() {
  emit PushButtonUpdate();
  // TODO
}

void MainWidget::on_moistureButton_clicked() {
  emit PushButtonUpdate();
  ui->moistureButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/huminity_btn_select.png);");
  delete ui->frame;
  ui->frame = new MoistureFrame(this);
  ui->frame->setGeometry(FRAME_X, FRAME_Y, FRAME_WIDTH, FRAME_HEIGHT);
}

void MainWidget::updatePushButton() {
  ui->tempButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/temp_btn.png);");
  ui->moistureButton->setStyleSheet(
      "border-image: url(:/mainWidget/image/humidity_btn.png);");
}
