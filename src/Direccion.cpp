#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Direccion.h"
#include "Fecha.h"

using namespace std;

/*Direccion::Direccion(char * _calle, int _numero, int _codPost, char * _localidad, int _piso){

    strcpy(calle, _calle);
    numero = _numero;
    codPost = _codPost;
    strcpy(localidad, _localidad);
    piso = _piso;

}*/

void Direccion::cargarDireccion(){

	cin.ignore();
	cout << "Calle:\t";
	cin.getline(calle,30,'\n');	cout << "Altura:\t";
	cin >> this->numero;
	cout << "Codigo postal:\t";
	cin >> this->codPost;	cin.ignore();
	cout << "Localidad:\t";
	cin.getline(localidad,30,'\n');
	cout << "Piso:\t";
	cin >> this->piso;
	cout << endl;
}

void Direccion::mostrarDireccion(){

	cout << left;
	cout << setw(10) << "CALLE Y ALTURA:" << setw(30) << this->calle << "\t" << this->numero << endl;
	cout << setw(10) << "CODIGO POSTAL:" << setw(30) << this->codPost << endl;
	cout << setw(10) << "LOCALIDAD:" << setw(30) << this->localidad << endl;
	cout << setw(10) << "PISO:" << setw(30) << this->piso << endl;

}
