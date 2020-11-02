#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "../Utilidades/menus.h"
#include "../Include/Entidad.h"
#include "../Include/Ventas.h"
#include "../Include/Compra.h"
#include "../Include/DetalleVenta.h"
#include "../Include/DetalleFactura.h"
#include "../Include/DetalleCompra.h"
#include "../Include/Producto.h"
#include "../Include/Productos.h"
#include "../Include/Usuario.h"


///---------------------------------------------- MENU PRINCIPAL
//Login oLogout;

void menuLogin(){

	int attempts = 3;
	bool chequeo=false;
//	int attempts = 0;///Se establece en 0  en desarrollo, para evitar loguearse a cada rato
//	bool chequeo=true;///Se establece en TRUE en desarrollo, para evitar loguearse a cada rato


    while(attempts != 0){
		title("LOGIN", WHITE, BLUE);
		cout << endl << endl;

        chequeo = login();

        if(chequeo == true){
            attempts = 0;
        }else{
        attempts--;
		}
		system("cls");
    }
    if(chequeo == true){
        menuPrincipal();
    }else{
        msj("HA SUPERADO EL LIMITE DE INTENTOS",WHITE,RED,130,TEXT_LEFT);
        return;
    }
}

void menuPrincipal(){

        const int POSMENUX = 0;
        const int POSMENUY = 0;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = RED;

    setlocale(LC_ALL, "spanish");
//    setConsoleTitle("TONGA GESTION");
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
//      setBackgroundColor(FONDO);
      locate(POSMENUX+5,POSMENUY+1);
//      locate(POSMENUX+5,POSMENUY+2);
//    cout<<"Usario Logueado: " ;oLogout.getUser();
      title("TONGA GESTION", WHITE, RED);
      locate(POSMENUX+3,POSMENUY+3);
      cout << "1. COMPRAS";
      locate(POSMENUX+3,POSMENUY+4);
      cout << "2. VENTAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. INVENTARIOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. ENTIDADES";
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
				menuInventario();
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
        case 0: return;
//        oLogout.setLogin(false);
        break;
        default:cout<<" OPCION INCORRECTA"<<endl;
                break;
      }
    }
    return;
}

///---------------------------------------------- MENU COMPRAS

void menuCompras(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
//        Compras compraPiloto;
        DetalleCompra detComp;



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
      cout << "2. LISTAR TODAS LAS COMPRAS";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. CARGAR PROVEEDOR";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. BUSCAR PROVEEDOR POR CUIT";
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. LISTAR PROVEEDORES";
      locate(POSMENUX+3,POSMENUY+8);
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
            if(opc < 5){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=5;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 2;
        }else{
            cursorY = POSMENUY + 8;
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
//			detComp.cargarCompras();
//			detComp.grabarEnDisco();
        break;
        case 2:
                cout <<"LISTAR TODAS LAS COMPRAS:"<<endl<<endl;
                cout<<"aguarde por favor!... En proceso"<<endl<<endl<<endl;
                cout <<"Esta cargando.... "<<endl<<endl<<endl<<endl;
                system("pause");
        break;
        case 3:
                EntidadPiloto.cargarCliente();
                EntidadPiloto.grabarEnDisco(1);
                EntidadPiloto.mostrarEntidad();
                system("pause");
        break;
        case 4:
                detComp.setProveedor();
                detComp.setIdProveedor();
                system("pause");
        break;
        case 5:
                    EntidadPiloto.listarEntidadesTabla(2);
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

///---------------------------------------------- MENU VENTAS

void menuVentas(){

        const int POSMENUX = 0;
        const int POSMENUY = 1;
        const int COLOR_PANTALLA = BLACK;
        const int LETRA = WHITE;
        const int FONDO = BLUE;
        Entidad EntidadPiloto;
        Ventas vtas;
        DetalleVenta deta;

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
      cout << "2. IMPRIMIR FACTURA";
      locate(POSMENUX+3,POSMENUY+5);
      cout << "3. LISTAR DETALLE DE TODAS LAS VENTAS";
      locate(POSMENUX+3,POSMENUY+6);
      cout << "4. LISTADO DE FACTURAS EMITIDAS"; /// ver como validad que no cargue en el arhcivo incorrecto
      locate(POSMENUX+3,POSMENUY+7);
      cout << "5. BUSCAR CLIENTE POR CUIT";
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
           vtas.cargarVtas();

        break;
        case 2:
                deta.imprimirFactura();
            system("pause");
        break;
        case 3:
            deta.listado_detalle();

            system("pause");
        break;
        case 4:
           vtas.listado_facturas();
//            EntidadPiloto.cargarCliente();
//            EntidadPiloto.mostrarEntidad();
//            EntidadPiloto.grabarEnDisco(1);
            system("pause");
        break;
        case 5:
            EntidadPiloto.buscarRazonSocial(1);
            system("pause");
        break;
        case 6:
               EntidadPiloto.listarEntidadesTabla(1);
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
Producto obj;
Productos objA;
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
            obj.cargarProducto();
            break;
      case 2:
          int id;
          cout<<"\nIngrese el Id del producto por favor: ";
          cin>>id;
            obj.buscarProdxId(id);
           obj.mostrarProducto();
            system("pause");
            break;
        case 3:
            objA.listarProductos();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}
