#include "articulo.h"

articulo::articulo()
{

}

void articulo::setId(QString art_id){
    id = art_id;
}

QString articulo::getId() const{
    return id;
}

void articulo::setNombre(QString art_nombre){
    nombre = art_nombre;
}

QString articulo::getNombre() const{
    return nombre;
}

void articulo::setCosto(double art_costo){
    costo = art_costo;
}

double articulo::getCosto() const{
    return costo;
}

void articulo::setIdVenta(int art_venta){
    id_venta = art_venta;
}

int articulo::getIdVenta() const{
    return id_venta;
}

void articulo::setGradoSat(int grado_sat)
{
    grado_satisfaccion = grado_sat;
}

int articulo::getGradoSat() const
{
    return grado_satisfaccion;
}

