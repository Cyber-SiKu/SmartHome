#include "mainpage.h"
#include "ui_mainpage.h"
#include "QPixmap"
#include "QDateTime"
#include "QJsonParseError"
#include "QJsonObject"
#include "QJsonDocument"

//当服务器有回应的时候调用 json
void MainPage::recvReplyHandler(QNetworkReply *reply)
{
    QString s;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray b = reply->readAll();
        QJsonParseError jsonpe;
        QJsonDocument json = QJsonDocument::fromJson(b, &jsonpe);
        QJsonObject obj = json.object();
      if (obj.contains(QString("value"))) {
            //通过判断sensor_id键所对应的值便可知道开关的编号
          s = obj.take("sensor_id").toString();
        if (s == QString("409824")) {
                QJsonValue jsonValue = obj.take("value");
                if(jsonValue.toInt()){
                    lampops.lampOn(0);
                    ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
                    ui->pushButton->setIconSize(ui->pushButton->size());
                    flag0 = false;
                } else {
                    lampops.lampOff(0);
                    ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
                    ui->pushButton->setIconSize(ui->pushButton->size());
                    flag0 = true;
                }
            }
            if (s == QString("410080")) {
                QJsonValue jsonValue = obj.take("value");
                if(jsonValue.toInt()){
                    lampops.lampOn(1);
                    ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
                    ui->pushButton_11->setIconSize(ui->pushButton_11->size());
                    flag1 = false;
                } else {
                    lampops.lampOff(1);
                    ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
                    ui->pushButton_11->setIconSize(ui->pushButton_11->size());
                    flag1 = true;
                }
            }
            if (s == QString("410081")) {
                QJsonValue jsonValue = obj.take("value");
                if(jsonValue.toInt()){
                    lampops.lampOn(2);
                    ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
                    ui->pushButton_12->setIconSize(ui->pushButton_12->size());
                    flag2 = false;
                } else {
                    lampops.lampOff(2);
                    ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
                    ui->pushButton_12->setIconSize(ui->pushButton_12->size());
                    flag2 = true;
                }
            }
            if (s == QString("410082")) {
                QJsonValue jsonValue = obj.take("value");
                if(jsonValue.toInt()){
                    lampops.lampOn(3);
                    ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
                    ui->pushButton_13->setIconSize(ui->pushButton_13->size());
                    flag3 = false;
                } else {
                    lampops.lampOff(3);
                    ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
                    ui->pushButton_13->setIconSize(ui->pushButton_13->size());
                    flag3 = true;
                }
            }
            if (s == QString("410186")) {
                QJsonValue jsonValue = obj.take("value");
                if(jsonValue.toInt()){
                    buzzerOps.buzzerOn();
                    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_on.ico")));
                    ui->pushButton_26->setIconSize(ui->pushButton->size());
                } else {
                    buzzerOps.buzzerOff();
                    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_off.ico")));
                    ui->pushButton_26->setIconSize(ui->pushButton->size());
                }
            }
        }
   }
}

