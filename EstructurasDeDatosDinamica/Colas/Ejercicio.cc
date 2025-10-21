#include <iostream>
#include <windows.h>
#include <queue>

struct Persona
{
    std::string nombre;
    std::string f_nac;
};

// Declaracion de funciones / creacion de prototipo

struct Persona SolicitarDatos(struct Persona p);   //Funcion para pedir datos
void Insertar(std::queue<Persona> &cola);     
void Eliminar();
void Imprimir(std::queue<Persona> &cola);

int main(int argc, char *argv[]){

    //Declaracion de cola
    std::queue <Persona> cola;
    struct Persona p;
    int opcion = 0;

    while(opcion != 2){

    p = SolicitarDatos(p);
    cola.push(p);

    std::cout <<"Desea ingresar mas elementos? \n";
    std::cout<<"1. Si\n";
    std::cout<<"2. No\n";
    std::cin >> opcion;

    }

    Imprimir(cola);
    

  return 0; 
}

struct Persona SolicitarDatos(struct Persona p){

    std::cout << "Ingresa un nombre: ";
    std::cin >> p.nombre;
    std::cout << "Ingresa la fecha de Nacimiento en forma DD//MM//ANO: ";
    std::cin >> p.f_nac;

    return p;
}

/*void Insertar(std::queue<Persona> &cola){
 
    cola.push(p);

} */

void Imprimir(std::queue<Persona> &cola){

    Persona frente = cola.front();

    if (!cola.empty()) {
        std::cout << "Frente: " << frente.nombre << ", " << frente.f_nac << std::endl;

        std::cout <<"Tamano de la cola: " << cola.size() << "\n";
    }

    Sleep(3000);

    cola.pop();

    std::cout << "Frente: " << frente.nombre << ", " << frente.f_nac << std::endl;
    std::cout <<"Tamano de la cola: " << cola.size() << "\n";


}