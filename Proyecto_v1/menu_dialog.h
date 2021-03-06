#ifndef MENU_DIALOG_H
#define MENU_DIALOG_H

#include <QDialog>
#include <pantalla_mostrar.h>

namespace Ui {
class menu_dialog;
}

class menu_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit menu_dialog(QWidget *parent = nullptr);
    ~menu_dialog();

private slots:


    void on_boton_mostar_clicked();

    void on_boton_ordenar_clicked();

    void on_boton_modificar_clicked();

    void on_boton_capturar_clicked();

    void on_boton_buscar_clicked();

private:
    Ui::menu_dialog *ui;
    pantalla_mostrar *mostrar_dialog;

signals:
    void modificar_pantalla();//
    void mostrar_pantalla();
    void ordenar_pantalla();
    void capturar_pantalla();
    void buscar_pantalla();
};

#endif // MENU_DIALOG_H
