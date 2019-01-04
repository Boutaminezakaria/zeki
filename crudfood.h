#ifndef CRUDFOOD_H
#define CRUDFOOD_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include "repas.h"
#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class crudfood;
}

class crudfood : public QDialog
{
    Q_OBJECT

public:
    explicit crudfood(QWidget *parent = nullptr);
   void settype(QString );


    ~crudfood();

private slots:
   void on_pushButton_clicked();
   void timer();


private:
    Ui::crudfood *ui;
    QString TYPE;
    int time;
    Repas rep;
};


#endif // CRUDFOOD_H

