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
    int opcion;
public:
    encuesta();
    encuesta(QString id_venta,QString fecha, int grado_satisfaccion);

    void setId_venta(QString);
    QString getId_venta()const;
    void setFecha(QString);
    QString getFecha()const;
    void setGrado_satisfaccion(int);
    int getGrado_satisfaccion()const;

    bool operator<(const encuesta& obj)const{
        if(opcion==1){return grado_satisfaccion<obj.grado_satisfaccion;}}

        bool operator>(const encuesta& obj)const{
            if(opcion==1){return grado_satisfaccion>obj.grado_satisfaccion;}}

        bool operator==(const encuesta&obj)const{
            if(opcion==2){return grado_satisfaccion==obj.grado_satisfaccion && fecha==obj.fecha;}}

        void set_opc(int opcion_text)
                {opcion=opcion_text;}
        int get_opc()
                {return opcion;}
            };

#endif // ENCUESTA_H
