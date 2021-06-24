#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H



#include <iostream>
#include <fstream>

#define MAX 5000

using namespace std;

/* Función auxiliar que obtiene el valor más pequeño de dos dados como
parámetros. La utiliza el método de Dijkstra. */
int Minimo(int Vali, int val2)
{
    int Min = Vali;
    if(val2 < Min){
        Min = val2;
    }
    return Min;
}

/* Definición de la plantilla de la clase GrafoDirigido. Se incluyen como
atributos, además de la matriz de adyacencia, el número de vértices y
su nombre, otros elementos que son utilizados en los métodos. */
template <class T>
class GrafoDirigido
{
private:
    /* Declaración del arreglo donde se almacenan las distancias
    entre los vértices. */
    T MatAdy[MAX][MAX];

    int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX],
        VerInt[MAX][MAX];

public:
    /* Método constructor y métodos auxiliares para leer la información
    relacionada a la gráfica e imprimir los resultados obtenidos al
    aplicar los demás métodos. */
    GrafoDirigido();
    void Lee();
    void Imprime(int);

    /* Métodos que recorren una gráfica dirigida, encontrando caminos
    de distancias mínimas. */
    void Warshall();
    void Floyd();
    void FloydVerInt();
    void Dijkstra();

};

/* Método constructor. Inicializa el número de vértices en cero y a la
matriz de adyacencias MatAdy con un valor arbitrario muy grande (999),
indicando que no existe camino entre los nodos correspondientes. Además,
asigna ceros a los arreglos auxiliares que se usan en los métodos. */
template <class T>
GrafoDirigido<T>::GrafoDirigido()
{
    int Ind1, Ind2;
    for(Ind1 = 0; Ind1 < MAX; Ind1++)
    {
        DistMin[Ind1] = 0;
        for(Ind2 = 0; Ind2 < MAX; Ind2 ++)
        {
            if(Ind1 != Ind2)
                MatAdy[Ind1][Ind2] = 999;
            else
                MatAdy[Ind1][Ind2] = 0;

            CerTran[Ind1][Ind2] = 0;
            VerInt[Ind1][Ind2] = 0;
        }

    }

    NumVer = 0;
}

/* Método que lee los datos de la gráfica dirigida directamente del
teclado. */
template <class T>
void GrafoDirigido<T>::Lee()
{
    int NumeArcos, Indice, Origen, Destino;

    cout << "\n Ingrese numero de vertices de la grafica dirigida: ";
    cin >> NumVer;
    cout << "\n Ingrese los nombres de los vertices de la grafica dirigida: " << endl;
    for (Indice = 0; Indice < NumVer; Indice++)
        cin >> Vertices[Indice];

    cout << "\nTotal de aristas de la grafica dirigida: ";
    cin >> NumeArcos;

    Indice = 0;
    while(Indice < NumeArcos)
    {
        cout << "\n Ingrese vertice origen: ";
        cin >> Origen;
        cout << "\nIngrese vertice destino: ";
        cin >> Destino;
        cout << "\nDistancia de origen a destino: ";
        cin >> MatAdy[Origen - 1][Destino - 1];
        Indice ++;
    }
}

