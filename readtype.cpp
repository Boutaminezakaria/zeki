#include "readtype.h"
#include "ui_readtype.h"
#include "mainwindow.h"
#include <QDebug>
ReadType::ReadType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReadType)
{

    ui->setupUi(this);
}


ReadType::~ReadType()
{
    delete ui;
}

//void ReadType::settype(QString n)
//{
    //ui->lineEdit_type->setText(n);
//}
