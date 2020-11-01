#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "Utilidades/menus.h"
#include "Utilidades/ui.h"
#include "Utilidades/rlutil.h"
#include "Include/Entidad.h"
#include "Include/Producto.h"
#include "Include/Compra.h"
#include "Include/DetalleFactura.h"
#include "Include/Ventas.h"
#include "Include/DetalleVenta.h"

//#include "../Include/Login.h"
using namespace rlutil;
int main(){
//    menuPrincipal();
       DetalleVenta obj2;
       Producto pij;
       Ventas obj ;
//cout<<sizeof(Ventas);
       int opc;
      while(opc != 0) {
      cout<<"Menu Ventas  "<<endl;
      cout<<"1 - Cargar Ventas :  "<<endl;
      cout<<"2 - Modificar un producto :  "<<endl;
      cout<<"3 - Cargar productos a la venta :  "<<endl;
      cout<<"4 - Listar ventas :  "<<endl;
      cout<<"5 - listado_detalle ventas :  "<<endl;
      cout<<"6 - Imprimir Factura :  "<<endl;
      cout<<"0 - Finalizar :  "<<endl;
      cin>>opc;
      switch(opc){
    case 1:
       obj.cargarVtas();
        break;
    case 2:
       obj2.ModificarVta();
        break;
    case 3:

        obj2.cDetalleVenta();
        break;
    case 4:

        obj.listado_facturas();
        //        for (int i=0; i<obj.getNroFact();i++){
//        obj2.leerDeDisco(i);
//        }
        break;
    case 5:
        obj2.listado_detalle();
        break;
    case 6:
//        pij.getProducto(6);
//        pij.leerDeDisco(pij.buscarProdxId(6));
//       pij.mostrarProducto();

        obj2.imprimirFactura();
        break;
    case 0:
        return 0;
        break;
    default:
        cout<<"Opcion incorrecta : "<<endl;
        break;
      }
      }

//      ;
//        cout<<obj2.fecha.getDia();
////     obj.setIdVenta();
////     cout <<obj.getIdVenta()
//     obj.leerDeDisco(1) ;
//    listarVentas();
    return 0;
}
