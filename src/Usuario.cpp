#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <locale.h>
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "Usuario.h"

using namespace std;
using namespace rlutil;


const char * FILE_USUARIOS = "Archivos/Usuarios.dat";

void Usuario::setNombreUser(){
    cout << "NOMBRE DE USUARIO: ";
	cin>>this->nombreUser;
}

void Usuario::setPassword(){
     setlocale(LC_CTYPE, "Spanish");
    cout << "CONTRASEÑA: ";
	cin>>this->password;
}

void Usuario::ingresarUsuario(){

    setNombreUser();
    setPassword();

}

bool Usuario::grabarEnDisco(){

    system("cls");
    FILE *c;
    bool chequeo;

        c = fopen(FILE_USUARIOS,"ab");
        if(c==NULL){
            cout << "Error al abrir el archivo clientes\n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Usuario),1,c);
        if(chequeo==1){

            msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            fclose(c);
            system("cls");
            return true;
        }
        else{
            cout << "El registro no pudo guardarse en clientes\n\n";
            fclose(c);
            system("pause");
            return false;
        }

    }

bool Usuario::leerDeDisco(int posicion){
        bool leyo;
        FILE *c;

            c = fopen(FILE_USUARIOS, "rb");
            if (c == NULL){
            cout << "Error archivo de USUARIOS";
            return false;
            }
            fseek(c, posicion * sizeof(Usuario), 0);
            leyo = fread(this, sizeof(Usuario), 1, c);
            fclose(c);
            return leyo;

}


///--------------------------------- GLOBAL

void crearUsuario(){

	Usuario regAux;

	regAux.ingresarUsuario();
    regAux.setIdUser(crearIdUsuario());
	regAux.setActivo();
	regAux.grabarEnDisco();

}

void listarUsuarios(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;

        c = fopen(FILE_USUARIOS, "rb");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c)==1){
                estadoAux = usuAux.getEstado();
                if(estadoAux == true){
                    cout  << "USER:" << usuAux.getNombreUser() << "\t"<< "PASSWORD:" << usuAux.getPassword() << "\tID\t" << usuAux.getIdUser();
                }
                cout << endl;
            }
        system("pause");
        fclose(c);
        return;
}

int login(){

    Usuario userLog, usuAux;
    int passAux, i=0;
    char *nombreAux;
    bool estadoAux;
    const int POSMENUX = 35;
    const int POSMENUY = 2;

    locate(POSMENUX+5,POSMENUY+1);
    userLog.setNombreUser();
    locate(POSMENUX+5,POSMENUY+2);
    userLog.setPassword();


    if(strcmp(userLog.getNombreUser(), "ADMIN")== 0){
        if(userLog.getPassword() == 1234){
            msj("INGRESO EXITOSO",WHITE,GREEN,130,TEXT_LEFT);
            return 2;
        }
    }
            while(usuAux.leerDeDisco(i++)){

                if(usuAux.getEstado() == true || usuAux.getEstado() == 1){

                    if(strcmp(userLog.getNombreUser(), usuAux.getNombreUser())== 0){
                        if(userLog.getPassword() == usuAux.getPassword()){
                            msj("INGRESO EXITOSO",WHITE,GREEN,130,TEXT_LEFT);
                            return 1;
                        }else{
							msj("CONTRASEÑA INCORRECTA",WHITE,RED,130,TEXT_LEFT);
							return 0;
							cout << endl;
                        }
                }
            }
        }
        msj("USUARIO INEXISTENTE",WHITE,RED,130,TEXT_LEFT);
        cout << endl;
		return 0;
}

void bagaLogicaUsuario(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;
    int idAux;

    cout << "INGESE:\t";
    cin >> idAux;

        c = fopen(FILE_USUARIOS, "rb");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c) == 1){
                if(usuAux.getIdUser() == idAux){
                    cout  << "USER:" << usuAux.getNombreUser() << "\t"<< "PASSWORD:" << usuAux.getPassword();
                    usuAux.setInactivo();
                }
                cout << endl;
            }
        system("pause");
        fclose(c);
        return;
}

int crearIdUsuario(){


    int bytes, cant;
    FILE *p = fopen(FILE_USUARIOS, "rb");
     if (p == NULL){
        return 1;
    }
	fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
	cant = bytes / sizeof(Usuario);
    return cant+1;

}
