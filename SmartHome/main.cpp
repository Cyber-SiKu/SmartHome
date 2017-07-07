#include "mainwidget.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
#if 0
  //设置显示中文
  int nIndex =
      QFontDatabase::addApplicationFont(QString("/usr/share/fonts/wqy"));
  //(指定字体在arm板中的绝对路径)
  if (nIndex != -1) {
    QStringList strList(QFontDatabase::applicationFontFamilies(nIndex));

    if (strList.count() > 0) {
      QFont fontThis(strList.at(0));
      fontThis.setPointSize(9);
      a.setFont(fontThis);
    }
  }
#endif
  MainWidget w;
  w.show();

  return a.exec();
}
