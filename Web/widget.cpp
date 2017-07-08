#include "widget.h"
#include "getstatuethread.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  ui->label->setText("off");
  ui->label_2->setText("off");
  ui->label_3->setText("off");
  ui->label_4->setText("off");
  ui->label_5->setText("off");
  GetStatueThread *gst = new GetStatueThread();
  connect(gst, SIGNAL(stateSingnal(int, int)), this,
		  SLOT(recvStaHandler(int, int)));
  gst->run();
}

Widget::~Widget() { delete ui; }

void Widget::recvStaHandler(int num, int on) {
  if (on) {
	switch (num) {
	case 0:
	  ui->label->setText("on");
	  break;
	case 1:
	  ui->label_2->setText("on");
	  break;
	case 2:
	  ui->label_3->setText("on");
	  break;
	case 3:
	  ui->label_4->setText("on");
	  break;
	case 4:
	  ui->label_5->setText("on");
	  break;
	}
  } else {
	switch (num) {
	case 0:
	  ui->label->setText("off");
	  break;
	case 1:
	  ui->label_2->setText("off");
	  break;
	case 2:
	  ui->label_3->setText("off");
	  break;
	case 3:
	  ui->label_4->setText("off");
	  break;
	case 4:
	  ui->label_5->setText("off");
	  break;
	}
  }
}
