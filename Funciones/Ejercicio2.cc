//Pedirle al usuario que area quiere calcular con funciones (circulo, cuadra, rectan, trian)


#include <iostream>
#include <cmath>

//Declaracion

float AreaCirculo(float radio);
float AreaRectangulo(float base, float altura);
float AreaCuadrado(float lado);
float AreaTriangulo(float base, float altura);

const float Pi = 3.1416;

int main(){

    std::cout<<"--------------------------------------------------"<< std::endl;
    std::cout<<"Seleccione un numero para sacar el area"<< std:: endl;
    std::cout<<"1. Circulo"<< std:: endl;
    std::cout<<"2. Rectangulo"<< std:: endl;
    std::cout<<"3. Cuadrado"<< std:: endl;
    std::cout<<"4. Triangulo"<< std:: endl;
    std::cout<<"--------------------------------------------------"<< std::endl;

    int opcion;
    std::cin >> opcion;

    switch (opcion){

        case 1: 

        float radio;
        std::cout<<"Escriba el radio del circulo: ";
        std:: cin >> radio;
        std::cout<<"==============================\n";
        std::cout<<"El area del circulo es: " << AreaCirculo(radio) << std::endl;
        break;

        case 2:

        float base, altura;
        std::cout<<"Escriba la base del rectangulo: ";
        std:: cin >> base;
        std::cout<<"Escriba la altura del rectangulo: ";
        std:: cin >> altura;
        std::cout<<"==============================\n";
        std::cout<<"El area del rectangulo es: " << AreaRectangulo(base, altura) << std::endl;
        break;

        case 3:

        float lado;
        std::cout<<"Escriba el lado del cuadrado: ";
        std:: cin >> lado;
        std::cout<<"==============================\n";
        std::cout<<"El area del circulo es: " << AreaCuadrado(lado) << std::endl;
        break;

        case 4:

        std::cout<<"Escriba la base del triangulo: ";
        std:: cin >> base;
        std::cout<<"Escriba la altura del triangulo: ";
        std:: cin >> altura;
        std::cout<<"==============================\n";
        std::cout<<"El area del triangulo es: " << AreaTriangulo(base, altura) << std::endl;
        break;

        default:
        std:: cout<<"Error";

    }

  return 0; 
}


//Definicion

float AreaCirculo(float radio){

    return Pi * pow(radio, 2);
}

float AreaRectangulo(float base, float altura){

    return base * altura; 
}

float AreaCuadrado(float lado){

    return pow(lado, 2);
}

float AreaTriangulo(float base, float altura){

    return (base * altura)/2;
}
