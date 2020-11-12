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
//    void setProveedor();
//    void setIdProveedor();

///gettes
    float getPrecio();
    float getImpuesto();
    int getcantProd();
//    int getIdProducto();
//    Entidad getProveedor();

///Disco
    int crearIdDetalle();
    void cDetalleCompra();
    bool grabarDetalleEnDisco();

///memoria

};
#endif // DETALLECOMPRA_H
