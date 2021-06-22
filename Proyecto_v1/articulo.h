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
    int opcion;
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

    void set_opc(int opcion_text)
    {opcion=opcion_text;}

    int get_opc()
    {return opcion;}

    bool operator<(const articulo& obj)const{
        if(opcion==1){return id_venta<obj.id_venta;}
    }


    bool operator>(const articulo& obj)const{
         if(opcion==1){return id_venta>obj.id_venta;}}

    bool operator==(const articulo& obj)const{
         if(opcion==1){return id_venta==obj.id_venta;}
    }

};



#endif // ARTICULO_H
