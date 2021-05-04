#include "venta.h"

venta::venta()
{

}


void venta::setId(QString venta_id){
    id = venta_id;
}

QString venta::getId() const{
    return id;
}

void venta::setFecha(QString venta_fecha){
    fecha = venta_fecha;
}

QString venta::getFecha() const{
    return fecha;
}

void venta::setId_cliente(QString venta_id_cliente){
    id_cliente = venta_id_cliente;
}

QString venta::getId_cliente() const{
    return id_cliente;
}

void venta::setId_articulo(QString venta_id_articulo){
    id_articulo = venta_id_articulo;
}

QString venta::getId_articulo() const{
    return id_articulo;
}

void venta::setCosto(QString venta_costo){
    costo = venta_costo;
}

QString venta::getCosto() const{
    return costo;
}

<<<<<<< HEAD
void venta::setVenta_registro(QString venta_venta_registro){
    venta_registro = venta_venta_registro;
}

QString venta::getVenta_registro() const{
    return venta_registro;
}

=======
void venta::setVenta_registro(int venta_venta_registro){
    venta_registro = venta_venta_registro;
}

int venta::getVenta_registro() const{
    return venta_registro;
}

bool venta::operator<(const venta &obj) const{
    return(venta_registro<obj.getVenta_registro());
}

bool venta::operator>(const venta &obj) const{
    return(venta_registro>obj.getVenta_registro());
}

bool venta::operator==(const venta &obj) const{
    return(venta_registro==obj.getVenta_registro());

>>>>>>> miguel
