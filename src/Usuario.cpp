#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
using namespace std;
using namespace rlutil;

#include "Usuario.h"

const char * FILE_USUARIOS = "Archivos/Usuarios.dat";

void Usuario::setNombreUser(){
    cout << "NOMBRE DE USUARIO: ";
	cin>>this->nombreUser;
}

void Usuario::setPassword(){
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
            cout << "Registro exitoso";
            fclose(c);
            system("pause");
            // cls();
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
	regAux.setActivo();
	regAux.grabarEnDisco();

}

void listarUsuarios(){

    Usuario usuAux;
    bool estadoAux;
    FILE *c;
    int idAux;

        c = fopen(FILE_USUARIOS, "rb");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return;
        }

            while(fread(&usuAux,sizeof(Usuario),1,c)==1){
                estadoAux = usuAux.getEstado();
                if(estadoAux == true){
                    cout << setw(30) << "USER:" << usuAux.getNombreUser() <<
                    cout << setw(30) << "PASSWORD:" << usuAux.getPassword();
                }
            }
        system("pause");
        fclose(c);
        return;
}

bool login(){

    Usuario userLog, usuAux;
    int atempts = 3, passAux;
    char * nombreAux;
    bool estadoAux;
    FILE *c;

    userLog.setNombreUser();
    userLog.setPassword();

	c = fopen(FILE_USUARIOS, "rb");
        if(c==NULL){
                cout << "Error de archivo usuarios\n";
                system("pause");
                return false;
        }
	while(atempts > 0){

            while(fread(&usuAux,sizeof(Usuario),1,c)==1){
				/// chequear si no pasa al siguiente usuario cuando se reingresa por error de tipeo
                estadoAux = usuAux.getEstado();
                strcpy(nombreAux, usuAux.getNombreUser());
                passAux = usuAux.getPassword();
                if(estadoAux == true){
                    if(strcmp(userLog.getNombreUser(), nombreAux)== 0){
                        if(userLog.getPassword() == passAux){
                            cout << "BIENVENIDO";
                            fclose(c);
                            return true;
                        }else{
							atempts--;
							cout << "CONTRASENIA";
							userLog.setPassword();
                        }
                    }else{
                        atempts--;
                    	cout << "USUARIO INCORRECTO";
                    	userLog.setNombreUser();
                    }
                }
            }
	}
		return false;
        system("pause");
        fclose(c);
}
