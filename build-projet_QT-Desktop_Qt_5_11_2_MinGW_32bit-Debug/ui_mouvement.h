/********************************************************************************
** Form generated from reading UI file 'mouvement.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUVEMENT_H
#define UI_MOUVEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_mouvement
{
public:

    void setupUi(QDialog *mouvement)
    {
        if (mouvement->objectName().isEmpty())
            mouvement->setObjectName(QStringLiteral("mouvement"));
        mouvement->resize(400, 300);

        retranslateUi(mouvement);

        QMetaObject::connectSlotsByName(mouvement);
    } // setupUi

    void retranslateUi(QDialog *mouvement)
    {
        mouvement->setWindowTitle(QApplication::translate("mouvement", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mouvement: public Ui_mouvement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUVEMENT_H
