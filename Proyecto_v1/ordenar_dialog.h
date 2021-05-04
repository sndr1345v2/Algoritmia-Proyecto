#ifndef ORDENAR_DIALOG_H
#define ORDENAR_DIALOG_H

#include <QDialog>

namespace Ui {
class ordenar_dialog;
}

class ordenar_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ordenar_dialog(QWidget *parent = nullptr);
    ~ordenar_dialog();

private:
    Ui::ordenar_dialog *ui;
    vector<template> merge();
    vector<template> merge_sort();

};

#endif // ORDENAR_DIALOG_H
