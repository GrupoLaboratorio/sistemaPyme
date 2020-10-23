#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <iomanip>
#include "DetalleFactura.h"
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
        cout<<"***************************************************************************************"<<endl;
        cout<<"DETALLE DE FACTURA"<<endl;
        cout<<"***************************************************************************************"<<endl;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        cout << setw(4) << "ID" << setw(10) << "#FACTURA" << setw(10) << "CODPROD." << setw(10) << "CANTIDAD";
        cout<< setw(10)<<"_PRECIO_"<<setw(10)<<"TOT_IVA."<<setw(10)<<"SUB_TOT."<<setw(7)<<"TOTAL";
        cout<<setw(6)<<"PCTA"<<setw(7)<<"C_ENT"<<setw(5)<<"ENT"<<endl;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        while (aux.leerDeDisco(i++)){
        cout << right;
        cout << setw(4) <<"01"<< setw(10) << aux.nroFactura<< setw(10) << aux.codProd << setw(10) << aux.cantidad;
        cout<< setw(10)<<aux.precioCosto<<setw(10)<<aux.ivaTotalProd<<setw(10)<<aux.subTotalProd<<setw(7)<<aux.TotalProd;
        cout<<setw(6)<<aux.planCta<<setw(7)<<aux.codEnt<<setw(5)<<aux.tipoEnt<<endl;
//        cout << endl;
        cout<<"---------------------------------------------------------------------------------------"<<endl;
        }
        }
