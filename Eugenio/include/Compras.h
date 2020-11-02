#ifndef COMPRAS_H
#define COMPRAS_H
#include "Fecha.h"
#include "DetalleCompra.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

class Compras{

  private:
        int idCompras;///Debe ser autoincremental
        char descripcion[20]; ///descripcion si no existe el prod modificar longitud
        char tipoFactura; ///Facturas de dos tipos (A: RI, C: monotributistas)
        int puntoVta;       ///Representa el numero de venta de la sucursal del proveedor( mayor a 0)
        int nroFactura;  ///Numero de factura autonumerico (-00000000)
        int idEntidad;
        int idProducto;
        int idCuenta;///Cuenta Contable para los balances
         int cantidad;  /// Cantidad del producto
         int impuesto;  /// Valor del Impuesto aplicado
         float preBruto;  /// Precio unitario del producto
         float preTotal; /// Total a pagar, calculado con el impuesto, el precio y la cantidad
        bool cierra;
        Fecha fechaFactura;
        Entidad proveedor;
//        Producto producto;
    public:
        Compras();
        void cargarCompras();  /// Carga los datos de las ventas
        void mostrarDetalleCompras(); /// Muestra los datos de las ventas
        void setTipoFact(); /// Asigna el tipo de factura
        void setPuntoVta();
        void setIdCuenta(); /// Asigna el numero de factura autonumerico
        void setNroFactura(); /// Asigna el numero de factura autonumerico
        void setIdProducto(); /// Asigna el Id de producto ingresado
        void setIdProveedor(); /// Asigna el Id del proveedor
        void setPrecio(); ///Asigna el Precio Unitario del producto
        void setCantidad(); ///Asigna la cantidad de producto en stock
        void setImpuesto(); ///Asigna el impuesto
        void setFechaFactura();
        char getTipoFact();  /// Muestra el tipo de factura
        int getNroFactura();  /// Muestra el numero de la factura
        int getIdProducto(); /// Muestra el numero de  id del producto
        int getpuntoVta();
        int getcantProd(); ///Muestra la cantidad de producto corroborado en setCantProd
        float getPrecio();  ///Muestra el precio unitario del producto
        float getImpuesto(); ///Muestra el Impuesto aplicado
        bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**

        int setIdCompras();
        int getIdCompras();

        void setIdEntidad();        int getIdEntidad();
        bool leerDeDisco(int posicion);
        void listado_compras();
//        int setIdProducto();
//        int getIdProducto();

};
int crearIdXCompras();
#endif // COMPRAS_H
