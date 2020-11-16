#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
#include "Utilidades/menus.h"
#include "Include/Persona.h"
#include "Utilidades/validaciones.h"
#include "Direccion.h"
#include "Include/Entidad.h"
#include "Include/Ventas.h"
#include "DetalleFactura.h"
#include "Include/Usuario.h"
#include <vector>


int main(){
     vector <DetalleVenta> vect;
     for (int i=0; i<100;i++) {
       vect.push_back(i+10);
     }
     for (int i=0; i<vect.size();i++) {
        cout<<vect.at(i)<<endl;
     }

    //menuLogin();

    return 0;
}
