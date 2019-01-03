#ifndef FENETRES_H
#define FENETRES_H

#include <iostream>
#include <QtSql/QSqlQueryModel>
#include "QMainWindow"
#include "ui_mainwindow.h"
#include <QSystemTrayIcon>


class fenetres
{
private:
    int num ;
    QString type;
    QString etat;
    QSystemTrayIcon *zSystemTrayIcon;
public:
    fenetres();
    fenetres(int,QString, QString);
    bool ajouter(Ui::Zakaria *ui);
    void AfficherTable(Ui::Zakaria *ui);
    bool modifier(Ui::Zakaria *ui);
    bool supprimer(Ui::Zakaria *ui);
    QSqlQueryModel *trier();
    QString calculer_fenetre();
    QString calculer_fenetre1();
    //QSqlQueryModel *rechercher_porte(int numero ,Ui::mainwindow_affich *ui);

};


#endif // FENETRES_H
