#include "ordenar_dialog.h"
#include "ui_ordenar_dialog.h"
#include <QDebug>
#include <vector>


ordenar_dialog::ordenar_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenar_dialog)
{
    ui->setupUi(this);

    QStringList opciones_ordenar1, opciones_ordenar2,opciones_ordenar3 ;

    opciones_ordenar1<<"     "<<"Grado de satisfaccion";
    opciones_ordenar2<<"     "<<"Id cliente"<<"Costo total"<<"Venta total";
    opciones_ordenar3<<"     "<<"Numero de ventas";
    ui->comboBox_ordenar->addItems(opciones_ordenar1);
    ui->comboBox_ordenar_2->addItems(opciones_ordenar2);
    ui->comboBox_ordenar_3->addItems(opciones_ordenar3);
}

ordenar_dialog::~ordenar_dialog()
{
    delete ui;
}


void ordenar_dialog::recibe_listas_ordenar(QList<venta> listaVentas, QList<encuesta> listaEncuesta, QList <articulo> listaArticulos)
{
    listaEncuestav1 = listaEncuesta;
    listaEncuestaCopy = listaEncuesta;
    listaVentav1 = listaVentas;
    listaVentaCopy = listaVentas;
    listaArticulov1 = listaArticulos;
    listaArticuloCopy = listaArticulos;

    mostrar_ordenar_encuestas(listaEncuestav1);
    mostrar_ordenar_ventas(listaVentav1);
    mostrar_ordenar_articulos(listaArticulov1);
}

