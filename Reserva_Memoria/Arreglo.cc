#include <iostream>

int main(){

    int dimension = 3;  //aqui ya podria expandir mas o menos mi arreglo;

    //reserva 
    int *ptr =  new int[dimension];     //este arreglo es dinamico, y se crea en el HEAP

    delete [] ptr;

    ptr = nullptr;

  return 0; 
}