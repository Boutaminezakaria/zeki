#ifndef MODIFIERT_H
#define MODIFIERT_H
#include <QDebug>
#include <QDialog>
#include "tiroir.h"
namespace Ui {
class modifierT;
}

class modifierT : public QDialog
{
    Q_OBJECT

public:
    explicit modifierT(QWidget *parent = 0);
   void settype(QString );
   void settirid(int);

    ~modifierT();

private slots:
   void on_pushButton_clicked();

private:
    Ui::modifierT *ui;
    QString TYPE;
     tiroir tir;
};
#endif // MODIFIERT_H
