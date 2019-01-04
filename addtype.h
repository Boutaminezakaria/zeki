#ifndef ADDTYPE_H
#define ADDTYPE_H

#include <QDebug>
#include <QDialog>

namespace Ui {
class AddType;
}

class AddType : public QDialog
{
    Q_OBJECT

public:
    explicit AddType(QWidget *parent = 0);
   void settype(QString );

    ~AddType();

private slots:
   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

private:
    Ui::AddType *ui;
    QString TYPE;
};

#endif // ADDTYPE_H
