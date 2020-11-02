#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;
#include "Ventas.h"
#include "Fecha.h"
#include "DetalleVenta.h"
#include "DetalleVenta.h"
#include "DetalleFactura.h"
#include "Calculadora.h"
#include "Producto.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/menus.h"


const char * FILE_VENTAS = "Archivos/Ventas.dat";

///----------------------------METODOS CLASE VENTAS---------------------------
Ventas::Ventas(){
    idCliente=0;
    tipoFactura='B';
}

void Ventas::cargarVtas(){
    setlocale(LC_CTYPE, "Spanish");
    Ventas();
    setTipoFact();
    setNroFact();
char c;
system("cls");
cout<<" Abrir una venta?. ";
cout<<"\nSi: 1";
cout<<"\nNo : 0 "<<endl;
int ok;
cin>>ok;
if(ok==1){
    bool grabo=grabarEnDisco();
    if(grabo==true )    {
        DetalleVenta  det;
        det.cDetalleVenta();
    }    else{
        cout<<"Fallo la grabacion, volver a intentar ";
        system("pause");
        return;
    }
}
return;
}

void Ventas::setNroFact(){
    this->nroFactura=crearIdXFact();
}

void Ventas::mostrarVtas(int posicion){
    cout<<"Fecha : "<<fechaVenta.getDia()<<"-"<<fechaVenta.getMes()<<endl;
    cout<<"Id de cliente : "<<idCliente<<endl;
    cout<<"Tipo de factura" <<tipoFactura<<endl;
    cout<<"Numero de factura" <<nroFactura<<endl;
}


void Ventas::setIdCliente(){
    cliente.buscarRazonSocial(1);
    idCliente=cliente.getIdEntidad();
}

void Ventas::setTipoFact(){
    char tipo;
    cout<<"FACTURA A o B? : ";
    cin>>tipo;
    while(!(tipo == 'A'  || tipo == 'B' ))
    {
        cout<<"Tipo de factura incorrecta";
        system("pause");
        system("cls");
        cout<<"Tipo de factura : ";
        cin>>tipo;
    }
    if(tipo=='A'){
        setIdCliente();
    }

    this->tipoFactura=tipo;
    int crearIdXFact();

}

//void Ventas::setOpcionPago()
//{
//    int modo;
//    float desc=0.1;
//    system("cls");
//    cout<<"Opciones de pago :"<<endl;
//    cout<<"1- Efectivo "<<endl;
//    cout<<" 2- Transferencia "<<endl ;
//    cout<<" 3 - Tarjeta de credito "<<endl;
//    cin>>modo;
//    switch(modo)
//    {
//    case 1:
//        this->modoPago=modo;
//        cout<< "Descuento del 5%"<<endl;
//        calculo.setDescuento(desc);
//        calculo.getDescuentoAplicado();
//        cout<< "Total a pagar : "<<598.95<<endl;
//        break;
//
//    case 2:
//        this->modoPago=modo;
//        cout<<"No posee descuentos ni recargos"<<endl;
//        calculo.setTotlaImponible(5, 50);
//        break;
//
//    case 3:
//        this->modoPago=modo;
//        cout<<"Recargo del 0.05 "<<endl;
//        /calculo. Recargo o setDescuento?
//        break;
//
//    default:
//        cout<<"Opcion de pago incorrecto ";
//        break;
//    }
//}

//int Ventas::getOpcionPago()
//{
//    return modoPago;
//}

bool Ventas::grabarEnDisco()
{
    system("cls");
    FILE *p;
    bool chequeo;

        p = fopen(FILE_VENTAS,"ab");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Ventas),1,p);
        if(chequeo==1)
        {
             fclose(p);
              return true;
        }
        else
        {
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);

            system("pause");
            return false;
        }


}

bool Ventas::leerDeDisco(int posicion)
{
    bool leyo;
    FILE *p;
        p = fopen(FILE_VENTAS, "rb");
        if (p == NULL)
        {
            return false;
        }
        fseek(p, posicion * sizeof(Ventas), 0);
        leyo = fread(this, sizeof(Ventas), 1, p);
        fclose(p);
        return leyo;
}

void Ventas::listado_facturas()
{

    Ventas aux;
    int i = 0;

//        char sing = getch() ;
//        char sing = ".";
        //selecciona un caracter para darle forma a tu tabla
        //string dato="esta tabla";
        ///Inicio de cabecera
        cout<<"|"<<setw(104)<<centrar("CABECERA DETALLE", 104)<<"|"<<endl;
        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<"|"<<setw(4)<<centrar("ID", 4);
        cout<<"|"<<setw(7)<<centrar("TIPO", 7);
        cout<<"|"<<setw(12)<<centrar("FECHA", 12);
        cout<<"|"<<setw(22)<<centrar("ID CLIENTE", 22)<<endl;

        cout<<"|"<<setw(105)<<setfill('_')<<"|"<<endl;
        cout<<" "<<setw(105)<<setfill(' ')<<" "<<endl;

        while (aux.leerDeDisco(i++))
        {
            cout<<"|"<<setw(4)<<centrarInt(aux.nroFactura, 4);
            cout<<" "<<setw(7)<<aux.tipoFactura;
            cout<<" "<<setw(2)<<aux.fechaVenta.getDia()<<setw(1)<<"/";
            cout<<setw(2)<<aux.fechaVenta.getMes()<<setw(1)<<"/";
            cout<<setw(4)<<aux.fechaVenta.getAnio()<<setw(2)<<" ";
            cout<<" "<<setw(22)<<centrarInt(aux.idCliente, 22)<<endl;
        }
            cout<<setfill(' ')<<endl;

}

///--------------------------------------FUNCIONES GLOBALES------------------------------------

int crearIdVentas()
{
//    int bytes, cant;
//
//    FILE *p = fopen(FILE_VENTAS, "rb");
//    if (p == NULL){
//        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
//    }
//    fseek(p, 0, SEEK_END);
//    bytes = ftell(p);
//    fclose(p);
//    cant=bytes / sizeof(Ventas);
//    return cant+1;
}


int crearIdXFact()
{
    int bytes, cant;


        FILE *p = fopen(FILE_VENTAS, "rb");
        if (p == NULL)
        {
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);

    cant = bytes / sizeof(Ventas);
    return cant+1;
}

//void  listarVentas()
//{
//    int i=0;
//    bool chequeo;
//    Ventas reg;
//    while(reg.leerDeDisco(i++))
//    {
//          cout<<reg.getNroFact()<<endl;
//         cout<< reg.getTipoFact()<<endl;
////          cout<<reg.fech()<<endl;
//    }
//    return;
//}
