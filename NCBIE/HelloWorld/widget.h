#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include "yeelink_lzy.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    private slots:
    void recvSwithFlagHandler(bool on);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H