template <typename encuesta>
void ordenar_dialog::mostrar_ordenar_encuestas(QList <encuesta> listaX)
{

    QStandardItemModel *model_encuestas = new QStandardItemModel;

    model_encuestas->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_encuestas->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_encuestas->setHorizontalHeaderItem(2,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaX.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaX[i].getId_venta());
        QStandardItem *fecha = new QStandardItem(listaX[i].getFecha());
        QStandardItem *grado = new QStandardItem (QString::number(listaX[i].getGrado_satisfaccion()));

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

template <typename venta>
void ordenar_dialog::mostrar_ordenar_ventas(QList <venta> listaX)
{
    model_venta->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_venta->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_venta->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo_total")));
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Vent total")));
    model_venta->setHorizontalHeaderItem(4,new QStandardItem(QString("Id_Cliente")));
    model_venta->setHorizontalHeaderItem(5,new QStandardItem(QString("Id_Articulo")));

    for(int i = 0; i <listaX.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaX[i].getId());
        QStandardItem *fecha = new QStandardItem (listaX[i].getFecha());
        QStandardItem *costo= new QStandardItem(QString::number(listaX[i].getCosto()));
        QStandardItem *venta_ = new QStandardItem (QString::number(listaX[i].getVenta_registro()));
        QStandardItem *id_cliente = new QStandardItem(listaX[i].getId_cliente());
        QStandardItem *id_articulo = new QStandardItem (listaX[i].getId_articulo());

        model_venta->setItem(i, 0, id);
        model_venta->setItem(i, 1, fecha);
        model_venta->setItem(i, 2, costo);
        model_venta->setItem(i, 3, venta_);
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

void ordenar_dialog::test_find()
{
    /*
  QList<cliente> lista_clientes = objeto_mostrar.listaClientes;
  QList<articulo> lista_articulos = objeto_mostrar.listaArticulos;

  for(int i=0; i<lista_clientes.size();i++){
      for (int j=0; i<lista_articulos.size();j++){
          if(lista_articulos[i].getId()==lista_clientes[i].getId()){
              lista_articulos[i].getNombre();
              lista_clientes[i].getNombre();
          }
      }
      qDebug()<<"Lista clientes copiada: "<<lista_clientes[i].getId();
  }*/
}



void ordenar_dialog::on_pushButton_regresarMenu_clicked()
{
    emit regresa_menu();
}



template<class T>
vector <T> merge(const vector<T> &left, const vector<T> &right)
{
    vector<T> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size())
    {

        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }


    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}


template<class T>
vector<T> merge_sort(vector<T> &vec){

    if(vec.size() == 1)
    {
        return vec;}

    typename std::vector<T>::iterator middle = vec.begin() + (vec.size() / 2);
    vector<T> left(vec.begin(), middle);
    vector<T> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);


}
void ordenar_dialog:: actualiza_listaVentaCopy()
{
    model_venta->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_venta->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_venta->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo_total")));
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Venta_total")));
    model_venta->setHorizontalHeaderItem(4,new QStandardItem(QString("Id_Cliente")));
    model_venta->setHorizontalHeaderItem(5,new QStandardItem(QString("Id_Articulo")));

    for(int i = 0; i <listaVentaCopy.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaVentaCopy[i].getId());
        QStandardItem *fecha = new QStandardItem (listaVentaCopy[i].getFecha());
        QStandardItem *costo= new QStandardItem(QString::number(listaVentaCopy[i].getCosto()));
        QStandardItem *venta_ = new QStandardItem (QString::number(listaVentaCopy[i].getVenta_registro()));
        QStandardItem *id_cliente = new QStandardItem(listaVentaCopy[i].getId_cliente());
        QStandardItem *id_articulo = new QStandardItem (listaVentaCopy[i].getId_articulo());

        model_venta->setItem(i, 0, id);
        model_venta->setItem(i, 1, fecha);
        model_venta->setItem(i, 2, costo);
        model_venta->setItem(i, 3, venta_);
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

void ordenar_dialog::actualiza_listaEncuestaCopy()
{
    QStandardItemModel *model_encuestas = new QStandardItemModel;

    model_encuestas->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_encuestas->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_encuestas->setHorizontalHeaderItem(2,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaEncuestaCopy.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaEncuestaCopy[i].getId_venta());
        QStandardItem *fecha = new QStandardItem(listaEncuestaCopy[i].getFecha());
        QStandardItem *grado = new QStandardItem (QString::number(listaEncuestaCopy[i].getGrado_satisfaccion()));

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

void ordenar_dialog::actualiza_listaArticuloCopy()
{
    model_articulos->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_articulo")));
    model_articulos->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));
    model_articulos->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo")));
    model_articulos->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_ventas")));
    model_articulos->setHorizontalHeaderItem(4,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaArticuloCopy.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaArticuloCopy[i].getId());
        QStandardItem *nombre = new QStandardItem (listaArticuloCopy[i].getNombre());
        QStandardItem *costo = new QStandardItem(QString::number(listaArticuloCopy[i].getCosto()));
        QStandardItem *id_venta = new QStandardItem (QString::number(listaArticuloCopy[i].getIdVenta()));
        QStandardItem *grado_satisfaccion = new QStandardItem (QString::number(listaArticuloCopy[i].getGradoSat()));

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

//Ordenar Ventas
void ordenar_dialog::on_comboBox_ordenar_2_currentTextChanged(const QString &current_text)
{
    if(current_text == "Id cliente")
    {
        vector<venta>vector1;
        vector<venta>vector2;

        std::copy(listaVentaCopy.begin(), listaVentaCopy.end(), std::back_inserter(vector1));

        for(int i=0; i<vector1.size();i++){
            vector1[i].set_opc(3);
        }
        vector2 = merge_sort(vector1);
        listaVentaCopy.clear();
        std::copy(vector2.begin(), vector2.end(), std::back_inserter(listaVentaCopy));
        actualiza_listaVentaCopy();
    }
    if(current_text == "Costo total")
    {
        vector<venta>vector1;
        vector<venta>vector2;

        std::copy(listaVentaCopy.begin(), listaVentaCopy.end(), std::back_inserter(vector1));

        for(int i=0; i<vector1.size();i++){
            vector1[i].set_opc(5);
        }
        vector2 = merge_sort(vector1);
        listaVentaCopy.clear();
        std::copy(vector2.begin(), vector2.end(), std::back_inserter(listaVentaCopy));
        actualiza_listaVentaCopy();
    }
    if(current_text == "Venta total")
    {
        vector<venta>vector1;
        vector<venta>vector2;

        std::copy(listaVentaCopy.begin(), listaVentaCopy.end(), std::back_inserter(vector1));

        for(int i=0; i<vector1.size();i++){
            vector1[i].set_opc(6);
        }
        vector2 = merge_sort(vector1);
        listaVentaCopy.clear();
        std::copy(vector2.begin(), vector2.end(), std::back_inserter(listaVentaCopy));
        actualiza_listaVentaCopy();
    }
}

//Ordenar encuestas
void ordenar_dialog::on_comboBox_ordenar_currentTextChanged(const QString &current_text)
{

    if(current_text == "Grado de satisfaccion")
    {

            vector<encuesta>vector1;
            vector<encuesta>vector2;

            std::copy(listaEncuestaCopy.begin(), listaEncuestaCopy.end(), std::back_inserter(vector1));

            for(int i=0; i<vector1.size();i++){
                vector1[i].set_opc(1);
            }
            vector2 = merge_sort(vector1);
            listaEncuestaCopy.clear();
            std::copy(vector2.begin(), vector2.end(), std::back_inserter(listaEncuestaCopy));
            actualiza_listaEncuestaCopy();

    }
}

//Ordenar Articulos
void ordenar_dialog::on_comboBox_ordenar_3_currentTextChanged(const QString &current_text)
{
    if(current_text == "Numero de ventas")
    {

            vector<articulo>vector1;
            vector<articulo>vector2;

            std::copy(listaArticuloCopy.begin(), listaArticuloCopy.end(), std::back_inserter(vector1));

            for(int i=0; i<vector1.size();i++){
                vector1[i].set_opc(2);
            }
            vector2 = merge_sort(vector1);
            listaArticuloCopy.clear();
            std::copy(vector2.begin(), vector2.end(), std::back_inserter(listaArticuloCopy));
            actualiza_listaArticuloCopy();

    }
}

template<typename articulo>
void ordenar_dialog::mostrar_ordenar_articulos(QList<articulo> listaX)
{ QStandardItemModel *model_articulos = new QStandardItemModel;

    model_articulos->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_articulo")));
    model_articulos->setHorizontalHeaderItem(1,new QStandardItem(QString("Nombre")));
    model_articulos->setHorizontalHeaderItem(2,new QStandardItem(QString("Costo")));
    model_articulos->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_ventas")));
    model_articulos->setHorizontalHeaderItem(4,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaX.size(); i++)
    {
        QStandardItem *id = new QStandardItem(listaX[i].getId());
        QStandardItem *nombre = new QStandardItem (listaX[i].getNombre());
        QStandardItem *costo = new QStandardItem(QString::number(listaX[i].getCosto()));
        QStandardItem *id_venta = new QStandardItem (QString::number(listaX[i].getIdVenta()));
        QStandardItem *grado_satisfaccion = new QStandardItem (QString::number(listaX[i].getGradoSat()));

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
