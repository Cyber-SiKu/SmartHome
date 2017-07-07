#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget {
  Q_OBJECT

public:
  explicit MainWidget(QWidget *parent = 0);
  ~MainWidget();

signals:
  void PushButtonUpdate();
private slots:
  void on_tempButton_clicked();

  void on_smokeButton_clicked();

  void on_moistureButton_clicked();

  void updatePushButton();

  void on_airConditionerButton_clicked();

  void on_lightButton_clicked();

  void on_alarmButton_clicked();

  void on_returnButto_clicked();

  void on_exitButton_clicked();

private:
  Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
