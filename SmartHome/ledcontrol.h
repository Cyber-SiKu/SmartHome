#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include <QObject>

class LedControl : public QObject {
  Q_OBJECT
public:
  explicit LedControl(QObject *parent = 0);
  void ledOn(int i);
  void ledOff(int i);
  void ledControl(int i, int state);

signals:

public slots:
};

#endif // LEDCONTROL_H
