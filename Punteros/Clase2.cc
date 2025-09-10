#include <iostream>

//Paso por valor
int Acumulador (int n);

//Paso por referencia
int AcumuladorRef(int &);

//Con punteros
int AcumuladorPuntero(int *);

int main(){

    int x = 10;

    std:: cout << "Nuevo valor: " << Acumulador(x) << "\n";
    std::cout <<"Valor de x: " << x << "\n";        //10

    std::cout << "Nuevo valor: " << AcumuladorRef(x)<< "\n"; //No es necesario poner & aqui pq espera recibir la direccion de x
    std::cout <<"Valor de x: " << x << "\n";        //11

    std::cout <<"Nuevo valor: " << AcumuladorPuntero(&x) << "\n";   //Los punteros apuntan a la direccion de x 
    std::cout <<"Valor de x: " << x << "\n";        //12



  return 0; 
}

int Acumulador (int n){
    n = n + 1;

    return n;
}

int AcumuladorRef (int &n){
     n = n + 1;

    return n;
}

int AcumuladorPuntero (int *n){ //Intermediario para llegar a la direccion de memoria (puntero)
     *n = *n + 1;

    return *n;
}