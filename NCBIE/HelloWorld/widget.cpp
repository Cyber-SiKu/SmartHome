#include "widget.h"
#include "getswichstatuesfromserver.h"
#include "ui_widget.h"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  //
  QPixmap *pix1 = new QPixmap(
      QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_off.png"));
  //  *pix1 = pix1->scaled(ui->lable_light_1->size());
  //  ui->lable_light_1->setPixmap(*pix1);
  //  ui->lable_light_2->setPixmap(*pix1);

  // create one thread
  GetSwichStatuesFromServer *gssfs = new GetSwichStatuesFromServer();
  // let new thred to run
  gssfs->start();
  connect(gssfs, SIGNAL(switchSignal(bool)), this,
          SLOT(recvSwithFlagHandler(bool)));

  // /root/image/xxx.png
  QPixmap *tempBtnPix = new QPixmap(QString("/root/images/temp_btn.png"));
  ui->tempbutton->setIcon((QIcon(*tempBtnPix)));
}

MainWidget::~MainWidget() { delete ui; }

void MainWidget::recvSwithFlagHandler(bool on) {
  //  if (on) {
  //    QPixmap *pix1 = new QPixmap(
  //        QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_on.png"));
  //    //    *pix1 = pix1->scaled(ui->lable_light_1->size());
  //    //    ui->lable_light_1->setPixmap(*pix1);
  //    //    ui->lable_light_2->setPixmap(*pix1);
  //    //  } else {
  //    //    QPixmap *pix1 = new QPixmap(
  //        QString("/home/uplooking/SmartHome/NCBIE/HelloWorld/img/lamp_off.png"));
  //        //    *pix1 = pix1->scaled(ui->lable_light_1->size());
  //        //    ui->lable_light_1->setPixmap(*pix1);
  //        //    ui->lable_light_2->setPixmap(*pix1);
  //        //  }
}
