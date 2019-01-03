#include <QApplication>
#include <iostream>

#include <QDebug>
#include <QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include "QMessageBox"
#include "zakaria.h"

#define q2c(string) string.toStdString()
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Zakaria w;
    w.setWindowTitle("Securite");
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setUserName("zakaria");
        db.setPassword("esprit2018");
        db.setDatabaseName("source_Projet2A");
    QSqlQuery q;
        if(db.open())
        {
            std::cout << "Vous êtes maintenant connecté à " << q2c(db.hostName()) << std::endl;
         //db.close();
        }
        else
        {
            std::cout << "La connexion a échouée, désolé" << std::endl;
        //qDebug()<<"erreur:"<<db.lastError().text();
        }
        w.show();
    return a.exec();
}
