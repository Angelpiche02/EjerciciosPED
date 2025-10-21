// Vector de struct almacena nombres de luchadores y pesos en libras
// Solicitar 5 nombres de 5 luchadores y sus pesos en libras 

#include <iostream>
#include <vector>

struct Datos{

    std::string nombres_luchadores;
    float pesos_libras;
};

std::vector <Datos> vector_datos;

struct Datos SolicitarDatos(Datos datos);
void Imprimir();
void OrdenarBurbuja(std::vector <Datos> &vector_datos);
void PesoMayor(std::vector <Datos> &vector_datos);

int main(){

    Datos dato;
    int opcion = 0;
    
    do {

        SolicitarDatos(dato);
        std::cout <<"Desea agregar otro luchador?\n";
        std::cout <<"1. Si\n";
        std::cout <<"2. No\n";
        std::cin >> opcion;

    }   while(opcion != 2);

    OrdenarBurbuja(vector_datos);
    Imprimir();
    PesoMayor(vector_datos);


  return 0; 
}

struct Datos SolicitarDatos(Datos datos){

    std::cout <<"Luchador: \n";
    std::cin >>  datos.nombres_luchadores;

    std::cout <<"Ingrese el peso de luchador en libras "  << ":" << "\n";
    std::cin >> datos.pesos_libras;

    vector_datos.push_back(datos);

    return datos;
}

void Imprimir(){

    for (auto i : vector_datos){

        std::cout <<"Nombres de luchadores: " << i.nombres_luchadores << " - Peso de luchador: " << i.pesos_libras << "\n";

    }
}

void OrdenarBurbuja(std::vector <Datos> &vector_datos) {
    int n = vector_datos.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (vector_datos[j].pesos_libras > vector_datos[j + 1].pesos_libras) {

                Datos temp = vector_datos[j];
                vector_datos[j] = vector_datos[j + 1];
                vector_datos[j + 1] = temp;
            }
        }
    }

    return;
}

void PesoMayor(std::vector <Datos> &vector_datos){
    
    int i = vector_datos.size() - 1;        //ultimo valor 

    std::cout << "EL luchador con mas peso es: " << vector_datos [i].nombres_luchadores << "\n";
    std::cout <<"SU peso es: " << vector_datos[i].pesos_libras << "\n";

}
