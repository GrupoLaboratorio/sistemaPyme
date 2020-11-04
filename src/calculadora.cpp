
#include <iostream>
using namespace std;

#include "calculadora.h"
    void calculadora::setExtraeIva(float _iva){
        this->extraeIva=_iva/100+1;
    }
    void calculadora::setImporteBruto( float _precioUnitario){
        this->importeBruto= _precioUnitario/getExtraeIva();
    }
    void calculadora::setImponible(int _cantidad){
        this->imponible=getImporteBruto()*float(_cantidad);
    }
    void calculadora::setDescuento(float _descuento){
        this->descuento= getImponible()*_descuento/100;
    }
    void calculadora::setDescuentoAplicado(){
        this->descuentoAplicado =getImponible()-getDescuento();
    }
    void calculadora::setImpuesto(float _impuesto){
        this->impuesto =getDescuentoAplicado()*_impuesto/100;
    }
    void calculadora::setImpuestoAplicado(){
        this->impuestoAplicado =getDescuentoAplicado()+getImpuesto();
    }

    float calculadora::getExtraeIva(){return extraeIva;}
    float calculadora::getImporteBruto(){return importeBruto;}
    float calculadora::getImponible(){return imponible;}
    float calculadora::getDescuento(){return descuento;}
    float calculadora::getDescuentoAplicado(){return descuentoAplicado;}
    float calculadora::getImpuesto(){return impuesto;}
    float calculadora::getImpuestoAplicado(){return impuestoAplicado; }
