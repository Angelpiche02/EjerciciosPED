// Paso por valor es basicamente una copia de una varibale o documento
// 

#include <iostream>

void PasoReferenciaDirecto (int &a, int &b);
void PasoReferencia(int *ptr_a, int *ptr_b);
void PasoValor(int a, int b);

int main(){

    int a;
    int b;

    std::cout<<"Ingrese el valor a: ";
    std:: cin >> a; 

    std::cout << "\nIngrese el valor b: ";
    std:: cin >> b;

    PasoValor(a, b);

    std::cout <<"-----------------------\n";

    PasoReferencia(&a, &b);

  return 0; 
}

void PasoValor(int a, int b){
    int temp = 0;
    
    temp = a;
    a = b;
    b = temp;

    std::cout <<"Valor nuevo de a: " << a << " - " << "Valor nuevo de b: " << b << "\n";


}

void PasoReferencia(int a, int b){
    int temp = 0;
    
    temp = a;
    a = b;
    b = temp;

    std::cout <<"Valor nuevo de a: " << a << " - " << "Valor nuevo de b: " << b << "\n";


}