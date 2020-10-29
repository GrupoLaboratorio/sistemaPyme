//#ifndef DETALLECOMPRA_H
//#define DETALLECOMPRA_H
//
//
//class DetalleCompra
//{
//  private:
//        char descripcion[20]; ///Descripcion del producto
//        char tipoFactura; ///Facturas de dos tipos (A: RI, C: monotributistas)
//
//        int idDetalleCompra;///Debe ser autoincremental
//        int puntoVta;       ///Representa el numero de venta de la sucursal del proveedor( mayor a 0)
//        int nroFactura;  ///Numero de la factura
//        int idEntidad; ///Id del Proveedor
//        int idProducto; ///Id del producto
//        int idProveedor; ///Id del producto
////        int cuit; ///cuit sin guiones
//        int idCuenta;///Cuenta Contable para los balances
//        int cantidad;  /// Cantidad del producto
//        int impuesto;  /// Valor del Impuesto aplicado
//
//        float preBruto;  /// Precio unitario del producto
//        float preTotal; /// Total a pagar, calculado con el impuesto, el precio y la cantidad
//
//        bool cierra;
//
//        Compras compra;
//        Entidad proveedor;
//        Producto producto;
//
//    public:
//
//    DetalleCompra::DetalleCompra(int _idProveedor, int _idProducto, bool _cierra=false ){
//       idProveedor=_idProveedor;
//       idProducto=_idProducto;
//       cierra = _cierra;
//    }
//        void setIdProveedor();
////        int getIdProveedor();
//
////        void setIdProducto();
////        int setIdProducto();
////
////        int setIdEntidad();////        int getIdEntidad();
////
////        int setIdDetalleCompra();
////        int getIdDetalleCompra();
////
////        void cargarDetalleCompras();
////        bool grabarDetalleEnDisco();
////        void leerDetalleDisco();
//};
//
//#endif // DETALLECOMPRA_H
