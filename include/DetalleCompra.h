#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H
#define FILE_DET_COMPRAS "Archivos/DetalleCompras.dat"
#include "Producto.h"
#include "Entidad.h"
#include "Compras.h"

class DetalleCompra{

private:
    char tipoFactura;
    int nroFactura, ptoVta;
    int idDetalle;
    int idProducto;
    int cantidad;
    int impuesto;
    float preBruto;
    float preTotal;

public:
///setters
    void setIdDetalle(){ this->idDetalle= crearIdDetalle();}
    void setTipoFactura(char t){  this->tipoFactura= t;}
    void setPtoVta(int n){this->ptoVta=n;}
    void setNroFactura(int n){this->nroFactura=n;}
    void setPrecio();
    void setCantidad();
    void setImpuesto();
    void setIdProducto();

///gettes
    float getPrecio(){return preBruto;}
    int getCantProducto(){return cantidad;}
    float getImpuesto(){return impuesto;}
    int getCodProducto(){return idProducto;}
    int getNroFactura(){return nroFactura;}


///Disco
    int crearIdDetalle();
    void cDetalleCompra();
    bool grabarDetalleEnDisco();
    void imprimirNotaCredito(int _n=0);
    bool leerDeDisco(int);
};

int posicionFact();
#endif // DETALLECOMPRA_H

