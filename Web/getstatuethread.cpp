#include "getstatuethread.h"

#include <QDebug>

extern "C" {
#include <unistd.h>
}
GetStatueThread::GetStatueThread() {
  this->manager = new QNetworkAccessManager();
}

void GetStatueThread::recvReplyHandler(QNetworkReply *reply) {
  // TODO:函数不被调用
  if (reply->error() == QNetworkReply::NoError) {
	QByteArray b = reply->readAll();
	qDebug() << b;
  } else {
	qDebug() << reply->errorString();
  }
}

void GetStatueThread::run() {
  //  this->manager = new QNetworkAccessManager();

  connect(manager, SIGNAL(finished(QNetworkReply *)), this,
		  SLOT(recvReplyHandler(QNetworkReply *)));

  yeelinkRequest.setRawHeader(
	  QString("U-ApiKey").toLatin1(),
	  QString("b36d241909a3db268eef175b26d40e23").toLatin1());
  yeelinkRequest.setUrl(QUrl(QString(
	  "http://api.yeelink.net/v1.1/device/359635/sensor/410078/datapoints")));
  //  while (1) {
  manager->get(yeelinkRequest);
  //  sleep(10);
  //  }
  //循环不出界面
  //访问yeelink服务器
}
