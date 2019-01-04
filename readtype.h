#ifndef READTYPE_H
#define READTYPE_H

#include <QDebug>
#include <QDialog>

namespace Ui {
class ReadType;
}

class ReadType : public QDialog
{
    Q_OBJECT

public:
    explicit ReadType(QWidget *parent = 0);
   void settype(QString );

    ~ReadType();

private:
    Ui::ReadType *ui;
    QString TYPE;
};

#endif // READTYPE_H
