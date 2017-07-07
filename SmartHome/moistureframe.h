#ifndef MOISTUREFRAME_H
#define MOISTUREFRAME_H

#include <QFrame>
#include <QTimer>

namespace Ui {
class MoistureFrame;
}

class MoistureFrame : public QFrame {
  Q_OBJECT

public:
  explicit MoistureFrame(QWidget *parent = 0);
  ~MoistureFrame();
  //重写show函数使得数据能够1s刷新1次
  void ShowTime();

private:
  Ui::MoistureFrame *ui;
  //计时器
  QTimer *timer;

  double bedroomMoisture;
  double parlourMoisture;
  double kitckenMoisture;
private slots:
  //使温度动态显示
  void timeoutSlot();
};

#endif // MOISTUREFRAME_H
