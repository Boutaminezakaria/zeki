#ifndef REPAS_H
#define REPAS_H
#include <QDebug>
#include <QDialog>

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Repas

{
public:
    Repas();
    Repas(int,QString,int);


      int get_ID2();
      int get_T();
      QString get_NOM();
      void set_T(int);
      void set_ID2(int);
      void set_NOM(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

private:
    QString NOM;
    int ID2,T;

};


#endif // REPAS_H
