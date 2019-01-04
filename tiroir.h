#ifndef TIROIR_H
#define TIROIR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class tiroir
{
public:
    tiroir();
    tiroir(QString,QString);
  //  tiroir(int,QString,QString,int);
    int get_ID();
    QString get_TYPE();
    QString get_NOM();
    int get_POIDS();
    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * trier();
    bool supprimer(int);
    bool modifier();
    void set_POIDS(int);
    void set_NOM(QString);
    void set_TYPE(QString);
    void set_ID(int);
private:
    QString TYPE,NOM;
    int ID,POIDS;

};


#endif // TIROIR_H
