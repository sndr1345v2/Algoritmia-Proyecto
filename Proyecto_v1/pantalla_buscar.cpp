#include "pantalla_buscar.h"
#include "ui_pantalla_buscar.h"

pantalla_buscar::pantalla_buscar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_buscar)
{
    ui->setupUi(this);
}

pantalla_buscar::~pantalla_buscar()
{
    delete ui;
}

void pantalla_buscar::on_pushButton_2_clicked()
{
    emit regresar_menu();
}
