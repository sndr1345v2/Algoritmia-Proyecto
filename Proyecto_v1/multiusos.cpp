#include "multiusos.h"
#include "ui_multiusos.h"

multiusos::multiusos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multiusos)
{
    ui->setupUi(this);
}

multiusos::~multiusos()
{
    delete ui;
}
