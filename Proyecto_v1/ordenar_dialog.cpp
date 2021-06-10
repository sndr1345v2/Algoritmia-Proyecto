#include "ordenar_dialog.h"
#include "ui_ordenar_dialog.h"
#include <QDebug>
#include <vector>


ordenar_dialog::ordenar_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenar_dialog)
{
    ui->setupUi(this);

    QStringList opciones_ordenar1, opciones_ordenar2;

    opciones_ordenar1<<"     "<<"Grado de satisfaccion";
    opciones_ordenar2<<"     "<<"Id cliente"<<"Costo total"<<"Venta total";
    ui->comboBox_ordenar->addItems(opciones_ordenar1);
    ui->comboBox_ordenar_2->addItems(opciones_ordenar2);
}

ordenar_dialog::~ordenar_dialog()
{
    delete ui;
}


void ordenar_dialog::recibe_listas_ordenar(QList<venta> listaVentas, QList<encuesta> listaEncuesta)
{
    listaEncuestav1 = listaEncuesta;
    listaVentav1 = listaVentas;
    listaVentaCopy = listaVentas;

    mostrar_ordenar_encuestas();
    mostrar_ordenar_ventas(listaVentav1);
}

void ordenar_dialog::mostrar_ordenar_encuestas()
{

    QStandardItemModel *model_encuestas = new QStandardItemModel;

    model_encuestas->setHorizontalHeaderItem(0,new QStandardItem(QString("Id_venta")));
    model_encuestas->setHorizontalHeaderItem(1,new QStandardItem(QString("Fecha")));
    model_encuestas->setHorizontalHeaderItem(2,new QStandardItem(QString("Grado_satisfaccion")));

    for(int i = 0; i <listaEncuestav1.size(); i++)
    {

        QStandardItem *id = new QStandardItem(listaEncuestav1[i].getId_venta());
        QStandardItem *fecha = new QStandardItem(listaEncuestav1[i].getFecha());
        QStandardItem *grado = new QStandardItem (QString::number(listaEncuestav1[i].getGrado_satisfaccion()));

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
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_de_venta")));
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

void ordenar_dialog::on_comboBox_ordenar_currentTextChanged(const QString &current_text)
{


}


template<class T>
vector <T> merge(const vector<T> &left, const vector<T> &right)
{
    vector<T> result;
    unsigned left_it = 0, right_it = 0;

    //string left_it =left[0].get_titulo();
    //string right_it= right[0].get_titulo();

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
    model_venta->setHorizontalHeaderItem(3,new QStandardItem(QString("Numero_de_venta")));
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
        //mostrar_ordenar_ventas(listaVentaCopy);

    }
}

