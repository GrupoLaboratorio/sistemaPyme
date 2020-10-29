#ifndef VENTAS_H
#define VENTAS_H
#include "Fecha.h"
#include "DetalleFactura.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

///-----------------------CLASE VENTAS

class Ventas{

    public:
    int idVenta, idCliente,IdProd, modoPago;
    char tipoFactura;
    int  nroFactura;
    ///Fecha fecha;
    DetalleFactura dato;
    calculadora calculo;
    Producto prod;
   Entidad cliente;
    public:
    Ventas();
   // ~Ventas();
    void cargarVtas();  /// Carga los datos de las ventas
    void mostrarVtas(int); /// Muestra los datos de las ventas
    void setIdVenta();  /// Asigna el Id de venta
    void setTipoFact();/// Se ingresa factura A O B
    void setIdCliente(char); /// Corrobora el si el id de Cliente existe, sino pide que lo cargue
    void setNroFact();  /// Numero autoincremental
    void setOpcionPago(); /// Metodo de pago (1- efectivo, 2- transferencia, 3- tarjeta)
    int getIdVenta();   /// Muestra el Id de ventas
    int getIdCliente();
    char getTipoFact();
    int getNroFact();
    int getOpcionPago();
    void  finalVenta(); /// permite al cliente la opcion de modificar algunos de los productos de la venta, conecta con opcion de pago
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
     bool leerDeDisco(int);
};

///-----------------------PROTOTIPOS GLOBALES
int crearIdVentas();
int crearIdXFact(char);
void listarVentas();

#endif // VENTAS_H

