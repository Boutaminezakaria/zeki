#include "mouvement.h"
#include "ui_mouvement.h"

mouvement::mouvement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mouvement)
{
    ui->setupUi(this);
}

mouvement::~mouvement()
{
    delete ui;
}
