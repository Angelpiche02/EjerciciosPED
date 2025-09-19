// Solicitar datos de la info del album y cantante
// imprimir en pantalla todos los datos almacenados del album y cantante
// hacer un vector de cantantes

#include <iostream>
#include <vector>
#include <utility>

int opcion;

struct InformacionAlbum
{
    std::string nombre_album;
    int antiguedad_album;
    int ano_lanzamiento;
    std::vector<std::pair<std::string, int>> titulo_numero;
};

struct InformacionCantante
{
    // snake_case
    std::string nombre_cantante;
    std::string nacionalidad;

   // std::vector<struct InformacionAlbum> vector_Album;
    struct InformacionAlbum inf_album;
};

 // aqui se guardara mi struct
std::vector<struct InformacionCantante> vector_cantante;

// Funciones
 // Se hace una funcion struct para que retorne un struct (contiene varios tipos de datos)
struct InformacionCantante SolicitarDatos();
void Imprimir(std::vector<struct InformacionCantante> vector_cantante);
// El parametro necesario no es la antiguedad es el año de lanzamiento
//int CalcularAntiguedad(int AntiguedadDeAlbum);
int CalcularAntiguedad(struct InformacionCantante datos);

int main()
{

    struct InformacionCantante datos;

    datos = SolicitarDatos();

    // Guardamos todo el struct en el vector
    vector_cantante.push_back(datos);

    Imprimir(vector_cantante);

    return 0;
}

struct InformacionCantante SolicitarDatos()
{

    struct InformacionCantante datos;

    std::cout << "Que album desea agregar?\n";
    std::cin >> datos.inf_album.nombre_album;

    std::cout << "Año de lanzamiento: \n";
    std::cin >> datos.inf_album.ano_lanzamiento;

    std::cout << "Nombre del cantante: \n";
    std::cin >> datos.nombre_cantante;

    std::cout << "Nacionalidad del cantante: \n";
    std::cin >> datos.nacionalidad;

    datos.inf_album.antiguedad_album = CalcularAntiguedad(datos);

    do
    {

        std::string titulo;
        int numero;

        std::cout << "Escriba el titulo de la cancion: \n";
        std::cin >> titulo;

        std::cout << "Escriba el numero de la cancion: \n";
        std::cin >> numero;

        std::cout << "Desea agregar otra cancion?\n";
        std::cout << "1. Si\n";
        std::cout << "2. No\n";
        std::cin >> opcion;

        if (opcion != 1 && opcion != 2)
        {
            std::cout << "Error\n";
        }

        if (opcion == 1)
        {

            datos.inf_album.titulo_numero.push_back({titulo, numero});
        }
        if (opcion == 2)
        {

            datos.inf_album.titulo_numero.push_back({titulo, numero});
        }

    } while (opcion == 1);

    return datos;
}

void Imprimir(std::vector<struct InformacionCantante> vector_cantante)
{

    std::cout << "Imprimiendo informacion de album\n";

    for (auto cancion : vector_cantante)
    {
        std::cout << "Nombre del album: " << cancion.inf_album.nombre_album << "\n";
        std::cout << "Ano en el que salio: " << cancion.inf_album.ano_lanzamiento << "\n";
        std::cout << "Nombre del cantante: " << cancion.nombre_cantante << "\n";
        std::cout << "Nacionalidad del cantante: " << cancion.nacionalidad << "\n";
        std::cout <<"Antiguedad de album: " << cancion.inf_album.antiguedad_album << "\n";

        std::cout <<"------------------------------------------------------------------------\n";

        for (auto t_n : cancion.inf_album.titulo_numero)
        {
            std::cout << "Nombre de la cancion: " << t_n.first << " -------- " << " Numero de la cancion: " << t_n.second << "\n";
        }
    }
}

int CalcularAntiguedad(struct InformacionCantante datos)
{

    return  2025 - datos.inf_album.ano_lanzamiento;

}
