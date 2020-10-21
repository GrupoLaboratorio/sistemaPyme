#include <iostream>
#include <iomanip>
#include "Utilidades/menus.h"
#include "Include/Persona.h"
#include "Utilidades/validaciones.h"
#include "Direccion.h"
#include "Include/Cliente.h"
#include "Include/Ventas.h"

using namespace std;

int main(){

	Ventas ventaUno;
	//menuPrincipal();

	ventaUno.CargarVtas();
	ventaUno.MostrarVtas();


    return 0;
}
