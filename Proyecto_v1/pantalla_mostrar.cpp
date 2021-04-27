#include "pantalla_mostrar.h"
#include "ui_pantalla_mostrar.h"

pantalla_mostrar::pantalla_mostrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_mostrar)
{
    ui->setupUi(this);
}

pantalla_mostrar::~pantalla_mostrar()
{
    delete ui;
}
