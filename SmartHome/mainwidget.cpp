#include "mainwidget.h"
#include "QPixmap"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);

  //设置背景
  QPalette backgroundPalette;
  backgroundPalette.setBrush(
      QPalette::Background,
      QBrush(QPixmap(":/main/prefix/image/maindesk.png").scaled(1024, 600)));
  this->setPalette(backgroundPalette);

  //  //设置温度按钮
  //  //  QPalette PushButtonPalette;
  //  //  PushButtonPalette.setBrush(
  //  //      QPalette::Button,
  //  QBrush(QPixmap("/image/temp_btn.png").scaled(150,
  //  //      70)));
  //  //  ui->tempButton->setPalette(PushButtonPalette);
  //  ui->tempButton->setIcon(QIcon(tr("/image/temp_btn.png")));
  //  ui->tempButton->setIconSize(ui->tempButton->size());
  //  ui->tempButton->setFlat(true);

  //  //设置湿度按钮
  //  ui->moistureButton->setIcon(QIcon(tr("/image/humidity_btn.png")));
  //  ui->moistureButton->setIconSize(ui->tempButton->size());
  //  ui->moistureButton->setFlat(true);

  //  //设置烟雾按钮
  //  ui->smokeButton->setIcon(QIcon(tr("/image/smoke_btn.png")));
  //  ui->smokeButton->setIconSize(ui->tempButton->size());
  //  ui->smokeButton->setFlat(true);

  //  //设置空调按钮
  //  ui->AirConditionerButton->setIcon(QIcon(tr("/image/air_condition_btn.png")));
  //  ui->AirConditionerButton->setIconSize(ui->tempButton->size());
  //  ui->AirConditionerButton->setFlat(true);
}

MainWidget::~MainWidget() { delete ui; }
