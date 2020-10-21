#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include "../Include/Ventas.h"
#include "../Include/Operacion.h"

const char * FILE_VENTAS = "Archivos/Ventas.dat";

using namespace std;

Ventas::Ventas(){
    Bonificacion=0;
    preciofinal=0;
}

void Ventas::CargarVtas(){
    CargarOp();
      cout<<"Tipo de factura :";
      cin>>tipofactura;
      setTipoFact(tipofactura);

}

 void Ventas::MostrarVtas(){

     MostrarOp();
     cout<<"Tipo de Factura : "<<tipofactura<<endl;
     cout<<"Numero: 0000 - "<<getNroFactura()<<endl;
     cout<<"Bonificacion : "<<getBonificacion()<<endl;
     cout<<"Precio Final a pagar : "<<getPrecioFinal()<<endl;

}

void Ventas::setNrofactura(){Nrofactura= crearId();}

int Ventas::getNroFactura(){return Nrofactura;}

void Ventas::setTipoFact(char _tipofactura){tipofactura = _tipofactura;}

 char Ventas::getTipoFact(){return tipofactura;}

void Ventas::setBonificacion(){      ///PROBAR CON SWITCH
	int opc;
	opc = getModoPago();
    switch(opc) {
    case  1:
    Bonificacion=0.9;
        break;
    case 2:
     Bonificacion=1.15;
     break;
    case 3:
    Bonificacion=1;
    break;
    }
}

float Ventas::getBonificacion(){return Bonificacion;}

 void Ventas::setprecioFinal(){
     precio=getPrecio();
     Bonificacion=getBonificacion();
        preciofinal= precio*Bonificacion;
 }

float Ventas::getPrecioFinal(){return preciofinal;}

///--------------------- GLOBALES -------------------------

int crearId(){
    int bytes, cant;
    FILE *p = fopen("FacturaA.dat", "rb");
    if (p == NULL){
        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Ventas);
    cout<<bytes;
    return cant+1;
}

