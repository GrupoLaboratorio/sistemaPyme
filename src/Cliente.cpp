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

const char * FILE_CLIENTES = "Archivos/Clientes.dat";

using namespace std;
using namespace rlutil;

Cliente::Cliente():Persona(){

	strcpy(this->razonSocial, "NN");
	strcpy(this->mail, "NN@NN");
    this->tipoCliente=0;

}

//Cliente::~Cliente(){cout << "El cliente murio";}


void Cliente::cargarCliente(){

    title("NUEVO CLIENTE", BLACK, CYAN); //-> ARREGLAR
    locate(3,3);
    cargarPersona();
    cin.ignore();
    cout << "RAZON SOCIAL:\t";
    cin.getline(this->razonSocial,50,'\n');
    cout << "EMAIL:\t";
    cin.getline(this->mail,50,'\n');
    cout << "CATEGORIA:\t";
    cin >> tipoCliente;
    this->idCliente = crearIdClientes();

}

void Cliente::mostrarCliente(){

	mostrarPersona();
	cout << setw(40) << "RAZON SOCIAL:" << setw(30) << this->razonSocial << endl;
	cout << setw(40) << "EMAIL:" << setw(30) << this->mail << endl;
	cout << setw(40) << "CATEGORIA:" << setw(30) << this->tipoCliente << endl;
	cout << setw(40) << "ID:" << setw(30) << this->idCliente << endl;

}

void Cliente::setRazonSocial(char * _razonSocial){strcpy(this->razonSocial,_razonSocial);}

void Cliente::setMail(char * _mail){strcpy(this->mail,_mail);}

void Cliente::setTipoCliente(){
    cout << "CATEGORIA:";
    cin >> this->tipoCliente;
        while(this->tipoCliente<0 || this->tipoCliente > 3){
            msj("INCORRECTO",WHITE,RED,130,TEXT_LEFT);
            cin >> this->tipoCliente;
        }
}

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

bool Cliente::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_CLIENTES, "rb");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof(Cliente), 0);
        leyo = fread(this, sizeof(Cliente), 1, p);
        fclose(p);
        return leyo;
}


///--------------------- GLOBALES -------------------------


void listarClientePorID(){

    Cliente *cliAux;
    FILE *p;
    int idAux;

    cout << "Ingrese ID a buscar:\t";
    cin >> idAux;

    p = fopen(FILE_CLIENTES, "rb");
    if(p==NULL){
            return;
    }

        while(fread(cliAux,sizeof(Cliente),1,p)){
            if(cliAux->getIdCliente() == idAux){
                cliAux->mostrarCliente();
            }
        }

    fclose(p);
    return;
}

int crearIdClientes(){

    int bytes, cant;
    FILE *p = fopen(FILE_CLIENTES, "rb");
    if (p == NULL){
        return 1;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Cliente);
    return cant+1;

}

void listarClientes(){

    int i=0;
    Cliente cliAux;
    bool estadoAux;

    cout << left;
    cout << setw(22) << "ID CLIENTE" << setw(22) << "RAZON SOCIAL" << setw(22) << "CATEGORIA" << endl;
    cout << endl;
        while(cliAux.leerDeDisco(i++)){
                estadoAux = cliAux.getIdCliente();
                estadoAux = cliAux.getEstado();
                if(estadoAux == true){
                cout << setw(22);
                cout << cliAux.getRazonSocial();
                cout << setw(22);
                switch(cliAux.getTipo()){
                case 1:
                    cout << setw(22) << "Monotributista";
                break;
                case 2:
                    cout << setw(22) << "Responsable Inscripto";
                break;
                case 3:
                    cout << setw(22) << "Consumidor final";
                break;
                default:
                    cout << "CATEGORIA INCORRECTA";
                break;
                }
                cout << endl;
            }
    }
}


//void listarClientes(){
//
//    Cliente cliAux;
//    bool estadoAux;
//    FILE *p;
//    int idAux;
//
//    p = fopen(FILE_CLIENTES, "rb");
//    if(p==NULL){
//            cout << "Error de archivo\n";
//            system("pause");
//            return;
//    }
//
//        while(fread(&cliAux,sizeof(Cliente),1,p)==1){
//            estadoAux = cliAux.getEstado();
//            if(estadoAux == true){
//                cliAux.mostrarCliente();
//            }
//        }
//    system("pause");
//    fclose(p);
//    return;
//}

//void listarClientes(){
//
//    Cliente cliAux;
//    bool estadoAux;
//    FILE *p;
//    int idAux;
//
//    p = fopen(FILE_CLIENTES, "rb");
//    if(p==NULL){
//            cout << "Error de archivo\n";
//            system("pause");
//            return;
//    }
//        cout << setw(22) << "RAZON SOCIAL" << setw(22) << "CATEGORIA" << endl;
//        while(fread(&cliAux,sizeof(Cliente),1,p)==1){
//                estadoAux = cliAux.getEstado();
//                if(estadoAux == true){
//                cout << left;
//                cout << cliAux.getRazonSocial();
//
//                cout << setw(22);
//                switch(cliAux.getTipo()){
//                case 1:
//                    cout << "Monotributista";
//                break;
//                case 2:
//                    cout << "Responsable Inscripto";
//                break;
//                case 3:
//                    cout << "Otro";
//                break;
//                default:
//                    cout << "CATEGORIA INCORRECTA";
//                break;
//                }
//            }
//        }
//    system("pause");
//    fclose(p);
//    return;
//}
