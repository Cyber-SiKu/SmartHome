#include "mainwidget.h"
#include "QPixmap"
#include "mainframe.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent), ui(new Ui::MainWidget) {
  ui->setupUi(this);
  delete ui->frame;
  ui->frame = new MainFrame(this);
  ui->frame->setGeometry(160, 20, 850, 480);
}

MainWidget::~MainWidget() { delete ui; }
