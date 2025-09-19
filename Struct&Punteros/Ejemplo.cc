//

#include <iostream>
#include <string>   //Buena practica 

struct Persona{

    std::string nombre;
    float altura;
    float peso;
    float imc;  //indice de masa corporal

} Persona; //variable global que representa la struct persona



int main(){

    struct Persona persona;
    struct Persona *ptr;    //Puntero local que represetnta al struct
    struct Persona *ptr = &persona;

    ptr->nombre = "Mario";    //Operador flecha, este se necesita para poder acceder al struct
    

  return 0; 
}