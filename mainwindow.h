#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <crudfood.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
//    void on_pushButton_affich_clicked();
    void on_pushButton_addType_clicked();
    void on_pushButton_readType_clicked();
    void on_pushButton_clicked();

// void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    crudfood * cr;



};

#endif // MAINWINDOW_H
