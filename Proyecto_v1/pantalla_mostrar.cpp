#include "pantalla_mostrar.h"
#include "ui_pantalla_mostrar.h"


pantalla_mostrar::pantalla_mostrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_mostrar)
{
    ui->setupUi(this);
    cargar_clientes();
    mostrar_clientes();
    cargar_articulos();
    mostrar_articulos();
    cargar_venta();
    mostrar_venta();
    cargar_encuesta();
    mostrar_encuesta();
}

pantalla_mostrar::~pantalla_mostrar()
{
    delete ui;
}


void pantalla_mostrar::on_pushButton_menu_clicked()
{
    emit (regresa_menu());
}


void pantalla_mostrar::cargar_clientes()
{
    qDebug() <<"Print";
    QFile jsonFile("registros_clientesv2/clientes.json");

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

void pantalla_mostrar::cargar_articulos()
{
    qDebug() <<"Print";
    QFile jsonFile("registros_articulos/articulos.json");

    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {

        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto

        QJsonValue usersArrayValue = jsonObject.value("articulos");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria

        int i=0;
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            a.setId(v.toObject().value("id").toString());//Indexa y transforma de objeto a cadena
            a.setNombre(v.toObject().value("first_name").toString());

            listaArticulos.push_back(a);
        }

    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

void pantalla_mostrar::mostrar_articulos()
{
    QStandardItemModel *model_articulos = new QStandardItemModel;

    model_articulos->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
    model_articulos->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));

    for(int i = 0; i <listaArticulos.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaArticulos[i].getId());
        QStandardItem *nombre = new QStandardItem (listaArticulos[i].getNombre());

        model_articulos->setItem(i, 0, id);
        model_articulos->setItem(i, 1, nombre);

    }

    ui->table_articulos->setModel(model_articulos);
    ui->table_articulos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_articulos->resizeColumnToContents(0);
    ui->table_articulos->setColumnWidth(1,260);
    ui->table_articulos->setColumnWidth(2,190);
    ui->table_articulos->verticalHeader()->setVisible(false);
}

void pantalla_mostrar::cargar_venta()
{
    QFile jsonFile("registros_ventas/venta.json");

    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {

        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto

        QJsonValue usersArrayValue = jsonObject.value("venta");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria

        int i=0;
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            ven.setId(v.toObject().value("id").toString());//Indexa y transforma de objeto a cadena
            ven.setFecha(v.toObject().value("fecha ").toString());
            ven.setCosto(v.toObject().value("costo").toString());//Indexa y transforma de objeto a cadena
            ven.setVenta_registro(v.toObject().value("venta ").toInt());
            ven.setId_cliente(v.toObject().value("id_cliente ").toString());
            ven.setId_articulo(v.toObject().value("id_articulo").toString());
            listaVentas.push_back(ven);
        }

    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

void pantalla_mostrar::mostrar_venta()
{
    QStandardItemModel *model_venta = new QStandardItemModel;

    model_venta->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
    model_venta->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_venta->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo")));
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Venta")));
    model_venta->setHorizontalHeaderItem(4,new QStandardItem(QString("ID_Cliente")));
    model_venta->setHorizontalHeaderItem(5,new QStandardItem(QString("ID_Articulo")));

    for(int i = 0; i <listaVentas.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaVentas[i].getId());
        QStandardItem *fecha = new QStandardItem (listaVentas[i].getFecha());
        QStandardItem *costo= new QStandardItem(listaVentas[i].getCosto());
        QStandardItem *venta = new QStandardItem (listaVentas[i].getVenta_registro());
        QStandardItem *id_cliente = new QStandardItem(listaVentas[i].getId_cliente());
        QStandardItem *id_articulo = new QStandardItem (listaVentas[i].getId_articulo());

        model_venta->setItem(i, 0, id);
        model_venta->setItem(i, 1, fecha);
        model_venta->setItem(i, 2, costo);
        model_venta->setItem(i, 3, venta);
        model_venta->setItem(i, 4, id_cliente);
        model_venta->setItem(i, 5, id_articulo);

    }

    ui->table_ventas->setModel(model_venta);
    ui->table_ventas->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_ventas->resizeColumnToContents(0);
    ui->table_ventas->setColumnWidth(1,260);
    ui->table_ventas->setColumnWidth(2,190);
    ui->table_ventas->verticalHeader()->setVisible(false);
}

void pantalla_mostrar::cargar_encuesta()
{
    QFile jsonFile("registros_encuestas/encuestas.json");

    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {

        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();

        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto

        QJsonValue usersArrayValue = jsonObject.value("encuesta");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria

        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            e.setId_venta(v.toObject().value("id_venta ").toString());//Indexa y transforma de objeto a cadena
            e.setGrado_satisfaccion(v.toObject().value("grado_satisfaccion").toInt());

            listaEncuestas.push_back(e);
        }

    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

void pantalla_mostrar::mostrar_encuesta()
{

    QStandardItemModel *model_encuestas = new QStandardItemModel;

    model_encuestas->setHorizontalHeaderItem(0,new QStandardItem(QString("id_venta")));
    model_encuestas->setHorizontalHeaderItem(1,new QStandardItem(QString("grado_satisfaccion")));

    for(int i = 0; i <listaEncuestas.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaEncuestas[i].getId_venta());
        QStandardItem *grado = new QStandardItem (listaEncuestas[i].getGrado_satisfaccion());

        model_encuestas->setItem(i, 0, id);
        model_encuestas->setItem(i, 1, grado);

    }

    ui->table_encuestas->setModel(model_encuestas);
    ui->table_encuestas->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_encuestas->resizeColumnToContents(0);
    ui->table_encuestas->setColumnWidth(1,260);
    ui->table_encuestas->setColumnWidth(2,190);
    ui->table_encuestas->verticalHeader()->setVisible(false);

}


