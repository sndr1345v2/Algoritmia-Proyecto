#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <QString>
using namespace std;


class encuesta
{
private:
    QString id_venta;
    QString fecha;
    QString grado_satisfaccion;
public:
    encuesta();
    encuesta(QString id_venta,QString fecha, QString grado_satisfaccion);

    void setId_venta(QString);
    QString getId_venta()const;
    void setFecha(QString);
    QString getFecha()const;
    void setGrado_satisfaccion(QString);
    QString getGrado_satisfaccion()const;
};

#endif // ENCUESTA_H
