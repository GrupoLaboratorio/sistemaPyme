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
    void setPrecio();
    void setCantidad();
    void setImpuesto();
    void setIdProducto();

///gettes
    float getPrecio();
    float getImpuesto();
    int getcantProd();

///Disco
    int crearIdDetalle();
    void cDetalleCompra();
    bool grabarDetalleEnDisco();
    void listado_detalle();
    bool leerDeDiscoD(int );
    bool leyo;

};
#endif // DETALLECOMPRA_H
