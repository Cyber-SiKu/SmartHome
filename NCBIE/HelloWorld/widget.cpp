#include "widget.h"
#include "getswichstatuesfromserver.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  //
  QPixmap *pix1 = new QPixmap(
      QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_off.png"));
  *pix1 = pix1->scaled(ui->lable_light_1->size());
  ui->lable_light_1->setPixmap(*pix1);
  ui->lable_light_2->setPixmap(*pix1);

  // create one thread
  GetSwichStatuesFromServer *gssfs = new GetSwichStatuesFromServer();
  // let new thred to run
  gssfs->start();
  connect(gssfs, SIGNAL(switchSignal(bool)), this,
          SLOT(recvSwithFlagHandler(bool)));
}

Widget::~Widget() { delete ui; }

void Widget::recvSwithFlagHandler(bool on) {
  if (on) {
    QPixmap *pix1 = new QPixmap(
        QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_on.png"));
    *pix1 = pix1->scaled(ui->lable_light_1->size());
    ui->lable_light_1->setPixmap(*pix1);
    ui->lable_light_2->setPixmap(*pix1);
  } else {
    QPixmap *pix1 = new QPixmap(
        QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_off.png"));
    *pix1 = pix1->scaled(ui->lable_light_1->size());
    ui->lable_light_1->setPixmap(*pix1);
    ui->lable_light_2->setPixmap(*pix1);
  }
}
