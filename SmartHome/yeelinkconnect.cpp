#include "yeelinkconnect.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>

YeelinkConnect::YeelinkConnect(QWidget *parent) : QWidget(parent) {

  networkAccessManager = new QNetworkAccessManager(parent);
  //  QObject::connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)),
  //                   this, SLOT(getSensorStatusValue(QNetworkReply *)));
  devices_status_ = "NULL";
}

int YeelinkConnect::setSensorData(const QString &UApiKey, const QString &device,
                                  const QString &sensor, const double &data) {
  //构建字符数组
  QJsonObject json;
  json.insert("value", data);
  QJsonDocument document;
  document.setObject(json);
  //把json数据转化成字符数组
  QByteArray byteArray = document.toJson(QJsonDocument::Compact);
  QNetworkRequest request;
  //设置请求头
  request.setHeader(QNetworkRequest::ContentTypeHeader,
                    "application/json;charset=utf-8");
  request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
  request.setRawHeader(QString("U-ApiKey").toLatin1(), UApiKey.toLatin1());
  request.setRawHeader("Connection", "close");
  //设置请求url
  request.setUrl(
      QObject::tr("http://api.yeelink.net/v1.1/device/%1/sensor/%2/datapoints")
          .arg(device, sensor));
  //发送post请求
  this->networkAccessManager->post(request, byteArray);
  return 1;
}

int YeelinkConnect::setSensorStatus(const QString &UApiKey,
                                    const QString &device,
                                    const QString &sensor, const int &status) {
  //构建字符数组
  QJsonObject json;
  json.insert("value", status);
  QJsonDocument document;
  document.setObject(json);
  //把json数据转化成字符数组
  QByteArray byteArray = document.toJson(QJsonDocument::Compact);
  QNetworkRequest request;
  //设置请求头
  request.setHeader(QNetworkRequest::ContentTypeHeader,
                    "application/json;charset=utf-8");
  request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
  request.setRawHeader(QString("U-ApiKey").toLatin1(), UApiKey.toLatin1());
  request.setRawHeader("Connection", "close");
  //设置请求url
  request.setUrl(QString(
      QObject::tr("http://api.yeelink.net/v1.1/device/%1/sensor/%2/datapoints")
          .arg(device, sensor)));
  //发送post请求
  this->networkAccessManager->post(request, byteArray);
  return 1;
}

void YeelinkConnect::getSensorStatus(const QString &UApiKey,
                                     const QString &device,
                                     const QString &sensor) {
  request.setRawHeader(QString("U-ApiKey").toLatin1(), UApiKey.toLatin1());
  request.setUrl(QUrl(QString(
      QObject::tr("http://api.yeelink.net/v1.1/device/%1/sensor/%2/datapoints")
          .arg(device, sensor))));
}

void YeelinkConnect::getSensorStatusValue(QNetworkReply *reply) {
  if (reply->error() == QNetworkReply::NoError) {
    //	QJsonDocument json =
    //		QJsonDocument::fromBinaryData(reply->readAll());
    QJsonObject obj = QJsonDocument::fromBinaryData(reply->readAll()).object();
    if (obj.contains("value")) {
      devices_status_ = obj["value"].toString();
    } else {
      qDebug() << obj.isEmpty();
    }
  } else {
    qDebug() << reply->error();
  }
}
