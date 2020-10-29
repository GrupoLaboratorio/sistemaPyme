#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <iomanip>
using namespace std;
#include "Compra.h"
#include "Producto.h"
#include "Fecha.h"

const char *FILE_COMPRA = "Archivos/Compra.dat";

void Compra::cargarCompra(){
    setIdCompra();
    setCodProv();
//    fecha.getDia();
//    fecha.getMes();
//    fecha.getAnio();
    setTipoFact();
    setPuntoVta();
    setNroFactura();
    setProducto();
    setCantProd();
    setPrecio();
    setImpuesto();
   /// setTotal();
}

 void Compra::mostrarCompra(){
     cout<<"Id de compra : "<<idCompra<<endl;
     cout<<"Id de proveedor : "<<codProv<<endl;
     cout<<"Tipo de Factura : "<<tipoFactura<<endl;
     cout<<"Numero : 000"<<puntoVta<<"-0000000"<<nroFactura<<endl;
     cout<<"Producto:  "<<codProv<<endl;
     cout<<"Cantidad:  "<<cantidad<<endl;
     cout<<"Precio por unidad:  "<<precio<<endl;
     cout<<"Impuesto aplicado :  "<<impuesto<<endl;
     //cout<<"Precio total :  "<<total<<endl;
     system("pause");
 }

 void Compra::setIdCompra(){
   this->idCompra=crearId();
 }

int Compra::getIdCompra(){
   return idCompra;
}

void Compra::setCodProv(){
     int codigo;
     cout<<"ID de proveedor : ";
     cin>>codigo;
     while(!(codigo>0)){
         cout<<"Codigo Incorrecto";
         system("pause");
         system("cls");
         cout<<"ID de proveedor : ";
         cin>>codigo;
     }
    this->codProv=codigo;
}

int Compra::getCodProv(){
    return codProv;
}

 void Compra::setNroFactura(){
     int numero;
    cout<<"Numero de  Factura : ";
    cin>>numero;
    while(numero <= 0){
     cout<<" Codigo incorrecto";
     system ("cls");
     cout<<"Numero de factura : ";
     cin>>numero;
    }
   this-> nroFactura=numero;
 }

 int  Compra::getNroFactura(){
     return nroFactura;
 }

 void Compra::setTipoFact(){
     char letra;
      cout<<"Tipo de factura : ";
      cin>>letra;
      while(!(letra == 'A'  || letra == 'C' )) {
     cout<<"Tipo de factura incorrecta";
     system("pause");
     system("cls");
     cout<<"Tipo de factura : ";
     cin>>letra;
      }
      this ->tipoFactura=letra;
 }

char Compra::getTipoFact(){
    return tipoFactura;
}

void Compra::setProducto(){
    int codigo;
     cout<<"\nID de producto : ";
    cin>>codigo;
     ///Producto prod1;
    while(codigo <= 0){
    cout<<"Codigo de producto incorrecto ";
      system("pause");
     system("cls");
      cout<<"\n ID  de producto : ";
    cin>>codigo;
    }
   /// prod1.buscarProdxId(codigo);
   this->codProd=codigo;
}


void Compra::setPrecio(){
    int valor;
       cout<<"Precio : ";
    cin>>valor;
    while(valor <= 0){
    cout<<"El valor ingresado es incorrecto ";
      system("pause");
     system("cls");
      cout<<"\n Precio : ";
    cin>>valor;
    }
   this->precio=valor;
}


void Compra::setCantProd(){
       int unidad;
       cout<<"Cantidad : ";
    cin>>unidad;
    while(unidad <= 0){
    cout<<"Cantidad incorrecta ";
      system("pause");
     system("cls");
      cout<<"\n Cantidad : ";
    cin>>unidad;
    }
   this->cantidad=unidad;
}

