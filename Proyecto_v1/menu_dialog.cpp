#include "menu_dialog.h"
#include "ui_menu_dialog.h"

menu_dialog::menu_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu_dialog)
{
    ui->setupUi(this);
    mostrar_dialog = new pantalla_mostrar;

}

menu_dialog::~menu_dialog()
{
    delete ui;
}

void menu_dialog::on_botoncapturar_clicked()
{
    mostrar_dialog->exec();
}

void menu_dialog::on_botonmodificar_clicked()
{

}
