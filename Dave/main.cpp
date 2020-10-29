#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
using namespace std;
#include "Utilidades/menus.h"
#include "Include/Persona.h"
#include "Utilidades/validaciones.h"
#include "Direccion.h"
#include "Include/Entidad.h"
#include "Include/Ventas.h"
#include "DetalleFactura.h"
#include "Ususario.h"
#include "Login.h"
#include "DetalleCompra.h"
#include "Include/Producto.h"
#include "Include/Productos.h"

int main()
{

    ///TEST DE PRODUCTOS
Productos obj;
obj.listarProdXIdProv(4);
/*
///test de entidades
Entidad ent;
//ent.cargarProveedor();
//ent.grabarEnDisco(2);
ent.listarEntidadesTabla(2);
///fin test entidades
/*
///test detalleCompra
    DetalleCompra obj;
    obj.setProveedor();
    cout<<endl;
    obj.setIdProveedor();
///Fin test detallecompras

///Menu
    menuPrincipal();*/
    return 0;
}
