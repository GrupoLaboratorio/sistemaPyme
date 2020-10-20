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
#include "../Include/Cliente.h"

using namespace rlutil;
using namespace std;

void menuPrincipal(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      //setBackgroundColor(FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      title("TONGA GESTION", WHITE, RED);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. COMPRAS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. VENTAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. INVENTARIOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. DOCUMENTACIONS";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. CONTABILIDAD";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "6. CONFIGURACION";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "0. SALIR\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                menuCompras();
        break;
        case 2:
                menuVentas();
        break;
        case 3:
                cout << "Opcion 3";
                system("pause");
        break;
        case 4:
                cout << "Opcion 4";
                system("pause");
        break;
        case 5:
                cout << "Opcion 5";
                system("pause");
        break;
        case 6:
                cout << "Opcion 6";
                system("pause");
        break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;
}

void menuCompras(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;


    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      //setBackgroundColor(FONDO);
      locate(POSMENUX+5,POSMENUY+1);
      title("COMPRAS", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. CARGAR COMPRA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. LISTAR COMPRA POR ID";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. LISTAR TODAS LAS COMPRAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. CARGAR PROVEEDOR";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. LISTAR PROVEEDOR POR ID";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "6. LISTAR PROVEEDORES";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "0. MENU PRINCIPAL\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                menuCompras();
        break;
        case 2:
                menuVentas();
        break;
        case 3:
                cout << "Opcion 3";
                system("pause");
        break;
        case 4:
                cout << "Opcion 4";
                system("pause");
        break;
        case 5:
                cout << "Opcion 5";
                system("pause");
        break;
        case 6:
                cout << "Opcion 6";
                system("pause");
        break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;

}

void menuVentas(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Cliente clientePiloto;


    setlocale(LC_ALL, "spanish");
    setConsoleTitle("TONGA GESTION");
    const int ANCHO_MENU = 75;
    const int ALTO_MENU = 8;
    int key, opc, cursorX, cursorY;
    while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 3;
      setBackgroundColor(COLOR_PANTALLA);
      system("cls");
      opc=1;
      setColor(LETRA);
      locate(POSMENUX+5,POSMENUY+1);
      title("VENTAS", WHITE, BLUE);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. CARGAR VENTA";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. LISTAR VENTA POR ID";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. LISTAR TODAS LAS VENTAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. CARGAR CLIENTE";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. LISTAR CLIENTE POR ID";
      locate(POSMENUX+3,POSMENUY+8);
      cout << "6. LISTAR CLIENTES";
      locate(POSMENUX+3,POSMENUY+9);
      cout << "0. MENU PRINCIPAL\n";
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
      switch(opc){
        case 1:
                cout << "Opcion 3";
                system("pause");
        break;
        case 2:
                cout << "Opcion 3";
                system("pause");
        break;
        case 3:
                cout << "Opcion 3";
                system("pause");
        break;
        case 4:
                clientePiloto.cargarCliente();
                clientePiloto.mostrarCliente();
                clientePiloto.grabarEnDisco();
                system("pause");
        break;
        case 5:
                listarClientePorID();
                system("pause");
        break;
        case 6:
                listarClientes();
                system("pause");
        break;
        case 0:
        return;
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;

}

void menuInventario(){

    while(true){
        cls();
        title("INVENTARIO",BLACK,BLUE);
        gotoxy(1,3);
        cout<<"1 - CARGAR PRODUCTO"<<endl;
        cout<<"2 - LISTAR PRODUCTO POR ID"<<endl;
        cout<<"3 - LISTAR TODOS LOS PRODUCTOS"<<endl;
        //cout<<"3 - LISTAR PRODUCTOS POR PROVEEDOR"<<endl;

        cout<<"------------------------"<<endl;
        cout<<"0 - MENU PRINCIPAL   "<<endl;
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
