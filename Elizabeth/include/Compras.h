#ifndef COMPRAS_H
#define COMPRAS_H
#define FILE_COMPRAS "Archivos/Compras.dat"
#include "Fecha.h"
#include "DetalleCompra.h"
#include "Calculadora.h"
#include "Producto.h"
#include "Entidad.h"

class Compras{

private:
    int idCompras;
  char tipoFactura;
    int puntoVta;
    int nroFactura;
    int idEntidad;
    Fecha fechaFactura;

public:
    Compras();
    void cargarCompras();
    void setTipoFact();
    void setPuntoVta();
    void setIdCuenta();
    void setNroFactura();
    void setIdProveedor();
    void setFechaFactura();
    char getTipoFact(){return tipoFactura;}
    int getNroFactura(){return nroFactura;}
    int getPuntoVta(){return puntoVta;}
    bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**

    int setIdCompras();
    int getIdCompras();

    void setIdEntidad();
    int getIdEntidad();
    bool leerDeDisco(int posicion);
    void listado_compras();

};
int crearIdXCompras();
#endif // COMPRAS_H
