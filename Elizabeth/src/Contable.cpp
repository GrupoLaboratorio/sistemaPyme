
#include <iostream>
using namespace std;

#include "Contable.h"

        ///setters
        void setFechaDesde(){}
        void setFechaHasta(){}
        void setNroCta(){}

        ///getters
        Fecha getFechaDesde(){}
        Fecha getFechaHasta(){}

        ///funciones
        void imputarCta(Fecha, int, bool, bool, float ){}///recibe parametros
        void grabarEnDisco(){}///graba la imputacion linea por linea con "rb+"
        void listarLibroDiario(Fecha){}///lista todas las cuentas  de una fecha determinada
        void listarLibroMayor(Fecha, Fecha, int){}
