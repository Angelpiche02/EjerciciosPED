// Gestion de cupones de premio
// Hacer una funcion que genere cupones compuesto por letras (el  parametro ) ingresadas por el usuario y un valor numeros en el rango de 100-999
// Los parametros son valores que vane a entrar en el cupon
//  Luego de generar cupon, hay que verificar el premio del cupon,  el parametro es el numero generado

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>  // para decrecer y crecer en tiempo de ejecucion
#include <utility> // esto es para usar el pair

struct InformacionPersona
{ // esto es para anidar los structs

    std::string nombre_persona;
};

struct InformacionCupon
{
    int cant_cupones;
    std::vector<std::pair<std::string, std::string>> cupones_premio; // el vector es unidimensional

    // el pair hace que esto me de un premio y el numero del cupon, esto es de la libreria utility

    struct InformacionPersona inf_persona; //aqui ya esta anidado el struct

}; 

// vector global de tipo struct
std::vector<struct InformacionCupon> vector_cupones; // y esto es un vector que va guardar un struct

struct InformacionCupon SolicitarDatosGenerales();

std::string GeneradorCupones(std::string letras);
std::string SolicitarDatos();
std::string AsignarPremio(std::string identificador_cupon);
void Imprimir(std::vector<struct InformacionCupon> vector_cupones);

int main()
{

    int opcion;

    do{

    srand(time(0));

    struct InformacionCupon cupon;

    cupon = SolicitarDatosGenerales();

    // ALMACENAR TODO EL STRUCT EN EL VECTOR
    vector_cupones.push_back(cupon); // Todo lo que se pide se guarda aca      //el push_back es para agregarle / guardar datos al vector

    // IMPRIMIR DATO DE VECTOR STRUCT - RECORRERLO CON UN FOR
    std::cout << vector_cupones[0].cant_cupones;

    // IMPRIMIR DESDE EL VECTOR_CUPONES
    Imprimir(vector_cupones);


    std::cout<<"Desea continuar generando cupones? \n";
    std::cout<<"1. Si \n";
    std::cout<<"2. No \n";
    std::cin >> opcion;

    }
    while(opcion == 1);

    return 0;
}

std::string SolicitarDatos()
{

    // Solicitar prefijo
    std::string prefijo;

    // Validar que la longitud length() sea 3
    do
    {
        // Solicitar el prefijo
        std::cout << "Ingresa el prefijo del cupon (3 letras maximo): ";
        std::cin >> prefijo;

        // Validar la longitud igual 3
        if (prefijo.length() == 3)
        {
            return prefijo;
        }
        else
        {
            std::cout << "Error. El prefijo debe ser de 3 letras.\n";
        }
    } while (true);
}

// return del prefijo validado

std::string GeneradorCupones(std::string letras)
{

    srand(time(0)); // Esto me dara un numero aleatorio diferente

    int NumeroAleatorio = std::rand() % 999 + 100;

    std::string Conversion = std::to_string(NumeroAleatorio);

    return letras + Conversion;
}

// De void a string

std::string AsignarPremio(std::string identificador_cupon)
{

    std::string mensaje;

    //'Extraer el valor numerico del identificador

    identificador_cupon = identificador_cupon.substr(3, 4); // el primer numero es la posicion y el segundo digito es cuantos datos voy a sacar

    int cupon = stoi(identificador_cupon); // string to int

    if ((cupon % 2) == 0)
    {

        mensaje = "Tiene premio";
    }
    else
    {

        mensaje = "No tiene premio";
    }

    return mensaje;
}

struct InformacionCupon SolicitarDatosGenerales()
{

    struct InformacionCupon cupon; // hacer la variable local

    // Cantidad de cupones
    std::cout << "Ingrese el nombre de la persona: \n";
    std::cin >> cupon.inf_persona.nombre_persona;

    std::cout << "Ingrese la cantidad de cupones que quiere tener: \n";
    std::cin >> cupon.cant_cupones;

    // GUARDAR EN EL ARREGLO

    for (int i = 0; i < cupon.cant_cupones; i++)
    {

        std::string cupon_generado = GeneradorCupones(SolicitarDatos());
        std::string premio = AsignarPremio(cupon_generado);

        cupon.cupones_premio.push_back({cupon_generado, premio}); // esto es para que ingrese otro elemento y ese se iria para atras  y  eso es para guardar dentro de un vector
    }

    return cupon;
}

void Imprimir(std::vector<struct InformacionCupon> vector_cupones) // lo que buscamos es recorrer mi vector que adentro de ese vector esta el struct, entonces debo recorrerlo
{

    // IMPRIMIR DESDE EL STRUCT
    std::cout << " Imprimiendo registros de cupones \n";
    for (auto c : vector_cupones)                           //esto me sirve cuando yo no conozco la cantidad del arreglo y el AUTO es para el tipo de dato que es el vector, osea se puede poner string tambien
    { // se pone en donde esta almacenado

        std::cout << "Nommbre de la persona: " << c.inf_persona.nombre_persona << "\n"; //y aqui ya anidamos el struct de inf_persona
        std::cout << "Cantidad de cupones: " << c.cant_cupones << "\n";

        // RECORRER EL VECTOR(PAIR) cupon_premio
        for (auto c_p : c.cupones_premio)
        {
            std::cout << "Cupon: " << c_p.first << "  - Premio: " << c_p.second << "\n";
        }
    }
}