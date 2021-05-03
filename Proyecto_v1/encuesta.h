#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <QString>
using namespace std;


class encuesta
{
private:
    QString id_venta;
    QString fecha;
    int grado_satisfaccion;
public:
    encuesta();
    encuesta(QString id_venta,QString fecha, int grado_satisfaccion);

    void setId_venta(QString);
    QString getId_venta()const;
    void setFecha(QString);
    QString getFecha()const;
    void setGrado_satisfaccion(int);
    int getGrado_satisfaccion()const;

    bool operator<(const encuesta&)const;
    bool operator>(const encuesta&)const;
    bool operator==(const encuesta&)const;
};

#endif // ENCUESTA_H
