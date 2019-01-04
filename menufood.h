#ifndef MENUFOOD_H
#define MENUFOOD_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class menufood;
}

class menufood : public QDialog
{
    Q_OBJECT

public:
    explicit menufood(QWidget *parent = nullptr);
   void settype(QString );


    ~menufood();


private slots:
   void on_pushButton_2_clicked();

   void on_pushButton_clicked();

private:
    Ui::menufood *ui;
    QString TYPE;
};




#endif // MENUFOOD_H
