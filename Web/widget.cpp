#include "widget.h"
#include "ui_widget.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  manager = new QNetworkAccessManager();

  connect(manager, SIGNAL(finished(QNetworkReply *)), this,
          SLOT(recvReplyHandler(QNetworkReply *)));

  yeelinkRequest.setRawHeader(
      QString("U-ApiKey").toLatin1(),
      QString("b36d241909a3db268eef175b26d40e23").toLatin1());
  yeelinkRequest.setUrl(QUrl(QString(
      "http://api.yeelink.net/v1.1/device/359635/sensor/410078/datapoints")));
  manager->get(yeelinkRequest);

  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));
  timer->start(1000);
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

void Widget::recvReplyHandler(QNetworkReply *reply) {
  // TOD:函数不被调用
  if (reply->error() == QNetworkReply::NoError) {
    QJsonDocument jd = QJsonDocument::fromBinaryData(reply->readAll());
    if (!jd.isEmpty()) {
      QVariantMap result = jd.toVariant().toMap();
      qDebug() << result["value"].toInt();
      recvStaHandler(1, result["value"].toInt());
    } else {
      qDebug() << "no data ";
    }
    /*
  QByteArray data = reply->readAll();

  QJsonDocument json = QJsonDocument::fromJson(data); // Qt5新类
  QJsonObject jo = json.object();
  if (jo.contains("value")) {
    QJsonValue jv = jo.take("value");
    recvStaHandler(1, jv.toInt());
  } else {
    qDebug() << tr("[%s] error no data").arg(__LINE__);
  }*/
  } else {
    qDebug() << reply->errorString();
  }
}

void Widget::timerHandler() {
  static int count = 0;
  static double temp = 20.5;
  count++;
  if (count == 15) {
    temp += 1;

    //构建json数据
    QJsonObject json;
    json.insert("value", temp);
    QJsonDocument document;
    document.setObject(json);
    //把json数据转换为字符数组
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QNetworkRequest request;
    //设置请求的头
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/json;charset=utf-8");
    request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
    request.setRawHeader(
        QString("U-ApiKey").toLatin1(),
        QString("b36d241909a3db268eef175b26d40e23").toLatin1());
    request.setRawHeader("Connection", "close");
    //设置请求url
    request.setUrl(QString(
        "http://api.yeelink.net/v1.1/device/359635/sensor/409773/datapoints"));
    //发送post请求
    manager->post(request, byte_array);
  }
}
