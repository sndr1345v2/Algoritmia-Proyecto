#include "principal.h"



principal::principal(QObject *parent) : QObject(parent)
{

    menu = new menu_dialog();

    p_mostrar = new pantalla_mostrar();
    p_modificar = new pantalla_modificar();
    p_registrar = new pantalla_registrar ();

    QObject::connect(menu, SIGNAL(mostrar_pantalla()), this, SLOT(abre_mostrar()));
    QObject::connect(p_mostrar, SIGNAL(regresa_menu()), this, SLOT(abre_menu()));
}


void principal::comenzar()
{
    menu->show();
}

void principal::abre_menu()
{
    if(p_mostrar->isVisible()){

        menu->setVisible(true);
        p_mostrar->setVisible(false);
    }
    else if (p_modificar->isVisible()){

        menu->setVisible(true);
        p_modificar->setVisible(false);
    }
    else if (p_registrar->isVisible()){

        menu->setVisible(true);
        p_registrar->setVisible(false);
    }

}

void principal::cierra_menu()
{
    menu->hide();
}

void principal::abre_mostrar()
{
    menu->hide();
    p_mostrar->setVisible(true);
}


