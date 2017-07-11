#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "QTimer"
#include "buzzerops.h"
#include "getstatethread.h"
#include <QPixmap>
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include "lampops.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private slots:
    void on_tempButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();
    void timerHandler();

    void on_pushButton_26_pressed();

    void on_pushButton_26_released();

    void recvReplyHandler(QNetworkReply *reply);

 //   void recvStateSingalHandler(int state);
    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

void  lamp0TimerHandler();

void  lamp1TimerHandler();

void  lamp2TimerHandler();

void  lamp3TimerHandler();

private:
    Ui::MainPage *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest yeelinkRequestLed0,yeelinkRequestLed1,yeelinkRequestLed2,yeelinkRequestLed3,yeelinkRequestBuzzer;
    QTimer *timer;
    BuzzerOps buzzerOps;
    LampOps lampops;
    QTimer lamp2Timer,lamp0Timer,lamp1Timer,lamp3Timer;
    bool flag0,flag1,flag2,flag3;
};

#endif // MAINPAGE_H