MainPage::MainPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);

    ui->allBackLabel->setPixmap(QPixmap(QString("/abc/images/maindesk1.png")));
    ui->backLabel->setPixmap(QPixmap(QString("/abc/images/temp_desk.png")));
    ui->lampBackLabel->setPixmap(QPixmap(QString("/abc/images/lamp_desk.png")));
    ui->testBackLabel->setPixmap(QPixmap(QString("/abc/images/air_condition_desk.png")));

    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_off.ico")));
    ui->pushButton_26->setIconSize(ui->pushButton_26->size());
    ui->pushButton_26->setFlat(true);

    setFixedSize(1024, 600);
    //灯光
    ui->tempButton->setIcon(QIcon(QString("/abc/images/lamp_btn.png")));
    ui->tempButton->setIconSize(ui->tempButton->size());

    //温度
    ui->pushButton_2->setIcon(QIcon(QString("/abc/images/temp_btn.png")));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());

    //湿度
    ui->pushButton_3->setIcon(QIcon(QString("/abc/images/humidity_btn.png")));
    ui->pushButton_3->setIconSize(ui->pushButton_3->size());

    //视频
    ui->pushButton_4->setIcon(QIcon(QString("/abc/images/camera_btn.png")));
    ui->pushButton_4->setIconSize(ui->pushButton_4->size());

    //窗帘
    ui->pushButton_5->setIcon(QIcon(QString("/abc/images/curtain_btn.png")));
    ui->pushButton_5->setIconSize(ui->pushButton_5->size());

    //空调
    ui->pushButton_6->setIcon(QIcon(QString("/abc/images/air_condition_btncam.png")));
    ui->pushButton_6->setIconSize(ui->pushButton_6->size());

    //灯按钮
    ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton->setIconSize(ui->pushButton->size());
    ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_11->setIconSize(ui->pushButton->size());
    ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_12->setIconSize(ui->pushButton->size());
    ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_13->setIconSize(ui->pushButton->size());
    ui->pushButton_14->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_14->setIconSize(ui->pushButton->size());
    ui->pushButton_15->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_15->setIconSize(ui->pushButton->size());
    ui->pushButton_16->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_16->setIconSize(ui->pushButton->size());
    ui->pushButton_17->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
    ui->pushButton_17->setIconSize(ui->pushButton->size());

    ui->lampFrame->setVisible(false);
    ui->testFrame->setVisible(false);
    ui->tempFrame->setVisible(false);

    manager = new QNetworkAccessManager(this);

    yeelinkRequestLed0.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    yeelinkRequestLed0.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/409824/datapoints")));
    yeelinkRequestLed1.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    yeelinkRequestLed1.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410080/datapoints")));
    yeelinkRequestLed2.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    yeelinkRequestLed2.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410081/datapoints")));
    yeelinkRequestLed3.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    yeelinkRequestLed3.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410082/datapoints")));
    yeelinkRequestBuzzer.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    yeelinkRequestBuzzer.setUrl(QUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410186/datapoints")));

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(recvReplyHandler(QNetworkReply*)));

    timerHandler();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));
    timer->start(1000);

    connect(&lamp0Timer,SIGNAL(timeout()),this,SLOT(lamp0TimerHandler()));
    connect(&lamp1Timer,SIGNAL(timeout()),this,SLOT(lamp1TimerHandler()));
    connect(&lamp2Timer,SIGNAL(timeout()),this,SLOT(lamp2TimerHandler()));
    connect(&lamp3Timer,SIGNAL(timeout()),this,SLOT(lamp3TimerHandler()));

}

MainPage::~MainPage()
{
    delete ui;
}

//灯光
void MainPage::on_tempButton_clicked()
{
    ui->testFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->lampFrame->setVisible(true);
    ui->lcdNumber->setVisible(false);
}

//系统测试
void MainPage::on_pushButton_8_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->testFrame->setVisible(true);
    ui->lcdNumber->setVisible(false);
}

//温度
void MainPage::on_pushButton_2_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(true);
    ui->testFrame->setVisible(false);
    ui->lcdNumber->setVisible(false);
}

//返回
void MainPage::on_pushButton_10_clicked()
{
    ui->lampFrame->setVisible(false);
    ui->tempFrame->setVisible(false);
    ui->testFrame->setVisible(false);
    ui->lcdNumber->setVisible(true);
}

void MainPage::timerHandler()
{
    QDateTime d = QDateTime::currentDateTime();
    ui->lcdNumber->display(d.toString(QString("yyyy-MM-dd hh:mm:ss")));

    static int count = 0;
    static double temp = 20.5;

    count++;
    if (count == 15) {
        temp += 2.5;
        if (temp >= 40) temp = 20.5;

        count = 0;

        //构建json数据
        QJsonObject json;
        json.insert("value", temp);
        QJsonDocument document;
        document.setObject(json);
        //把json数据转换为字符数组
        QByteArray byte_array = document.toJson(QJsonDocument::Compact);
        QNetworkRequest request;
        //设置请求的头
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
        request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
        request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
        request.setRawHeader("Connection","close");
        //设置请求url
        request.setUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/409778/datapoints"));
        //发送post请求
        manager->post(request, byte_array);
    }
manager->get(yeelinkRequestLed1);
   manager->get(yeelinkRequestLed0);

    manager->get(yeelinkRequestLed2);
    manager->get(yeelinkRequestLed3);
     manager->get(yeelinkRequestBuzzer);

}
//testFram button de  caohanshu
void MainPage::on_pushButton_26_pressed()
{
    //打开蜂鸣器
    buzzerOps.buzzerOn();
    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_on.ico")));
    ui->pushButton_26->setIconSize(ui->pushButton->size());
}

void MainPage::on_pushButton_26_released()
{
    //关闭蜂鸣器
    buzzerOps.buzzerOff();
    ui->pushButton_26->setIcon(QIcon(QString("/abc/images/buzzer_off.ico")));
    ui->pushButton_26->setIconSize(ui->pushButton->size());
}

