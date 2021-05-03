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
    int venta_registro;
public:
    venta();
    venta(QString id,QString fecha,QString id_cliente,QString id_articulo,QString costo,int venta_registro);


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
    void setVenta_registro(int);
    int getVenta_registro()const;

    bool operator<(const venta&)const;
    bool operator>(const venta&)const;
    bool operator==(const venta&)const;
};

#endif // VENTA_H
