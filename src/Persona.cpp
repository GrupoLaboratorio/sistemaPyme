#include <iostream>
#include <cstring>
#include <iomanip>
#include "Persona.h"
#include "Fecha.h"

using namespace std;


Persona::Persona(){
    //ctor
}
void Persona::cargarPersona(){

    cout<<"Nombre y apellido:\t";
    cin.getline(apenom, 50, '\n');
    cout<<"Fecha de Nacimiento: ";
    fecNac.setFecha();
    cout<<"DNI: ";
    cin >> nDoc;
    cout<<"Direccion: ";
    domicilio.cargarDireccion();
}

void Persona::mostrarPersona(){

	cout << left;
    cout << setw(10) << "Nombre y apellido:" << setw(30) << this->apenom << endl;
    cout << setw(10) << "Fecha de nacimiento:\t" << setw(30);
    fecNac.MostrarFecha();
    cout << endl;
    cout << setw(10) << "DNI:" << setw(30) << this->nDoc << endl;
    domicilio.mostrarDireccion();

}

/*
void Persona::setApenom(){}
void Persona::setNDoc(){}
void Persona::setNacimiento(){}
void Persona::setDomicilio(){}
const char * Persona::getApenom(){}
int Persona::getNDoc(){}
//Fecha Persona::getNacimiento(){}
//Direccion Persona::getDomicilio(){}
*/
