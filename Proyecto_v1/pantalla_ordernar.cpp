#include "pantalla_ordernar.h"
#include "ui_pantalla_ordernar.h"

pantalla_ordernar::pantalla_ordernar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_ordernar)
{
    ui->setupUi(this);
}

pantalla_ordernar::~pantalla_ordernar()
{
    delete ui;
}
