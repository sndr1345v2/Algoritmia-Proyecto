#include "qt_library_example.h"
#include <QDebug>

qt_library_example::qt_library_example(QObject *parent) : QObject(parent)
{

}

void qt_library_example::imprimir_pantalla()
{
   QString cadena1 = objeto.get_cadena();
   qDebug()<< cadena1;

}
