#ifndef PANTALLA_MOSTRAR_H
#define PANTALLA_MOSTRAR_H

#include <QDialog>

#include <QList>
#include "articulo.h"
#include "cliente.h"
#include "encuesta.h"
#include "venta.h"
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

namespace Ui {
class pantalla_mostrar;
}

class pantalla_mostrar : public QDialog
{
    Q_OBJECT
    
public:
    explicit pantalla_mostrar(QWidget *parent = nullptr);
    ~pantalla_mostrar();
    
    QList<cliente> listaClientes1;
    QList<articulo> listaArticulos1;
    QList<encuesta> listaEncuestas1;
    QList<venta> listaVentas1;

    void mostrar_clientes();
    void mostrar_articulos();
    void mostrar_venta();
    void mostrar_encuesta(); 



    
private slots:
    void on_pushButton_menu_clicked();
    
private:
    Ui::pantalla_mostrar *ui;
    
signals:
    void regresa_menu();
    
public slots:

    void recibe_listas(QList<cliente>,QList<articulo>,QList<encuesta>,QList<venta>);
    
};

#endif // PANTALLA_MOSTRAR_H
