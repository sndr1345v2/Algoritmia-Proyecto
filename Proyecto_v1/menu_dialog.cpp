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

void menu_dialog::on_botoncapturar_clicked()
{
  emit (confirma_boton(true));
}

void menu_dialog::on_botonmodificar_clicked()
{

}
