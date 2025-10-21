// LIFO LAST IN FIRST OUT   (creo que es FIFO) ejemplo una cola en cafeteria
// Se agregan los elemtnos al final(insertar al final)

// Cola simple: los elementos se eliminan en el orden que se almacenan
// Cola circular: se puede manipular desde el frente y la ultima posicion conecta con la primera 
// Cola de prioridad: los elementos entran en cualquier posicion y se remueven solo en el frente

// Libreria queue para colas, push(elemento) - insertar / pop() eliminar / front () - devuelve el primer elemento / back() - el ultimo

#include <iostream>

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    int f_nac;
};

struct Nodo
{
    struct Persona inf;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *frente_cola = nullptr;
struct Nodo *final_cola = nullptr;

// Declaracion de funciones / creacion de prototipo
bool Vacia();
void Insertar(struct Persona p);    // se pone struct 
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();

int main(int argc, char *argv[])
{
    struct Persona p;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Ingresa un nombre ";
        std::cin >> p.nombre;
        std::cout << "Ingresa la fecha de Nac";
        std::cin >> p.f_nac;
        Insertar(p);
    }
    std::cout << " --------------- " << std::endl;
    Imprimir();

    frente_cola->inf.nombre;    //conocer el primer dato

    return 0;
}

// Operación vacia
bool Vacia()
{
    if (frente_cola == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(struct Persona p)
{
    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;
    // Asignacion del valor que ingresa el usuario
    nuevo_nodo->inf = p;                // Esto se pone asi para evitar codigo que tendria que ser como p.f_nac
    nuevo_nodo->siguiente = nullptr;

    if (frente_cola == nullptr)
    {
        frente_cola = nuevo_nodo;
    }
    else
    {
        final_cola->siguiente = nuevo_nodo;
    }
    // Se establece el final de la cola con el nuevo nodo agregado
    final_cola = nuevo_nodo;
}

// Desencolar -- inicio de la lista
void Eliminar()
{
    if (!Vacia())
    {
        struct Nodo *temporal = frente_cola;
        if (frente_cola == final_cola)
        {
            frente_cola = nullptr;
            final_cola = nullptr;
        }
        else
        {
            frente_cola = temporal->siguiente;
        }
        delete temporal;
        temporal = nullptr;
    }
}

// Imprimir elementos de la cola
void Imprimir()
{
    struct Nodo *temporal = frente_cola;
    while (temporal != nullptr)
    {
        std::cout << "Elementos de la cola " << temporal->inf.nombre
                  << " - " << temporal->inf.f_nac << " dir propia "
                  << temporal << " dir nod sig " << temporal->siguiente << std::endl;
        temporal = temporal->siguiente;
    }
}

void ImprimirFrente()
{
    struct Nodo *temporal = frente_cola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento frente en la cola " << temporal->inf.nombre << std::endl;
    }
}

void ImprimirFinal()
{

    struct Nodo *temporal = final_cola;

    if (temporal != nullptr)
    {
        std::cout << "Elemento final en la cola " << temporal->inf.nombre << std::endl;
    }
}
