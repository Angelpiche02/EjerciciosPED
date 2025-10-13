#include <iostream>

struct Datos
{
    int elemento;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
};

//struct Nodo *lista = nullptr;        //este es un puntero global, si uso eso ya no tendria que ponerle un puntero como parametro a mis funciones

void InsertarInicio(struct Nodo *&lista,int n);     // el ampersand esta obteniendo la direccion de memoria del puntero y el asterisco modifica el valor que esta guardado en esa direccion
void InsertarFinal(struct Nodo *&lista, int n);     
void InsertarIntermedio(struct Nodo *&lista, int, int);
void EliminarInicio(struct Nodo *&lista);
void EliminarFinal(struct Nodo *&lista);
void EliminarIntermedio(struct Nodo *&lista, int);
void Imprimir(struct Nodo *&lista);

int main(int argc, char *argv[])
{
    //PUNTERO LOCAL, solo es afectado adentro de la funcion, pq estamos pasando un puntero por valor
    struct Nodo *lista = nullptr;

    InsertarInicio(lista, 300);
    InsertarInicio(lista, 159);

    // std::cout<<lista->datos.elemento;
    // std::cout<<lista->siguiente->datos.elemento;
    Imprimir(lista);

    return 0;
}

void InsertarInicio(struct Nodo *&lista, int n)     //(acepta la direccion de memoria de un puntero)
{
    // Las primeras 3 lineas reservan un espacio de memoria para el valor que llegara
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)               //aqui evaluo la direccion de lista
    {
        lista = nuevoNodo;
        // Circularidad
        lista->siguiente = lista;
        temporal = lista;              // aqui solo igualamos el puntero con lista (inicio)
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;              //aqui hago que el nuevo valor sea el inicio
        // Circularidad
        temporal->siguiente = lista;    // y aqui que el primer valor que obtuvimos al inicio de todo apuntara hacia mi inicio actual
    }
}

void InsertarFinal(struct Nodo *&lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        temporal = nuevoNodo;
    }
}

void InsertarIntermedio(struct Nodo *&lista, int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->datos.elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;      //puntero que apunta a la lista

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal = temporal->siguiente;     // Sabemos que temporal es lista (primer valor), osea mi inicio, y esa linea me dice que cada vez que se avance en los valores de la lista, temporal va siendo cada dato
        }
        temporal->siguiente = lista->siguiente;  //y aqui me dice que mi segundo valor, va ser el que le sigue  a LISTA 
        delete lista;                            // y aqui se elimina el primer dato
        lista = temporal->siguiente;             // hacemos que ahora lista sea el segundo dato de toda mi lista

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista Vacia";
    }
}
void EliminarFinal(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }

        temporal2->siguiente = lista;
        delete temporal;
        temporal = nullptr;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        std::cout << "Lista vacia";
    }
}

void EliminarIntermedio(struct Nodo *&lista, int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
    delete temporal;
    temporal = nullptr;
}

void Imprimir(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            std::cout << "Lista " << temporal->datos.elemento
                      << " Direccion " << temporal
                      << " Dir siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        std::cout << "Lista vacia";
    }
}
