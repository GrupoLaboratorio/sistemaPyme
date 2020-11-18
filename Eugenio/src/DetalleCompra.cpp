#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <locale.h>
using namespace std;
#include "Producto.h"
#include "Productos.h"
#include "Entidad.h"
#include "Calculadora.h"
#include "Contable.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "../Utilidades/menus.h"
#include "Fecha.h"
#include "Entidad.h"
#include "Producto.h"
#include "DetalleCompra.h"
#include "Compras.h"
using namespace rlutil;

void DetalleCompra::cDetalleCompra(){
    setlocale(LC_CTYPE, "Spanish");
    Compras  datoCp;
    Contable conta;
    int i= crearIdXCompras()-2;
    datoCp.leerDeDisco(i);//leer de Compras
    int continuar;
    do{
        this->idDetalle= crearIdDetalle();
        this->tipoFactura= datoCp.getTipoFact();
        ptoVta= datoCp.getPuntoVta();
        this->nroFactura= datoCp.getNroFactura();
        setIdProducto();
        grabarDetalleEnDisco();
        conta.imputarCta(18, 11, 2020, nroFactura, cantidad, 2, idProducto);
        system("cls");
        cout<<"\nContinua cargando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;

        cin>> continuar;
    }while(continuar==1);
    ///DEBERIA MOSTRAR EL DETALLE DE LA COMPRA O LA ORDEN DE COMPRA
    return;
}
void DetalleCompra::setIdProducto(){
    Producto prod;
    cout<<"Ingrese codigo producto : ";
    cin>>idProducto;
    if (prod.buscarProdxId(idProducto) == -2){
        prod.cargarProducto();
        prod.mostrarProducto();
        idProducto=prod.getId();
        cantidad=prod.getStock();
        prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
    }else{
        if(prod.buscarProdxId(idProducto)>0){
            cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
            prod.setPrecioCosto();
            setCantidad();
            prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
        }else{
            return;
        }
    }
}
void DetalleCompra::setPrecio(){
    cout<<"Precio :"<<endl;
    cin>>this->preBruto;
}
void DetalleCompra::setCantidad(){
    cout<<"Ingrese la cantidad: "<<endl;
    cin>>this->cantidad;
}
void DetalleCompra::setImpuesto(){
    cout<<"Porcentaje de Iva"<<endl;
    cin>>this->impuesto;
}
int DetalleCompra::crearIdDetalle(){
    int bytes, cant;
    FILE *p = fopen(FILE_DET_COMPRAS, "rb");
    if (p == NULL){ return 1;}
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(DetalleCompra);
    return cant+1;
}
bool DetalleCompra::grabarDetalleEnDisco(){
    system("cls");
    FILE *p;
    bool chequeo;
    p = fopen(FILE_DET_COMPRAS,"ab");
    if(p==NULL) {
        cout << "Error al abrir el archivo \n";
        return false;
    }
    chequeo = fwrite(this, sizeof(DetalleCompra),1,p);
    if(chequeo==1)  {
        fclose(p);
        return true;
    }else {
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        return false;
    }
}
void DetalleCompra::listado_detalle(){
    DetalleCompra aux;
    int i = 0;
    ///Inicio de cabecera
    title("DETALLE DE FACTURAS",WHITE, RED);
    cout<<endl;
    setBackgroundColor(DARKGREY);
    cout<<" "<<setw(15)<<centrar("Id", 15)<<"|";
    cout<<" "<<setw(15)<<centrar("# Fact", 15)<<"|";
    cout<<" "<<setw(38)<<centrar("Tipo de Factura", 38)<<"|"<<endl;
    setBackgroundColor(BLACK);

    while (aux.leerDeDiscoD(i++)){
    cout<<" "<<setw(15)<<centrarInt(aux.idDetalle, 15);
    cout<<" "<<setw(15)<<centrarInt(aux.ptoVta, 15);
    cout<<" "<<setw(21)<<aux.idProducto<<endl;
     }
    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
    system("pause");
}
bool DetalleCompra::leerDeDiscoD(int posicion){
    bool leyo;
    FILE *p;
    p = fopen(FILE_DET_COMPRAS, "rb");
    if (p == NULL)
    {

        return false;
    }
    fseek(p, posicion * sizeof(DetalleCompra), 0);
    leyo = fread(this, sizeof(DetalleCompra), 1, p);
    fclose(p);
    return leyo;
}
