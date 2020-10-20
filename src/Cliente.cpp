#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include "../Utilidades/menus.h"
#include "Persona.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
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

void Cliente::setRazonSocial(char * _razonSocial){strcpy(this->razonSocial,_razonSocial);}

void Cliente::setMail(char * _mail){strcpy(this->mail,_mail);}

void Cliente::setTipoCliente(int _tipo){this->tipoCliente = _tipo;}

bool Cliente::grabarEnDisco(){

    system("cls");
    FILE *p;
    bool chequeo;

    p = fopen(FILE_CLIENTES,"ab");
    if(p==NULL){
		cout << "Error al abrir el archivo \n";
        return false;
    }
    chequeo = fwrite(this, sizeof(Cliente),1,p);
    if(chequeo==1){

		//msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
		cout << "Registro exitoso";
        fclose(p);
        system("pause");
		// cls();
        return true;
    }
    else{
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        //cls();
        return false;
    }

}

/*
bool Cliente::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_CLIENTES, "rb");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Examen), 0);
        leyo = fread(this, sizeof(Examen), 1, p);
        fclose(p);
        return leyo;
    }
*/
