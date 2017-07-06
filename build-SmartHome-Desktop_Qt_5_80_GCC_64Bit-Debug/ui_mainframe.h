/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_mainFrame
{
public:

    void setupUi(QFrame *mainFrame)
    {
        if (mainFrame->objectName().isEmpty())
            mainFrame->setObjectName(QStringLiteral("mainFrame"));
        mainFrame->setFrameShadow(QFrame::Raised);
        mainFrame->resize(400, 300);
        mainFrame->setFrameShape(QFrame::StyledPanel);

        retranslateUi(mainFrame);

        QMetaObject::connectSlotsByName(mainFrame);
    } // setupUi

    void retranslateUi(QFrame *mainFrame)
    {
        mainFrame->setWindowTitle(QApplication::translate("mainFrame", "Frame", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainFrame: public Ui_mainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
