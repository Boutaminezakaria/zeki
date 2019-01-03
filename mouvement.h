#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include <QDialog>

namespace Ui {
class mouvement;
}

class mouvement : public QDialog
{
    Q_OBJECT

public:
    explicit mouvement(QWidget *parent = nullptr);
    ~mouvement();

private:
    Ui::mouvement *ui;
};

#endif // MOUVEMENT_H
