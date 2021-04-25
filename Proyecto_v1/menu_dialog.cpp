#include "menu_dialog.h"
#include "ui_menu_dialog.h"

menu_dialog::menu_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_dialog)
{
    ui->setupUi(this);
}

menu_dialog::~menu_dialog()
{
    delete ui;
}
