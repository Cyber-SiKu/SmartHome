#include "mainframe.h"
#include "ui_mainframe.h"

#include <QDateTime>

MainFrame::MainFrame(QWidget *parent) : QFrame(parent), ui(new Ui::MainFrame) {
  ui->setupUi(this);
  timeoutSlot();
  //添加计时器1s刷新一次lcd
  timer = new QTimer(this);
  timer->start(1000);
  connect(timer, SIGNAL(timeout()), this, SLOT(timeoutSlot()));
}

MainFrame::~MainFrame() { delete ui; }

void MainFrame::ShowTime() {
  show();
  timeoutSlot();
}

void MainFrame::timeoutSlot() {
  QDateTime date = QDateTime::currentDateTime();
  QString dateStr = date.toString(QString("hh:mm:ss"));
  ui->lcdNumber->display(dateStr);
}
