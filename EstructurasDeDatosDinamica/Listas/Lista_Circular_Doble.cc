//eliminar inicio, imprimir, y agregar

#include <iostream>

struct Datos{

    int numero;
};
struct Nodo{

    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
    
};

void InsertarInicio(struct Nodo *&lista, int n);
void EliminarInicio(struct Nodo *&lista);
void Imprimir(struct Nodo *&lista);

int main(){

    struct Nodo *lista = nullptr;

    InsertarInicio(lista, 200);
    InsertarInicio(lista, 300);
    InsertarInicio(lista, 400);
    //EliminarInicio(lista);

    Imprimir(lista);

  return 0; 
}

void InsertarInicio(struct Nodo *&lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->datos.numero = n;

    if(lista == nullptr){

        lista = nuevoNodo;
        lista->siguiente = lista;
        lista->anterior = lista;
        temporal = lista;
    }

    else{

        temporal = lista->anterior;     //Cuando la lista NO está vacía, sabemos que el último nodo actual es lista->anterior.
        nuevoNodo->siguiente = lista;
        nuevoNodo->anterior = temporal;

        // Actualizar vecinos
        temporal->siguiente = nuevoNodo;    //mi ultimo dato apunta al primer dato
        lista->anterior = nuevoNodo;   // El nodo que era el viejo primer nodo (lista) ahora debe apuntar hacia atrás (anterior) al nuevo nodo

        //Actualizar cabeza
        lista = nuevoNodo;  
    }
}

void EliminarInicio(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;      //puntero que apunta a la lista

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        temporal->anterior = lista->anterior;
        delete lista;
        lista = temporal->siguiente;

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

void Imprimir(struct Nodo *&lista)
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            std::cout << "Lista " << temporal->datos.numero
                      << " Direccion " << temporal
                      << " Dir siguiente " << temporal->siguiente 
                      << " Dir anterior " << temporal->anterior << std::endl;

            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        std::cout << "Lista vacia";
    }
}
