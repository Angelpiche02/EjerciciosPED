
//Un puntero sirve para senalar objetos y manipularlos , este apunta hacia una direccion de memoria de una variable 
// En este  tipo de casos, ya se esta tocando mas la memoria
// El output que me dan es un hexadecimal, el 0x me indica que lo es.
// El * sirve para declarar y sirve para obtener el contenido de una variable; entonces si yo solo imprimo ptr me da la direccion, y si lo hago con * me da el valor
// El paso de referencia se basa en ir a la direccion de memoria y asi ambas tazas se llenan en funcion

#include <iostream>

void PasoPorValor(int n);
void PasoPorReferencia(int &n);


int main(){

    int num = 100;    //Necesitan ser del mismo tipo de dato o variable
    int *ptr = &num;
    
    std::cout <<"Valor de num: "<< num << "\n"; //100

    PasoPorValor(num);   // 110

    std::cout <<"Valor de num: " << num << "\n"; // 100

    std ::cout <<" --------------------------------------------\n";

    PasoPorReferencia(num);  // El parametro espera la direccion de memoria

    std::cout << "Valor de num: " << num << "\n";

  return 0; 
}


void PasoPorValor(int n){
    std::cout <<"Valor de num: " << n + 10 << "\n";

}

void PasoPorReferencia(int &n){
    std::cout <<"Numero de num por referencia: " << &n + 10 << "\n";

}

