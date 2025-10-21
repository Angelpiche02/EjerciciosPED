#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

struct Luchadores
{
    std::string nombre_Luchador;
    float pesos_Libreas;
};
std::vector<Luchadores> vector_Luchadores;

struct Luchadores SolicitarDatos();
void Imprimir();
void Comparar();
void Imprimir2();

int main ()
{
    int opcion;
    do{
   SolicitarDatos();
   std::cout<<"deseas agregar otro luchador?\n";
   std::cout<<"1.si      2.no\n";
   std::cin>>opcion;
    }while(opcion != 2);
    Comparar();
    Imprimir();
    Imprimir2();
    return 0;


}
struct Luchadores SolicitarDatos()
{
    int i = 0;
        Luchadores Datos;
        std::cout << i+1 << ". Nombre: ";
        std::cin >> Datos.nombre_Luchador;

        std::cout << "Peso del luchador: ";
        std::cin >> Datos.pesos_Libreas;
        std::cout << "\n";

        vector_Luchadores.push_back(Datos);

}
void Imprimir()
{
    struct Luchadores datos;
    std::cout<<"---------------imprimiendo-------------------------\n";
    for(auto i: vector_Luchadores)
    {
        std::cout<<"luchador: "<<i.nombre_Luchador;
        std::cout<<"\n";
        std::cout<<"peso: "<<i.pesos_Libreas;
        std::cout<<"\n";
    }
}
void Comparar()
{
    std::sort(vector_Luchadores.begin(), vector_Luchadores.end(),
    [](Luchadores a, Luchadores b) {
        return a.pesos_Libreas > b.pesos_Libreas;
    });

}
void Imprimir2()
{
    std::cout<<"EL luchador con mas pero eessssssssssssss\n";
    Sleep(3000);
    std::cout<<"nombre: "<<vector_Luchadores[0].nombre_Luchador;
    Sleep(1000);
    std::cout<<"nombre: "<<vector_Luchadores[0].pesos_Libreas;
}