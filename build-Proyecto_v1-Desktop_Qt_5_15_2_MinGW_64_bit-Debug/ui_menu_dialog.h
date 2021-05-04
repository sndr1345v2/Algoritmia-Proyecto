/********************************************************************************
** Form generated from reading UI file 'menu_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_DIALOG_H
#define UI_MENU_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_menu_dialog
{
public:
    QPushButton *boton_capturar;
    QPushButton *boton_modificar;
    QPushButton *boton_mostar;

    void setupUi(QDialog *menu_dialog)
    {
        if (menu_dialog->objectName().isEmpty())
            menu_dialog->setObjectName(QString::fromUtf8("menu_dialog"));
        menu_dialog->resize(512, 326);
        boton_capturar = new QPushButton(menu_dialog);
        boton_capturar->setObjectName(QString::fromUtf8("boton_capturar"));
        boton_capturar->setGeometry(QRect(170, 70, 161, 41));
        boton_modificar = new QPushButton(menu_dialog);
        boton_modificar->setObjectName(QString::fromUtf8("boton_modificar"));
        boton_modificar->setGeometry(QRect(170, 120, 161, 41));
        boton_mostar = new QPushButton(menu_dialog);
        boton_mostar->setObjectName(QString::fromUtf8("boton_mostar"));
        boton_mostar->setGeometry(QRect(170, 170, 161, 41));

        retranslateUi(menu_dialog);

        QMetaObject::connectSlotsByName(menu_dialog);
    } // setupUi

    void retranslateUi(QDialog *menu_dialog)
    {
        menu_dialog->setWindowTitle(QCoreApplication::translate("menu_dialog", "Dialog", nullptr));
        boton_capturar->setText(QCoreApplication::translate("menu_dialog", "CAPTURAR", nullptr));
        boton_modificar->setText(QCoreApplication::translate("menu_dialog", "MODIFICAR", nullptr));
        boton_mostar->setText(QCoreApplication::translate("menu_dialog", "MOSTRAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu_dialog: public Ui_menu_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_DIALOG_H
