#ifndef ARTICULO_H
#define ARTICULO_H
#include <QString>
using namespace std;


class articulo
{
private:
    QString id;
    QString nombre;
    QString costo;
    QString venta;
public:
    articulo();
    articulo(QString id,QString nombre,QString costo, QString venta);

    void setId(QString);
    QString getId()const;
    void setNombre(QString);
    QString getNombre()const;
    void setCosto(QString);
    QString getCosto()const;
    void setVenta(QString);
    QString getVenta()const;
};

#endif // ARTICULO_H