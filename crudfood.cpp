#include "crudfood.h"
#include "ui_crudfood.h"
#include "mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QMenu>
#include <QAction>
#include <QStyle>
#include <repas.h>

crudfood::crudfood(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::crudfood)
{
    time=0;
    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
}


crudfood::~crudfood()
{
    delete ui;
}

//void crudfood::settype(QString n)
//{
    //ui->lineEdit_type->setText(n);
//}
void crudfood::timer()
{
    rep.modifier();
    QSystemTrayIcon *notif= new QSystemTrayIcon(this);
    notif->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
                    notif->show();
                   QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
                   QString msg2="le repas "+rep.get_NOM()+" est pret" ;
                   notif->showMessage("repas pret",msg2,icon,5000);


}

void crudfood::on_pushButton_clicked()
{
    int ID2 = 0;
    QString NOM= ui->lineEdit_2->text();
    int T= ui->lineEdit_3->text().toInt();

    Repas z(ID2,NOM,T);
    rep.set_ID2(ID2);
    rep.set_NOM(NOM);
    rep.set_T(T);


    bool test=z.ajouter();



    QTimer::singleShot( T*1000 , this, SLOT(timer())) ;


        if(test)
      {
      QMessageBox::information(nullptr, QObject::tr("Ajouter repas"),
                        QObject::tr("   repas ajoutée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter repas"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


      }
