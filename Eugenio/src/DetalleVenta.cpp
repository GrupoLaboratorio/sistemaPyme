#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <iomanip>
#include <conio.h>
using namespace std;
#include "DetalleVenta.h"
#include "Ventas.h"
#include "Producto.h"
#include "Productos.h"
#include "Entidad.h"
#include "Calculadora.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/menus.h"
using namespace rlutil;

const char *FILE_DETALLE="Archivos/DetalleVentas.dat" ;


void DetalleVenta::cDetalleVenta(){

    dato= new Ventas;
    int i= crearIdXFact()-2;
    dato->leerDeDisco(i);
    int continuar;
    do{
        this->idDetalle= crearIdDetalle();
        tipoFactura= dato->getTipoFact();
        nroFactura= dato->getNroFact();
        setCodProducto();
        setPrecio();
        Estado=true;
        grabarDetalleEnDisco();
        system("pause");
        cout<<"Comprar otro producto :    1- si , 0 - no " ;
        cin>> continuar;
    }while(continuar==1);
    delete dato;
    return;
}

void DetalleVenta::setCodProducto(){
    cout<<"Ingrese codigo producto : ";
    cin>>codProd;
    prod.buscarProdxId(codProd);
    cout<< prod.getPrecioCosto()<<endl;
    cout<< prod.getIva();
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
    if(p==NULL)
    {
        cout << "Error al abrir el archivo \n";
        return false;
    }

    chequeo = fwrite(this, sizeof(DetalleVenta),1,p);
    if(chequeo==1)
    {
        cout<< "Carga exitosa";
        fclose(p);

        system("pause");
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

bool DetalleVenta::leerDeDiscoD(int posicion){
    bool leyo;
    FILE *p;
    p = fopen(FILE_DETALLE, "rb");
    if (p == NULL)
    {

        return false;
    }
    fseek(p, posicion * sizeof(DetalleVenta), 0);
    leyo = fread(this, sizeof(DetalleVenta), 1, p);
    fclose(p);
    return leyo;
}

void DetalleVenta::listado_detalle(){
    DetalleVenta aux;
    int i = 0;

    ///Inicio de cabecera
    cout<<"|"<<setw(88)<<centrar("DETALLE DE FACTURAS", 88)<<"|"<<endl;
    cout<<" "<<setw(89)<<setfill('_')<<"|"<<endl;
    cout<<" "<<setw(4)<<centrar("#id", 4);
    cout<<" "<<setw(8)<<centrar("# Fact", 8);
    cout<<" "<<setw(10)<<centrar("tipo fac", 10)<<endl;

    cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
    cout<<" "<<setw(89)<<setfill(' ')<<" "<<endl;

    while (aux.leerDeDiscoD(i++)){
    cout<<"|"<<setw(15)<<centrarInt(aux.idDetalle, 15);
    cout<<"|"<<setw(15)<<centrarInt(aux.getNroFactura(), 15);
    cout<<" "<<setw(19)<<aux.getTipoFactura()<<endl;
    //        cout<<"|"<<setw(89)<<setfill(sing)<<"|"<<endl;
    }
    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
}
//bool DetalleVenta::leerDeDisco(int posicion){
        //    FILE *p;
        //    bool chequeo;
        //
        //    p = fopen(FILE_DETALLE,"rb");
        //    if(p==NULL){
        //    cout << "Error al abrir el archivo \n";
        //    return false;
        //    }
        //    fseek(p,posicion*sizeof(DetalleVenta),SEEK_SET);
        //    chequeo=fread(this, sizeof(DetalleVenta),1,p);
        //    if( chequeo == 1){
        //    mostrarDetalleVenta(posicion);
        //    fclose(p);
        //
        //    system("pause");
        //    return true;
        //    }else{
        //    cout << "El registro no pudo guardarse \n\n";
        //    fclose(p);
        //
        //    system("pause");
        //    return false;
        //        }
//    }

void DetalleVenta::mostrarDetalleVenta(int posicion)
{
//    cout<<"Fecha : "<<codProd<<endl;
//    cout<<"Tipo de factura hola : " <<dato->getTipoFact()<<endl;
//    cout<<"Numero de factura" <<dato->getNroFact()<<endl;
}

bool DetalleVenta::ModificarVta()
{
    FILE *p;
    int posicion, cod;
    bool chequeo;

    cout<<"Ingrese el id de producto : " ;
    cin>>cod;
    posicion= buscarXCodProd(cod);

    if(posicion >= 0)
    {
        p=fopen(FILE_DETALLE,"wb" );
        if(p == NULL)
        {
            return false;
        }
        fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
        fread(this, sizeof(DetalleVenta),1,p);
        Estado == false;

        fseek(p, posicion*sizeof(DetalleVenta), SEEK_SET);
        chequeo= fwrite(this, sizeof(DetalleVenta),1,p);
        if(chequeo==true)
        {
            cout<<"Se modifico exitosamente "<<endl;
            fclose(p);
            return true;
        }
        fclose(p);

        cout<<"No se puso modificar el archivo "<<endl;
        return false;
    }
    else
    {
        if(posicion == -2)
        {
            cout<<"No se encontro el producto "<<endl;
            return false;
        }
    }
}

void DetalleVenta::setTipoFactura(){

//    this->tipoFactura= dato->getTipoFact;
//    strcpy(this->tipoFactura, dato->getTipoFact);
}
char DetalleVenta::getTipoFactura(){return tipoFactura;}
void DetalleVenta::setIdCliente(){this->idCliente=dato->getIdCliente();}
char DetalleVenta::getIdCliente(){return idCliente;}
void DetalleVenta::setNroFactura(){this->nroFactura=dato->getNroFact();}
void DetalleVenta::setIdDetalle(){this->idDetalle=crearIdDetalle();}
int DetalleVenta::getNroFactura(){return nroFactura;}
///----------------------FUNCIONES GLOBALES-----------------

int buscarXCodProd(int codigo)
{
    FILE *p;
    DetalleVenta reg;
    int posicion=0;

    p=fopen(FILE_DETALLE, "rb");
    if(p == NULL)
    {
        return -1;
    }
    while( fread(&reg, sizeof(DetalleVenta), 1, p) == 1)
    {
        if(reg.getCodProducto() == codigo)
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -2;
}
int crearIdDetalle()
{
    int bytes, cant;

    FILE *p = fopen(FILE_DETALLE, "rb");
    if (p == NULL){
        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(DetalleVenta);
    return cant+1;
}
void DetalleVenta::imprimirFactura(){
////    system("color 0F");
    system("color 4F");
    int pos= crearIdXFact()-2;
    float  sTot=0, sIva=0, tTot=0, tPrUn=0;
    DetalleVenta aux;
//    char a='d'+42;
    int i =0,  f;

    cls();
    cout<<"\nIngrese el numero de factura que desea imprimir: ";
    cin>>f;
    cls();

//            setBackgroundColor(RED);
            cout<<endl;
            cout<<"|"<<setw(89)<<setfill('¯')<<"|"<<endl;
            cout<<"|"<<setw(88)<<centrar("FACTURA", 88)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;            cout<<"|"<<setw(69)<<""<<"Nro Fac: 0001-"<<derechaInt(f, 5)<<"|"<<endl;
            //cout<<cli.getApenom()<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<right;
            cout<<"|"<< "TONGA GESTION SRL   "<<setw(31)<<""<<"R.SOCIAL :"<<setw(27)<<"LARA COLA SRL"<<"|"<<endl;
            cout<<"|"<< "info@tongagest.com  "<<setw(31)<<""<<"MAIL     :"<<setw(27)<<"info@briancola.com"<<"|"<<endl;
            cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<""<<"DIR      :"<<setw(27)<<"Games F"<<"|"<<endl;
            cout<<"|"<< "Cod Post : 1640     "<<setw(31)<<""<<"TEL      :"<<setw(27)<<"458-4584"<<"|"<<endl;
            cout<<"|"<< "Cuit: 30-12345678-0 "<<setw(31)<<""<<"CUIT     :"<<setw(27)<<"44-44444444-4"<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
            cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
            cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
            cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
            cout<<"|"<<setw(10)<<centrar("IVA", 10);
            cout<<"|"<<setw(9)<<"SUB_TOT"<<endl;
            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

// }
        while (aux.leerDeDiscoD(i++)){
        if(aux.getNroFactura()==f){
            Producto *prod1;
            prod1 = new Producto;
             prod1->leerDeDisco(prod1->buscarProdxId(aux.getCodProducto()));
                cout<<setfill(' ');
                cout<<"|"<< setw(9)<<centrarInt(aux.getCodProducto(), 9);
                cout<<left;
                cout<<"|"<< setw(28)<<aux.prod.getDescripcion();
                cout<<right;
                cout<<"|"<< setw(10)<<centrarInt(aux.getCantProducto(), 10);
                cout<<"|"<< setw(10)<<aux.getPrecio();
                 cout<<"|"<< setw(10)<<(aux.getPrecio()*prod1->getIva()/100);
                 cout<<"|"<<setw(16)<<((aux.getPrecio()+(aux.getPrecio()*prod1->getIva()/100))*aux.getCantProducto())<<"|"<<endl;

                tPrUn+=aux.getPrecio();
                sTot+=(aux.getPrecio()*aux.getCantProducto());
                sIva+=((aux.getPrecio()*prod1->getIva()/100)*aux.getCantProducto());
            delete prod1;
        }
        }
                tTot+=(sIva+sTot);
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<< right;
            cout<<"|"<<setw(80)<<"SubTotal:$"<<setw(8)<<derechafloat(sTot,8)<<"|"<<endl;
            cout<<"|"<<setw(80)<<"Total Iva:$"<<setw(8)<<derechafloat(sIva,8)<<"|"<<endl;
            cout<<"|"<<setw(80)<<"Total Final:$"<<setw(8)<<derechafloat(tTot,8)<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('+')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('¯')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('$')<<"|"<<endl;
            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;

}
