#ifndef CONSULTERFOOD_H
#define CONSULTERFOOD_H
#include "repas.h"
#include <QObject>
#include <QWidget>
#include <QDialog>

namespace Ui {
class consulterfood;
}

class consulterfood : public QDialog
{
    Q_OBJECT

public:
    explicit consulterfood(QWidget *parent = nullptr);
   void settype(QString );

    ~consulterfood();


private slots:


   void on_pushButton_clicked();

private:
    Ui::consulterfood *ui;
    QString TYPE;
    Repas rp;
};


#endif // CONSULTERFOOD_H
