#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H
#include "Ventas.h"

class DetalleVenta{
    private:
    int nroFactura, codProd, cantidad;
    float precio;
    Ventas dato;
    calculadora calculo;
     Producto prod;
    public:
    void cDetalleVenta();
    void setCodProducto();
    void setCantProducto();
    void setPrecio(){this->precio=prod.getPrecioCosto();}
    int getCodProducto(){return codProd;}
    int getCantProducto(){return cantidad;}
    float getPrecio(){return precio;}
    void mostrarDetalleVenta(int);
   bool grabarDetalleEnDisco();
   bool leerDeDisco(int posicion);
};

#endif // DETALLEVENTA_H
