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
        nroFactura= datoCp.getNroFactura();
        setIdProducto();
        grabarDetalleEnDisco();
        conta.imputarCta(datoCp.getNroFactura(), cantidad, 2, idProducto);
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
