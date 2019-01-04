#include "repas.h"

#include <QDebug>
#include "mainwindow.h"

Repas::Repas()
{
    ID2=0;
    NOM="";
    T=0;
}
Repas::Repas(int ID2,QString NOM, int T)
{
    this->ID2=ID2;
    this->NOM=NOM;
    this->T=T;
}

int Repas::get_ID2(){return ID2;}
QString Repas::get_NOM(){return NOM ;}

int Repas::get_T(){return T;}
void Repas::set_T(int T){this->T= T ;}
void Repas::set_NOM(QString nom){this->NOM=nom;}
void Repas::set_ID2(int ID){this->ID2=ID;}

bool Repas::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID2);
    query.prepare("INSERT INTO Repas (NOM, T,ACHEVEE) "
                        "VALUES (:NOM, :T,:ACHEVEE )");
    query.bindValue(":NOM", NOM);
    query.bindValue(":T", T);
    query.bindValue(":ACHEVEE", "NON");

    return    query.exec();
}
QSqlQueryModel * Repas::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Repas");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID2"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("T"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ACHEVEE"));
    return model;
}

bool Repas::supprimer(int ID)
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("Delete from Repas where ID2 = :ID2 ");
query.bindValue(":ID2", res);
return    query.exec();
}
bool Repas::modifier()
{
    QSqlQuery query;
    query.prepare(" UPDATE Repas set ACHEVEE=:ACHEVEE where NOM=:NOM");
    query.bindValue(":NOM",NOM);
    query.bindValue(":ACHEVEE","OUI");
    return query.exec();
}
