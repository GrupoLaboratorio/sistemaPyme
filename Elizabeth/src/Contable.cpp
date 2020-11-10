
#include <iostream>
using namespace std;
#include "Contable.h"
#include "Fecha.h"
#include "Calculadora.h"

///setters

void Contable::setFechaDesde(){
       f.setFecha(); }
        void Contable::setFechaHasta(){
        f.setFecha(); }
        void Contable::setNroCta(){}

        ///getters
        Fecha Contable::getFechaDesde(){
         f.MostrarFecha(); }
        Fecha Contable::getFechaHasta(){
        f.MostrarFecha();}

        ///funciones
        void Contable::imputarCta(Fecha, int, bool, bool, float ){
        }///recibe parametros
//        void Contable::grabarEnDisco(int posicion){
//        FILE *p;
//        bool guardo;
//
//        p=fopen("Contabilidad. dat","rb+");
//        if(p==NULL) return;
//         fseek(p,sizeof(Contable), SEEK_SET);
//        guardo = fwrite(this, sizeof(Contable)1,p);
//
//        }///graba la imputacion linea por linea con "rb+"
        void Contable::listarLibroDiario(Fecha){}///lista todas las cuentas  de una fecha determinada
        void Contable::listarLibroMayor(Fecha, Fecha, int){}
