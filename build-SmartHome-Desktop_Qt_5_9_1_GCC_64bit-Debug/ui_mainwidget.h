/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QLabel *backgroundLabel;
    QSplitter *splitter_2;
    QPushButton *alarmButton_2;
    QPushButton *introductionButton_2;
    QPushButton *testButton_2;
    QPushButton *aboutButton_2;
    QPushButton *returnButto_2;
    QPushButton *otherButton_8;
    QFrame *frame;
    QSplitter *splitter;
    QPushButton *tempButton_2;
    QPushButton *moistureButton_2;
    QPushButton *smokeButton_2;
    QPushButton *AirConditionerButton_2;
    QPushButton *lightButton_2;
    QPushButton *VideoButton_2;
    QPushButton *curtainButton_2;
    QPushButton *otherButton_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1024, 600);
        MainWidget->setStyleSheet(QStringLiteral(""));
        backgroundLabel = new QLabel(MainWidget);
        backgroundLabel->setObjectName(QStringLiteral("backgroundLabel"));
        backgroundLabel->setGeometry(QRect(0, 0, 1024, 600));
        backgroundLabel->setStyleSheet(QStringLiteral("background-image: url(:/mainWidget/image/maindesk.png);"));
        splitter_2 = new QSplitter(MainWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(170, 510, 841, 81));
        splitter_2->setOrientation(Qt::Horizontal);
        alarmButton_2 = new QPushButton(splitter_2);
        alarmButton_2->setObjectName(QStringLiteral("alarmButton_2"));
        alarmButton_2->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(alarmButton_2);
        introductionButton_2 = new QPushButton(splitter_2);
        introductionButton_2->setObjectName(QStringLiteral("introductionButton_2"));
        introductionButton_2->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(introductionButton_2);
        testButton_2 = new QPushButton(splitter_2);
        testButton_2->setObjectName(QStringLiteral("testButton_2"));
        testButton_2->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(testButton_2);
        aboutButton_2 = new QPushButton(splitter_2);
        aboutButton_2->setObjectName(QStringLiteral("aboutButton_2"));
        aboutButton_2->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(aboutButton_2);
        returnButto_2 = new QPushButton(splitter_2);
        returnButto_2->setObjectName(QStringLiteral("returnButto_2"));
        returnButto_2->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(returnButto_2);
        otherButton_8 = new QPushButton(splitter_2);
        otherButton_8->setObjectName(QStringLiteral("otherButton_8"));
        otherButton_8->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        splitter_2->addWidget(otherButton_8);
        frame = new QFrame(MainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, 20, 850, 480));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(1);
        splitter = new QSplitter(MainWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 152, 601));
        splitter->setOrientation(Qt::Vertical);
        tempButton_2 = new QPushButton(splitter);
        tempButton_2->setObjectName(QStringLiteral("tempButton_2"));
        tempButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/temp_btn.png);"));
        splitter->addWidget(tempButton_2);
        moistureButton_2 = new QPushButton(splitter);
        moistureButton_2->setObjectName(QStringLiteral("moistureButton_2"));
        moistureButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/humidity_btn.png);"));
        splitter->addWidget(moistureButton_2);
        smokeButton_2 = new QPushButton(splitter);
        smokeButton_2->setObjectName(QStringLiteral("smokeButton_2"));
        smokeButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/smoke_btn.png);"));
        splitter->addWidget(smokeButton_2);
        AirConditionerButton_2 = new QPushButton(splitter);
        AirConditionerButton_2->setObjectName(QStringLiteral("AirConditionerButton_2"));
        AirConditionerButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/air_condition_btn.png);"));
        splitter->addWidget(AirConditionerButton_2);
        lightButton_2 = new QPushButton(splitter);
        lightButton_2->setObjectName(QStringLiteral("lightButton_2"));
        lightButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/lamp_btn.png);"));
        splitter->addWidget(lightButton_2);
        VideoButton_2 = new QPushButton(splitter);
        VideoButton_2->setObjectName(QStringLiteral("VideoButton_2"));
        VideoButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/camera_btn.png);"));
        splitter->addWidget(VideoButton_2);
        curtainButton_2 = new QPushButton(splitter);
        curtainButton_2->setObjectName(QStringLiteral("curtainButton_2"));
        curtainButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/curtain_btn.png);"));
        splitter->addWidget(curtainButton_2);
        otherButton_2 = new QPushButton(splitter);
        otherButton_2->setObjectName(QStringLiteral("otherButton_2"));
        otherButton_2->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/other_dev_btn.jpg);"));
        splitter->addWidget(otherButton_2);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        backgroundLabel->setText(QString());
        alarmButton_2->setText(QApplication::translate("MainWidget", "\346\212\245\350\255\246\350\256\276\347\275\256", Q_NULLPTR));
        introductionButton_2->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\347\256\200\344\273\213", Q_NULLPTR));
        testButton_2->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\346\265\213\350\257\225", Q_NULLPTR));
        aboutButton_2->setText(QApplication::translate("MainWidget", "\345\205\263\344\272\216\346\210\221\344\273\254", Q_NULLPTR));
        returnButto_2->setText(QApplication::translate("MainWidget", "\350\277\224\345\233\236\346\241\214\351\235\242", Q_NULLPTR));
        otherButton_8->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        tempButton_2->setText(QString());
        moistureButton_2->setText(QString());
        smokeButton_2->setText(QString());
        AirConditionerButton_2->setText(QString());
        lightButton_2->setText(QString());
        VideoButton_2->setText(QString());
        curtainButton_2->setText(QString());
        otherButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
