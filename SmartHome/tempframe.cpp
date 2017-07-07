#include "tempframe.h"
#include "ui_tempframe.h"

TempFrame::TempFrame(QWidget *parent) : QFrame(parent), ui(new Ui::TempFrame) {
  ui->setupUi(this);

  bedroomTemp = 16;
  parlourTemp = 26;
  kitckenTemp = 30;

  //添加计时器1s刷新一次数据
  timer = new QTimer(this);
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

TempFrame::~TempFrame() { delete ui; }

void TempFrame::ShowTime() {
  show();
  timeoutSlot();
}

void TempFrame::timeoutSlot() {
  bedroomTemp = bedroomTemp + 0.1;
  ui->bedroomTempProgressBar->setValue(bedroomTemp);
  ui->bedroomTemp->setText(QString::number(bedroomTemp));

  parlourTemp = parlourTemp + 0.1;
  ui->parlourTempProgressBar->setValue(parlourTemp);
  ui->parlourTemp->setText(QString::number(parlourTemp));

  kitckenTemp = kitckenTemp + 0.1;
  ui->kitchenTempProgressBar->setValue(kitckenTemp);
  ui->kitchenTemp->setText(QString::number(kitckenTemp));
}
