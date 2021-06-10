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
    double costo;
    int venta_registro;
    int opcion;

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
    void setCosto(double);
    double getCosto()const;
    void setVenta_registro(int);
    int getVenta_registro()const;


    void set_opc(int opcion_text)
    {opcion=opcion_text;}

    int get_opc()
    {return opcion;}

    bool operator<(const venta&obj)const
    {//Seleccionar el atributo a comparar por la opcion elegida

        if(opcion==1)
        {return id < obj.id;}

        else if(opcion==2)
        { return fecha < obj.fecha;}

        else if(opcion==3)
        {return id_cliente <obj.id_cliente;}

        else if(opcion==4)
        {return id_articulo <obj.id_articulo;}

        else if(opcion==5)
        {return costo<obj.costo;}

        else if(opcion==6)
        {return venta_registro<obj.venta_registro;}
    }

    bool operator>(const venta&obj)const
    {
        if(opcion==1)
        {return id > obj.id;}

        else if(opcion==2)
        { return fecha > obj.fecha;}

        else if(opcion==3)
        {return id_cliente > obj.id_cliente;}

        else if(opcion==4)
        {return id_articulo > obj.id_articulo;}

        else if(opcion==5)
        {return costo > obj.costo;}

        else if(opcion==6)
        {return venta_registro > obj.venta_registro;}
    }

    bool operator==(const venta&obj)const
    {
        return id ==obj.getId()&& fecha == obj.getFecha() && id_cliente == obj.getId_cliente() && id_articulo == obj.getId_articulo() && costo == obj.getCosto() && venta_registro == obj.getVenta_registro();
    }
};

#endif // VENTA_H
