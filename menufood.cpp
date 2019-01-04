#include "menufood.h"
#include "crudfood.h"
#include "consulterfood.h"
#include "ui_menufood.h"
#include "mainwindow.h"
#include "ajoutert.h"
#include <QDebug>
#include<QDialog>

menufood::menufood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menufood)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
}


menufood::~menufood()
{
    delete ui;
}


void menufood::on_pushButton_2_clicked()
{
    crudfood crd;
    crd.exec();

}

void menufood::on_pushButton_clicked()
{
    consulterfood con;
    con.exec();
}
