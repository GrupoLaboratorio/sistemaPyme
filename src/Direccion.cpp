#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "Direccion.h"
#include "Fecha.h"

using namespace std;

Direccion::Direccion(char * _calle, int _numero, int _codPost, char * _localidad, int _piso){

    strcpy(calle, _calle);
    numero = _numero;
    codPost = _codPost;
    strcpy(localidad, _localidad);
    piso = _piso;

}

Direccion::Direccion(){

    strcpy(calle, "NS/NC");
    numero = 0;
    codPost = 0;
    strcpy(localidad, "NS/NC");
    piso = 0;

}

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
	cout << setw(40) << "CALLE Y ALTURA:" << setw(25) << this->calle << setw(5) << this->numero << endl;
	cout << setw(40) << "CODIGO POSTAL:" << setw(30) << this->codPost << endl;
	cout << setw(40) << "LOCALIDAD:" << setw(30) << this->localidad << endl;
	cout << setw(40) << "PISO:" << setw(30) << this->piso << endl;

}
