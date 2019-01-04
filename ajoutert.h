#ifndef AJOUTERT_H
#define AJOUTERT_H
#include "tiroir.h"
#include <QDebug>
#include <QDialog>

namespace Ui {
class AjouterT;
}

class AjouterT : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterT(QWidget *parent = 0);
   void settype(QString );

    ~AjouterT();

private slots:
   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

   void on_pushButton_3_clicked();

   void on_pushButton_4_clicked();

private:
    Ui::AjouterT *ui;
    QString TYPE;
    tiroir tir;

};
#endif // AJOUTERT_H