/* Método que imprime información relacionada a una gráfica dirigida.
Por medio de un número entero se selecciona lo que se va a imprimir, lo
cual depende del método aplicado para recorrer la digráfica. */
template <class T>
void GrafoDirigido<T>::Imprime(int Opc)
{
    int Ind1, Ind2;
    //declaracion de archivos logicos
    ofstream archivoWarshall, archivoFloyd, archivoFloydVerInt, archivoDijkstra;

    switch(Opc)
    {
       /* Impresión de la matriz de adyacencia o de costos. */
        case 0: cout << "\n Matriz de Adyacencia o de Costos: \n";
                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    cout << Vertices[Ind1]<< ": ";
                    for (Ind2= 0; Ind2 < NumVer; Ind2++)
                        cout << MatAdy[Ind1][Ind2] << "\t";
                    cout << endl;
                }
        break;

        /* Impresión de la cerradura transitiva correspondiente a la
        matriz de adyacencia. Se obtiene cuando se aplica el método de
        Warshall. */
        case 1:
            archivoWarshall.open("Warshall.txt", ios::out); //apertura del archivo logico
            if(!archivoWarshall) //comprobar si fue posible abrir el archivo
                {
                    cout << "El archivo no se pudo abrir";
                    exit(1);
                }

            cout << "\n Cerradura Transitiva de la Matriz de Adyacencia: " << endl;
            archivoWarshall << "\n Cerradura Transitiva de la Matriz de Adyacencia: " << endl; //escritura en archivo

                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    cout << Vertices[Ind1] << ": ";
                    archivoWarshall << Vertices[Ind1] << ": "; //escritura en archivo

                    for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    {
                        cout << CerTran[Ind1][Ind2]<<"\t"; //escritura en archivo
                        archivoWarshall << CerTran[Ind1][Ind2] << "\t"; //escritura en archivo
                    }

                    cout << endl;
                    archivoWarshall << endl;
                }
            archivoWarshall.close();//cierre del archivo
        break;

        /* Impresión de la matriz de distancias mínimas entre todos los
        vértices de la gráfica. Se obtiene por medio del método de Floyd. */
        case 2:
            archivoFloyd.open("Floyd.txt", ios::out); //apertura del archivo logico
            if(!archivoFloyd) //comprobar si fue posible abrir el archivo
                {
                    cout << "El archivo no se pudo abrir";
                    exit(1);
                }

            cout << "\n Matriz de Distancias Minimas: " << endl;
            archivoFloyd << "\n Matriz de Distancias Minimas: " << endl;//escritura en archivo

                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    cout << Vertices[Ind1]<< ": ";
                    archivoFloyd << Vertices[Ind1]<< ": "; //escritura en archivo

                    for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    {
                        cout << MatAdy[Ind1][Ind2] << "\t";
                        archivoFloyd << MatAdy[Ind1][Ind2] << "\t"; //escritura en archivo
                    }

                    cout << endl;
                    archivoFloyd << endl; //escritura en archivo
                }

            archivoFloyd.close(); //cerrar archivo logico
        break;

        /* Impresión de la matriz con los vértices intermedios usados
        ➥para establecer los caminos de distancias mínimas. Esta
        ➥impresión complementa la de la opción 2 cuando se aplica el
        ➥método FloydVerInt. */
        case 3:
                archivoFloydVerInt.open("FloydVerInt.txt", ios::out); //apertura del archivo logico
                if(!archivoFloydVerInt) //comprobar si fue posible abrir el archivo
                {
                    cout << "El archivo no se pudo abrir";
                    exit(1);
                }

                cout << "\n Vertices Intermedios para lograr distancias minimas: "<< endl;
                archivoFloydVerInt << "\n Vertices Intermedios para lograr distancias minimas: "<< endl; //escritura en archivo

                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    {
                        cout << VerInt[Ind1][Ind2] <<"\t";
                        archivoFloydVerInt << VerInt[Ind1][Ind2] << "\t"; //escritura en archivo
                    }

                    cout << endl;
                    archivoFloydVerInt << endl; //escritura en archivo
                }

                archivoFloydVerInt.close(); //cerrar archivo logico
        break;

        /* Impresión de las distancias mínimas entre un vértice y los
        demás. Se obtiene con el método de Dijkstra. */
        case 4:
                archivoDijkstra.open("Dijkstra.txt", ios::out);//apertura del archivo logico
                if(!archivoDijkstra) //comprobar si fue posible abrir el archivo
                {
                    cout << "El archivo no se pudo abrir";
                    exit(1);
                }

                cout << "\n Distancias minimas a partir del vertice: "<< Vertices[0] << "\n";
                archivoDijkstra << "\n Distancias minimas a partir del vertice: "<< Vertices[0] << "\n"; //escritura en archivo

                for (Ind1= 0; Ind1 < NumVer; Ind1++)
                {
                    cout <<" "<<DistMin[Ind1]<<"\t"<<endl;
                    archivoDijkstra << " " << DistMin[Ind1] << "\t" << endl;//escritura en archivo
                }

                archivoDijkstra.close(); //cerrar archivo logico

                break;
        default: break;
    }
    cout << endl;
}

