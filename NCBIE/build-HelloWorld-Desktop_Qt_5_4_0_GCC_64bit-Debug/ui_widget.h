/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *lable_light_1;
    QLabel *lable_light_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(358, 225);
        lable_light_1 = new QLabel(Widget);
        lable_light_1->setObjectName(QStringLiteral("lable_light_1"));
        lable_light_1->setGeometry(QRect(20, 10, 150, 200));
        lable_light_1->setStyleSheet(QStringLiteral("background-color: rgb(92, 53, 102);"));
        lable_light_2 = new QLabel(Widget);
        lable_light_2->setObjectName(QStringLiteral("lable_light_2"));
        lable_light_2->setGeometry(QRect(190, 10, 150, 200));
        lable_light_2->setStyleSheet(QStringLiteral("background-color: rgb(92, 53, 102);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        lable_light_1->setText(QApplication::translate("Widget", "TextLabel", 0));
        lable_light_2->setText(QApplication::translate("Widget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
