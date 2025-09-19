// el array trabaja como un puntero pero no lo es 
//al compilar la diferencia de la direccion de memoria es de 4 bytes 
// cada vez se multiplica el indice del array por 4 bytes, y asi va incrementando la direccion de memoria

#include <iostream>

int main(){

    int arreglo[3] = {1,3,100};

    //Puntero que apunta a la direccion de memoria de la pos 0
    int *ptr = arreglo; //En este caso no es necesario meterle el signo & pq sabemos que el array funciona como puntero

    // calcular el peso bytes de int
    std::cout << "Peso en bytes de int: " << sizeof(int) <<"\n";

    // acceder a los elementos del arreglo 
    std::cout <<"Direccion de memoria: "<< &arreglo <<" Valor pos[0]: " << arreglo[0] << "\n";

    // acceder en notacion puntero
    // operacion aritmetica = suma 
    std::cout <<"Direccion de memoria: "<< (arreglo + 1) <<" Valor pos[1]: " << *(arreglo + 1) << "\n";

    // Como acceder a los elementos con punteros / Aplicando aritmetica de punteros
    std::cout <<"Direccion de memoria: "<< ptr + 2 <<" Valor pos[2]: " << *(ptr + 2) << "\n";


  return 0; 
}