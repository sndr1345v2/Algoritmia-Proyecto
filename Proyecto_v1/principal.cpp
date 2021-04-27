#include "principal.h"

principal::principal(QObject *parent) : QObject(parent)
{
     menu = new menu_dialog();
     modificar = new pantalla_modificar();
   //  QObject::connect(menu, SIGNAL(confirma_boton(bool)), this, SLOT(recibe_señal(bool)));


}

void principal::comenzar()
{
    menu->exec();


}

/*bool principal::recibe_senal(bool boleano)
{

}*/
