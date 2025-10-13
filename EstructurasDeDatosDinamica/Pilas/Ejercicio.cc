// Almacenar las letras de mi nombre
// crear una pila, apilar las letras usando push
// Imprimir letrass desapilando la pila utilizando pop
// explicar

//Se puede hacer con struct y los strutcs se guradaran en la pila

#include <iostream>
#include <stack>    // Nueva libreria para pilas

struct Datos{

    std::string nombre;
};

struct Nodo{

    struct Datos datos;

    struct Nodo *siguiente;
};

void Insertar(Nodo *&pila);

void Imprimir(Nodo *pila);

int main(){

   // struct Nodo *pila = nullptr;

    std::stack <char> pila;



  return 0; 

}

void Insertar(Nodo *&pila){

    std::string nombre;
    char n;

    struct Nodo *nuevo_nodo = new Nodo;

    std::cout<< "Ingrese el nombre: \n";
    std::cin >> nombre;

    for(int i = 0; i < nombre.length();i++)
    {
        std::cout<<"Ingrese la letra "<< i + 1 <<"\n"; 
        std::cin>>n;
        pila.push(n)
    }

}

void Imprimir(Nodo *pila);