//lamp0
void MainPage::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    lamp0Timer.start(12000);
    //构建json数据
    QJsonObject json;

    if(flag0) {
        lampops.lampOn(0);
        json.insert("value", 1);
        ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
        ui->pushButton->setIconSize(ui->pushButton->size());
        flag0 = false;
    } else {
        lampops.lampOff(0);
        json.insert("value",0);
        ui->pushButton->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
        ui->pushButton->setIconSize(ui->pushButton->size());
        flag0 = true;
    }
    QJsonDocument document;
    document.setObject(json);
    //把json数据转换为字符数组
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QNetworkRequest request;
    //设置请求的头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
    request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    request.setRawHeader("Connection","close");
    //设置请求url
    request.setUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/409824/datapoints"));
    //发送post请求
    manager->post(request, byte_array);
}
//lamp1
void MainPage::on_pushButton_11_clicked()
{
    ui->pushButton_11->setEnabled(false);
    lamp1Timer.start(12000);
    //构建json数据
    QJsonObject json;

    if(flag1) {
        lampops.lampOn(1);
        json.insert("value", 1);
        ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
        ui->pushButton_11->setIconSize(ui->pushButton->size());
        flag1 = false;
    } else {
        lampops.lampOff(1);
        json.insert("value", 0);
        ui->pushButton_11->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
        ui->pushButton_11->setIconSize(ui->pushButton->size());
        flag1 = true;
    }
    QJsonDocument document;
    document.setObject(json);
    //把json数据转换为字符数组
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QNetworkRequest request;
    //设置请求的头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
    request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    request.setRawHeader("Connection","close");
    //设置请求url
    request.setUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410080/datapoints"));
    //发送post请求
    manager->post(request, byte_array);
}
//lamp2
void MainPage::on_pushButton_12_clicked()
{
    ui->pushButton_12->setEnabled(false);
    lamp2Timer.start(12000);
    //构建json数据
    QJsonObject json;
    if(flag2) {
        lampops.lampOn(2);
        json.insert("value", 1);
        ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
        ui->pushButton_12->setIconSize(ui->pushButton->size());
        flag2 = false;
    } else {
        lampops.lampOff(2);
        json.insert("value", 0);
        ui->pushButton_12->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
        ui->pushButton_12->setIconSize(ui->pushButton->size());
        flag2 = true;
    }
    QJsonDocument document;
    document.setObject(json);
    //把json数据转换为字符数组
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QNetworkRequest request;
    //设置请求的头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
    request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    request.setRawHeader("Connection","close");
    //设置请求url
    request.setUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410081/datapoints"));
    //发送post请求
    manager->post(request, byte_array);
}
//lamp3
void MainPage::on_pushButton_13_clicked()
{
    ui->pushButton_13->setEnabled(false);
    lamp3Timer.start(12000);
    //构建json数据
    QJsonObject json;

    if(flag3) {
        lampops.lampOn(3);
        json.insert("value", 1);
        ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_on.png")));
        ui->pushButton_13->setIconSize(ui->pushButton->size());
        flag3 = false;
    } else {
        lampops.lampOff(3);
        json.insert("value", 0);
        ui->pushButton_13->setIcon(QIcon(QString("/abc/images/lamp_off.png")));
        ui->pushButton_13->setIconSize(ui->pushButton->size());
        flag3 = true;
    }
    QJsonDocument document;
    document.setObject(json);
    //把json数据转换为字符数组
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QNetworkRequest request;
    //设置请求的头
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json;charset=utf-8");
    request.setHeader(QNetworkRequest::ContentLengthHeader, "100");
    request.setRawHeader(QString("U-ApiKey").toLatin1(), QString("5720c164161dacd62feed337f406f2a3").toLatin1());
    request.setRawHeader("Connection","close");
    //设置请求url
    request.setUrl(QString("http://api.yeelink.net/v1.1/device/359621/sensor/410081/datapoints"));
    //发送post请求
    manager->post(request, byte_array);
}

void MainPage::lamp0TimerHandler()
{
    lamp0Timer.stop();
    ui->pushButton->setEnabled(true);
}

void MainPage::lamp1TimerHandler()
{
    lamp1Timer.stop();
    ui->pushButton_11->setEnabled(true);
}

void MainPage::lamp2TimerHandler()
{
    lamp2Timer.stop();
    ui->pushButton_12->setEnabled(true);
}

void MainPage::lamp3TimerHandler()
{
    lamp3Timer.stop();
    ui->pushButton_13->setEnabled(true);
}
