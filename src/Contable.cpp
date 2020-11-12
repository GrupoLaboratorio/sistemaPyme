
#include <iostream>
using namespace std;

#include "Contable.h"
#include "DetalleVenta.h"

        ///setters
        void Contable::setOperacion(int _tipo){}
        void Contable::setNroCta(int _nCta){}
        void Contable::setDebe(float _debe){ debe = _debe; }
        void Contable::setHaber(float _haber){ haber= _haber;}
        void Contable::setSaldo(float _saldo){ saldo= _saldo;}
        void Contable::setFechaDesde(){}
        void Contable::setFechaHasta(){}

        ///getters
         int  Contable::getOperacion(){}
        int  Contable::gettNroCta(){}
        float   Contable::getDebe(){return debe;}
        float   Contable::getHaber(){return haber;}
        float   Contable::getSaldo(){return saldo;}
        Fecha Contable::getFechaDesde(){}
        Fecha Contable::getFechaHasta(){}

        ///funciones
        void Contable::imputarCta(Fecha, int, bool, bool, float ){}///recibe parametros
        void Contable::grabarEnDisco(){}///graba la imputacion linea por linea con "rb+"


        void Contable::listarLibroDiario(){
            calculadora cal;
            DetalleVenta  detVta;
            int i=0;
            while(detVta.leerDeDiscoD(i++)){
                     setDebe(detVta.getPrecio());
                     setHaber(0);
                     setSaldo( getHaber() - getDebe());
                    cout<<"DEBE: "<<getDebe()<<endl;
                    cout<<"HABER: "<<getHaber()<<endl;
                    cout<<"SALDO: "<<getSaldo()<<endl;
            }

        }///lista todas las cuentas  de una fecha determinada
        void Contable::listarLibroMayor(Fecha, Fecha, int){}
