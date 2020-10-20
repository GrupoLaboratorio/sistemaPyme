#ifndef OPERACION_H
#define OPERACION_H


class Operacion{
    protected:
     int producto;
     int cantidad;  ///Cantidad del producto
     float precio;  ///Precio unitario del producto
     float impuesto;  ///Impuesto aplicado al 21, 03 %, (iva = 21%, percepciones (sobre el iva)=0,03%)
     int modoPago; ///Condicion de pago (1: efectivo, 2: tarjeta de credito, 3: transferencia)
     float total; ///Total a pagar, calculado con el impuesto, el precio y la cantidad

    public:
    Operacion();
     void CargarOp(); ///Carga los datos de la operacion
     void MostrarOp();  ///Muestra los datos de la operacion
     void setPrecio(float); ///Asigna el Precio Unitario del producto
     void setModoPago(int); ///Asigna el modo de pago
     void setCantProd(int); ///Asigna la cantidad de producto en stock
     void setImpuesto(float);   ///Asigna el impuesto
     void setMonto(float, float, int);  ///Calcula Precio total, suma entre precio e impuesto
     int getcantProd(); ///Muestra la cantidad de producto corroborado en setCantProd
     float getMonto(); ///Muestra el precio total a pagar
    float getPrecio();  ///Muestra el precio unitario del producto
    int getModoPago(); ///Muestra  el modo de pago
    float getImpuesto(); ///Muestra el Impuesto aplicado.
};

#endif // OPERACION_H
