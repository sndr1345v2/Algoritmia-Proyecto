#ifndef VENTA_H
#define VENTA_H
#include <QString>
using namespace std;


class venta
{
private:
    QString id;
    QString fecha;
    QString id_cliente;
    QString id_articulo;
    QString costo;
    QString venta_registro;
public:
    venta();
    venta(QString id,QString fecha,QString id_cliente,QString id_articulo,QString costo,QString venta_registro);


    void setId(QString);
    QString getId()const;
    void setFecha(QString);
    QString getFecha()const;
    void setId_cliente(QString);
    QString getId_cliente()const;
    void setId_articulo(QString);
    QString getId_articulo()const;
    void setCosto(QString);
    QString getCosto()const;
    void setVenta_registro(QString);
    QString getVenta_registro()const;
};

#endif // VENTA_H
