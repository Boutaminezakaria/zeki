#include "ajoutert.h"
#include "addtype.h"
#include "tiroir.h"
#include "supmodt.h"
#include "ui_ajoutert.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QElapsedTimer>
#include <QMessageBox>


AjouterT::AjouterT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterT)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
    ui->tableView->setModel(tir.afficher());
}


AjouterT::~AjouterT()
{
    delete ui;
}



void AjouterT::on_pushButton_clicked()
{
    //int ID = ui->lineEdit_ID->text().toInt();
    QString TYPE= ui->lineEdit_TYPE->text();
    QString NOM= ui->lineEdit_NOM->text();
   // int POIDS = ui->lineEdit_2->text().toInt();
  //tiroir z(ID,TYPE,NOM,POIDS);
    tiroir z(TYPE,NOM);
    QMessageBox *mbox = new QMessageBox;
    mbox->setWindowTitle(tr("waiting for weight"));
    mbox->setText("wait for weight calculation");
    mbox->show();
    QTimer::singleShot(5000, mbox, SLOT(hide())) ;

       QTime dieTime= QTime::currentTime().addSecs(5);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    qsrand(0);
    int POIDS=qrand() % 10 + 0 ;
    z.set_POIDS(POIDS);
    bool test=z.ajouter();
    if(test)
  {ui->tableView->setModel(tir.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter tiroir"),
                    QObject::tr("tiroir ajoutée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter tiroir"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


void AjouterT::on_pushButton_2_clicked()
{
    AddType ad;
this->close();
    ad.exec();
}


void AjouterT::on_pushButton_3_clicked()
{
    supmodT ad;
this->close();
    ad.exec();
}

void AjouterT::on_pushButton_4_clicked()
{
    ui->setupUi(this);
    ui->tableView->setModel(tir.trier());
}
