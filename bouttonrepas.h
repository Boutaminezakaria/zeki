#ifndef BOUTTONREPAS_H
#define BOUTTONREPAS_H
#include <QDebug>
#include <QDialog>

#include <QWidget>
#include "ui_bouttonrepas.h"




namespace Ui {
class Bouttonrepas;
}

class Bouttonrepas : public QDialog
{
    Q_OBJECT

public:
    explicit Bouttonrepas(QWidget *parent = 0);
   void settype(QString );

    ~Bouttonrepas();

private:
    Ui::Bouttonrepas *ui;
    QString TYPE;
};
#endif // BOUTTONREPAS_H
