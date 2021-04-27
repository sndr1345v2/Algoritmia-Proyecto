#include "principal.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>

principal::principal(QObject *parent) : QObject(parent)
{

    menu = new menu_dialog();

   //  QObject::connect(menu, SIGNAL(confirma_boton(bool)), this, SLOT(recibe_señal(bool)));


}

void principal::comenzar()
{

    menu->exec();
}

/*bool principal::recibe_senal(bool boleano)
{

}*/
