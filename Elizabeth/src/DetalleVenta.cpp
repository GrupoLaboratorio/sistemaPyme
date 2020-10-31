#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
using namespace std;
#include "DetalleVenta.h"
#include "Ventas.h"
#include "Producto.h"
#include "Productos.h"
#include "Calculadora.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/menus.h"

const char *FILE_DETALLE="Archivos/DetalleVentas.dat" ;


void DetalleVenta::cDetalleVenta(){

    int continuar;
    do{
    dato.getTipoFact();
    dato.getNroFact();
    setCodProducto();
    setPrecio();
    Estado=true;
    grabarDetalleEnDisco();
    system("pause");
    cout<<"Comprar otro producto :    1- si , 0 - no " ;
    cin>> continuar;
    } while(continuar==1);
    return;
}

void DetalleVenta::setCodProducto(){
  cout<<"Ingrese codigo producto : ";
  cin>>codProd;
  prod.buscarProdxId(codProd);
  cout<< prod.getPrecioCosto();
  setCantProducto();
}

void DetalleVenta::setCantProducto(){
   prod.setStock();
   this->cantidad=prod.getStock();
}

bool DetalleVenta::grabarDetalleEnDisco(){

    system("cls");
    FILE *p;
    bool chequeo;

    p = fopen(FILE_DETALLE,"ab");
    if(p==NULL){
    cout << "Error al abrir el archivo \n";
    return false;}

    chequeo = fwrite(this, sizeof(DetalleVenta),1,p);
    if(chequeo==1){
    cout<< "Carga exitosa";
    fclose(p);

    system("pause");
    return true;
    }else{
    cout << "El registro no pudo guardarse \n\n";
    fclose(p);

    system("pause");
    return false;
}
}

bool DetalleVenta::leerDeDisco(int posicion){
    FILE *p;
    bool chequeo;

    p = fopen(FILE_DETALLE,"rb");
    if(p==NULL){
    cout << "Error al abrir el archivo \n";
    return false;
    }
    fseek(p,posicion*sizeof(DetalleVenta),SEEK_SET);
    chequeo=fread(this, sizeof(DetalleVenta),1,p);
    if( chequeo == 1){
    mostrarDetalleVenta(posicion);
    fclose(p);

    system("pause");
    return true;
    }else{
    cout << "El registro no pudo guardarse \n\n";
    fclose(p);

    system("pause");
    return false;
        }
    }

void DetalleVenta::mostrarDetalleVenta(int posicion){
    cout<<"Fecha : "<<codProd<<endl;
//    cout<<"Id de ventas : "<<getIdVenta()<<endl;
//    cout<<"Id de cliente : "<<idProducto<<endl;
    cout<<"Tipo de factura hola : " <<dato.getTipoFact()<<endl;
    cout<<"Numero de factura" <<dato.getNroFact()<<endl;
}

 bool DetalleVenta::ModificarVta(){
    FILE *p;
    int posicion, cod;
    bool chequeo;

     cout<<"Ingrese el id de producto : " ;
    cin>>cod;
    posicion= buscarXCodProd(cod);

    if(posicion >= 0){
    p=fopen(FILE_DETALLE,"wb" );
    if(p == NULL){
    return false;
    }
   fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
   fread(this, sizeof(DetalleVenta),1,p);
    Estado == false;

   fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
  chequeo= fwrite(this, sizeof(DetalleVenta),1,p);
  if(chequeo==true){
    cout<<"Se modifico exitosamente "<<endl;
    fclose(p);
    return true;
  }
    fclose(p);

    cout<<"No se puso modificar el archivo "<<endl;
    return false;
 }   else{ if(posicion == -2){
     cout<<"No se encontro el producto "<<endl;
     return false;
 } }
 }

 ///----------------------FUNCIONES GLOBALES-----------------

int buscarXCodProd(int codigo){
    FILE *p;
    DetalleVenta reg;
    int posicion=0;

    p=fopen(FILE_DETALLE, "rb");
    if(p == NULL){
    return -1;
      }
    while( fread(&reg, sizeof(DetalleVenta), 1, p) == 1){
    if(reg.getCodProducto() == codigo){
    fclose(p);
    return posicion;
       }
    posicion++;
    }

    fclose(p);
  return -2;
}

