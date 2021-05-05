#include "principal.h"



principal::principal(QObject *parent) : QObject(parent)
{

    menu = new menu_dialog();

    p_mostrar = new pantalla_mostrar();
    p_modificar = new pantalla_modificar();
    p_registrar = new pantalla_registrar ();
    p_ordenar = new ordenar_dialog();

    QObject::connect(menu, SIGNAL(mostrar_pantalla()), this, SLOT(abre_mostrar()));
    QObject::connect(p_mostrar, SIGNAL(regresa_menu()), this, SLOT(abre_menu()));
    QObject::connect(menu, SIGNAL(ordenar_pantalla()), this, SLOT(abre_ordenar()));
    QObject::connect(p_ordenar, SIGNAL(regresa_menu()), this, SLOT(abre_menu()));
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
    else if(p_ordenar->isVisible()){

        menu->setVisible(true);
        p_ordenar->setVisible(false);
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

void principal::abre_ordenar()
{
    menu->hide();
    p_ordenar->setVisible(true);
}


