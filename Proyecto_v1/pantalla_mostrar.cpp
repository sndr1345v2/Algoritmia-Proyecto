#include "pantalla_mostrar.h"
#include "ui_pantalla_mostrar.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include <QJsonArray>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStandardItem>

pantalla_mostrar::pantalla_mostrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_mostrar)
{
    ui->setupUi(this);
    cargar_clientes();
    mostrar_clientes();

}

pantalla_mostrar::~pantalla_mostrar()
{
    delete ui;
}

void pantalla_mostrar::cargar_clientes()
{
    qDebug() <<"Print";
    QFile jsonFile("registros_clientes/clientes.json");

    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {

        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto

        QJsonValue usersArrayValue = jsonObject.value("clientes");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria

        int i=0;
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            c.setId(v.toObject().value("id").toString());//Indexa y transforma de objeto a cadena
            c.setNombre(v.toObject().value("first_name").toString());

            listaClientes.push_back(c);

            qDebug() <<i<< v.toObject().value("id").toString();//Indexa y transforma de objeto a cadena
            qDebug() << v.toObject().value("first_name").toString();
            qDebug() << "\n";
            i++;
        }

    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

void pantalla_mostrar::mostrar_clientes()
{

    QStandardItemModel *model_clientes = new QStandardItemModel;

    model_clientes->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
    model_clientes->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));

    for(int i = 0; i < listaClientes.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaClientes[i].getId());
        QStandardItem *nombre = new QStandardItem (listaClientes[i].getNombre());

        model_clientes->setItem(i, 0, id);
        model_clientes->setItem(i, 1, nombre);

    }

    ui->table_clientes->setModel(model_clientes);
    ui->table_clientes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_clientes->resizeColumnToContents(0);
    ui->table_clientes->setColumnWidth(1,260);
    ui->table_clientes->setColumnWidth(2,190);
    ui->table_clientes->verticalHeader()->setVisible(false);
}
