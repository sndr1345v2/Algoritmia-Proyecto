#include "pantalla_mostrar.h"
#include "ui_pantalla_mostrar.h"


pantalla_mostrar::pantalla_mostrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pantalla_mostrar)
{
    ui->setupUi(this);
}

pantalla_mostrar::~pantalla_mostrar()
{
    delete ui;
}


void pantalla_mostrar::on_pushButton_menu_clicked()
{
    emit (regresa_menu());

}

void pantalla_mostrar::recibe_listas(QList<cliente> clientes, QList<articulo> articulos, QList<encuesta> encuestas, QList<venta> ventas)
{
    listaClientes1 = clientes;
    listaArticulos1 = articulos;
    listaEncuestas1 = encuestas;
    listaVentas1 = ventas;

    mostrar_clientes();
    mostrar_articulos();
    mostrar_venta();
    mostrar_encuesta();

}



void pantalla_mostrar::mostrar_clientes()
{

    QStandardItemModel *model_clientes = new QStandardItemModel;

    model_clientes->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_cliente")));
    model_clientes->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));

    for(int i = 0; i < listaClientes1.size(); i++){
        QStandardItem *id = new QStandardItem(listaClientes1[i].getId());
        QStandardItem *nombre = new QStandardItem (listaClientes1[i].getNombre());
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


void pantalla_mostrar::mostrar_articulos()
{
    QStandardItemModel *model_articulos = new QStandardItemModel;

    model_articulos->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_articulo")));
    model_articulos->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));
    model_articulos->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo")));
    model_articulos->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_ventas")));
    model_articulos->setHorizontalHeaderItem(4,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaArticulos1.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaArticulos1[i].getId());
        QStandardItem *nombre = new QStandardItem (listaArticulos1[i].getNombre());
        QStandardItem *costo = new QStandardItem(QString::number(listaArticulos1[i].getCosto()));
        QStandardItem *id_venta = new QStandardItem (QString::number(listaArticulos1[i].getIdVenta()));
        QStandardItem *grado_satisfaccion = new QStandardItem (QString::number(listaArticulos1[i].getGradoSat()));

        model_articulos->setItem(i, 0, id);
        model_articulos->setItem(i, 1, nombre);
        model_articulos->setItem(i, 2, costo);
        model_articulos->setItem(i, 3, id_venta);
        model_articulos->setItem(i, 4, grado_satisfaccion);

    }

    ui->table_articulos->setModel(model_articulos);
    ui->table_articulos->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_articulos->resizeColumnToContents(0);
    ui->table_articulos->setColumnWidth(1,260);
    ui->table_articulos->setColumnWidth(2,190);
    ui->table_articulos->verticalHeader()->setVisible(false);
}


void pantalla_mostrar::mostrar_venta()
{
    QStandardItemModel *model_venta = new QStandardItemModel;

    model_venta->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_venta->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_venta->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo_total")));
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_de_venta")));
    model_venta->setHorizontalHeaderItem(4,new QStandardItem(QString("Id_Cliente")));
    model_venta->setHorizontalHeaderItem(5,new QStandardItem(QString("Id_Articulo")));

    for(int i = 0; i <listaVentas1.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaVentas1[i].getId());
        QStandardItem *fecha = new QStandardItem (listaVentas1[i].getFecha());
        QStandardItem *costo= new QStandardItem(QString::number(listaVentas1[i].getCosto()));
        QStandardItem *venta = new QStandardItem (QString::number(listaVentas1[i].getVenta_registro()));
        QStandardItem *id_cliente = new QStandardItem(listaVentas1[i].getId_cliente());
        QStandardItem *id_articulo = new QStandardItem (listaVentas1[i].getId_articulo());

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


void pantalla_mostrar::mostrar_encuesta()
{

    QStandardItemModel *model_encuestas = new QStandardItemModel;

    model_encuestas->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_encuestas->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_encuestas->setHorizontalHeaderItem(2,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaEncuestas1.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaEncuestas1[i].getId_venta());
        QStandardItem *fecha = new QStandardItem(listaEncuestas1[i].getFecha());
        QStandardItem *grado = new QStandardItem (QString::number(listaEncuestas1[i].getGrado_satisfaccion()));

        model_encuestas->setItem(i, 0, id);
        model_encuestas->setItem(i, 1, fecha);
        model_encuestas->setItem(i, 2, grado);

    }

    ui->table_encuestas->setModel(model_encuestas);
    ui->table_encuestas->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->table_encuestas->resizeColumnToContents(0);
    ui->table_encuestas->setColumnWidth(1,260);
    ui->table_encuestas->setColumnWidth(2,190);
    ui->table_encuestas->verticalHeader()->setVisible(false);

}




