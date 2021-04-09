/********************************************************************************
** Form generated from reading UI file 'schermata.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHERMATA_H
#define UI_SCHERMATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Schermata
{
public:

    void setupUi(QWidget *Schermata)
    {
        if (Schermata->objectName().isEmpty())
            Schermata->setObjectName(QString::fromUtf8("Schermata"));
        Schermata->resize(800, 600);

        retranslateUi(Schermata);

        QMetaObject::connectSlotsByName(Schermata);
    } // setupUi

    void retranslateUi(QWidget *Schermata)
    {
        Schermata->setWindowTitle(QCoreApplication::translate("Schermata", "Schermata", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Schermata: public Ui_Schermata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHERMATA_H
