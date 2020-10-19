
#include <iostream>
using namespace std;
#include <cstring>
#include "Persona.h"

Persona::Persona(){
    //ctor
}
void Persona::cargarPersona(){

    cout<<"Ingese Apellido y Nombre: ";
    cin.getline(apenom, 50, '\n');
    cout<<"Fecha de Nacimiento: ";
    cout<<"DNI: ";
    cout<<"Direccion: ";
}
void Persona::mostrarPersona(){}
void Persona::setApenom(){}
void Persona::setNDoc(){}
void Persona::setNacimiento(){}
void Persona::setDomicilio(){}
const char * Persona::getApenom(){}
int Persona::getNDoc(){}
//Fecha Persona::getNacimiento(){}
//Direccion Persona::getDomicilio(){}
