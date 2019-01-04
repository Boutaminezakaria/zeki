#include "modifiert.h"
#include "ui_modifiert.h"
#include "mainwindow.h"
#include "tiroir.h"
#include <QDebug>
#include <qmessagebox.h>


modifierT::modifierT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifierT)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);

}


modifierT::~modifierT()
{
    delete ui;
}

/*void modifierT::settype(QString n)
{
   // ui->lineEdit_type->setText(n);
}*/
void modifierT::settirid(int n)
{
   this->tir.set_ID(n);
}


void modifierT::on_pushButton_clicked()
{

    QString TYPE= ui->lineEdit->text();
    QString NOM= ui->lineEdit_2->text();
    tir.set_NOM(NOM);
    tir.set_TYPE(TYPE);

    bool test=tir.modifier();
    if(test)
  {
  QMessageBox::information(nullptr, QObject::tr("modifier tiroir"),
                    QObject::tr("tiroir modifiée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier tiroir"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
