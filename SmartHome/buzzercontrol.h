#ifndef BUZZERCONTROL_H
#define BUZZERCONTROL_H

#include <QObject>

class BuzzerControl : public QObject {
  Q_OBJECT
public:
  explicit BuzzerControl(QObject *parent = 0);

  void buzzerOn();

  void buzzerOff();

  void buzzerControl(int state);
signals:

public slots:
};

#endif // BUZZERCONTROL_H
