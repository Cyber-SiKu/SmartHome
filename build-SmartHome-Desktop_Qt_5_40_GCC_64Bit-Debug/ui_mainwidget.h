/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
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
    QPushButton *alarmButton;
    QPushButton *introductionButton;
    QPushButton *testButton_;
    QPushButton *aboutButton;
    QPushButton *returnButto;
    QPushButton *exitButton;
    QFrame *frame;
    QSplitter *splitter;
    QPushButton *tempButton;
    QPushButton *moistureButton;
    QPushButton *smokeButton;
    QPushButton *airConditionerButton;
    QPushButton *lightButton;
    QPushButton *videoButton;
    QPushButton *curtainButton;
    QPushButton *otherButton;

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
        alarmButton = new QPushButton(splitter_2);
        alarmButton->setObjectName(QStringLiteral("alarmButton"));
        alarmButton->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        alarmButton->setFlat(true);
        splitter_2->addWidget(alarmButton);
        introductionButton = new QPushButton(splitter_2);
        introductionButton->setObjectName(QStringLiteral("introductionButton"));
        introductionButton->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        introductionButton->setFlat(true);
        splitter_2->addWidget(introductionButton);
        testButton_ = new QPushButton(splitter_2);
        testButton_->setObjectName(QStringLiteral("testButton_"));
        testButton_->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        testButton_->setFlat(true);
        splitter_2->addWidget(testButton_);
        aboutButton = new QPushButton(splitter_2);
        aboutButton->setObjectName(QStringLiteral("aboutButton"));
        aboutButton->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        aboutButton->setFlat(true);
        splitter_2->addWidget(aboutButton);
        returnButto = new QPushButton(splitter_2);
        returnButto->setObjectName(QStringLiteral("returnButto"));
        returnButto->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        returnButto->setFlat(true);
        splitter_2->addWidget(returnButto);
        exitButton = new QPushButton(splitter_2);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setStyleSheet(QLatin1String("border-image: url(:/mainWidget/image/main_desk_btn_back.png);\n"
"color: rgb(206, 92, 0);"));
        exitButton->setFlat(true);
        splitter_2->addWidget(exitButton);
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
        tempButton = new QPushButton(splitter);
        tempButton->setObjectName(QStringLiteral("tempButton"));
        tempButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/temp_btn.png);"));
        tempButton->setFlat(true);
        splitter->addWidget(tempButton);
        moistureButton = new QPushButton(splitter);
        moistureButton->setObjectName(QStringLiteral("moistureButton"));
        moistureButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/humidity_btn.png);"));
        moistureButton->setFlat(true);
        splitter->addWidget(moistureButton);
        smokeButton = new QPushButton(splitter);
        smokeButton->setObjectName(QStringLiteral("smokeButton"));
        smokeButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/smoke_btn.png);"));
        smokeButton->setFlat(true);
        splitter->addWidget(smokeButton);
        airConditionerButton = new QPushButton(splitter);
        airConditionerButton->setObjectName(QStringLiteral("airConditionerButton"));
        airConditionerButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/air_condition_btn.png);"));
        airConditionerButton->setFlat(true);
        splitter->addWidget(airConditionerButton);
        lightButton = new QPushButton(splitter);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        lightButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/lamp_btn.png);"));
        lightButton->setFlat(true);
        splitter->addWidget(lightButton);
        videoButton = new QPushButton(splitter);
        videoButton->setObjectName(QStringLiteral("videoButton"));
        videoButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/camera_btn.png);"));
        videoButton->setFlat(true);
        splitter->addWidget(videoButton);
        curtainButton = new QPushButton(splitter);
        curtainButton->setObjectName(QStringLiteral("curtainButton"));
        curtainButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/curtain_btn.png);"));
        curtainButton->setFlat(true);
        splitter->addWidget(curtainButton);
        otherButton = new QPushButton(splitter);
        otherButton->setObjectName(QStringLiteral("otherButton"));
        otherButton->setStyleSheet(QStringLiteral("border-image: url(:/mainWidget/image/other_dev_btn.jpg);"));
        otherButton->setFlat(true);
        splitter->addWidget(otherButton);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0));
        backgroundLabel->setText(QString());
        alarmButton->setText(QApplication::translate("MainWidget", "\346\212\245\350\255\246\350\256\276\347\275\256", 0));
        introductionButton->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\347\256\200\344\273\213", 0));
        testButton_->setText(QApplication::translate("MainWidget", "\347\263\273\347\273\237\346\265\213\350\257\225", 0));
        aboutButton->setText(QApplication::translate("MainWidget", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
        returnButto->setText(QApplication::translate("MainWidget", "\350\277\224\345\233\236\346\241\214\351\235\242", 0));
        exitButton->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272\347\263\273\347\273\237", 0));
        tempButton->setText(QString());
        moistureButton->setText(QString());
        smokeButton->setText(QString());
        airConditionerButton->setText(QString());
        lightButton->setText(QString());
        videoButton->setText(QString());
        curtainButton->setText(QString());
        otherButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
