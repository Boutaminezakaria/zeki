#include <smtp.h>
#include "zakaria.h"
#include "ui_zakaria.h"
#include"porte.h"
#include "fenetres.h"
#include <QModelIndex>
#include<QSystemTrayIcon>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSound>
#include <QMessageBox>
#include<QSystemTrayIcon>

Zakaria::Zakaria(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zakaria)
{
    ui->setupUi(this);

    //
    ui->horizontalSlider->setMinimum(ui->lineEdit_min->text().toInt());
    ui->horizontalSlider->setMaximum(ui->lineEdit_max->text().toInt());

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

     ui->horizontalSlider_2->setMinimum(ui->lineEdit_n5->text().toInt());
     ui->horizontalSlider_2->setMaximum(ui->lineEdit_n6->text().toInt());

// for email
   // Smtp  * smtp= new Smtp("mohamedzakaria.boutamine@esprit.tn", "*168831450#", "smtp.gmail.com" , 465);
   // connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

   // smtp->sendMail("mohamedzakaria.boutammine@esprit.tn", "mohamedzakaria.boutammine@esprit.tn" , "This is a subject","your message");

    //sound opening
    QSound::play ("C:/Users/HP/Music/kkk.wav");

    //HTML
    ui->pushButton_close_z->setToolTip("Click pour quitter !! " );
    ui->pushButton_affich_z->setToolTip("Click pour afficher les pieces !! " );
    ui->pushButton_ajou_z->setToolTip("Click pour ajouter pieces !! " );
    ui->pushButton_ajouter_z->setToolTip("Click pour ajouter !! " );
    ui->pushButton_ajouter_f->setToolTip("Click pour ajouter !! " );
    ui->pushButton_modf->setToolTip("Click pour passer à la modification !! " );
    ui->tableView_supp->setToolTip("sélectionner la porte et puis click supprimer _ or click deux fois pour le modifier!! " );
    ui->tableView_suup_f->setToolTip("sélectionner la fenetre et puis click supprimer _ or click deux fois pour le modifier!! " );

    //image plus
    QPixmap pix ("C:/Users/HP/Pictures/61975.png");
    ui->label_22->setPixmap(pix.scaled(50,50,Qt::KeepAspectRatio));
    //image eyes
    QPixmap pix1 ("C:/Users/HP/Pictures/64875.png");
    ui->label_23->setPixmap(pix1.scaled(60,60,Qt::KeepAspectRatio));
    //
    QPixmap pix2 ("C:/Users/HP/Pictures/2019.png");
    ui->label_59->setPixmap(pix2.scaled(60,60,Qt::KeepAspectRatio));

    QPixmap pix6 ("C:/Users/HP/Pictures/fenetre_f.png");
    ui->label_64->setPixmap(pix6.scaled(80,80,Qt::KeepAspectRatio));

    QPixmap pix7 ("C:/Users/HP/Pictures/porte_p.png");
    ui->label_65->setPixmap(pix7.scaled(80,80,Qt::KeepAspectRatio));

    //background
    QPixmap pix4 ("C:/Users/HP/Pictures/123zz.jpg");
    ui->label->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_2->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_3->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_7->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_11->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_12->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_13->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_17->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_18->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));
    ui->label_57->setPixmap(pix4.scaled(700,500,Qt::KeepAspectRatio));

    //label securtiy
    QPixmap pix5 ("C:/Users/HP/Pictures/nn.png");
    ui->label_48->setPixmap(pix5.scaled(120,120,Qt::KeepAspectRatio));
    ui->label_49->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_50->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_51->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_52->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_53->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));
    ui->label_54->setPixmap(pix5.scaled(150,150,Qt::KeepAspectRatio));

    //button close
    QPixmap pixadmin2("C:/Users/HP/Pictures/close.png");
    QIcon ButtonIcon2(pixadmin2);
    ui->pushButton_close_z->setIcon(ButtonIcon2);
    ui->pushButton_close_z->setIconSize(pixadmin2.rect().size()/3);

    //button home
    QPixmap pixadmin4("C:/Users/HP/Pictures/home.png");
    QIcon ButtonIcon4(pixadmin4);
    ui->pushButton_home0->setIcon(ButtonIcon4);
    ui->pushButton__->setIcon(ButtonIcon4);
    ui->pushButton_home_modf->setIcon(ButtonIcon4);
    ui->pushButton_home_suup->setIcon(ButtonIcon4);
    ui->pushButton_home_md_f->setIcon(ButtonIcon4);
    ui->pushButton_suup_home->setIcon(ButtonIcon4);
    //size
    ui->pushButton_home0->setIconSize(pixadmin4.rect().size()/3.8);
    ui->pushButton__->setIconSize(pixadmin4.rect().size()/3.8);
    ui->pushButton_home_modf->setIconSize(pixadmin4.rect().size()/3.8);
    ui->pushButton_home_suup->setIconSize(pixadmin4.rect().size()/3.8);
    ui->pushButton_home_md_f->setIconSize(pixadmin4.rect().size()/3.8);
    ui->pushButton_suup_home->setIconSize(pixadmin4.rect().size()/3.8);

    //button retour
    QPixmap pixadmin3("C:/Users/HP/Pictures/return.png");
    QIcon ButtonIcon3(pixadmin3);
    ui->pushButton_return_0->setIcon(ButtonIcon3);
    ui->pushButton_return1->setIcon(ButtonIcon3);
    ui->pushButton_return->setIcon(ButtonIcon3);
    ui->pushButton_4_return_aff->setIcon(ButtonIcon3);
    ui->pushButton_return_mod->setIcon(ButtonIcon3);
    ui->pushButton_return_supp->setIcon(ButtonIcon3);
    ui->pushButton_->setIcon(ButtonIcon3);
    ui->pushButton_returnff->setIcon(ButtonIcon3);
    ui->pushButton_rf->setIcon(ButtonIcon3);
    //size
    ui->pushButton_return_0->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_return1->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_return->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_4_return_aff->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_return_mod->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_return_supp->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_returnff->setIconSize(pixadmin3.rect().size()/10);
    ui->pushButton_rf->setIconSize(pixadmin3.rect().size()/10);

    //button _porte
    QPixmap pixadmin("C:/Users/HP/Pictures/porte_p.png");
    QIcon ButtonIcon0(pixadmin);
    ui->pushButton_ajou_p->setIcon(ButtonIcon0);
    ui->pushButton_aff_porte->setIcon(ButtonIcon0);
    //size
    ui->pushButton_ajou_p->setIconSize(pixadmin.rect().size()/2.5);
    ui->pushButton_aff_porte->setIconSize(pixadmin.rect().size()/2.5);

     //button _fenetre
     QPixmap pixadmin1("C:/Users/HP/Pictures/fenetre_f.png");
     QIcon ButtonIcon1(pixadmin1);
     ui->pushButton_ajou_f->setIcon(ButtonIcon1);
     ui->pushButton_aff_fenetre->setIcon(ButtonIcon1);
     ui->pushButton_ajou_f->setIconSize(pixadmin1.rect().size()/2.5);
     ui->pushButton_aff_fenetre->setIconSize(pixadmin1.rect().size()/2.5);

     // notification:
     zSysteTraymIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
     zSysteTraymIcon->show();

     // animation
     QPropertyAnimation  *animation;
     QPropertyAnimation  *animation1;
     QPropertyAnimation  *animation2;
     QPropertyAnimation  *animation3;
     QPropertyAnimation  *animation4;
     QPropertyAnimation  *animation5;
     QPropertyAnimation  *animation6;
         animation =new QPropertyAnimation(ui->pushButton_close_z,"geometry");
         animation1 =new QPropertyAnimation(ui->label_22,"geometry");
         animation2 =new QPropertyAnimation(ui->label_23,"geometry");
         animation3 =new QPropertyAnimation(ui->pushButton_ajou_z,"geometry");
         animation4 =new QPropertyAnimation(ui->pushButton_affich_z,"geometry");
         animation5 =new QPropertyAnimation(ui->label_48,"geometry");
         animation6 =new QPropertyAnimation(ui->pushButton_opp,"geometry");
         animation->setDuration(10000);
         animation1->setDuration(10000);
         animation2->setDuration(10000);
         animation3->setDuration(10000);
         animation4->setDuration(10000);
         animation5->setDuration(10000);
         animation6->setDuration(10000);
         animation->setStartValue(QRect(35,10,0,0));
         animation->setEndValue(QRect(35,10,45,45));
         animation1->setStartValue(QRect(420,170,0,0));
         animation1->setEndValue(QRect(420,170,50,50));
         animation2->setStartValue(QRect(420,240,0,0));
         animation2->setEndValue(QRect(420,240,60,60));
         animation3->setStartValue(QRect(200,170,0,0));
         animation3->setEndValue(QRect(200,170,200,50));
         animation4->setStartValue(QRect(200,250,0,0));
         animation4->setEndValue(QRect(200,250,200,50));
         animation5->setStartValue(QRect(500,0,0,0));
         animation5->setEndValue(QRect(500,0,150,150));
         animation6->setEndValue(QRect(200,330,0,0));
         animation6->setEndValue(QRect(200,330,200,50));
         animation->setEasingCurve(QEasingCurve::InBack);//hedhi tbambi
         animation1->setEasingCurve(QEasingCurve::InBack);
         animation2->setEasingCurve(QEasingCurve::InBack);
         animation3->setEasingCurve(QEasingCurve::InBack);
         animation4->setEasingCurve(QEasingCurve::InBack);
         animation5->setEasingCurve(QEasingCurve::InBack);
         animation6->setEasingCurve(QEasingCurve::InBack);
         animation->start();
         animation1->start();
         animation2->start();
         animation3->start();
         animation4->start();
         animation5->start();
         animation6->start();

     }


