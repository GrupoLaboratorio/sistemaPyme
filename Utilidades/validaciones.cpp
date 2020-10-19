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
} /// Falta revisar la parte de tamaños

/*
bool validarFecha( int dia, int mes, int anio){

    Fecha fechaDeHoy;

    fechaDeHoy = hoy();
    bool fec = false;

    if (anio >= fechaDeHoy.anio )
        if(mes >= fechaDeHoy.mes)
         if(dia >= fechaDeHoy.dia){
            fec=false;
              return fec;
    }

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes ){

        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if( dia >= 1 && dia <= 31 ){  fec = true;}
            break;

        case 4:case 6:case 9:case 11:
            if( dia >= 1 && dia <= 30 ){ fec = true;}
            break;


        case 2://Si el año es bisiesto +1 día.

            if( ((anio%4 == 0)   &&   (anio%100 != 0)) ||   (anio%400 == 0) ){
                if( dia >= 1 && dia <= 29 ){
                    fec = true;
                }
            }else{
                if( dia >= 1 && dia <= 28 ){
                    fec = true;
                }
            }
            break;

        }

    }
    return fec;
}
*/
