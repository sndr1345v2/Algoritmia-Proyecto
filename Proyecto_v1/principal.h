#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <menu_dialog.h>
#include <pantalla_modificar.h>
#include <pantalla_mostrar.h>
#include <pantalla_registrar.h>


class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);

    menu_dialog *menu;
    pantalla_mostrar *p_mostrar;
    pantalla_modificar *p_modificar;
    pantalla_registrar *p_registrar;

    void comenzar();


signals:

public slots:

    void abre_menu();
    void cierra_menu();
    void abre_mostrar();

};

#endif // PRINCIPAL_H
