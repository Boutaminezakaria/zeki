#ifndef PORTE_H
#define PORTE_H



#include <iostream>
#include <QtSql/QSqlQueryModel>
#include "QMainWindow"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>


class porte
{
private:
    int num ;
    QString type;
    QString etat;
    QSystemTrayIcon *zSystemTrayIcon;

public:
    porte();
    porte(int,QString, QString);
    bool ajouter(Ui::Zakaria *ui);
    void AfficherTable(Ui::Zakaria *ui);
    bool modifier(Ui::Zakaria *ui);
    bool supprimer(Ui::Zakaria *ui);
    void chercher(Ui::Zakaria *ui);
    bool cher(Ui::Zakaria *ui);
    QString calculer_porte();
    QString calculer_porte1();
    QSqlQueryModel *trier();
    //QSqlQueryModel *rechercher_porte(int numero ,Ui::mainwindow_affich *ui);

};


#endif // PORTE_H
