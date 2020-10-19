#include <iostream>
#include <iomanip>
#include <cstring>
#include "../Utilidades/menus.h"
#include "Persona.h"
#include "../Utilidades/validaciones.h"
#include "Cliente.h"

using namespace std;

Cliente::Cliente():Persona(){

	strcpy(this->razonSocial, "NN");
	strcpy(this->mail, "NN@NN");
    this->tipoCliente=0;

}

//Cliente::~Cliente(){cout << "El cliente murio";}


void Cliente::cargarCliente(){

    cargarPersona();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    cout << "CATEGORIA:\t";
    cin >> tipoCliente;

}

void Cliente::mostrarCliente(){

	mostrarPersona();
	cout << setw(40) << "RAZON SOCIAL:" << setw(30) << this->razonSocial << endl;
	cout << setw(40) << "EMAIL:" << setw(30) << this->mail << endl;
	cout << setw(40) << "CATEGORIA:" << setw(30) << this->tipoCliente << endl;

}
