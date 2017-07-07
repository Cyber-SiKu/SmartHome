#ifndef BUZZERCONTROL_H
#define BUZZERCONTROL_H

#include <QObject>

class BuzzerControl : public QObject {
  Q_OBJECT
public:
  explicit BuzzerControl(QObject *parent = 0);

  void buzzerOn();

  void buzzerOff();
signals:

public slots:
};

#endif // BUZZERCONTROL_H
