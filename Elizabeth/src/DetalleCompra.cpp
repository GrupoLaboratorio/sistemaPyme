<<<<<<< Updated upstream
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
        setIdDetalle();
        setTipoFactura(datoCp.getTipoFact());
        setPtoVta(datoCp.getPuntoVta());
        setNroFactura(datoCp.getNroFactura());
//        this->idDetalle= crearIdDetalle();
//        this->tipoFactura= datoCp.getTipoFact();
//        ptoVta= datoCp.getPuntoVta();
//        nroFactura= datoCp.getNroFactura();
        setIdProducto();
        grabarDetalleEnDisco();
        conta.imputarCta(datoCp.getFecha(),datoCp.getNroFactura(), cantidad, 2, idProducto);
        system("cls");
        cout<<"\nContinua cargando?. ";
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;
        cin>> continuar;
         while(!(continuar == 0 || continuar == 1)){
        cout<<" Opcion incorrrecta : ";
        system("pause");
        system("cls");
         cout<<"\nCountinua cargando?. "<<endl;
        cout<<"\nSi: 1";
        cout<<"\nNo : 0 "<<endl;
        cin>> continuar;
    }
    }while(continuar==1);
    ///DEBERIA MOSTRAR EL DETALLE DE LA COMPRA O LA ORDEN DE COMPRA
    return;
}
void DetalleCompra::setIdProducto(){
    Producto prod;
    cout<<"Ingrese codigo producto : ";
    cin>>idProducto;
     while(idProducto < 1){
        cout<<"Codigo de producto incorrrecta : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese codigo producto : "<<endl;
        cin>> idProducto;
    }
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
    int precio;
    cout<<"Precio :"<<endl;
    cin>>precio;
    while(precio<1){
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese precio : "<<endl;
        cin>> precio;
    }
    this->preBruto=precio;
}
void DetalleCompra::setCantidad(){
    int cant;
    cout<<"Ingrese la cantidad: "<<endl;
    cin>>cant;
     while(cant<1){
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese cantidad : "<<endl;
        cin>> cant;
    }
    this->cantidad=cant;
}
void DetalleCompra::setImpuesto(){
    float imp;
    cout<<"Porcentaje de Iva"<<endl;
    cin>>imp;
    while(imp != 10.5 || imp != 21) {
    cout<<"Valor ingresado no valido : ";
        system("pause");
        system("cls");
         cout<<"\nIngrese impuesto : "<<endl;
        cin>> imp;
    }
    this->impuesto=imp;
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
=======
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <cstdio>
//#include <time.h>
//#include <iomanip>
//#include <conio.h>
//#include <locale.h>
//using namespace std;
//#include "Producto.h"
//#include "Productos.h"
//#include "Entidad.h"
//#include "Calculadora.h"
//#include "Contable.h"
//#include "../Utilidades/centrarTabla.h"
//#include "../Utilidades/ui.h"
//#include "../Utilidades/rlutil.h"
//#include "../Utilidades/menus.h"
//#include "Fecha.h"
//#include "Entidad.h"
//#include "Producto.h"
//#include "DetalleCompra.h"
//#include "Compras.h"
//using namespace rlutil;
//
//void DetalleCompra::cDetalleCompra(){
//    setlocale(LC_CTYPE, "Spanish");
//    Compras  datoCp;
//    Contable conta;
//    int i=crearIdXCompras()-2;
//    datoCp.leerDeDisco(i);//leer de Compras
//    int continuar;
//    cout<<datoCp.getNroFactura();
//    do{
//        setIdDetalle();
//        setTipoFactura(datoCp.getTipoFact());
//        setPtoVta(datoCp.getPuntoVta());
//        setNroFactura(datoCp.getNroFactura());
//        setIdProducto();
//        grabarDetalleEnDisco();
//        conta.imputarCta(getNroFactura(), cantidad, 2, idProducto);
//        system("cls");
//        cout<<"\nContinua cargando?. ";
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//        cin>> continuar;
//         while(!(continuar == 0 || continuar == 1)){
//        cout<<" Opcion incorrrecta : ";
//        system("pause");
//        system("cls");
//         cout<<"\nCountinua cargando?. "<<endl;
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//        cin>> continuar;
//    }
//    }while(continuar==1);
//    ///DEBERIA MOSTRAR EL DETALLE DE LA COMPRA O LA ORDEN DE COMPRA
//    return;
//}
//void DetalleCompra::setIdProducto(){
//    Producto prod;
//    cout<<"Ingrese codigo producto : ";
//    cin>>idProducto;
//     while(idProducto < 1){
//        cout<<"Codigo de producto incorrrecta : ";
//        system("pause");
//        system("cls");
//         cout<<"\nIngrese codigo producto : "<<endl;
//        cin>> idProducto;
//    }
//    if (prod.buscarProdxId(idProducto) == -2){
//        prod.cargarProducto();
//        prod.mostrarProducto();
//        idProducto=prod.getId();
//        cantidad=prod.getStock();
//        prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
//    }else{
//        if(prod.buscarProdxId(idProducto)>0){
//            cout<<"Precio: $"<< prod.getPrecioCosto()<<endl;
//            prod.setPrecioCosto();
//            setCantidad();
//            prod.setMod(idProducto, 2, cantidad,  prod.getPrecioCosto());
//        }else{
//            return;
//        }
//    }
//}
//void DetalleCompra::setPrecio(){
//    int precio;
//    cout<<"Precio :"<<endl;
//    cin>>precio;
//    while(precio<1){
//    cout<<"Valor ingresado no valido : ";
//        system("pause");
//        system("cls");
//         cout<<"\nIngrese precio : "<<endl;
//        cin>> precio;
//    }
//    this->preBruto=precio;
//}
//void DetalleCompra::setCantidad(){
//    int cant;
//    cout<<"Ingrese la cantidad: "<<endl;
//    cin>>cant;
//     while(cant<1){
//    cout<<"Valor ingresado no valido : ";
//        system("pause");
//        system("cls");
//         cout<<"\nIngrese cantidad : "<<endl;
//        cin>> cant;
//    }
//    this->cantidad=cant;
//}
//void DetalleCompra::setImpuesto(){
//    float imp;
//    cout<<"Porcentaje de Iva"<<endl;
//    cin>>imp;
//    while(imp != 10.5 || imp != 21) {
//    cout<<"Valor ingresado no valido : ";
//        system("pause");
//        system("cls");
//         cout<<"\nIngrese impuesto : "<<endl;
//        cin>> imp;
//    }
//    this->impuesto=imp;
//}
//int DetalleCompra::crearIdDetalle(){
//    int bytes, cant;
//    FILE *p = fopen(FILE_DET_COMPRAS, "rb");
//    if (p == NULL){ return 1;}
//    fseek(p, 0, SEEK_END);
//    bytes = ftell(p);
//    fclose(p);
//    cant=bytes / sizeof(DetalleCompra);
//    return cant+1;
//}
//bool DetalleCompra::grabarDetalleEnDisco(){
//    system("cls");
//    FILE *p;
//    bool chequeo;
//    p = fopen(FILE_DET_COMPRAS,"ab");
//    if(p==NULL) {
//        cout << "Error al abrir el archivo \n";
//        return false;
//    }
//    chequeo = fwrite(this, sizeof(DetalleCompra),1,p);
//    if(chequeo==1)  {
//        fclose(p);
//        return true;
//    }else {
//        cout << "El registro no pudo guardarse \n\n";
//        fclose(p);
//        system("pause");
//        return false;
//    }
//}
//
////void DetalleVenta::listado_detalle(){
////    DetalleVenta aux;
////    int i = 0;
////    ///Inicio de cabecera
////    title("DETALLE DE FACTURAS",WHITE, RED);
////    cout<<endl;
////    setBackgroundColor(DARKGREY);
////    cout<<" "<<setw(15)<<centrar("Id", 15)<<"|";
////    cout<<" "<<setw(15)<<centrar("# Fact", 15)<<"|";
////    cout<<" "<<setw(38)<<centrar("Tipo de Factura", 38)<<"|"<<endl;
////    setBackgroundColor(BLACK);
////
////    while (aux.leerDeDiscoD(i++)){
////    cout<<" "<<setw(15)<<centrarInt(aux.idDetalle, 15);
////    cout<<" "<<setw(15)<<centrarInt(aux.getNroFactura(), 15);
////    cout<<" "<<setw(21)<<aux.getTipoFactura()<<endl;
////     }
////    cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
////    system("pause");
////}
//
//int posicionFact(){
//    Compras reg;
//    int factura, contador=0, opcion;
//    bool b=false;
//   do{
//   cout<<"Ingrese numero de factura : ";
//   cin>>factura;
//   while(factura < 0) {
//       cout<<"Numero de factura incorrecto ";
//       system("pause");
//       system("cls");
//       cout<<"\nIngrese el numero de factura que desea imprimir: ";
//       cin>>factura;
//   }
//
//   FILE *p=fopen(FILE_COMPRAS,"rb");
//   if(p == NULL)return -1;
//
//   while(fread(p,sizeof(Compras), 1, p)){
//    if(reg.getNroFactura() == factura){
//            fclose(p);
//            b=true;
//        return contador;
//    }
//    contador++;
//   }
//    cout<<"Numero de factura inexistente";
//    fclose(p);
//     system("pause");
//    system("cls");
//     cout<<"\nIngresara un numero de factura?. ";
//    cout<<"\nSi: 1";
//      cout<<"\nNo : 0 "<<endl;
//        cin>> opcion;
//
//         while(!(opcion == 0 || opcion == 1)){
//        cout<<" Opcion incorrrecta : ";
//        system("pause");
//        system("cls");
//         cout<<"\nCountinua cargando?. "<<endl;
//        cout<<"\nSi: 1";
//        cout<<"\nNo : 0 "<<endl;
//        cin>> opcion;
//    }  if(opcion==1){
//         b=false;
////        listado_detalle();
//        system("pause");
//        system("cls");
//    }else{return -2;}
//    }while(b == false);  }
//
//void DetalleCompra::imprimirNotaCredito(int _n){
//    float  sTot=0, sIva=0, tTot=0, tPrUn=0;
//    Compras  dato;
//    Entidad cliente;
//    Producto prod;
//    int i =0, f;
//    cls();
//    if(_n == 0){
//    f =posicionFact();
//   if(f == -2){
//    return;}
//    }else{
//        f=_n -1;
//    }
//    cls();
//    dato.leerDeDisco(f);
//    cliente.leerDeDisco(dato.getIdEntidad()-1,1);
//    char a[30];
//        if(dato.getTipoFact() =='A'){
//             system("color 0E");
//           setBackgroundColor(BLUE);
//        }else{
//             system("color 0F");
//            setBackgroundColor(RED);
//        }
//    strcpy(a, "FACTURA ");
//            cout<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(88)<<centrar(a, 87)<<"|"<<endl;
//            cout<<"|"<<setw(88)<<dato.getTipoFact()<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;//            cout<<"|"<<setw(69)<<""<<getPtoVta()<<derechaInt(f, 5)<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<right;
////            cout<<"|"<< "TONGA GESTION SRL   "<<setw(31)<<""; if(dato.getTipoFact()=='A'){cout<<"R.SOCIAL :"<<setw(27)<<cliente.getRazonSocial() <<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
////            cout<<"|"<< "info@tongagest.com  "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"MAIL     :"<<setw(27)<<cliente.getMail()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
////            cout<<"|"<< "Dir: Yrigoyen 197   "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"DIR      :"<<setw(27)<<cliente.getDomicilio().getCalle()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
////            cout<<"|"<< "Cod Post : 1640     "<<setw(31)<<"";if(dato.getTipoFact()=='A'){cout<<"CUIT     :"<<setw(27)<<cliente.getCuit()<<"|"<<endl;}else{cout<<setw(37)<<" "<<"|"<<endl;}
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(9)<<centrar("CODPROD", 9);
//            cout<<"|"<<setw(28)<<centrar("DESCRIPCION", 28);
//            cout<<"|"<<setw(10)<<centrar("CANTIDAD", 10);
//            cout<<"|"<<setw(10)<<centrar("PRECIO", 10);
//            cout<<"|"<<setw(10)<<centrar("IVA", 10);
//            cout<<"|"<<setw(16)<<centrar("SUB TOT", 16)<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//        while ( (i++)){
//        if(aux.getNroFactura()==f){
//             prod.leerDeDisco(prod.buscarProdxId(aux.getCodProducto()));
//                cout<<setfill(' ');
//                cout<<"|"<< setw(9)<<centrarInt(aux.getCodProducto(), 9);
//                cout<<left;
//                cout<<"|"<< setw(28)<<prod.getDescripcion();
//                cout<<right;
//                cout<<"|"<< setw(10)<<centrarInt(aux.getCantProducto(), 10);
//                cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<aux.getPrecio();
//                 cout<<"|"<< setw(10)<<fixed<<setprecision(2)<<(aux.getPrecio()*prod.getIva()/100);
//                 cout<<"|"<<setw(16)<<fixed<<setprecision(2)<<((aux.getPrecio()+(aux.getPrecio()*prod.getIva()/100))*aux.getCantProducto())<<"|"<<endl;
//                tPrUn+=aux.getPrecio();
//                sTot+=(aux.getPrecio()*aux.getCantProducto());
//                sIva+=((aux.getPrecio()*prod.getIva())/100*aux.getCantProducto());
//        }
//        }
//                tTot+=(sIva+sTot);
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<< right;
//           cout<<"|"<<setw(80)<<"SubTotal:$"<<setw(8)<<fixed<<setprecision(2)<<sTot<<"|"<<endl;
//            cout<<"|"<<setw(80)<<"Total Iva:$"<<setw(8)<<fixed<<setprecision(2)<<sIva<<"|"<<endl;
//            cout<<"|"<<setw(80)<<"Total Final:$"<<setw(8)<<fixed<<setprecision(2)<<tTot<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill(' ')<<"|"<<endl;
//            cout<<"|"<<setw(89)<<setfill('_')<<"|"<<endl;
//    system("pause");
//}
>>>>>>> Stashed changes
