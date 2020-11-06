
#include <iostream>
using namespace std;
#include "Contable.h"
#include "Fecha.h"
#include "Calculadora.h"

///setters

void Contable::setFechaDesde(){
       f.setFecha(); }
        void Contable::setFechaHasta(){
        }
        void Contable::setNroCta(){}

        ///getters
        Fecha Contable::getFechaDesde(){
          }
        Fecha Contable::getFechaHasta(){}

        ///funciones
        void Contable::imputarCta(Fecha, int, bool, bool, float ){}///recibe parametros
        void Contable::grabarEnDisco(){}///graba la imputacion linea por linea con "rb+"
        void Contable::listarLibroDiario(Fecha){}///lista todas las cuentas  de una fecha determinada
        void Contable::listarLibroMayor(Fecha, Fecha, int){}
