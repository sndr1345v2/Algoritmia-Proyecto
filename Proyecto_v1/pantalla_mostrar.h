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

    void cargar_clientes();
    void mostrar_clientes();

    void cargar_articulos();
    void mostrar_articulos();

    void cargar_venta();
    void mostrar_venta();

    void cargar_encuesta();
    void mostrar_encuesta();

private slots:
    void on_pushButton_menu_clicked();

private:
    Ui::pantalla_mostrar *ui;

    cliente c;
    articulo a;
    encuesta e;
    venta ven;

    QList<cliente> listaClientes;
    QList<articulo> listaArticulos;
    QList<encuesta> listaEncuestas;
    QList<venta> listaVentas;


signals:
    void regresa_menu();
};

#endif // PANTALLA_MOSTRAR_H
