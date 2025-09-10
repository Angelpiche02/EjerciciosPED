//La funci0on recibe un puntero a la cadena de texto, permitiendo modificarla directamente
//Usando referencia la funcion recibe la cadena de texto por referncia lo que permite modificiarla directamente
//Paso por valor

#include <iostream>

//Paso por valor
std::string PasoValor(std::string texto);

//Paso por referencia
std::string PasoReferencia(std::string &texto);

//Paso por referencia con punteros
std::string PasoReferenciaPtr ( std::string *texto);



int main(){

    std::string texto = "hola";

    std::cout << "Mensaje original: " << texto << "\n";

    std::cout << "--------------------------------------- \n";

    std::cout <<"Nuevo mensaje por valor: " << PasoValor(texto) << "\n";

    std::cout << "Mensaje original ahora es: "<< texto << "\n";

    std::cout << "--------------------------------------- \n";

    std::cout << "Nuevo mensaje por referencia: " << PasoReferencia(texto) << "\n";

    std::cout << "Mensaje original ahora es: "<< texto << "\n";

    std::cout << "--------------------------------------- \n";

    std::cout <<"Nuevo mensaje usando punteros: " << PasoReferenciaPtr(&texto) << "\n";

    std::cout << "Mensaje original ahora es: "<< texto << "\n";



  return 0; 
}

std::string PasoValor(std::string texto){

    std::cout <<"Escriba un nuevo mensaje: \n";
    std::cin >> texto;

    return texto;
}

std::string PasoReferencia(std::string &texto){

    std::cout <<"Escriba un nuevo mensaje: \n";
    std::cin >> texto;

    return texto;
}

std::string PasoReferenciaPtr(std::string *texto){

    std::cout <<"Escriba un nuevo mensaje: \n";
    std::cin >> *texto;

    return *texto;
}