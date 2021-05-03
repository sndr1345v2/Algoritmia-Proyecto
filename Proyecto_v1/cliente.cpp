#include "cliente.h"

cliente::cliente()
{

}


void cliente::setId(QString cli_id){
    id = cli_id;
}

QString cliente::getId() const{
    return id;
}

void cliente::setNombre(QString cli_nombre){
    nombre = cli_nombre;
}

QString cliente::getNombre() const{
    return nombre;
}

bool cliente::operator<(const cliente &obj) const{
    return(id<obj.getId());
}

bool cliente::operator>(const cliente &obj) const{
    return(id>obj.getId());
}

bool cliente::operator==(const cliente &obj) const{
    return(id==obj.getId());
}
