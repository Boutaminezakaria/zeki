#include "addtype.h"
//#include "consultert.h"
#include "ui_addtype.h"

#include "supmodt.h"
#include "ajoutert.h"
#include <QDebug>


AddType::AddType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddType)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
}


AddType::~AddType()
{
    delete ui;
}



void AddType::on_pushButton_clicked()
{
    AjouterT ad;
this->close();
    ad.exec();
}

void AddType::on_pushButton_2_clicked()
{
    supmodT ad;
this->close();
    ad.exec();

}
