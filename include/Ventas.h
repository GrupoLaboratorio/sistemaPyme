#ifndef VENTAS_H
#define VENTAS_H
#include "Operacion.h"

class Ventas: public Operacion{

    protected:
    char tipofactura; ///Facturas de dos tipos (A: empresa, B: consumidor final)
    int Nrofactura;  ///Numero de factura autonumerico (0000-00000000)
    float Bonificacion; ///teniendo en cuenta el modo de pago (1: 10 % descuento, 2: 15% de recargo, 3: sin bonificacion)
   float preciofinal;

    public:
    Ventas();
    void CargarVtas();  /// Carga los datos de las ventas
    void MostrarVtas(); /// Muestra los datos de las ventas
    void setTipoFact(char); /// Asigna el tipo de factura
    void setNrofactura(); /// Asigna el numero de factura autonumerico
    void setBonificacion();  /// Asigna la bonificacion que requiera de acuerdo al modo de pago
    void setprecioFinal();  /// Calcula el precio aplicando la bonificacion
    char getTipoFact();  /// Muestra el tipo de factura
    int getNroFactura();  /// Muestra el numero de la factura
    float getBonificacion(); ///  Muestra la bonificacion aplicada
    float getPrecioFinal();  /// Muestra el precio con la bonificacion aplicada
};

///--------------------- GLOBALES -------------------------

int crearId();

#endif // VENTAS_H

