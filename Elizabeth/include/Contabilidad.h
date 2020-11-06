#ifndef CONTABILIDAD_H
#define CONTABILIDAD_H


class Contabilidad{
    protected:
    float cajaD, ivaCompra, ivaVenta, pNetoCompra, pNetoVenta;
    float cajaH, mercaderiaD, mercaderiaH;
    int servicios;
    Ventas *venta;
    Compras *compra;
    Calculadora calculos;
    public:
    void setIvaCompra();
    void setIvaVenta();
    void setCajaDebe();
    void setCajaHaber();
    void setPNetoCompra();
    void setPNetoVenta();
    void setMercaderiaD();
    void setMercaderiaH();
    void setServicios();
    float getIvaCompra(){return ivaCompra;}
    float getIvaVenta(){return ivaVenta;}
    float getCajaDebe(){return cajaD;}
    float getCajaHaber(){return cajaD;}
    float getPNetoCompra(){return pNetoCompra;}
    float getPNetoVenta(){return pNetoCompra;}
    float getMercaderiaD(){return mercaderiaD;}
    float getMercaderiaH(){return mercaderiaH;}
    float  getServicios(){return servicios;}
};

#endif // CONTABILIDAD_H
