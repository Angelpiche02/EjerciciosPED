//Solicita precios al usuario, n cantidad precios (arreglo dinamico float), despues los suma y obtiene el promedio de ventas
// arreglo, new y delete
//void solicitar ventas y acepte parametro un puntero
//void para mostrar direcciones de memoria con cada ventas 
// calcular promedio de las ventas , con parametro un puntero


#include <iostream>

void SolicitarDatos (float *ptr);

int main(){

    int valor;

    std::cout <<"Ingrese la cantidad de ventas: \n";
    std::cin >> valor;

    float *ptr = new float[valor];

    for(int i = 0; i < valor; i++){

        std::cout <<"Ingrese la venta " << i + 1 << " del arreglo: \n";
        std::cin >> ptr[i];     //*(ptr + i)
    }

    for(int i = 0; i < valor; i++){

        std::cout <<"Direccion de memoria: " << ptr + i << " - venta: " << *(ptr + i) << "\n";
    }

    float promedio = 0;

    for(int i = 0; i < valor; i++){

       promedio += *(ptr + i); 
    }

    std::cout <<"=================================================\n";
    std::cout <<"Promedio de ventas: " << promedio / valor << "\n";

    delete ptr;
    ptr = nullptr;

  return 0; 
}