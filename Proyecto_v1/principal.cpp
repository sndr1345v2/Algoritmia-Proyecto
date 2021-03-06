#include "principal.h"



principal::principal(QObject *parent) : QObject(parent)
{
    
    menu = new menu_dialog();
    
    p_mostrar = new pantalla_mostrar();
    p_modificar = new pantalla_modificar();
    p_registrar = new pantalla_registrar ();
    p_ordenar = new ordenar_dialog();
    p_buscar = new pantalla_buscar();
    
    QObject::connect(menu, SIGNAL(mostrar_pantalla()), this, SLOT(abre_mostrar()));
    QObject::connect(p_mostrar, SIGNAL(regresa_menu()), this, SLOT(abre_menu()));
    QObject::connect(menu, SIGNAL(ordenar_pantalla()), this, SLOT(abre_ordenar()));
    QObject::connect(p_ordenar, SIGNAL(regresa_menu()), this, SLOT(abre_menu()));
    QObject::connect(this, SIGNAL(envia_listas(QList<cliente>,QList<articulo>,QList<encuesta>,QList<venta>)), p_mostrar, SLOT(recibe_listas(QList<cliente>,QList<articulo>,QList<encuesta>,QList<venta>)));
    QObject::connect(this, SIGNAL(envia_listas_ordenar(QList<venta>,QList<encuesta>,QList<articulo>)), p_ordenar, SLOT(recibe_listas_ordenar(QList<venta>,QList<encuesta>,QList<articulo>)));
    QObject::connect(menu,SIGNAL(modificar_pantalla()), this, SLOT(abre_modificar()));
    QObject::connect(menu,SIGNAL(capturar_pantalla()), this, SLOT(abre_capturar()));
    QObject::connect(menu,SIGNAL(buscar_pantalla()), this, SLOT(abre_buscar()));
    QObject::connect(p_buscar, SIGNAL(regresar_menu()), this, SLOT(abre_menu()));
    QObject::connect(p_registrar, SIGNAL(regresar_menu()), this, SLOT(abre_menu()));
    QObject::connect(p_modificar, SIGNAL(regresar_menu()), this, SLOT(abre_menu()));

}

//Clientes
void principal::cargar_clientes()
{
    qDebug() <<"Print";
    QFile jsonFile("registros_clientesv2/clientesv3.json");
    
    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        
        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();
        
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto
        
        QJsonValue usersArrayValue = jsonObject.value("clientes");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria
        
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            c.setId(v.toObject().value("id_cliente").toString());//Indexa y transforma de objeto a cadena
            c.setNombre(v.toObject().value("nombre").toString());
            
            listaClientes.push_back(c);
        }
        
    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

//Articulos
void principal::cargar_articulos()
{
    
    qDebug() <<"Print";
    QFile jsonFile("registros_articulosv2/articulosv3.json");
    
    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        
        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();
        
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto
        
        QJsonValue usersArrayValue = jsonObject.value("articulos");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria
        
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            a.setId(QString::number(v.toObject().value("id_articulo").toInt()));
            a.setNombre(v.toObject().value("nombre").toString());
            a.setCosto(v.toObject().value("costo").toDouble());
            a.setIdVenta(v.toObject().value("num_ventas").toInt());
            a.setGradoSat((v.toObject().value("grado_satisfaccion").toInt()));
            
            listaArticulos.push_back(a);
        }
        
    }
    else
    {
        qDebug()<<"ARTICULOS.Archivo no existe o se encuentra corrupto.";
    }
}

void principal::cargar_venta()
{
    QFile jsonFile("registros_ventasv2/ventasv3.json");
    
    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        
        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();
        
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto
        
        QJsonValue usersArrayValue = jsonObject.value("ventas");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria
        
        
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            ven.setId(v.toObject().value("id_venta").toString());//Indexa y transforma de objeto a cadena
            ven.setFecha(v.toObject().value("fecha").toString());
            double costo = v.toObject().value("costo_total").toString().toDouble();
            ven.setCosto(costo);
            double total_venta = v.toObject().value("numero_de_venta").toString().toDouble();
            ven.setVenta_registro(total_venta);
            ven.setId_cliente(v.toObject().value("id_cliente").toString());
            ven.setId_articulo(v.toObject().value("id_articulo").toString());
            
            listaVentas.push_back(ven);
        }
        
    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
}

void principal::cargar_encuesta()
{
    QFile jsonFile("registros_encuestasv2/encuestasv3.json");
    
    if(jsonFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        
        QByteArray jsonFileData = jsonFile.readAll();
        jsonFile.close();
        
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonFileData);
        QJsonObject jsonObject = jsonDocument.object(); //Se transforma el documento entero en un objeto
        
        QJsonValue usersArrayValue = jsonObject.value("encuestas");//Busca la llave del arreglo del objeto
        QJsonArray usersArray = usersArrayValue.toArray(); //Se asigna a arreglo la llave en memoria
        
        foreach (const QJsonValue & v, usersArray) //Busca en el arreglo por los valoresJSON del arreglo
        {
            e.setId_venta(v.toObject().value("id_venta").toString());
            e.setFecha(v.toObject().value("fecha").toString());
            e.setGrado_satisfaccion(v.toObject().value("grado_satisfaccion").toInt());
            
            listaEncuestas.push_back(e);
        }
        
    }
    else
    {
        qDebug()<<"Archivo no existe o se encuentra corrupto.";
    }
    
}


void principal::comenzar()
{
    cargar_clientes();
    cargar_articulos();
    cargar_venta();
    cargar_encuesta();

    menu->show();

    emit envia_listas(listaClientes,listaArticulos,listaEncuestas,listaVentas), envia_listas_ordenar(listaVentas,listaEncuestas,listaArticulos);
}

void principal::abre_menu()
{
    if(p_mostrar->isVisible()){
        
        menu->setVisible(true);
        p_mostrar->setVisible(false);
    }
    else if (p_modificar->isVisible()){
        
        menu->setVisible(true);
        p_modificar->setVisible(false);
    }
    else if (p_buscar->isVisible()){

        menu->setVisible(true);
        p_buscar->setVisible(false);
    }

    else if (p_registrar->isVisible()){
        menu->setVisible(true);
        p_registrar->setVisible(false);
    }
    else if (p_registrar->isVisible()){
        
        menu->setVisible(true);
        p_registrar->setVisible(false);
    }
    else if(p_ordenar->isVisible()){
        
        menu->setVisible(true);
        p_ordenar->setVisible(false);
    }
    else if(p_modificar->isVisible()){

        menu->setVisible(true);
        p_modificar->setVisible(false);
    }
    
}

void principal::cierra_menu()
{
    menu->hide();
}

void principal::abre_mostrar()
{
    menu->hide();
    p_mostrar->setVisible(true);
}

void principal::abre_ordenar()
{
    menu->hide();
    p_ordenar->setVisible(true);
}

void principal::abre_modificar(){
    menu->hide();
    p_modificar->setVisible(true);
}

void principal::abre_capturar(){
    menu->hide();
    p_registrar->setVisible(true);
}

void principal::abre_buscar(){
    menu->hide();
    p_buscar->setVisible(true);
}