Zakaria::~Zakaria()
{
    delete ui;
}
//*****************************************************************************************************************************
bool Zakaria::update_label()
{
    //QString g="humid";
    data=A.read_from_arduino();
    ui->label_60->setText(data);
    if ((ui->label_60->text() == ""))
    {
            return  0;
    }else
    {

        zSysteTraymIcon->showMessage("Notification","\n fama mtar ",QSystemTrayIcon::Information);

        Smtp  * smtp= new Smtp("mohamedzakaria.boutamine@esprit.tn", "*168831450#", "smtp.gmail.com" , 465);
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("mohamedzakaria.boutammine@esprit.tn", "mohamedzakaria.boutammine@esprit.tn" , "This is a subject","your message");


    }
    //qDebug ()<<data;
}


void Zakaria::on_horizontalSlider_valueChanged(int value)
{
    //ui->label_plus->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(value));
    A.write_to_arduino(QString("%1").arg(value));
    //qDebug() << value;
}


void Zakaria::on_horizontalSlider_2_valueChanged(int value)
{
    //ui->label_plus->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%4</span>").arg(value));
    A.write_to_arduino(QString("%1").arg(value));
    //qDebug() << value;
}


//****************************************************************************************************************************


void Zakaria::on_pushButton_ajou_z_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSound::play ("C:/Users/HP/Music/ppp.wav");

}
void Zakaria::on_pushButton_ajou_p_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_ajou_f_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_return_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_return1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_home0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton__clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}

