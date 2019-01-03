#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <smtp.h>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include "arduino.h"



namespace Ui {
class Zakaria;
}

class Zakaria : public QMainWindow
{
    Q_OBJECT

public:


    explicit Zakaria(QWidget *parent = nullptr);
    ~Zakaria();

private slots:
    void on_pushButton_ajou_z_clicked();

    void on_pushButton_ajou_p_clicked();

    void on_pushButton_ajou_f_clicked();

    void on_pushButton_return_0_clicked();

    void on_pushButton_return1_clicked();

    void on_pushButton_home0_clicked();

    void on_pushButton_return_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_ajouter_z_clicked();

    void on_pushButton_ajouter_f_clicked();

    void on_pushButton_affich_z_clicked();

    void on_pushButton_aff_porte_clicked();

    void on_pushButton_modf_clicked();

    void on_pushButton_4_return_aff_clicked();

    void on_pushButton_return_mod_clicked();

    void on_pushButton_home_modf_clicked();

    void on_pushButton_home_suup_clicked();

    void on_pushButton_return_supp_clicked();

    void on_pushButton_supp_clicked();

    void on_tableView_supp_activated(const QModelIndex &index);

    void on_pushButton_change_clicked();

    void on_pushButton_aff_fenetre_clicked();

    void on_pushButton_modff_clicked();

    void on_pushButton__clicked();

    void on_pushButton_home_md_f_clicked();

    void on_pushButton_returnff_clicked();

    void on_pushButton_suup_home_clicked();

    void on_pushButton_suup_f_clicked();

    void on_pushButton_chang_ff_clicked();

    void on_tableView_suup_f_activated(const QModelIndex &index);

    void on_pushButton___clicked();

    void on_pushButton_close_z_clicked();

    void on_lineEdit_cher_textChanged(const QString &arg1);

    void on_pushButton_opp_clicked();

    void on_pushButton_rf_clicked();

    bool update_label();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::Zakaria *ui;
    QSystemTrayIcon *zSysteTraymIcon;
    QByteArray data; // variable contenant les données reçues
    Arduino A;

};

#endif // MAINWINDOW_H
