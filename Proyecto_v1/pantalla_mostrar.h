#ifndef PANTALLA_MOSTRAR_H
#define PANTALLA_MOSTRAR_H

#include <QDialog>

#include <QList>
#include "articulo.h"
#include "cliente.h"
#include "encuesta.h"
#include "venta.h"

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

    cliente c;
    articulo a;
    encuesta e;
    venta v;

    QList<cliente> listaClientes;
    QList<articulo> listaArticulos;
    QList<encuesta> listaEncuestas;
    QList<venta> listaVentas;


private:
    Ui::pantalla_mostrar *ui;
};

#endif // PANTALLA_MOSTRAR_H
