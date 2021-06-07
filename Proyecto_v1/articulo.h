#ifndef ARTICULO_H
#define ARTICULO_H
#include <QString>
using namespace std;


class articulo
{
private:
    QString id;
    QString nombre;
    double costo;
    int id_venta;
public:
    articulo();
    articulo(QString id,QString nombre,QString costo, QString id_venta);

    void setId(QString);
    QString getId()const;
    void setNombre(QString);
    QString getNombre()const;
    void setCosto(double);
    double getCosto()const;
    void setIdVenta(int);
    int getIdVenta()const;

    bool operator<(const articulo&)const;
    bool operator>(const articulo&)const;
    bool operator==(const articulo&)const;

};



#endif // ARTICULO_H
