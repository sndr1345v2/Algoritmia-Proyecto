#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <menu_dialog.h>
#include <pantalla_modificar.h>
#include <pantalla_mostrar.h>
#include <pantalla_registrar.h>
#include <ordenar_dialog.h>


class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);
    
    menu_dialog *menu;
    pantalla_mostrar *p_mostrar;
    pantalla_modificar *p_modificar;
    pantalla_registrar *p_registrar;
    ordenar_dialog *p_ordenar;
    
    void cargar_clientes();
    void cargar_articulos();
    void cargar_venta();
    void cargar_encuesta();
    
    void comenzar();
    
    cliente c;
    articulo a;
    encuesta e;
    venta ven;
    
    QList<cliente> listaClientes;
    QList<articulo> listaArticulos;
    QList<encuesta> listaEncuestas;
    QList<venta> listaVentas;
    
signals:
    
    void envia_listas(QList<cliente>,  QList<articulo>, QList<encuesta>, QList<venta> );
    void envia_listas_ordenar(QList<venta>,QList<encuesta>);
    
public slots:
    
    void abre_menu();
    void cierra_menu();
    void abre_mostrar();
    void abre_ordenar();
    
    
};

#endif // PRINCIPAL_H
