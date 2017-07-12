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

signals:
  void stateSingnal(int, int);

private slots:
  void recvReplyHandler(QNetworkReply *);


private:
  QNetworkRequest yeelinkRequest;
  QNetworkAccessManager *manager;
};

#endif // GETSTATUETHREAD_H
