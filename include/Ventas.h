#ifndef VENTAS_H
#define VENTAS_H
#include "Fecha.h"
#include "DetalleFactura.h"
//#include "DetalleVenta.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

///-----------------------CLASE VENTAS

class Ventas{

    public:
    int  idCliente;
//    int IdProd, modoPago;
    char tipoFactura;
    int  nroFactura;
    Fecha fechaVenta;
//    Producto prod;
//    DetalleVenta venta;

   Entidad cliente;
    public:
    Ventas();
   // ~Ventas();
   /// void setFechaVta();
    void cargarVtas();
    void mostrarVtas(int);
//    void setIdVenta(){this->idVenta=crearIdVentas();}
    void setTipoFact();
    void setIdCliente();
    void setNroFact();
   // void setOpcionPago();
  // Fecha getFechaVta(){}
//    int getIdVenta(){return idVenta;}
    int getIdCliente(){return idCliente;}
    char getTipoFact(){return tipoFactura;}
    int getNroFact(){return nroFactura;}
   // int getOpcionPago();
   // void  finalVenta();
    bool grabarEnDisco();
     bool leerDeDisco(int);
    void listado_facturas();
};

///-----------------------PROTOTIPOS GLOBALES
int crearIdVentas();
int crearIdXFact();
void listarVentas();

#endif // VENTAS_H

