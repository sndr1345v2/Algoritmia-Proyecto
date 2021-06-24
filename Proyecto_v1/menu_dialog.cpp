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




void menu_dialog::on_boton_mostar_clicked()
{
   emit mostrar_pantalla();
}


void menu_dialog::on_boton_ordenar_clicked()
{
    emit ordenar_pantalla();
}

void menu_dialog::on_boton_modificar_clicked()
{
    emit modificar_pantalla();

}

void menu_dialog::on_boton_capturar_clicked()
{
    emit capturar_pantalla();
}

void menu_dialog::on_boton_buscar_clicked()
{
    emit buscar_pantalla();
}