void Zakaria::on_pushButton_ajouter_z_clicked()
{
    porte p;
    p.ajouter(ui);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_ajouter_f_clicked()
{
    fenetres f;
    f.ajouter(ui);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_affich_z_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
    /*
    if(arduino->isWritable()){
        arduino->write("0");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
    */
}
void Zakaria::on_pushButton_aff_porte_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    porte p;
    p.AfficherTable(ui);

    porte *k= new porte();
    ui->tableView_porte->setModel(k->trier());

   QString zaki;
   zaki= p.calculer_porte();
   ui->textEdit_porte->setText(zaki);

   QString zaki1;
   zaki1= p.calculer_porte1();
   ui->textEdit_porte1->setText(zaki1);

   QSound::play ("C:/Users/HP/Music/ppp.wav");

    ////////////
}

void Zakaria::on_pushButton_modf_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    porte p;
    p.AfficherTable(ui);
    porte *k= new porte();
    ui->tableView_supp->setModel(k->trier());

    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_4_return_aff_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_return_mod_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_home_modf_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_home_suup_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton___clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_return_supp_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_supp_clicked()
{
    if  (ui->tableView_supp->selectionModel()->hasSelection())
        {
        porte p;
        p.supprimer(ui);
        p.AfficherTable(ui);
        }
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_tableView_supp_activated(const QModelIndex &index)
{
    {
        //pour modifier la porte :
        ui->lineEdit_chang_p->setText(ui->tableView_supp->model()->data(ui->tableView_supp->model()->index(ui->tableView_supp->selectionModel()->currentIndex().row(),0)).toString());
        ui->comboBox_4->setCurrentText(ui->tableView_supp->model()->data(ui->tableView_supp->model()->index(ui->tableView_supp->selectionModel()->currentIndex().row(),1)).toString());
        ui->comboBox_5->setCurrentText(ui->tableView_supp->model()->data(ui->tableView_supp->model()->index(ui->tableView_supp->selectionModel()->currentIndex().row(),2)).toString());
    }
}
void Zakaria::on_pushButton_change_clicked()
{
    if  (ui->tableView_supp->selectionModel()->hasSelection())
        {
        porte p;
        p.modifier(ui);
        p.AfficherTable(ui);
        }
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_aff_fenetre_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    fenetres f;
    f.AfficherTable(ui);

    fenetres *k= new fenetres();
    ui->tableView_mod_f->setModel(k->trier());

    QString zaki;
    zaki= f.calculer_fenetre();
    ui->textEdit_fenetre->setText(zaki);

    QString zaki1;
    zaki1= f.calculer_fenetre1();
    ui->textEdit_fenetre1->setText(zaki1);

    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_modff_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

    fenetres *k= new fenetres();
    ui->tableView_suup_f->setModel(k->trier());

    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_home_md_f_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_returnff_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_rf_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_suup_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_tableView_suup_f_activated(const QModelIndex &index)
{
    //pour modifier fenetre :
    ui->lineEdit_supp_f->setText(ui->tableView_suup_f->model()->data(ui->tableView_suup_f->model()->index(ui->tableView_suup_f->selectionModel()->currentIndex().row(),0)).toString());
    ui->comboBox_6->setCurrentText(ui->tableView_suup_f->model()->data(ui->tableView_suup_f->model()->index(ui->tableView_suup_f->selectionModel()->currentIndex().row(),1)).toString());
    ui->comboBox_7->setCurrentText(ui->tableView_suup_f->model()->data(ui->tableView_suup_f->model()->index(ui->tableView_suup_f->selectionModel()->currentIndex().row(),2)).toString());
}
void Zakaria::on_pushButton_suup_f_clicked()
{
     if  (ui->tableView_suup_f->selectionModel()->hasSelection())
    {
    fenetres f;
    f.supprimer(ui);
    f.AfficherTable(ui);
    }

     QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_pushButton_chang_ff_clicked()
{
    if  (ui->tableView_suup_f->selectionModel()->hasSelection())
    {
    fenetres f;
    f.modifier(ui);
    f.AfficherTable(ui);
    }
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}

void Zakaria::on_pushButton_close_z_clicked()
{
    close();
    zSysteTraymIcon->showMessage("Notification","\n you closed the application ",QSystemTrayIcon::Information);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}
void Zakaria::on_lineEdit_cher_textChanged(const QString &arg1)
{
    porte p;
    p.chercher(ui);
    QSound::play ("C:/Users/HP/Music/ppp.wav");
}

void Zakaria::on_pushButton_opp_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

