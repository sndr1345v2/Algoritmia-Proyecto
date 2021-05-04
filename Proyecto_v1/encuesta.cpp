#include "encuesta.h"

encuesta::encuesta()
{

}

void encuesta::setId_venta(QString enc_id_venta){
    id_venta = enc_id_venta;
}


QString encuesta::getId_venta() const{
    return id_venta;
}

void encuesta::setFecha(QString enc_fecha){
    fecha = enc_fecha;
}

QString encuesta::getFecha() const{
    return fecha;
}

void encuesta::setGrado_satisfaccion(int enc_grado_satisfaccion){
    grado_satisfaccion = enc_grado_satisfaccion;
}

int encuesta::getGrado_satisfaccion() const{
    return grado_satisfaccion;
}

bool encuesta::operator<(const encuesta &obj) const{
    return(grado_satisfaccion<obj.getGrado_satisfaccion());
}

bool encuesta::operator>(const encuesta &obj) const{
    return(grado_satisfaccion>obj.getGrado_satisfaccion());
}

bool encuesta::operator==(const encuesta &obj) const{
    return(grado_satisfaccion==obj.getGrado_satisfaccion());}

