#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include "QNetworkAccessManager"
#include <QWidget>

namespace Ui {
class HomePage;
}

class HomePage : public QWidget {
  Q_OBJECT

public:
  explicit HomePage(QWidget *parent = 0);
  ~HomePage();

private slots:
  void on_pushButton_clicked();
  void replyFinished(QNetworkReply *);

  void on_pushButton_2_clicked();

private:
  Ui::HomePage *ui;
  QNetworkAccessManager *m;
};

#endif // HOMEPAGE_H
