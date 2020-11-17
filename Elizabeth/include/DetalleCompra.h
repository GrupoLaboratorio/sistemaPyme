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
    int getIdDetalle(){ return idDetalle;}
    char getTipoFactura(){  return tipoFactura;}
    int getPtoVta(){return ptoVta;}
    int getNroFactura(){return nroFactura;}
    float getPrecio();
    float getImpuesto();
    int getcantProd();

///Disco
    int crearIdDetalle();
    void cDetalleCompra();
    bool grabarDetalleEnDisco();

};
#endif // DETALLECOMPRA_H
