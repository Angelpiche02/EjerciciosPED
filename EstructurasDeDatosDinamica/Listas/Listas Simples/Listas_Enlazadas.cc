//  Las estruturas de datos dinamicas se basan en las lineales que son listas, pilas y colas; y NO lineal que son grafos y arboles 
//  Las estructuras de datos dinamicas es una coleccion de elementos / nodos

/*  TIPOS DE LISTAS ENLAZADAS
  En la lista simple solo se va recto
  En la lista doblemente enlazada se puede ir hacia delante y hacia atras
  Lista circula simple enlazada 
  Lista circular doblemente enlazada */

//  En una lista simplemente enlazada, cada nodo apunta al que sigue, hasta el ultimo que ese apunta a nullptr

/*Cuando se reserva memoria para cada nodo (struct), estos pueden quedar en distintas direcciones de memoria.
El puntero siguiente actúa como un enlace que conecta un nodo con el siguiente.
El último nodo siempre apunta a nullptr para indicar el final de la lista*/

// CADA NODO ES UN STRUCT DISTINTO

#include <iostream>

//  Struct de la informacionn que guardara en la lista
struct Datos{

  int numero;

};

//  Las listas enlazadas constan de un numero de nodos y estos tienen 2 compontentes que van en el struct, un enlace va al sigueiente nodo
struct Nodo{

  struct Datos datos;
  struct Nodo *siguiente;   // Apunta a otro struct Nodo, es decir, a otro nodo de la misma lista. Cada nodo tiene su propio campo siguiente

};

//Puntero global en memoria estatica, osea solo esta para recibir, esto es necesarion para cada funcion, por eso es global, por comodidad 
struct Nodo *inicio_lista = nullptr;

void InsertarInicio(int);
void InsertarFinal(int);
void EliminarInicio();
void EliminarFinal();
void Imprimir();

int main(){

  //InsertarFinal(89);
  InsertarInicio(40);
  InsertarInicio(80);
  //InsertarInicio(100);
  //EliminarInicio();
  Imprimir();

  /*std::cout << "Dir memoria: " << inicio_lista->siguiente  << " - Numero: " << inicio_lista->datos.numero << "\n";
  std::cout <<"Dir memoria: " << inicio_lista->siguiente->siguiente << " - Numero: " << inicio_lista->siguiente->siguiente->datos.numero << "\n"; */

  return 0; 
}

void InsertarInicio(int n){

  //  Reserva de memoria, esto manejandose en el heap, osea es dinamico, apunta a todo lo nuevo que va llegar, esto hace que se creen mas structs
  struct Nodo *nuevo_nodo = new Nodo;

  //  Variable auxiliar almacena el nodo actual
  nuevo_nodo->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;

  //  Si la lista esta vacia se agrega al primer elemento (el nuevo nodo)
  if(inicio_lista == nullptr){

    inicio_lista = nuevo_nodo;
  }
  else{

      nuevo_nodo->siguiente = inicio_lista;   /*"El puntero siguiente de un nodo apunta al próximo nodo de la lista.
                                                Si no hay un próximo nodo, su valor será nullptr*/
      inicio_lista = nuevo_nodo;  // El puntero global inicio_lista siempre apunta al primer nodo de la lista (o a nullptr si la lista está vacía).
  }
}

void Imprimir(){

  struct Nodo *temporal = inicio_lista;

  if(inicio_lista != nullptr){

    while(temporal != nullptr){

      std::cout <<"Valores de lista: " << temporal->datos.numero <<" - Direccion: " << temporal << " - Dir nodo siguiente: " << temporal->siguiente <<"\n";
    
      temporal = temporal->siguiente;
    }
  }
}

void InsertarFinal(int n){

  struct Nodo *temporal = inicio_lista;   //crear un puntero auxiliar (temporal) que apunta al mismo lugar que inicio_lista.
  struct Nodo* nuevo_nodo = new Nodo;

  nuevo_nodo->datos.numero = n;
  nuevo_nodo->siguiente = nullptr;

  if(inicio_lista == nullptr){

    inicio_lista = nuevo_nodo;
  }
  else{

    while (temporal->siguiente != nullptr){

      temporal = temporal->siguiente;
    }
    temporal->siguiente = nuevo_nodo;
  }
}

void EliminarInicio(){

  struct Nodo *temporal = inicio_lista;

  //SI EN LA LISTA  SE ENCUENTRAN ELEMENTOS;
  if (inicio_lista != nullptr){

    //Borra el elemento
    inicio_lista = temporal->siguiente;

    //Libera la memoria
    delete temporal;
    temporal = nullptr;
  }
}

void EliminarFinal(){

  struct Nodo *temporal = inicio_lista;
  struct Nodo *temporal2;

  if(inicio_lista != nullptr){

    if(temporal->siguiente != nullptr){

      while(inicio_lista != nullptr)
      {
        temporal2 = temporal;
        temporal = temporal->siguiente;
      }

      //Almacena el penultimo nodo sera quien apunte a nullptr
      temporal2->siguiente = nullptr;

      delete temporal;
      temporal = nullptr;
    }
  }
}