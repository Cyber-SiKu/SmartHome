#ifndef AIRCONDITIONFRAME_H
#define AIRCONDITIONFRAME_H

#include <QFrame>

namespace Ui {
class AirConditionFrame;
}

class AirConditionFrame : public QFrame {
  Q_OBJECT

public:
  explicit AirConditionFrame(QWidget *parent = 0);
  ~AirConditionFrame();
  //重写show函数使得数据能够1s刷新1次
  void ShowTime();

private slots:
  void on_bedroomPushButton_clicked();

  void on_parlourPushButton_clicked();

  void on_kitchenPushButton_clicked();

private:
  Ui::AirConditionFrame *ui;
  QTimer *timer;
  double bedroomAirCondition;
  double parlourAirCondition;
  double kitckenAirCondition;
  //使温度动态显示
  void timeoutSlot();
};

#endif // AIRCONDITIONFRAME_H
