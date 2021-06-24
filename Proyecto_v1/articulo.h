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
    int grado_satisfaccion;
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
    void setGradoSat(int);
    int getGradoSat()const;

    void set_opc(int opcion_text)
    {opcion=opcion_text;}

    int get_opc()
    {return opcion;}

    bool operator<(const articulo& obj)const{
        if(opcion==1){return id_venta<obj.id_venta;}
        if(opcion==2){return grado_satisfaccion<obj.grado_satisfaccion;}
    }

    bool operator>(const articulo& obj)const{
         if(opcion==1){return id_venta>obj.id_venta;}
         if(opcion==2){return grado_satisfaccion>obj.grado_satisfaccion;}

    }

    bool operator==(const articulo& obj)const{
         if(opcion==1){return id_venta==obj.id_venta;}
         if(opcion==2){return grado_satisfaccion == obj.grado_satisfaccion;}

    }

};



#endif // ARTICULO_H
