#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

private slots:
  void recvStaHandler(int num, int on);
  void recvReplyHandler(QNetworkReply *);
  void timerHandler();

private:
  Ui::Widget *ui;
  QNetworkRequest yeelinkRequest;
  QNetworkAccessManager *manager;
  QTimer *timer;
};

#endif // WIDGET_H
