#ifndef TEMPFRAME_H
#define TEMPFRAME_H

#include <QFrame>
#include <QTimer>

namespace Ui {
class TempFrame;
}

class TempFrame : public QFrame {
  Q_OBJECT

public:
  explicit TempFrame(QWidget *parent = 0);
  ~TempFrame();
  //重写show函数使得数据能够1s刷新1次
  void ShowTime();

private:
  Ui::TempFrame *ui;
  //计时器
  QTimer *timer;

  double bedroomTemp;
  double parlourTemp;
  double kitckenTemp;
private slots:
  //使温度动态显示
  void timeoutSlot();
};

#endif // TEMPFRAME_H
