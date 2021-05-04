/********************************************************************************
** Form generated from reading UI file 'pantalla_mostrar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTALLA_MOSTRAR_H
#define UI_PANTALLA_MOSTRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_pantalla_mostrar
{
public:
    QTableView *table_clientes;
    QLabel *label;
    QLabel *label_2;
    QTableView *table_articulos;
    QLabel *label_3;
    QTableView *table_ventas;
    QLabel *label_4;
    QTableView *table_encuestas;
    QPushButton *pushButton_menu;

    void setupUi(QDialog *pantalla_mostrar)
    {
        if (pantalla_mostrar->objectName().isEmpty())
            pantalla_mostrar->setObjectName(QString::fromUtf8("pantalla_mostrar"));
        pantalla_mostrar->resize(777, 556);
        table_clientes = new QTableView(pantalla_mostrar);
        table_clientes->setObjectName(QString::fromUtf8("table_clientes"));
        table_clientes->setGeometry(QRect(20, 60, 691, 71));
        label = new QLabel(pantalla_mostrar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 47, 13));
        label_2 = new QLabel(pantalla_mostrar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 160, 47, 13));
        table_articulos = new QTableView(pantalla_mostrar);
        table_articulos->setObjectName(QString::fromUtf8("table_articulos"));
        table_articulos->setGeometry(QRect(20, 180, 691, 81));
        label_3 = new QLabel(pantalla_mostrar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 290, 47, 13));
        table_ventas = new QTableView(pantalla_mostrar);
        table_ventas->setObjectName(QString::fromUtf8("table_ventas"));
        table_ventas->setGeometry(QRect(20, 310, 691, 71));
        label_4 = new QLabel(pantalla_mostrar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 410, 47, 13));
        table_encuestas = new QTableView(pantalla_mostrar);
        table_encuestas->setObjectName(QString::fromUtf8("table_encuestas"));
        table_encuestas->setGeometry(QRect(20, 430, 691, 71));
        pushButton_menu = new QPushButton(pantalla_mostrar);
        pushButton_menu->setObjectName(QString::fromUtf8("pushButton_menu"));
        pushButton_menu->setGeometry(QRect(20, 0, 91, 21));

        retranslateUi(pantalla_mostrar);

        QMetaObject::connectSlotsByName(pantalla_mostrar);
    } // setupUi

    void retranslateUi(QDialog *pantalla_mostrar)
    {
        pantalla_mostrar->setWindowTitle(QCoreApplication::translate("pantalla_mostrar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pantalla_mostrar", "Clientes", nullptr));
        label_2->setText(QCoreApplication::translate("pantalla_mostrar", "Art\303\255culos", nullptr));
        label_3->setText(QCoreApplication::translate("pantalla_mostrar", "Ventas", nullptr));
        label_4->setText(QCoreApplication::translate("pantalla_mostrar", "Encuestas", nullptr));
        pushButton_menu->setText(QCoreApplication::translate("pantalla_mostrar", "Regresar a Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pantalla_mostrar: public Ui_pantalla_mostrar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTALLA_MOSTRAR_H
