//Solicita precios al usuario, n cantidad precios (arreglo dinamico float), despues los suma y obtiene el promedio de ventas
// arreglo, new y delete
//void solicitar ventas y acepte parametro un puntero
//void para mostrar direcciones de memoria con cada ventas 
// calcular promedio de las ventas , con parametro un puntero


#include <iostream>

void SolicitarDatos (float *ptr);
void MostrarDatos ();
int CalcularPromedio (float *ptr);

int main(){

    int valor;

    std::cout <<"Ingrese la cantidad del arreglo: \n";
    std::cin >> valor;

    float *ptr = new float[valor];

    for(int i = 0; i < valor; i++){

        std::cout <<"Ingrese el elemento " << i + 1 << " del arreglo: \n";
        std::cin >> ptr[i];
    }

    for(int i = 0; i < valor; i++){

        std::cout <<"Direccion de memoria: " << ptr + i << " - elemento: " << *(ptr + i) << "\n";
    }

    delete ptr;
    ptr = nullptr;

  return 0; 
}

void SolicitarDatos ()