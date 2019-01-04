#include "tiroir.h"
#include <QDebug>
tiroir::tiroir()
{
    ID=0;
    TYPE="";
    NOM="";
    POIDS=0;
}
tiroir::tiroir(QString TYPE,QString NOM)
{
    //this->ID=ID;
    this->TYPE=TYPE;
    this->NOM=NOM;

}
/*tiroir::tiroir(QString TYPE,QString NOM,int POIDS)
{
    this->ID=ID;
    this->TYPE=TYPE;
    this->NOM=NOM;
    this->POIDS=POIDS;

}*/
int tiroir::get_ID(){return ID;}
QString tiroir::get_TYPE(){return TYPE;}
QString tiroir::get_NOM(){return NOM;}
int tiroir::get_POIDS(){return POIDS;}
void tiroir::set_POIDS(int POIDS){this->POIDS=POIDS;}
void tiroir::set_NOM(QString NOM){this->NOM=NOM;}
void tiroir::set_TYPE(QString TYPE){this->TYPE=TYPE;}
void tiroir::set_ID(int ID){this->ID=ID;}

bool tiroir::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("INSERT INTO tiroir ( TYPE, NOM,POIDS) "
                        "VALUES ( :TYPE, :NOM, :POIDS)");

    query.bindValue(":TYPE", TYPE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":POIDS", POIDS);

    return    query.exec();
}
QSqlQueryModel * tiroir::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tiroir");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("POIDS"));
    return model;
}

QSqlQueryModel * tiroir::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tiroir ORDER BY ID");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("POIDS"));
    return model;
}

bool tiroir::supprimer(int ID)
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("Delete from tiroir where ID = :ID ");
query.bindValue(":ID", res);
return    query.exec();
}
bool tiroir::modifier()
{
    QSqlQuery query;
    QString res= QString(TYPE);
    QString res1= QString(NOM);
    query.prepare(" UPDATE tiroir set TYPE=:TYPE, NOM=:NOM where ID=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":TYPE",res);
    query.bindValue(":NOM",res1);
    return query.exec();
}

