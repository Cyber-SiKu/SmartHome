#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QFrame>
#include <QTimer>

namespace Ui {
class MainFrame;
}

class MainFrame : public QFrame {
  Q_OBJECT

public:
  explicit MainFrame(QWidget *parent = 0);
  ~MainFrame();
  //重写show函数使得lcd能够1s刷新1次
  void ShowTime();

private:
  Ui::MainFrame *ui;
  QTimer *timer;
private slots:
  //使lcd显示时间
  void timeoutSlot();
};

#endif // MAINFRAME_H
