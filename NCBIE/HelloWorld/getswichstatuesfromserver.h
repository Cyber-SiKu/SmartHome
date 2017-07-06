#ifndef GETSWICHSTATUESFROMSERVER_H
#define GETSWICHSTATUESFROMSERVER_H

#include <QThread>

class GetSwichStatuesFromServer : public QThread
{
    Q_OBJECT

public:
    GetSwichStatuesFromServer();
private:
    //thread function
    void run();
signals:
    void switchSignal(bool on);
};

#endif // GETSWICHSTATUESFROMSERVER_H
