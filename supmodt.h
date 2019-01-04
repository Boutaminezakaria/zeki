#ifndef SUPMODT_H
#define SUPMODT_H
#include "tiroir.h"
#include <QObject>
#include <QDialog>


namespace Ui {
class supmodT;
}

class supmodT : public QDialog
{
    Q_OBJECT

public:
    explicit supmodT(QWidget *parent = 0);
   void settype(QString );

    ~supmodT();

private slots:
   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

private:
    Ui::supmodT *ui;
    QString TYPE;
    tiroir tir;

};




#endif // SUPMODT_H
