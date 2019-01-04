#include "consulterfood.h"
#include "addtype.h"
#include "ui_consulterfood.h"
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>


consulterfood::consulterfood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consulterfood)
{

    ui->setupUi(this);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
    ui->tableView->setModel(rp.afficher());
}


consulterfood::~consulterfood()
{
    delete ui;
}


void consulterfood::on_pushButton_clicked()
{
    int ID2 = ui->tableView->currentIndex().data().toInt();
            bool test=rp.supprimer(ID2);
    ui->tableView->setModel(rp.afficher());//refresh

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer tiroir"),
                    QObject::tr("repas supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer repas"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
