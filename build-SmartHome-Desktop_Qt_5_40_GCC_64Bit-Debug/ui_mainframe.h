/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QTextBrowser *runingTextBrowser;
    QFrame *frame_2;
    QTextBrowser *alarmTextBrowser;
    QFrame *frame_3;
    QTextBrowser *serverTextBrowser;
    QLCDNumber *lcdNumber;

    void setupUi(QFrame *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName(QStringLiteral("MainFrame"));
        MainFrame->resize(850, 480);
        MainFrame->setLayoutDirection(Qt::LeftToRight);
        MainFrame->setFrameShape(QFrame::NoFrame);
        MainFrame->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(MainFrame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 831, 321));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(layoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/mainFrame/image/running_text.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        runingTextBrowser = new QTextBrowser(frame);
        runingTextBrowser->setObjectName(QStringLiteral("runingTextBrowser"));
        runingTextBrowser->setGeometry(QRect(0, 0, 271, 321));
        runingTextBrowser->setSizeIncrement(QSize(0, 0));
        runingTextBrowser->setAutoFillBackground(false);
        runingTextBrowser->setFrameShape(QFrame::Panel);
        runingTextBrowser->setFrameShadow(QFrame::Plain);
        runingTextBrowser->setLineWidth(5);
        runingTextBrowser->setMidLineWidth(20);
        runingTextBrowser->setLineWrapColumnOrWidth(0);

        horizontalLayout->addWidget(frame);

        frame_2 = new QFrame(layoutWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral("border-image: url(:/mainFrame/image/alarming_text.png);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        alarmTextBrowser = new QTextBrowser(frame_2);
        alarmTextBrowser->setObjectName(QStringLiteral("alarmTextBrowser"));
        alarmTextBrowser->setGeometry(QRect(0, 0, 271, 321));
        alarmTextBrowser->setFrameShape(QFrame::NoFrame);
        alarmTextBrowser->setFrameShadow(QFrame::Plain);
        alarmTextBrowser->setLineWidth(5);
        alarmTextBrowser->setMidLineWidth(20);

        horizontalLayout->addWidget(frame_2);

        frame_3 = new QFrame(layoutWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setStyleSheet(QStringLiteral("border-image: url(:/mainFrame/image/server_text.png);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        serverTextBrowser = new QTextBrowser(frame_3);
        serverTextBrowser->setObjectName(QStringLiteral("serverTextBrowser"));
        serverTextBrowser->setGeometry(QRect(0, 0, 271, 321));
        serverTextBrowser->setFrameShape(QFrame::NoFrame);
        serverTextBrowser->setFrameShadow(QFrame::Plain);
        serverTextBrowser->setLineWidth(5);
        serverTextBrowser->setMidLineWidth(20);

        horizontalLayout->addWidget(frame_3);

        lcdNumber = new QLCDNumber(MainFrame);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(190, 360, 490, 110));
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(239, 41, 41);"));
        lcdNumber->setDigitCount(9);

        retranslateUi(MainFrame);

        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QFrame *MainFrame)
    {
        MainFrame->setWindowTitle(QApplication::translate("MainFrame", "Frame", 0));
        runingTextBrowser->setHtml(QApplication::translate("MainFrame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'WenQuanYi Micro Hei'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">\347\263\273\347\273\237\350\277\220\350\241\214\346\203\205\345\206\265\345\246\202\344\270\213:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">\346\210\220\345\212\237\346\211\223\345\274\200\347\232\204\350\256\276\345\244\207-&gt;</span></p></body></html>", 0));
        alarmTextBrowser->setHtml(QApplication::translate("MainFrame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'WenQuanYi Micro Hei'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">\347\263\273\347\273\237\350\277\220\350\241\214\346\203\205\345\206\265\345\246\202\344\270\213:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">\346\255\243\345\234\250\350\255\246\346\212\245\347\232\204\350\256\276\345\244\207-&gt;</span></p></body></html>", 0));
        serverTextBrowser->setHtml(QApplication::translate("MainFrame", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'WenQuanYi Micro Hei'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">\347\263\273\347\273\237\350\277\220\350\241\214\346\203\205\345\206\265\345\246\202\344\270\213:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'WenQuanYi Micro Hei Mono';\">-&gt;\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245\346\210\220\345\212\237</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
