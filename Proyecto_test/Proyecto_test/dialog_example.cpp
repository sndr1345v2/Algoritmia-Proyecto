#include "dialog_example.h"
#include "ui_dialog_example.h"

dialog_example::dialog_example(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_example)
{
    ui->setupUi(this);
}

dialog_example::~dialog_example()
{
    delete ui;
}