/* Método que determina si existe un camino entre cada uno de los
vértices de la gráfica dirigida. CerTran es una matriz que representa
la cerradura transitiva de la matriz de adyacencia. */
template <class T>
void GrafoDirigido<T>::Warshall()
{
   int Ind1, Ind2, Ind3;
    /* En la posición i,j de la matriz de adyacencia se asignó el valor 999
    si no existe un camino directo del vértice i al vértice j. La cerradura
    transitiva se forma inicialmente a partir de la matriz de adyacencia. */

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        for (Ind2= 0; Ind2 < NumVer; Ind2++)
            if (MatAdy[Ind1][Ind2] != 999)
                CerTran[Ind1][Ind2]= 1;

    /* Se recorren todos los vértices para determinar si existe un camino
    entre él y los demás, usando otros vértices como intermedios. */

    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                CerTran[Ind1][Ind2] |= CerTran[Ind1][Ind3] && CerTran[Ind3][Ind2];
}

/* Método que encuentra el camino de costo mínimo entre todos los
vértices de la gráfica dirigida. Va modificando la matriz de adyacencia
a medida que encuentra un camino más corto entre dos vértices. */
template <class T>
void GrafoDirigido<T>::Floyd()
{
    int Ind1, Ind2, Ind3;
    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                if ( (MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2])
                    MatAdy[Ind1][Ind2]= MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
}

/* Método Floyd modificado para que, además de encontrar las distancias
mínimas entre todos los vértices de una digráfica, genere una matriz
(VerInt) con los vértices intermedios utilizados para minimizar las
distancias. Este método usa los atributos Vertices (arreglo que
almacena los nombres de todos los vértices de la digráfica) y VerInt
(arreglo donde se van guardando los vértices intermedios. Fue inicia-
lizado en 0 en el método constructor). */
template <class T>
void GrafoDirigido<T>::FloydVerInt()
{
    int Ind1, Ind2, Ind3;
    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2])
                {
                    MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
                    VerInt[Ind1][Ind2] = Vertices[Ind3];
                }
}

/* Método que encuentra la distancia mínima entre un vértice dado y los
demás vértices de una gráfica dirigida. En el arreglo DistMin se
almacenan las distancias mínimas desde el vértice origen a cada uno
de los otros nodos. Es decir DistMin[i] almacena la menor distancia
entre el vértice origen y el vértice i. */
template <class T>
void GrafoDirigido<T>::Dijkstra()
{
    int Aux[MAX], VertInc[MAX], Ver1, Ver2, Ind1, Ind2, Menor, Band,Origen;
    /* El arreglo VertInc se utiliza para guardar los vértices elegidos
    por ser los de la distancia mínima. El arreglo Aux es un arreglo
    lógico que indica si el nodo de la posición i ya fue incluido en
    VertInc y de esta manera evitar ciclos. */

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        Aux[Ind1]= 0;
        VertInc[Ind1]= 0;
    }

    cout << "\n Ingrese vertice origen: ";
    cin >> Origen;
    Aux[Origen - 1]= 1;

    /* El arreglo donde se guardan las distancias mínimas del Origen a
    los demás vértices se inicializa con los valores de la matriz de
    adyacencia. */

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        DistMin[Ind1]= MatAdy[Origen][Ind1];

    for (Ind1= 0; Ind1<NumVer; Ind1++)
    {
        /* Se busca el vértice Ver1 en (Vertices - VertInc) tal que
        DistMin[Ver1] sea el mínimo valor. Se usa el 999 como valor
        inicial ya que es el elegido para indicar que no existe camino
        entre dos vértices. */
        Menor= 999;

        for (Ind2= 1; Ind2 < NumVer; Ind2++)
            if (DistMin[Ind2] < Menor && !Aux[Ind2])
            {
                Ver1= Ind2;
                Menor= DistMin[Ind2];
            }

        /* Se incluye Ver1 a VertInc y se actualiza el arreglo Aux. */
        VertInc[Ind1]= Ver1;
        Aux[Ver1]= 1;
        /* Se busca la distancia mínima para cada vértice Ver2 en
        (Vertices - VertInc). */
        Ver2= 1;

        while (Ver2 < NumVer)
        {
            Band=0;
            Ind2= 1;
            while (Ind2 < NumVer && !Band)
                if (VertInc[Ind2] == Ver2)
                    Band= 1;
                else
                    Ind2++;
            if (!Band)
                    DistMin[Ver2]= Minimo (DistMin[Ver2], DistMin[Ver1] + MatAdy[Ver1][Ver2]);
            Ver2++;
        }
    }
}


#endif // GRAFODIRIGIDO_H
