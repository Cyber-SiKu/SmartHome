#ifndef GETSTATUETHREAD_H
#define GETSTATUETHREAD_H

#include "devicessetting.h"
#include <QThread>

class GetStatueThread : public QThread {
  Q_OBJECT
public:
  GetStatueThread();
signals:
  void statueSignal(int id, int state);

private:
  void run();
};

#endif // GETSTATUETHREAD_H
