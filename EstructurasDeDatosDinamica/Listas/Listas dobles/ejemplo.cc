//

#include <iostream>
 
// Struct de la informacion que se guardara en la lista
struct Datos
{
    int numero;
};
struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};
 
// Declaración de funciones
void InsertarInicio(struct Nodo **lista, int n);    // Un puntero doble ** o puntero a puntero, guarda la direccion de otro puntero y la direccion de nodos
 
int main(int argc, char *argv[])
{
    // Reserva memoria stack, partiendo de este, yo puedo conocer los siguientes nodos
    struct Nodo *lista = nullptr;
   
    InsertarInicio(&lista, 100);  // direccion del puntero 
    InsertarInicio(&lista, 7);
    InsertarInicio(&lista, 17);

    // Imprimir 17
    std::cout << "Dir. memoria: " << lista << "\n";
    std::cout << "Dir. memoria sig: " << lista->siguiente << "\n";
    std::cout << "Dir. memoria ant: " << lista->anterior << "\n";
    std::cout << "Valor: " << lista->datos.numero << "\n";

    //Imprimir 100
    std::cout << "Dir. memoria: " << lista->siguiente->siguiente << "\n";
    std::cout << "Dir. memoria sig: " << lista->siguiente->siguiente->siguiente << "\n";
    std::cout << "Dir. memoria ant: " << lista->siguiente->siguiente->anterior << "\n";
    std::cout << "Valor: " << lista->siguiente->siguiente->datos.numero << "\n";
 
    // 40 100 7
    return 0;
}
 
 
 
// Insertar nodos al inicio de la lista
void InsertarInicio(struct Nodo **lista, int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
 
    // Si la lista esta vacia, se pone * pq es un puntero doble, si se pone ** agarra el valor, y en este caso es la direccion
    if (*lista == nullptr)
    {
        *lista = nuevoNodo;
    }
    else
    {
        // conexion del nuevo nodo con la lista
        nuevoNodo->siguiente = *lista;
        (*lista)->anterior = nuevoNodo;
        // asignar el nuevonodo a la cabeza de la lista
        *lista = nuevoNodo;
    }
}