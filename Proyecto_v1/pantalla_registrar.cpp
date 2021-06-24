#include "pantalla_registrar.h"
#include "ui_pantalla_registrar.h"

pantalla_registrar::pantalla_registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_registrar)
{
    ui->setupUi(this);
}

pantalla_registrar::~pantalla_registrar()
{
    delete ui;
}

void pantalla_registrar::on_pushButton_5_clicked()
{
    regresar_menu();
}
