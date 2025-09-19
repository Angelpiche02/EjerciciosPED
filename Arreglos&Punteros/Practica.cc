#include <iostream>

int main(){

    int arreglo[5] = {10,20,30,40,50};
    int *ptr = arreglo;


    for(int i = 0; i < 5; i++){

        std::cout <<"Elementos del arreglo: "<< arreglo[i] << " Direccion del arreglo: " << &arreglo[i] << "\n";
    }

    
    int indice = 0;

    do{

        std::cout <<"Elementos del arreglo usando punteros: " << *(ptr + indice) << " Direccion del arreglo usando punteros: " << ptr + indice << "\n";

        indice++;

    } while(indice < 5);

    //Sumar los elementos
    int suma = 0;

    for(int i = 0; i < 5; i++){
        
        suma += arreglo[i];
        
    }

   std::cout <<"Suma de los elementos del arreglo: " << suma;

  return 0; 
}