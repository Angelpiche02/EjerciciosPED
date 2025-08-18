//Gestion de cupones de premio 
//Hacer una funcion que genere cupones compuesto por letras (el  parametro ) ingresadas por el usuario y un valor numeros en el rango de 100-999
//Los parametros son valores que vane a entrar en el cupon 
// Luego de generar cupon, hay que verificar el premio del cupon,  el parametro es el numero generado


#include <iostream>
#include <cstdlib>
#include <ctime>


std::string GeneradorCupones(std::string letras);

void AsignarPremio(std::string identificador_cupon);


int main(){

    std::string letras;
    std::cout<<"Ingrese letras: \n";
    std::cin >> letras;

    std::string cupon_generado = GeneradorCupones(letras);

    std::cout<<"Tu cupon es: " << GeneradorCupones (letras) << std::endl;

    AsignarPremio(cupon_generado);


  return 0; 
}


std::string GeneradorCupones(std::string letras){

    srand(time(0));  //Esto me dara un numero aleatorio diferente

    int NumeroAleatorio = std::rand() % 999 + 100;

    std::string Conversion = std::to_string (NumeroAleatorio);

    return letras + Conversion;

}

void AsignarPremio(std::string identificador_cupon){
    
    //'Extraer el valor numerico del identificador 

    identificador_cupon = identificador_cupon.substr(3, 4);   //el primer numero es la posicion y el segundo digito es cuantos datos voy a sacar 

    std::cout<< identificador_cupon << std::endl;


    int cupon = stoi(identificador_cupon);   //string to int

    if ((cupon % 2) == 0){

        std::cout <<"Tiene premio\n";
    } 
    else{

        std::cout<<"No tiene premio\n";
    }
}