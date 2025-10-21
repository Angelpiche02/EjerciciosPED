// Hay 3 tipos de memoria
// Memoria estatica, aqui hay variables globales constantes
// Heap busca donde puede entrar un objeto que pese memoria, Es memoria que se gestiona manualmente (dinámica)
//Stack es como una pila, donde los valores se van colocando uno tras otro y esta se libera cuando la funcion termina, Y SON VARIABLES LOCALES
 
// El almacenamiento libre no es una funcion inagotablke de memoria

//malloc() y free() son funciones desarrolladas en c, malloc permite asignar memoria 
//new y delete no son funciones, son OPERADORES, new permite reservar memoria y delete liberar la memoria

// nullptr 

#include <iostream>

int main(){

    // 4 bytes se reservan en el STACK
    int numero = 99;

    // 20 bytes se reservan en el STACK
    int lista_numeros[5] = {1,2,46,7,8};

    // tambien stack
    int *ptr = &numero;

    // Reserva dinamica para tipo int 
    int *ptr_2 = new int;           //aqui ya se reservo memoria para 1 dato, este seria mi HEAP

    *ptr_2 = 10;    //este 10 se guarda en el espacio dinamico que se acaba de crear

    delete ptr_2;   //aqui se libera, pero la direccion sigue guardada en el puntero

    ptr_2 = nullptr;    //esto es una buena practica, para que se borre la direccion guardada

  return 0; 
}