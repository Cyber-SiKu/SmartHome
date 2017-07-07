#include "moistureframe.h"
#include "ui_moistureframe.h"

MoistureFrame::MoistureFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::MoistureFrame) {
  ui->setupUi(this);
  this->show();

  bedroomMoisture = 16;
  parlourMoisture = 26;
  kitckenMoisture = 30;

  //添加计时器1s刷新一次数据
  timer = new QTimer(this);
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

MoistureFrame::~MoistureFrame() { delete ui; }

void MoistureFrame::ShowTime() {
  show();
  timeoutSlot();
}

void MoistureFrame::timeoutSlot() {
  // TODO:更新数据
}
