#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include "../Utilidades/menus.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"

using namespace rlutil;
using namespace std;


void menuPrincipal(){

    while(true){
        cls();
        title("BIENVENIDO A TONGA GESTION",BLACK,RED);
        gotoxy(1,3);
        cout<<"1 - COMPRAS"<<endl;
        cout<<"2 - VENTAS"<<endl;
        cout<<"3 - INVENTARIO"<<endl;
        cout<<"4 - DOCUMENTACION"<<endl;
        cout<<"5 - CONTABILIDAD"<<endl;
        cout<<"6 - CONFIGURACION"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            menuCompras();
            break;
        case 2:
            menuVentas();
            break;
        case 4:
            //menuConfig();
        case 5:
            //menuPreParcial();
            break;
        case 6:
            //menuParcial();
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuCompras(){

    while(true){
        cls();
        title("COMPRAS",BLACK,BLUE);
        gotoxy(1,3);
        cout<<"1 - CARGAR COMPRA"<<endl;
        cout<<"2 - LISTAR COMPRA POR ID"<<endl;
        cout<<"3 - LISTAR TODAS LAS COMPRAS"<<endl;
        cout<<"4 - CARGAR PROVEEDOR"<<endl; /// proveedores.dat
        cout<<"5 - LISTAR PROVEEDOR POR ID"<<endl; /// proveedores.dat
        cout<<"6 - LISTAR PROVEEDORES"<<endl; /// proveedores.dat

        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion){
        case 1:
            //menuUsuarios();
            break;
        case 2:
            //menuRutinas();
            break;
        case 4:
            //menuConfig();
        case 5:
            //menuPreParcial();
            break;
        case 6:
            //menuParcial();
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuVentas(){

    while(true){
        cls();
        title("VENTAS",BLACK,BLUE);
        gotoxy(1,3);
        cout<<"1 - CARGAR VENTA"<<endl;
        cout<<"2 - LISTAR VENTA POR ID"<<endl;
        cout<<"3 - LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"4 - CARGAR CLIENTE"<<endl; /// clientes.dat
        cout<<"5 - LISTAR CLIENTE POR ID"<<endl;
        cout<<"6 - LISTAR CLIENTES"<<endl;

        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            //menuUsuarios();
            break;
        case 2:
            //menuRutinas();
            break;
        case 4:
            //menuConfig();
        case 5:
            //menuPreParcial();
            break;
        case 6:
            //menuParcial();
        case 0:
            return;
        default:
            break;
        }
    }
}

void menuVentas(){

    while(true){
        cls();
        title("INVENTARIO",BLACK,BLUE);
        gotoxy(1,3);
        cout<<"1 - CARGAR PRODUCTO"<<endl;
        cout<<"2 - LISTAR PRODUCTO POR ID"<<endl;
        cout<<"3 - LISTAR TODOS LOS PRODUCTOS"<<endl;
        //cout<<"3 - LISTAR PRODUCTOS POR PROVEEDOR"<<endl;

        cout<<"------------------------"<<endl;
        cout<<"0 - SALIR   "<<endl;
        int opcion;
        cout<<"> ";
        cin>>opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            //menuUsuarios();
            break;
        case 2:
            //menuRutinas();
            break;
        case 4:
            //menuConfig();
        case 5:
            //menuPreParcial();
            break;
        case 6:
            //menuParcial();
        case 0:
            return;
        default:
            break;
        }
    }
}
