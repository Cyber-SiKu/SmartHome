#ifndef SMOKEFRAME_H
#define SMOKEFRAME_H

#include <QFrame>
#include <QTimer>

namespace Ui {
class SomkeFrame;
}

class SmokeFrame : public QFrame {
  Q_OBJECT

public:
  explicit SmokeFrame(QWidget *parent = 0);
  ~SmokeFrame();
  //重写show函数使得数据能够1s刷新1次
  void ShowTime();

private:
  Ui::SomkeFrame *ui;
  QTimer *timer;
  double bedroomSmoke;
  double parlourSmoke;
  double kitckenSmoke;
private slots:
  //使数据动态显示
  void timeoutSlot();
};

#endif // SOMKEFRAME_H
