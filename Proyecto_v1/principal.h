#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <menu_dialog.h>
#include <pantalla_modificar.h>
#include <pantalla_mostrar.h>
#include <pantalla_registrar.h>
#include <ordenar_dialog.h>


class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);

    menu_dialog *menu;
    pantalla_mostrar *p_mostrar;
    pantalla_modificar *p_modificar;
    pantalla_registrar *p_registrar;
    ordenar_dialog *p_ordenar;


    void comenzar();


signals:

public slots:

    void abre_menu();
    void cierra_menu();
    void abre_mostrar();
    void abre_ordenar();

};

#endif // PRINCIPAL_H
