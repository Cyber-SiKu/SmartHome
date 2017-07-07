/********************************************************************************
** Form generated from reading UI file 'moistureframe.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOISTUREFRAME_H
#define UI_MOISTUREFRAME_H

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

class Ui_MoistureFrame
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *bedroomMoistureProgressBar;
    QLabel *bedroomMoisture;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QProgressBar *parlourMoistureProgressBar;
    QLabel *parlourMoisture;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QProgressBar *kichenMoistureProgressBar;
    QLabel *kitchenTemp;

    void setupUi(QFrame *MoistureFrame)
    {
        if (MoistureFrame->objectName().isEmpty())
            MoistureFrame->setObjectName(QStringLiteral("MoistureFrame"));
        MoistureFrame->resize(850, 480);
        MoistureFrame->setFrameShape(QFrame::StyledPanel);
        MoistureFrame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(MoistureFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 771, 431));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        bedroomMoistureProgressBar = new QProgressBar(layoutWidget);
        bedroomMoistureProgressBar->setObjectName(QStringLiteral("bedroomMoistureProgressBar"));
        bedroomMoistureProgressBar->setEnabled(true);
        QFont font1;
        font1.setKerning(true);
        bedroomMoistureProgressBar->setFont(font1);
        bedroomMoistureProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(32, 74, 135);"));
        bedroomMoistureProgressBar->setValue(16);

        horizontalLayout->addWidget(bedroomMoistureProgressBar);

        bedroomMoisture = new QLabel(layoutWidget);
        bedroomMoisture->setObjectName(QStringLiteral("bedroomMoisture"));
        bedroomMoisture->setFont(font);

        horizontalLayout->addWidget(bedroomMoisture);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        parlourMoistureProgressBar = new QProgressBar(layoutWidget);
        parlourMoistureProgressBar->setObjectName(QStringLiteral("parlourMoistureProgressBar"));
        parlourMoistureProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(32, 74, 135);"));
        parlourMoistureProgressBar->setValue(22);

        horizontalLayout_2->addWidget(parlourMoistureProgressBar);

        parlourMoisture = new QLabel(layoutWidget);
        parlourMoisture->setObjectName(QStringLiteral("parlourMoisture"));
        parlourMoisture->setFont(font);

        horizontalLayout_2->addWidget(parlourMoisture);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        kichenMoistureProgressBar = new QProgressBar(layoutWidget);
        kichenMoistureProgressBar->setObjectName(QStringLiteral("kichenMoistureProgressBar"));
        kichenMoistureProgressBar->setStyleSheet(QStringLiteral("selection-background-color: rgb(32, 74, 135);"));
        kichenMoistureProgressBar->setValue(30);

        horizontalLayout_3->addWidget(kichenMoistureProgressBar);

        kitchenTemp = new QLabel(layoutWidget);
        kitchenTemp->setObjectName(QStringLiteral("kitchenTemp"));
        kitchenTemp->setFont(font);

        horizontalLayout_3->addWidget(kitchenTemp);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(MoistureFrame);

        QMetaObject::connectSlotsByName(MoistureFrame);
    } // setupUi

    void retranslateUi(QFrame *MoistureFrame)
    {
        MoistureFrame->setWindowTitle(QApplication::translate("MoistureFrame", "Frame", 0));
        label->setText(QApplication::translate("MoistureFrame", "\345\215\247\345\256\244", 0));
        bedroomMoistureProgressBar->setFormat(QString());
        bedroomMoisture->setText(QApplication::translate("MoistureFrame", "16.00%", 0));
        label_2->setText(QApplication::translate("MoistureFrame", "\345\256\242\345\216\205", 0));
        parlourMoistureProgressBar->setFormat(QString());
        parlourMoisture->setText(QApplication::translate("MoistureFrame", "22.00%", 0));
        label_3->setText(QApplication::translate("MoistureFrame", "\345\216\250\346\210\277", 0));
        kichenMoistureProgressBar->setFormat(QString());
        kitchenTemp->setText(QApplication::translate("MoistureFrame", "30.00%", 0));
    } // retranslateUi

};

namespace Ui {
    class MoistureFrame: public Ui_MoistureFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOISTUREFRAME_H
