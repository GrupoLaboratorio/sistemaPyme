#include <iostream>
#include <cstring>
#include <iomanip>
#include "Persona.h"
#include "Fecha.h"

using namespace std;


Persona::Persona(){

    strcpy(this->apenom, "NN");
    this->nDoc= 0;
    //this->domicilio.Direccion();
    this->activo = false;

}
void Persona::cargarPersona(){

    cin.ignore();
    cout<<"NOMBRE Y APELLIDO:\t";
    cin.getline(apenom, 50, '\n');
    cout<<"DNI: ";
    cin >> nDoc;
    domicilio.cargarDireccion();
    this->activo = true;
}

void Persona::mostrarPersona(){

	cout << left;
    cout << setw(40) << "NOMBRE Y APELLIDO:" << setw(30) << this->apenom << endl;
    cout << setw(40) << "DNI:" << setw(30) << this->nDoc << endl;
    domicilio.mostrarDireccion();

}
void Persona::setApenom(){

    cout << "NOMBRE Y APELLIDO:\t";
    cin.getline(this->apenom,50,'n');

}

void Persona::setNDoc(){

    cout << "DNI:\t";
    cin >> this->nDoc;

}

void Persona::setDomicilio(){

    this->domicilio.cargarDireccion();

}
