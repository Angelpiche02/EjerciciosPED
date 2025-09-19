//funcion struct que solicite datos y este sin parametros
//crear una funcion void para calcular IMC (IMC = peso/ (altura*altura)) y este lo guardara en el campo IMC del struct
//aceptar  como parametro un puntero STRUCT en el void
// peso en kg y metros

#include <iostream>

struct Persona{

    std::string nombre;
    float altura;
    float peso;
    float imc;  //indice de masa corporal

};


struct Persona SolicitarDatos();
void CalculoIMC(struct Persona *ptr);

int main(){

    struct Persona persona;
    struct Persona *ptr;

    persona = SolicitarDatos();
    CalculoIMC(&persona);


  return 0; 
}

struct Persona SolicitarDatos(){

    struct Persona persona;

    std::cout <<"Ingrese el nombre de la persona: ";
    std::cin >> persona.nombre;

    std::cout <<"\nIngrese la altura de la persona en metros: ";
    std::cin >> persona.altura;

    std::cout <<"\nIngrese el peso de la persona en kg: ";
    std::cin >> persona.peso;

    return persona;
}

void CalculoIMC (struct Persona *ptr){

    ptr->imc = ptr->peso / (ptr->altura * ptr->altura);

    std::cout <<"\nEl imc de la persona es: " << ptr->imc;
}