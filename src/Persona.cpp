#include <iostream>
#include <cstring>
#include <iomanip>
#include "Persona.h"
#include "Fecha.h"

using namespace std;


Persona::Persona(){

    strcpy(this->apenom, "NN");
    this->fecNac.setDia(0);
    this->fecNac.setMes(0);
    this->fecNac.setAnio(0);
    this->nDoc= 0;
    //this->domicilio.Direccion();
    this->activo = false;

}
void Persona::cargarPersona(){

    cin.ignore();
    cout<<"Nombre y apellido:\t";
    cin.getline(apenom, 50, '\n');
    cout<<"Fecha de Nacimiento: ";
    fecNac.setFecha();
    cout<<"DNI: ";
    cin >> nDoc;
    cout<<"Direccion: ";
    domicilio.cargarDireccion();
    this->activo = true;
}

void Persona::mostrarPersona(){

	cout << left;
    cout << setw(40) << "NOMBRE Y APELLIDO:" << setw(30) << this->apenom << endl;
    cout << setw(40) << "FECHA DE NACIMIENTO:\t";
    fecNac.MostrarFecha();
    cout << endl;
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

void Persona::setNacimiento(){

    this->fecNac.setFecha();

}
void Persona::setDomicilio(){

    this->domicilio.cargarDireccion();

}


/*

//Fecha Persona::getNacimiento(){}
//Direccion Persona::getDomicilio(){}
*/
