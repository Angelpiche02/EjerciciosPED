#include <iostream>

int main(){

    int *ptr= new int;
    *ptr = 100;

    //validacion de asignacion 
    if(ptr == nullptr){

        std::cout <<"Error de asignacion de memoria \n";

    } else{
        std::cout <<"Dir. de memoria: " << ptr << "\n";

    }

    delete ptr;
    ptr = nullptr;


  return 0; 
}