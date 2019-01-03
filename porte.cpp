#include <QMessageBox>
#include "QString"
#include "QMainWindow"
#include "zakaria.h"
#include "porte.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include<QSystemTrayIcon>

porte::porte()
{
    num=0;
    type="";
    etat="";
}
porte::porte(int num,QString type,QString etat)
{
    this->num=num;
    this->type=type;
    this->etat=etat;
}
QString porte::calculer_porte()
{
    QSqlQuery q;
    q.prepare("select count(*)from PORTE where etat=:etat");
    q.bindValue(":etat","Active");
    q.exec();
    while (q.next())
    {
    return q.value(0).toString();
    }
}

QString porte::calculer_porte1()
{
    QSqlQuery q;
    q.prepare("select count(*)from PORTE where etat=:etat");
    q.bindValue(":etat","No_Active");
    q.exec();
    while (q.next())
    {
    return q.value(0).toString();
    }
}
bool porte::cher(Ui::Zakaria *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    if(ui->lineEdit->text() != "")
    {
    q.prepare("select num,type,etat from PORTE where num=:num");
    q.bindValue(":num",ui->lineEdit->text());
    q.exec();
    modal->setQuery(q);
    ui->tableView_porte->setModel(modal);
    return true;
    }
    else
    {
    return false;
    }
}

bool porte::ajouter(Ui::Zakaria *ui)
{

    QSqlQuery q;
    q.prepare("INSERT into PORTE(num, type, etat) VALUES (:num, :type, :etat)");
    q.bindValue(":num",ui->lineEdit->text());
    q.bindValue(":type",ui->comboBox_1->currentText());
    q.bindValue(":etat",ui->comboBox_2->currentText());
    if (    q.exec())
    {
                    //std::cout << "Ça marche ! 🙂" << std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("porte a ete ajoute ");
                    //msgBox.exec();
     zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
     zSystemTrayIcon->show();
     zSystemTrayIcon->showMessage("Notification","\n la porte a ete ajouter ",QSystemTrayIcon::Information);
     return true ;
     }
     else
     {
     if (ui->lineEdit->text()=="")
     {
                    //std::cout<< "Ça marche pas ! :(" <<std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("porte n a ete ajoute ");
                    //msgBox.exec();
      zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
      zSystemTrayIcon->show();
      zSystemTrayIcon->showMessage("Notification","\n saisir le num  ",QSystemTrayIcon::Information);
      return false;
      }
      else if (porte::cher(ui)==true)
     {
                    //std::cout<< "Ça marche pas ! :(" <<std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("porte n a ete ajoute ");
                    //msgBox.exec();
      zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
      zSystemTrayIcon->show();
      zSystemTrayIcon->showMessage("Notification","\n le numero exist déja  ",QSystemTrayIcon::Information);
      return false;
      }
      else
      {
                    //std::cout<< "Ça marche pas ! :(" <<std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("porte n a ete ajoute ");
                    //msgBox.exec();
      zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
      zSystemTrayIcon->show();
      zSystemTrayIcon->showMessage("Notification","\n le num doit etre de type int  ",QSystemTrayIcon::Information);
      return false;
      }

      }
}

void porte::AfficherTable(Ui::Zakaria *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select num,type,etat from PORTE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_porte->setModel(modal);
    ui->tableView_supp->setModel(modal);
}
void porte::chercher(Ui::Zakaria *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    if(ui->lineEdit_cher->text() != "")
    {
    q.prepare("select num,type,etat from PORTE where num=:num");
    q.bindValue(":num",ui->lineEdit_cher->text());
    q.exec();
    modal->setQuery(q);
    ui->tableView_porte->setModel(modal);
    ui->tableView_supp->setModel(modal);
    }
    else
    {
    q.prepare("select num,type,etat from PORTE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_porte->setModel(modal);
    ui->tableView_supp->setModel(modal);
    }

}
bool porte::supprimer(Ui::Zakaria *ui)
{
    QSqlQuery q;
    q.prepare("DELETE FROM PORTE WHERE NUM ='"+ui->tableView_supp->model()->data(ui->tableView_supp->model()->index(ui->tableView_supp->selectionModel()->currentIndex().row(),0)).toString()+"'");
    if(q.exec())
    {
    zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
    zSystemTrayIcon->show();
    zSystemTrayIcon->showMessage("Notification","\n la porte a ete supprimer ",QSystemTrayIcon::Information);
    return true;
    }
    else
    { return false;}
}
bool porte::modifier(Ui::Zakaria *ui)
{
    QSqlQuery q;
    q.prepare("update PORTE set num=:num,type=:type,etat=:etat where num=:num" );
    q.bindValue(":num",ui->lineEdit_chang_p->text());
    q.bindValue(":type",ui->comboBox_4->currentText());
    q.bindValue(":etat",ui->comboBox_5->currentText());
    if(q.exec())
    {

                //QMessageBox msgBox ;
                //msgBox.setText("la porte a ete modifie ");
                //msgBox.exec();
     zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
     zSystemTrayIcon->show();
     zSystemTrayIcon->showMessage("Notification","\n la porte a ete modifier ",QSystemTrayIcon::Information);
        return true;
     }
     else
     {
                //QMessageBox msgBox ;
                //msgBox.setText("la porte n'est pas modifie ");
                //msgBox.exec();
     zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
     zSystemTrayIcon->show();
     zSystemTrayIcon->showMessage("Notification","\n vous pouvez pas changer le NUM !! ",QSystemTrayIcon::Information);
     return false;
     }
}

QSqlQueryModel *porte::trier()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  num,type,etat from PORTE order by NUM");
    return model ;
}




















