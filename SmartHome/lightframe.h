#ifndef LIGHTFRAME_H
#define LIGHTFRAME_H

#include <QFrame>

namespace Ui {
class LightFrame;
}

class LightFrame : public QFrame {
  Q_OBJECT

public:
  explicit LightFrame(QWidget *parent = 0);
  ~LightFrame();

private slots:
  void on_bedroomPushButton_clicked();

  void on_parlourPushButton_clicked();

  void on_kitchenPushButton_clicked();

private:
  Ui::LightFrame *ui;
  bool bedroom_light_;
  bool parlour_light_;
  bool kitchen_light_;
};

#endif // LIGHTFRAME_H
