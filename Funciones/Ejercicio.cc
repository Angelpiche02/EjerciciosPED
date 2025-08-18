//Crear una funcion que calcule el area de un circulo solicitando datos al usuario
// round trabaja con double y roundf trabaja con float
// si quiero redondear a un decimal tengo que multiplicar el area por 10 y y a eso dividirle 10.0, asi obtenemos solo un decimal
// tambien puedo usar #include <iomanip> para setprecision(1) ese 1 es para poner la cantidad de decimales    


#include <iostream>
#include <cmath>

//Declaracion 

float AreaDelCirculo (float radio); //Variable local 

const double kPi = 3.1416;          //Variable global

int main(){

    float radio;
    std::cout<<"Ingrese el radio para ver el area del circulo: ";
    std:: cin >> radio;

    std::cout <<"---------------------------------------------"<< std:: endl;
    std::cout <<"El resultado es: "<< AreaDelCirculo(radio);            //Invocacion


  return 0; 
}

//Definicion

float AreaDelCirculo(float radio){
    return roundf((radio * radio) * kPi);       //Investigar roundf 
}