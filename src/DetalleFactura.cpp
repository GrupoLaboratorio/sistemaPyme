#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "DetalleFactura.h"
#include "Entidad.h"
const char * FILE_DETFAC = "Archivos/DetalleFacturas.dat";
void DetalleFactura::CDetalleFactura(
   int _nroFactura,
   int _codProd,
   int _cantidad,
   int _codEnt,
   int _planCta,
   float _precioCosto,
   float _ivaTotalProd,
   float _subTotalProd,
   float _TotalProd,
   char _tipoEnt ){
    nroFactura    =    _nroFactura;
    codProd         =         _codProd;
    cantidad        =        _cantidad;
    codEnt           =           _codEnt;
    planCta          =         _planCta;
    precioCosto   =   _precioCosto;
    ivaTotalProd  = _ivaTotalProd;
    subTotalProd =_subTotalProd;
    TotalProd       =      _TotalProd;
    estado            =                false;
//    strcpy(tipoEnt, _tipoEnt) ;
}
bool DetalleFactura::guardarEnDisco(int posicion){
        bool grabo;
        FILE *p;

            p = fopen(FILE_DETFAC, "ab");
            if (p == NULL){
                return false;
            }

        grabo = fwrite(this, sizeof(DetalleFactura), 1, p);
        fclose(p);
        return grabo;
    }
    bool DetalleFactura::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_DETFAC, "rb");
        if (p == NULL){

            return false;
        }
        fseek(p, posicion * sizeof(DetalleFactura), 0);
        leyo = fread(this, sizeof(DetalleFactura), 1, p);
        fclose(p);
        return leyo;
    }
    void listado_facturas(){
        DetalleFactura aux;
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
        cout<< setw(2)<<"01";
        cout<< setw(8)<< aux.nroFactura;
        cout<< setw(10) << aux.codProd;
        cout<< setw(10) << aux.cantidad;
        cout<< setw(10)<<aux.precioCosto;
        cout<<setw(10)<<aux.ivaTotalProd;
        cout<<setw(10)<<aux.subTotalProd;
        cout<<setw(10)<<aux.TotalProd;
        cout<<setw(6)<<aux.planCta;
        cout<<setw(5)<<aux.codEnt;
        cout<<setw(5)<<"CL";
        cout<<endl;
        cout<<"________________________________________________________________________________________"<<endl;

        }
        }
void  mostrarDetalle(){
    float  sTot, sIva, tTot, tPrUn;
          DetalleFactura aux;
          Entidad cli;
          cli.leerDeDisco(aux.codEnt, 'CLIENTE');
        int i = 0;

        cout << left;
        cout<<"*__________________________FACTURA____________________________*"<<endl;
        cout<<"***************************************************************"<<endl;
//        cout<<setfill('*');
//        cout<<setw(63)<<endl;
        cout<<setw(42)<<""<<"Nro Fac: 0000-"<<aux.nroFactura<<endl;
        cout<<cli.getApenom()<<endl;
        cout<<endl;
        cout<<right;
        cout<< "TONGA GESTION SRL   "<<setw(20)<<""<<"R.SOCIAL: "<<setw(13)<<"LARA COLA SRL"<<endl;
        cout<< "info@tongagest.com  "<<setw(20)<<""<<"MAIL:"<<setw(13)<<"info@briancola.com"<<endl;
        cout<< "Dir: Yrigoyen 197   "<<setw(20)<<""<<"DIR :     "<<setw(13)<<"Games F"<<endl;
        cout<< "Cod Post : 1640     "<<setw(20)<<""<<"TEL :     "<<setw(13)<<"458-4584"<<endl;
        cout<< "Cuit: 30-12345678-0 "<<setw(20)<<""<<"CUIT:     "<<setw(13)<<"44-44444444-4"<<endl;
//        cout<<setw(4)  <<"ID";
        cout<<endl;
        cout<<endl;
        cout << left;
        cout<<"_______________________________________________________________"<<endl;
        cout<<setw(8)<<"#__";
        cout<<setw(10)<<"CODPROD.";
        cout<<setw(10)<<"CANTIDAD";
        cout<<setw(10)<<"_PRECIO_";
        cout<<setw(10)<<"TOT_IVA.";
        cout<<setw(10)<<"SUB_TOT.";
        cout<<setw(7)  <<"TOTAL";
        cout<<endl;
        cout<<"_______________________________________________________________"<<endl;
        while (aux.leerDeDisco(i++)){

        cout<< right;
        cout<< setw(10) << aux.codProd;
        cout<< setw(10) << aux.cantidad;
        cout<< setw(10)<<aux.precioCosto;
        cout<<setw(10)<<aux.ivaTotalProd;
        cout<<setw(10)<<aux.subTotalProd;
        cout<<setw(10)<<aux.TotalProd;
        cout<<endl;
         tPrUn+=aux.precioCosto;
        sIva+=aux.ivaTotalProd;
         sTot+=aux.subTotalProd;
        tTot+=aux.TotalProd;
//        cout<<"________________________________________________________________________________________"<<endl;

        }
        cout<<endl;
        cout<<endl;
        cout<< right;
        cout<<setw(50)<<"SubTotal: "<<setw(9)<<sTot<<endl;
        cout<<setw(50)<<"Total Iva: "<<setw(9)<<sIva<<endl;
        cout<<setw(50)<<"Total Final: "<<setw(9)<<tTot<<endl;
        cout<<"_______________________________________________________________"<<endl;

}
