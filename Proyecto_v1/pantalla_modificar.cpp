#include "pantalla_modificar.h"
#include "ui_pantalla_modificar.h"

pantalla_modificar::pantalla_modificar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_modificar)
{
    ui->setupUi(this);
}

pantalla_modificar::~pantalla_modificar()
{
    delete ui;
}