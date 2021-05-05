#ifndef ORDENAR_DIALOG_H
#define ORDENAR_DIALOG_H

#include <QDialog>
#include <pantalla_mostrar.h>

namespace Ui {
class ordenar_dialog;
}

class ordenar_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ordenar_dialog(QWidget *parent = nullptr);
    ~ordenar_dialog();

    pantalla_mostrar objeto_mostrar;

private:
    Ui::ordenar_dialog *ui;

    void test_find();
    /*vector<template> merge();
    vector<template> merge_sort();*/


signals:
    void regresa_menu();

private slots:
    void on_pushButton_regresarMenu_clicked();
};

#endif // ORDENAR_DIALOG_H
