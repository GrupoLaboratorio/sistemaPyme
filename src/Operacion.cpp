#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include "Operacion.h"

using namespace std;

Operacion::Operacion(){
    producto=0;
    cantidad=0;
    precio=0;
    total=0;
}

void  Operacion::CargarOp(){
    cout<<"Producto : ";
    cin>>producto;
    cout<<"Cantidad : ";
    cin>>cantidad;
   // setCantProd(cantidad);
    cout<<"Precio : ";
    cin>>precio;
    cout<<"Impuesto : ";
    cin>>impuesto;
    cout<<"Condiciones de pago : ";
    cin>>modoPago;
    setMonto(precio, impuesto, cantidad);
}

void Operacion::MostrarOp(){
    cout<<endl<<endl;
    cout<<"Producto : "<<producto<<endl;
    cout<<"Cantidad : "<<cantidad<<endl;
    cout<<"Precio : "<<precio<<endl;
    cout<<"Impuesto : "<<impuesto<<endl;
    cout<<"Condiciones de pago : "<<modoPago<<endl;
    cout<<"Total a pagar : "<<getMonto()<<endl<<endl;
}

void Operacion::setMonto(float _precio, float _impuesto, int _cantidad){
      precio=_precio;
      impuesto=_impuesto;
      cantidad=_cantidad;
    total=precio*cantidad*impuesto;
}

void Operacion::setCantProd(int _cantidad){
      cantidad=_cantidad;
}

  float Operacion::getMonto(){
  return total;
  }


//}
//
//int Operacion::getcantProd(){
//}
