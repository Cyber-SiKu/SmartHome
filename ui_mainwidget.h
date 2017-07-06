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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QSplitter *splitter;
    QPushButton *tempButton;
    QPushButton *moistureButton;
    QPushButton *smokeButton;
    QPushButton *AirConditionerButton;
    QPushButton *lightButton;
    QPushButton *VideoButton;
    QPushButton *curtainButton;
    QPushButton *otherButton;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1024, 600);
        splitter = new QSplitter(MainWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 152, 601));
        splitter->setOrientation(Qt::Vertical);
        tempButton = new QPushButton(splitter);
        tempButton->setObjectName(QStringLiteral("tempButton"));
        splitter->addWidget(tempButton);
        moistureButton = new QPushButton(splitter);
        moistureButton->setObjectName(QStringLiteral("moistureButton"));
        splitter->addWidget(moistureButton);
        smokeButton = new QPushButton(splitter);
        smokeButton->setObjectName(QStringLiteral("smokeButton"));
        splitter->addWidget(smokeButton);
        AirConditionerButton = new QPushButton(splitter);
        AirConditionerButton->setObjectName(QStringLiteral("AirConditionerButton"));
        splitter->addWidget(AirConditionerButton);
        lightButton = new QPushButton(splitter);
        lightButton->setObjectName(QStringLiteral("lightButton"));
        splitter->addWidget(lightButton);
        VideoButton = new QPushButton(splitter);
        VideoButton->setObjectName(QStringLiteral("VideoButton"));
        splitter->addWidget(VideoButton);
        curtainButton = new QPushButton(splitter);
        curtainButton->setObjectName(QStringLiteral("curtainButton"));
        splitter->addWidget(curtainButton);
        otherButton = new QPushButton(splitter);
        otherButton->setObjectName(QStringLiteral("otherButton"));
        splitter->addWidget(otherButton);

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
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
