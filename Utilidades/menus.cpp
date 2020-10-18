#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include "ui.h"
#include "rlutil.h"

using namespace rlutil;
using namespace std;



void menuPrincipal(){

    while(true){
        cls();
        title("MENU PRINCIPAL",BLACK,CYAN);
        gotoxy(1,3);
        cout<<"1 - USUARIOS"<<endl;
        cout<<"2 - ENTRENAMIENTOS"<<endl;
        cout<<"3 - REPORTES"<<endl;
        cout<<"4 - CONFIGURACION"<<endl;
        cout<<"5 - MODELO PARCIAL"<<endl;
        cout<<"6 - PARCIAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            menuUsuarios();
            break;
        case 2:
            menuRutinas();
            break;
        case 4:
            menuConfig();
        case 5:
            menuPreParcial();
            break;
        case 6:
            menuParcial();
        case 0:
            return;
        default:
            break;
        }
    }
}
