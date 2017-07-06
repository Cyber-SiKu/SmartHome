/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QFrame *frame;
    QSplitter *splitter;
    QPushButton *tempButton;
    QPushButton *moistureButton;
    QPushButton *smokeButton;
    QPushButton *AirConditionerButton;
    QPushButton *lightButton;
    QPushButton *VideoButton;
    QPushButton *curtainButton;
    QPushButton *otherButton;
    QSplitter *splitter_2;
    QPushButton *alarmButton;
    QPushButton *introductionButton;
    QPushButton *testButton;
    QPushButton *aboutButton;
    QPushButton *returnButto;
    QPushButton *otherButton_7;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1024, 600);
        MainWidget->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(MainWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(160, 20, 850, 480));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(1);
        splitter = new QSplitter(MainWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 152, 601));
        splitter->setOrientation(Qt::Vertical);
        tempButton = new QPushButton(splitter);
        tempButton->setObjectName(QStringLiteral("tempButton"));
        tempButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/temp_btn.png);"));
        splitter->addWidget(tempButton);
        moistureButton = new QPushButton(splitter);
        moistureButton->setObjectName(QStringLiteral("moistureButton"));
        moistureButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/humidity_btn.png);"));
        splitter->addWidget(moistureButton);
        smokeButton = new QPushButton(splitter);
        smokeButton->setObjectName(QStringLiteral("smokeButton"));
        smokeButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/smoke_btn.png);"));
        splitter->addWidget(smokeButton);
        AirConditionerButton = new QPushButton(splitter);
        AirConditionerButton->setObjectName(QStringLiteral("AirConditionerButton"));
        AirConditionerButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/air_condition_btn.png);"));
        splitter->addWidget(AirConditionerButton);
        lightButton = new QPushButton(splitter);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        lightButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/lamp_btn.png);"));
        splitter->addWidget(lightButton);
        VideoButton = new QPushButton(splitter);
        VideoButton->setObjectName(QStringLiteral("VideoButton"));
        VideoButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/camera_btn.png);"));
        splitter->addWidget(VideoButton);
        curtainButton = new QPushButton(splitter);
        curtainButton->setObjectName(QStringLiteral("curtainButton"));
        curtainButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/curtain_btn.png);"));
        splitter->addWidget(curtainButton);
        otherButton = new QPushButton(splitter);
        otherButton->setObjectName(QStringLiteral("otherButton"));
        otherButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/other_dev_btn.jpg);"));
        splitter->addWidget(otherButton);
        splitter_2 = new QSplitter(MainWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(170, 510, 841, 81));
        splitter_2->setOrientation(Qt::Horizontal);
        alarmButton = new QPushButton(splitter_2);
        alarmButton->setObjectName(QStringLiteral("alarmButton"));
        alarmButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(alarmButton);
        introductionButton = new QPushButton(splitter_2);
        introductionButton->setObjectName(QStringLiteral("introductionButton"));
        introductionButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(introductionButton);
        testButton = new QPushButton(splitter_2);
        testButton->setObjectName(QStringLiteral("testButton"));
        testButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(testButton);
        aboutButton = new QPushButton(splitter_2);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(aboutButton);
        returnButto = new QPushButton(splitter_2);
        returnButto->setObjectName(QStringLiteral("returnButto"));
        returnButto->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(returnButto);
        otherButton_7 = new QPushButton(splitter_2);
        otherButton_7->setObjectName(QStringLiteral("otherButton_7"));
        otherButton_7->setStyleSheet(QStringLiteral("border-image: url(:/main/prefix/image/main_desk_btn_back.png);"));
        splitter_2->addWidget(otherButton_7);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        tempButton->setText(QString());
        moistureButton->setText(QString());
        smokeButton->setText(QString());
        AirConditionerButton->setText(QString());
        lightButton->setText(QString());
        VideoButton->setText(QString());
        curtainButton->setText(QString());
        otherButton->setText(QString());
        alarmButton->setText(QApplication::translate("MainWidget", "\346\212\245\350\255\246\350\256\276\347\275\256", Q_NULLPTR));
        introductionButton->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\347\256\200\344\273\213", Q_NULLPTR));
        testButton->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\346\265\213\350\257\225", Q_NULLPTR));
        aboutButton->setText(QApplication::translate("MainWidget", "\345\205\263\344\272\216\346\210\221\344\273\254", Q_NULLPTR));
        returnButto->setText(QApplication::translate("MainWidget", "\350\277\224\345\233\236\346\241\214\351\235\242", Q_NULLPTR));
        otherButton_7->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
