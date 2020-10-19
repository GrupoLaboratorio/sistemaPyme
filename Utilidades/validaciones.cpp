#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "../Utilidades/rlutil.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/menus.h"
#include "../Include/Persona.h"
#include "validaciones.h"

using namespace std;
using namespace rlutil;

bool validarNombresApellidos(char *nombres, int tam){

    int  cadena = 0, contEspacios=0;
    cadena = strlen(nombres);
    bool valorFinal = true;

     while (cadena == 0){
		system("cls");
        msj("Campo vacio",WHITE,RED,130,TEXT_LEFT);
        gotoxy(1,5);
        title("NUEVO USUARIO");
        locate(1,5);cout << "Nombre : ";
        cin.getline(nombres, tam);
         cadena = strlen (nombres);}


    for(int i=0; i <= cadena; i++){
        if(nombres[i]==' '){
            contEspacios++;
        }
        if(isdigit(nombres[i])==true){
            return false;
        }
    }
    if(contEspacios>=2){
        return false;
    }
    return valorFinal;
}
