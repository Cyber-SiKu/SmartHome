#include "homepage.h"
#include "QDateTime"
#include "QPixmap"
#include "QtWebEngineWidgets/QtWebEngineWidgets"
#include "ui_homepage.h"
#include <QNetworkReply>

HomePage::HomePage(QWidget *parent) : QWidget(parent), ui(new Ui::HomePage) {
  ui->setupUi(this);

  QWebEngineView *view = new QWebEngineView(this);
  view->setWindowFlags(Qt::FramelessWindowHint);
  view->setGeometry(10, 10, 640, 480);
  view->setUrl(QUrl(QString("http://192.168.200.210:8080/?action=stream")));
  view->show();

  //创建网络访问对象
  m = new QNetworkAccessManager();
  //绑定信号与槽，请求完成后调用槽函数
  connect(m, SIGNAL(finished(QNetworkReply *)), this,
		  SLOT(replyFinished(QNetworkReply *)));
}

HomePage::~HomePage() { delete ui; }

void HomePage::on_pushButton_clicked() {
  //从下面的url下载一张图片存储到文件系统
  // /home/zyli/bhht/2017-07-011_15:05:29.jpg
  // http://192.168.200.105:8080/?action=snapshot
  //创建网络请求
  QNetworkRequest request;
  //设置请求url
  request.setUrl(QUrl(QString("http://192.168.200.105:8080/?action=snapshot")));
  //开始请求
  m->get(request);
}

void HomePage::replyFinished(QNetworkReply *reply) {
  if (reply->error() == QNetworkReply::NoError) {
	QPixmap p;
	p.loadFromData(reply->readAll());
	// /home/zyli/bhht/2017-07-011_15:05:29.jpg
	QPixmap p1 = p.scaled(ui->picture->size());
	ui->picture->setPixmap(p1);
	QString name;
	name.clear();
	name.append("/home/zyli/bhht/");
	QDateTime t = QDateTime::currentDateTime();
	name.append(t.toString(QString("yyyy-MM-dd_hh:mm:ss")));
	name.append(".jpg");
	p.save(name);
  }
}

void HomePage::on_pushButton_2_clicked() {
  //  QString path = QFileDialog::getOpenFileName(this, tr("Open Image"), ".",
  //											  tr("Image
  // Files(*.jpg
  //*.png)"));
  //  if (path.length() == 0) {
  //	QMessageBox::information(NULL, tr("Path"),
  //							 tr("You didn't select
  // any
  // files."));
  //  } else {
  //	QMessageBox::information(NULL, tr("Path"), tr("You selected ") + path);
  //  }
  QString path = QFileDialog::getOpenFileName(
	  this, tr("Open Image"), ".", tr("Image Files(*.jpg *.png *.ico)"));
  if (path.length() != 0) {
	QLabel *select = new QLabel();
	select->setPixmap(QPixmap(path));
	select->show();
  } else {
	QMessageBox::information(this, "浏览图片", QString("啥也没选中"));
  }
}
