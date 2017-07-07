/********************************************************************************
** Form generated from reading UI file 'tempframe.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPFRAME_H
#define UI_TEMPFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TempFrame
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *bedroomTempProgressBar;
    QLabel *bedroomTemp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QProgressBar *parlourTempProgressBar;
    QLabel *parlourTemp;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QProgressBar *kitchenTempProgressBar;
    QLabel *kitchenTemp;

    void setupUi(QFrame *TempFrame)
    {
        if (TempFrame->objectName().isEmpty())
            TempFrame->setObjectName(QStringLiteral("TempFrame"));
        TempFrame->resize(850, 480);
        TempFrame->setFrameShape(QFrame::StyledPanel);
        TempFrame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(TempFrame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 30, 771, 431));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        bedroomTempProgressBar = new QProgressBar(widget);
        bedroomTempProgressBar->setObjectName(QStringLiteral("bedroomTempProgressBar"));
        bedroomTempProgressBar->setEnabled(true);
        QFont font1;
        font1.setKerning(true);
        bedroomTempProgressBar->setFont(font1);
        bedroomTempProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(193, 125, 17);"));
        bedroomTempProgressBar->setValue(16);

        horizontalLayout->addWidget(bedroomTempProgressBar);

        bedroomTemp = new QLabel(widget);
        bedroomTemp->setObjectName(QStringLiteral("bedroomTemp"));
        bedroomTemp->setFont(font);

        horizontalLayout->addWidget(bedroomTemp);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        parlourTempProgressBar = new QProgressBar(widget);
        parlourTempProgressBar->setObjectName(QStringLiteral("parlourTempProgressBar"));
        parlourTempProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(193, 125, 17);"));
        parlourTempProgressBar->setValue(22);

        horizontalLayout_2->addWidget(parlourTempProgressBar);

        parlourTemp = new QLabel(widget);
        parlourTemp->setObjectName(QStringLiteral("parlourTemp"));
        parlourTemp->setFont(font);

        horizontalLayout_2->addWidget(parlourTemp);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        kitchenTempProgressBar = new QProgressBar(widget);
        kitchenTempProgressBar->setObjectName(QStringLiteral("kitchenTempProgressBar"));
        kitchenTempProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(193, 125, 17);"));
        kitchenTempProgressBar->setValue(30);

        horizontalLayout_3->addWidget(kitchenTempProgressBar);

        kitchenTemp = new QLabel(widget);
        kitchenTemp->setObjectName(QStringLiteral("kitchenTemp"));
        kitchenTemp->setFont(font);

        horizontalLayout_3->addWidget(kitchenTemp);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(TempFrame);

        QMetaObject::connectSlotsByName(TempFrame);
    } // setupUi

    void retranslateUi(QFrame *TempFrame)
    {
        TempFrame->setWindowTitle(QApplication::translate("TempFrame", "Frame", 0));
        label->setText(QApplication::translate("TempFrame", "\345\215\247\345\256\244", 0));
        bedroomTempProgressBar->setFormat(QString());
        bedroomTemp->setText(QApplication::translate("TempFrame", "16", 0));
        label_2->setText(QApplication::translate("TempFrame", "\345\256\242\345\216\205", 0));
        parlourTempProgressBar->setFormat(QString());
        parlourTemp->setText(QApplication::translate("TempFrame", "22", 0));
        label_3->setText(QApplication::translate("TempFrame", "\345\216\250\346\210\277", 0));
        kitchenTempProgressBar->setFormat(QString());
        kitchenTemp->setText(QApplication::translate("TempFrame", "30", 0));
    } // retranslateUi

};

namespace Ui {
    class TempFrame: public Ui_TempFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPFRAME_H
