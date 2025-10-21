#include <iostream>
#include <algorithm>
#include <vector>

struct Datos
{

    std::string nombres_luchadores;
    float pesos_libras;
};

std::vector<Datos> vector_datos;

struct Datos SolicitarDatos(struct Datos datos);
void Imprimir();
void OrdenarBurbuja(std::vector<Datos> &vector_datos);
void BuscarMayorPeso();

int main()
{

    SolicitarDatos();
    OrdenarBurbuja(vector_datos);
    Imprimir();

    return 0;
}

struct Datos SolicitarDatos(struct Datos datos)
{

    std::cout << "Ingrese el nombre de 5 luchadores: \n";

    for (int i = 1; i < 6; i++)
    {

        std::cout << "Luchador numero " << i << ":\n";
        std::cin >> datos.nombres_luchadores;

        std::cout << "Ingrese el peso de luchador en libras " << i << ":" << "\n";
        std::cin >> datos.pesos_libras;

        vector_datos.push_back(datos);
    }
}

void Imprimir()
{

    for (auto i : vector_datos)
    {

        std::cout << "Nombres de luchadores: " << i.nombres_luchadores << " - Peso de luchador: " << i.pesos_libras << "\n";
    }
}

void OrdenarBurbuja(std::vector<Datos> &vector_datos)   // Necesito modificar el sort para que acepte structs
{

    std::sort(vector_datos.begin(), vector_datos.end(), [](const Datos &a, const Datos &b)  {
        
                  return a.pesos_libras < b.pesos_libras; // ascendente
              });

}

void BuscarMayorPeso(const std::vector<Datos>& vector_datos, float pesoBuscado) {

    // std::binary_search solo compara con valores directos, así que usamos transform_iterator o hacemos manualmente:
    bool encontrado = std::binary_search(
        vector_datos.begin(), vector_datos.end(), pesoBuscado, [](const Datos& d, float peso) {
            return d.pesos_libras < peso; // criterio de comparación
        }
    );

    if (encontrado)
        std::cout << "\n Se encontró un luchador con peso " << pesoBuscado << " libras.\n";
    else
        std::cout << "\n No hay luchador con ese peso exacto.\n";
}

//Preguntar que peso desea buscar