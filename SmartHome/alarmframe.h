#ifndef ALARMFRAME_H
#define ALARMFRAME_H

#include <QFrame>

namespace Ui {
class AlarmFrame;
}

class AlarmFrame : public QFrame {
  Q_OBJECT

public:
  explicit AlarmFrame(QWidget *parent = 0);
  ~AlarmFrame();

private slots:
  void on_pushButton_pressed();

  void on_pushButton_released();

private:
  Ui::AlarmFrame *ui;
};

#endif // ALARMFRAME_H
