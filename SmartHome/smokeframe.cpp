#include "smokeframe.h"
#include "ui_somkeframe.h"

SmokeFrame::SmokeFrame(QWidget *parent)
    : QFrame(parent), ui(new Ui::SomkeFrame) {
  ui->setupUi(this);

  bedroomSmoke = 16;
  parlourSmoke = 26;
  kitckenSmoke = 30;

  //添加计时器1s刷新一次数据
  timer = new QTimer(this);
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

SmokeFrame::~SmokeFrame() { delete ui; }

void SmokeFrame::ShowTime() {
  show();
  timeoutSlot();
}
void SmokeFrame::timeoutSlot() {}
