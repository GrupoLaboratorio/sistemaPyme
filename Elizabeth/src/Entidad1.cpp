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
#include "Entidad.h"

const char * FILE_CLIENTES = "Archivos/Clientes.dat";
const char * FILE_PROVEEDORES = "Archivos/Proveedores.dat";

using namespace std;
using namespace rlutil;

Entidad::Entidad():Persona(){

	strcpy(this->razonSocial, "NN");
	strcpy(this->mail, "NN@NN");
    this->tipoEntidad=0;

}

//Entidad::~Entidad(){cout << "El Entidad murio";}


void Entidad::cargarCliente(){

    //title("NUEVO CLIENTE", BLACK, CYAN); //-> ARREGLAR
    locate(3,3);
    cargarPersona();
    cin.ignore();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    setTipoEntidad(1);
    this->idEntidad = crearIdEntidades(this->getTipoEntidad());

}

void Entidad::cargarProveedor(){

    //title("NUEVO PROVEEDOR", BLACK, CYAN); //-> ARREGLAR
    locate(3,3);
    cargarPersona();
    cin.ignore();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    setTipoEntidad(2);
    this->idEntidad = crearIdEntidades(this->getTipoEntidad());

}

void Entidad::mostrarEntidad(){

	mostrarPersona();
	cout << setw(40) << "RAZON SOCIAL:" << setw(30) << this->razonSocial << endl;
	cout << setw(40) << "EMAIL:" << setw(30) << this->mail << endl;
	cout << setw(40) << "CATEGORIA:" << setw(30);
	switch(this->tipoEntidad){
	case 1: cout << "CLIENTE" << endl; break;
	case 2: cout << "PROVEEDOR" << endl; break;
	}
	cout << setw(40) << "ID:" << setw(30) << this->idEntidad << endl;

}

void Entidad::setRazonSocial(char * _razonSocial){strcpy(this->razonSocial,_razonSocial);}

void Entidad::setMail(char * _mail){strcpy(this->mail,_mail);}

//void Entidad::setTipoEntidad(){
//    cout << "CATEGORIA:";
//    cin >> this->tipoEntidad;
//        while(this->tipoEntidad != 1 || this->tipoEntidad != 2){
//            msj("INCORRECTO",WHITE,RED,130,TEXT_LEFT);
//            cin >> this->tipoEntidad;
//        }
//}

void Entidad::setTipoEntidad(int _tipo){this->tipoEntidad = _tipo;}

bool Entidad::grabarEnDisco(int _tipoEntidad){

    system("cls");
    FILE *c, *p;
    bool chequeo;

    switch(_tipoEntidad){

    case 1:
        c = fopen(FILE_CLIENTES,"ab");
        if(c==NULL){
            cout << "Error al abrir el archivo clientes\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Entidad),1,c);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            cout << "Registro exitoso";
            fclose(c);
            system("pause");
            // cls();
            return true;
        }else{
            cout << "El registro no pudo guardarse en clientes\n\n";
            fclose(c);
            system("pause");
            return false;
        }
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo proveedores\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Entidad),1,p);
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
    break;

    }
}

bool Entidad::leerDeDisco(int posicion,int _tipoEntidad){ /// Modificar
        bool leyo;
        FILE *c, *p;

        switch(_tipoEntidad){
        case 1:
            c = fopen(FILE_CLIENTES, "rb");
            if (c == NULL){
            cout << "Error archivo de clientes";
            return false;
            }
            fseek(c, posicion * sizeof(Entidad), 0);
            leyo = fread(this, sizeof(Entidad), 1, c);
            fclose(c);
            return leyo;
        break;
        case 2:
            p = fopen(FILE_PROVEEDORES, "rb");
            if (p == NULL){
            cout << "Error archivo de proveedores";
            return false;
            }
            fseek(p, posicion * sizeof(Entidad), 0);
            leyo = fread(this, sizeof(Entidad), 1, p);
            fclose(p);
            return leyo;
        break;
    }
}

///--------------------- GLOBALES -------------------------


void listarEntidadPorID(int _tipoEntidad){

    Entidad *entiAux;
    FILE *p, *c;
    int idAux;

    cout << "Ingrese ID a buscar:\t";
    cin >> idAux;

    switch(_tipoEntidad){

    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if(c==NULL){
        return;
        }

            while(fread(entiAux,sizeof(Entidad),1,c)){
                if(entiAux->getIdEntidad() == idAux){
                    entiAux->mostrarEntidad();
                }
            }

        fclose(c);
        return;
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if(p==NULL){
        return;
        }

            while(fread(entiAux,sizeof(Entidad),1,p)){
                if(entiAux->getIdEntidad() == idAux){
                    entiAux->mostrarEntidad();
                }
            }

        fclose(p);
        return;
    break;



    }
}

int crearIdEntidades(int _tipoEntidad){

    int bytes, cant;
    FILE *c, *p;
    cout << "Llego a la funcion";
    system("pause");
    switch(_tipoEntidad){
    case 1:
        c = fopen(FILE_PROVEEDORES, "rb");
        if (c == NULL){
            return 1;
        }
        fseek(c, 0, SEEK_SET);
        bytes = ftell(c);
        fclose(c);
        cant = bytes / sizeof(Entidad);
        return cant+1;
    break;
    case 2:
        p = fopen(FILE_CLIENTES, "rb");
        if (p == NULL){
            return 2000000;
        }
        fseek(p, 0, SEEK_SET);
        bytes = ftell(p);
        fclose(p);
        cant = bytes / sizeof(Entidad);
        return cant+1;
    break;
    }
}

void listarEntidades(int _tipoEntidad){

    Entidad cliAux;
    bool estadoAux;
    FILE *p, *c;
    int idAux;

    switch(_tipoEntidad){
    case 1:
        c = fopen(FILE_CLIENTES, "rb");
        if(c==NULL){
                cout << "Error de archivo\n";
                system("pause");
                return;
        }

            while(fread(&cliAux,sizeof(Entidad),1,c)==1){
                estadoAux = cliAux.getEstado();
                if(estadoAux == true){
                    cliAux.mostrarEntidad();
                }
            }
        system("pause");
        fclose(c);
        return;
    break;
    case 2:
        p = fopen(FILE_PROVEEDORES, "rb");
        if(p==NULL){
                cout << "Error de archivo\n";
                system("pause");
                return;
        }

            while(fread(&cliAux,sizeof(Entidad),1,p)==1){
                estadoAux = cliAux.getEstado();
                if(estadoAux == true){
                    cliAux.mostrarEntidad();
                }
            }
        system("pause");
        fclose(p);
        return;
    break;

    }
}