void Compra::setImpuesto(){
      int valor;
    cout<<"Impuesto : ";
    cin>>valor;
    while(!(valor > 0 || valor <=22 )){
    cout<<"Valor de impuesto incorrecto ";
      system("pause");
     system("cls");
      cout<<"\n Impuesto : ";
    cin>>valor;
    }
   this->impuesto=valor;
}

void Compra::setPuntoVta(){
//     numeracion(4);
//    cout<<nroChar;
}


int Compra::getProducto(){
    return codProd;
}

float Compra::getPrecio(){
  return precio;
}

int Compra::getCantProd(){
   return cantidad;
}

void Compra::getPuntoVta(){
    cout<<puntoVta;
//   return *puntoVta;
}

 bool Compra::grabarEnDisco(){

        system("cls");
        FILE *p;
        bool chequeo;

        p = fopen(FILE_COMPRA,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo \n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Compra),1,p);
        if(chequeo==1){
                cout<<"Carga exitosa";
            fclose(p);
            return true;
        }
        else{
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);
            system("pause");
            return false;
        }
    }

 bool Compra::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_COMPRA, "rb");
        if (p == NULL){

            return false;
        }
        fseek(p, posicion * sizeof(Compra), 0);
        leyo = fread(this, sizeof(Compra), 1, p);
        fclose(p);
        return leyo;
    }

///----------------------------------FUNCIONES GLOBALES---------------------------------------------------

 int crearId(){
    int bytes, cant;
    FILE *p = fopen(FILE_COMPRA, "rb");
     if (p == NULL){
        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
      fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return cant+1;
}

//string numeracion(int tam){
//    char caracter;
//    bool bandera=true;
//    cout<<"Introduce un mumero: ";
//
//    while(bandera == true){
//    int i=0, opc;
////    nroChar[tam]={0};
//    caracter=getch();
//    while(caracter != 13 &&  i<tam){
//
//             if (caracter >=48 && caracter <=57){
//            cout<<caracter;
//            nroChar[i]=caracter;
//            i++;}
//       caracter=getch();}
//
//        cout<<endl;
//        for(int i=0; i<tam; i++) {cout<<nroChar[i];}
//
//        cout<<"Confirma la numeracion :    1 - SI    o    0 - NO"  ;
//        cin>>opc;
//        if(opc ==1){
//        bandera=false;
//        }else{bandera=true;}
//        }
//        return *nroChar;
//}



   void listado_Compras(){
        Compra aux;
        int i = 0;
        cout << left;
        cout<<"*****************************************************************************************"<<endl;
        cout<<"*_______________________________DETALLE DE FACTURA"<<setw(40)<<"______________________________________*"<<endl;
        cout<<"*****************************************************************************************"<<endl;
        cout<<endl;
        cout<<setw(4)  <<"ID";
        cout<<setw(10)<<"#FACTURA";
        cout<<setw(10)<<"CODPROD.";
        cout<<setw(10)<<"CANTIDAD";
        cout<<setw(10)<<"_PRECIO_";
        cout<<setw(10)<<"TOT_IVA.";
        cout<<setw(10)<<"SUB_TOT.";
        cout<<setw(7)  <<"TOTAL";
        cout<<setw(6)  <<"PCTA";
        cout<<setw(7)  <<"C_ENT";
        cout<<setw(5)  <<"ENT";
        cout<<endl;
        cout<<"________________________________________________________________________________________"<<endl;
        while (aux.leerDeDisco(i++)){
        cout<< right;
        cout<< setw(2)<<aux.idCompra;
        cout<< setw(8)<< aux.nroFactura;
        cout<< setw(10) << aux.codProd;
        cout<< setw(10) << aux.cantidad;
        cout<< setw(10)<<aux.precio;
        cout<<setw(10)<<aux.impuesto;
        cout<<setw(10)<<aux.total;
        cout<<setw(10)<<aux.total;
        cout<<setw(6)<<aux.idCompra;
        cout<<setw(5)<<aux.codProv ;
        cout<<setw(5)<<"CL";
        cout<<endl;
        cout<<"________________________________________________________________________________________"<<endl;

        }
        }
