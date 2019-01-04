#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtype.h"
#include "menufood.h"
#include "readtype.h"
#include "securite.h"
#include <QIntValidator>
#include <QPixmap>
#include <QPalette>
#include "mail.h"
#include <QDebug>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   setFixedSize(650,400);
    QPixmap bkngd("C:/Users/DELL/Desktop/test 4/image/modern-wallpaper.jpg");
    bkngd=bkngd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkngd);
    this->setPalette(palette);
   // resize(QDesktopWidget().availableGeometry(this).size() * 0.7);


}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addType_clicked()
{
    AddType ad;
    ad.setWindowTitle("TIRROIR");
    ad.exec();

}
void MainWindow::on_pushButton_readType_clicked()
{
    ReadType rd;

    rd.exec();

}

void MainWindow::on_pushButton_clicked()
{

    menufood rd;
    rd.setWindowTitle("REPAS");
    rd.exec();


}







void MainWindow::on_pushButton_6_clicked()
{
    Dialog2 rd;
    rd.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    Mail m;
    m.exec();

}
