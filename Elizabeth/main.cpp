#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;
#include "Utilidades/menus.h"
#include "Utilidades/ui.h"
#include "Utilidades/rlutil.h"
#include "Include/Entidad.h"
#include "Include/Compra.h"
#include "Include/DetalleFactura.h"
#include "Include/Ventas.h"
//#include "../Include/Login.h"
using namespace rlutil;
int main(){
//       Producto obj;
//       obj.cargarProducto();
//       obj.getProducto();
       Ventas obj2 ;
//        cout<<obj2.fecha.getDia();
////     obj.setIdVenta();
////     cout <<obj.getIdVenta();
     obj2.cargarVtas();
     obj2.leerDeDisco(0) ;
//    listarVentas();
    return 0;
}
