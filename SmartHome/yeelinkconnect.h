#ifndef YEELINKCONNECT_H
#define YEELINKCONNECT_H

#include <QTimer>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

//定义yeelink服务器api格式
#define URL_YEELINK "http://api.yeelink.net/v1.1/device/%1/sensor/%2/datapoints"

class YeelinkConnect {
public:
  YeelinkConnect(QWidget *parent);

  /*
  函数功能：向yeelink服务器上传数据
  参数：
  UApiKey：yeelink中的api key
  device：设备号
  sensor：传感器
  data：要上传的数据
  */
  int setSensorData(const QString &UApiKey, const QString &device,
					const QString &sensor, const double &data);

  /*
  函数功能：设置开关状态
  参数：
								UApiKey：yeelink中的api key
  device：设备
  sensor：传感器
  status：开关的状态
  */
  int setSensorStatus(const QString &UApiKey, const QString &device,
					  const QString &sensor, const int &status);

  /*
  函数功能：从yeelink服务器获取开关状态
  参数：
  UApiKey：yeelink中的api key
  device：设备
  sensor：传感器
  */
  int getSensorStatus(const QString &UApiKey, const QString &device,
					  const QString &sensor);
  /*
   * 函数功能,调用完getSensorStatus()后调用此函数
   * 返回QJsonValue类型的数据
   * 判断数据类型
  */
  QJsonValue getSensorStatusValue(QNetworkReply *reply);

private:
  QNetworkAccessManager *networkAccessManager;
  QNetworkRequest request;
};

#endif // YEELINKCONNECT_H
