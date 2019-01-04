#include "modifiert.h"
#include "supmodt.h"
#include "ui_supmodt.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QTime>



supmodT::supmodT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supmodT)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);

    ui->tableView2->setModel(tir.afficher());


    QSystemTrayIcon *notif= new QSystemTrayIcon(this);
    notif->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
                    notif->show();
                    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    for (int i = 0; i <= ui->tableView2->model()->rowCount() ; ++i)
    {
        if(ui->tableView2->model()->data(ui->tableView2->model()->index(i,3)).toInt()>5)
        {
            QString msg=ui->tableView2->model()->data(ui->tableView2->model()->index(i,2)).toString() ;
            QString msg2="the shelf "+msg+" is overweighted" ;
            notif->showMessage("overweight",msg2,icon,5000);
            QTime dieTime= QTime::currentTime().addSecs(1);
             while (QTime::currentTime() < dieTime)
                 QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }




}


supmodT::~supmodT()
{
    delete ui;
}

/*void supmodT::settype(QString n)
{
   // ui->lineEdit_type->setText(n);
}*/

void supmodT::on_pushButton_clicked()
{
    modifierT ad;
    int ID = ui->tableView2->currentIndex().data().toInt();
     ad.settirid(ID);
this->close();
    ad.exec();
}

void supmodT::on_pushButton_2_clicked()
{

    int ID = ui->tableView2->currentIndex().data().toInt();
            bool test=tir.supprimer(ID);
    ui->tableView2->setModel(tir.afficher());//refresh

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer tiroir"),
                    QObject::tr("tiroir supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer tiroir"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
