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
<<<<<<< HEAD

void articulo::setNombre(QString art_nombre){
    nombre = art_nombre;
}

QString articulo::getNombre() const{
    return nombre;
}

void articulo::setCosto(QString art_costo){
    costo = art_costo;
}

QString articulo::getCosto() const{
    return costo;
}

void articulo::setVenta(QString art_venta){
    venta = art_venta;
}

QString articulo::getVenta() const{
    return venta;
=======

void articulo::setNombre(QString art_nombre){
    nombre = art_nombre;
}

QString articulo::getNombre() const{
    return nombre;
}

void articulo::setCosto(QString art_costo){
    costo = art_costo;
}

QString articulo::getCosto() const{
    return costo;
}

void articulo::setVenta(QString art_venta){
    venta = art_venta;
}

QString articulo::getVenta() const{
    return venta;
}

bool articulo::operator<(const articulo &obj) const{
    return(id<obj.getId());
}

bool articulo::operator>(const articulo &obj) const{
    return(id>obj.getId());
}

bool articulo::operator==(const articulo &obj) const{
    return(id==obj.getId());
>>>>>>> miguel
}
