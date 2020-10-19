#include <iostream>
#include <cstdlib>
//#include "Inmueble.h"
#include "../include/Direccion.h"
//#include "Fecha.h"

using namespace std;

/*Direccion::Direccion(char * _calle, int _numero, int _codPost, char * _localidad, int _piso){

    strcpy(calle, _calle);
    numero = _numero;
    codPost = _codPost;
    strcpy(localidad, _localidad);
    piso = _piso;

}*/




void Direccion::cargarDireccion(){

	cout << "Calle:\t";
	cin >> this->calle;
	cout << endl;	cout << "Altura:\t";
	cin >> this->numero;
	cout << endl;
	cout << "Codigo postal:\t";
	cin >> this->codPost;
	cout << endl;	cout << "Localidad:\t";
	cin >> this->localidad;
	cout << endl;
	cout << "Piso:\t";
	cin >> this->piso;
	cout << endl;
}

void Direccion::mostrarDireccion(){

	cout << "Calle y altura:\t" << calle << "   " << numero << endl;
	cout << "Codigo postal:\t" << codPost << endl;
	cout << "Localidad:\t" << localidad << endl;
	cout << "Piso:\t" << piso << endl;

}
