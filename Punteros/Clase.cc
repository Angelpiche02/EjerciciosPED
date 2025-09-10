//Un puntero sirve para senalar objetos y manipularlos , este apunta hacia una direccion de memoria de una variable 
// En este  tipo de casos, ya se esta tocando mas la memoria
// El output que me dan es un hexadecimal, el 0x me indica que lo es.
// El * sirve para declarar y sirve para obtener el contenido de una variable; entonces si yo solo imprimo ptr me da la direccion, y si lo hago con * me da el valor
// El paso de referencia se basa en ir a la direccion de memoria y asi ambas tazas se llenan en funcion

#include <iostream>

int main(){

    int num = 5;    //Necesitan ser del mismo tipo de dato o variable

    int *ptr_2 = nullptr; // esto es cuando el puntero no apunta a nadie de momento, NULL es definido como 0 y nullptr cambia, y esto da un valor

    int *ptr = &num;   //puntero, no es una variable, y el asterisco es para declarar el puntero
    //la & es un operador de referencia

    *ptr = 100; //A traves del putero puedo modificar los valores de la variable, y mi num jamas sera 5 pq estoy modificando la direccion de memoria
    
    num = 99;   // En este caso mi puntero sigue apuntando a num entonces se modifica siempre 

    *ptr = 500;

    std::cout << "Direccion de memoria: " << ptr << " - " << *ptr << " - " << &num << " - "<< &ptr; // y aqui al final vuelve a la direccion de memoria del puntero y de num



  return 0; 
}


