#ifndef GETSTATUETHREAD_H
#define GETSTATUETHREAD_H

#include <QThread>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

class GetStatueThread : public QThread {
  Q_OBJECT
public:
  GetStatueThread();
  void run();

signals:
  void stateSingnal(int, int);

private slots:
  void recvReplyHandler(QNetworkReply *);

private:
  QNetworkAccessManager *manager;
  QNetworkRequest yeelinkRequest;
};

#endif // GETSTATUETHREAD_H
