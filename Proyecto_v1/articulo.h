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
<<<<<<< HEAD

    void setId(QString);
    QString getId()const;
    void setNombre(QString);
    QString getNombre()const;
    void setCosto(QString);
    QString getCosto()const;
    void setVenta(QString);
    QString getVenta()const;
=======

    void setId(QString);
    QString getId()const;
    void setNombre(QString);
    QString getNombre()const;
    void setCosto(QString);
    QString getCosto()const;
    void setVenta(QString);
    QString getVenta()const;

    bool operator<(const articulo&)const;
    bool operator>(const articulo&)const;
    bool operator==(const articulo&)const;

>>>>>>> miguel
};



#endif // ARTICULO_H
