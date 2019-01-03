#include <QMessageBox>
#include "QString"
#include "QMainWindow"
#include "zakaria.h"
#include "fenetres.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>

fenetres::fenetres()
{
    num=0;
    type="";
    etat="";
}
fenetres::fenetres(int num,QString type,QString etat)
{
    this->num=num;
    this->type=type;
    this->etat=etat;
}

QString fenetres::calculer_fenetre()
{
    QSqlQuery q;

        q.prepare("select count(*)from FENETRE where etat=:etat");
        q.bindValue(":etat","Active");
        q.exec();
        while (q.next())
        {
        return q.value(0).toString();
        }
}

QString fenetres::calculer_fenetre1()
{
    QSqlQuery q;

        q.prepare("select count(*)from FENETRE where etat=:etat");
        q.bindValue(":etat","No_Active");
        q.exec();
        while (q.next())
        {
        return q.value(0).toString();
        }
}


bool fenetres::ajouter(Ui::Zakaria *ui)
{
    QSqlQuery q;
        q.prepare("INSERT into FENETRE (num, type, etat) VALUES (:num, :type, :etat)");
        q.bindValue(":num",ui->lineEdit_3->text());
        q.bindValue(":type",ui->comboBox->currentText());
        q.bindValue(":etat",ui->comboBox_3->currentText());
        if (q.exec())
        {
                    //std::cout << "Ça marche ! 🙂" << std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("la fenetre a ete ajoute ");
                    //msgBox.exec();
            zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
            zSystemTrayIcon->show();
            zSystemTrayIcon->showMessage("Notification","\n la fenetre a ete ajoute ",QSystemTrayIcon::Information);
                    return true ;
        }
        else
        {
                    //std::cout<< "Ça marche pas ! :(" <<std::endl;
                    //QMessageBox msgBox ;
                    //msgBox.setText("la fenetre n a ete ajoute ");
                    //msgBox.exec();
            zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
            zSystemTrayIcon->show();
            zSystemTrayIcon->showMessage("Notification","\n la fenetre n'est pas ajoute ",QSystemTrayIcon::Information);
                    return false;
        }
}

void fenetres::AfficherTable(Ui::Zakaria *ui)
{
    QSqlQuery q;
    QSqlQueryModel *modal=new QSqlQueryModel();
    q.prepare("select num,type,etat from FENETRE");
    q.exec();
    modal->setQuery(q);
    ui->tableView_mod_f->setModel(modal);
    ui->tableView_suup_f->setModel(modal);

}

bool fenetres::supprimer(Ui::Zakaria *ui)
{
    QSqlQuery q;

         q.prepare("DELETE FROM FENETRE WHERE NUM ='"+ui->tableView_suup_f->model()->data(ui->tableView_suup_f->model()->index(ui->tableView_suup_f->selectionModel()->currentIndex().row(),0)).toString()+"'");


         if(q.exec())
         {
             zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
             zSystemTrayIcon->show();
             zSystemTrayIcon->showMessage("Notification","\n la fenetre a ete supprimé ",QSystemTrayIcon::Information);
             return true;
         }
         else { return false;
}
}

bool fenetres::modifier(Ui::Zakaria *ui)
{
    QSqlQuery q;
    q.prepare("update FENETRE set num=:num,type=:type,etat=:etat where num=:num" );
    q.bindValue(":num",ui->lineEdit_supp_f->text());
    q.bindValue(":type",ui->comboBox_6->currentText());
    q.bindValue(":etat",ui->comboBox_7->currentText());

    if(q.exec())
    {

                //QMessageBox msgBox ;
                //msgBox.setText("la fenetre a ete modifie ");
                //msgBox.exec();
        zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
        zSystemTrayIcon->show();
        zSystemTrayIcon->showMessage("Notification","\n la fenetre a ete modifier ",QSystemTrayIcon::Information);
        return true;
    }
    else
{
                //QMessageBox msgBox ;
                //msgBox.setText("la fenetre n'est pas modifie ");
                //msgBox.exec();
        zSystemTrayIcon =new QSystemTrayIcon (QIcon(QPixmap("C:/Users/HP/Pictures/gg.png")));
        zSystemTrayIcon->show();
        zSystemTrayIcon->showMessage("Notification","\n vous pouvez pas changer le NUM !! ",QSystemTrayIcon::Information);
        return false;
}
}

QSqlQueryModel *fenetres::trier()
{
    QSqlQueryModel *model= new QSqlQueryModel() ;
    model->setQuery("select  num,type,etat from FENETRE order by NUM");
   return model ;
}























