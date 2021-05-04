#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <QString>
using namespace std;


class encuesta
{
private:
    QString id_venta;
    QString fecha;
<<<<<<< HEAD
    QString grado_satisfaccion;
public:
    encuesta();
    encuesta(QString id_venta,QString fecha, QString grado_satisfaccion);
=======
    int grado_satisfaccion;
public:
    encuesta();
    encuesta(QString id_venta,QString fecha, int grado_satisfaccion);
>>>>>>> miguel

    void setId_venta(QString);
    QString getId_venta()const;
    void setFecha(QString);
    QString getFecha()const;
<<<<<<< HEAD
    void setGrado_satisfaccion(QString);
    QString getGrado_satisfaccion()const;
=======
    void setGrado_satisfaccion(int);
    int getGrado_satisfaccion()const;

    bool operator<(const encuesta&)const;
    bool operator>(const encuesta&)const;
    bool operator==(const encuesta&)const;
>>>>>>> miguel
};

#endif // ENCUESTA_H
