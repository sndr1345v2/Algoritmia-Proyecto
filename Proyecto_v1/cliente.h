#ifndef CLIENTE_H
#define CLIENTE_H
#include <QString>
using namespace std;


class cliente
{
private:
    QString id;
    QString nombre;
public:
    cliente();
    cliente(QString id,QString nombre);

    void setId(QString);
    QString getId()const;
    void setNombre(QString);
    QString getNombre()const;

    bool operator<(const cliente&)const;
    bool operator>(const cliente&)const;
    bool operator==(const cliente&)const;
};

#endif // CLIENTE_H
