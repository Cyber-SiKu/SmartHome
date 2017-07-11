#ifndef LAMPOPS_H
#define LAMPOPS_H

#include <QObject>

class LampOps : public QObject
{
    Q_OBJECT
public:
    explicit LampOps(QObject *parent = 0);

    void lampOn(int no);
    void lampOff(int no);

signals:

public slots:
};

#endif // LAMPOPS_H
