#include <iostream>
#include <iomanip>
#include "Utilidades/menus.h"
#include "Include/Persona.h"
#include "Utilidades/validaciones.h"
#include "Direccion.h"
#include "Cliente.h"

using namespace std;

int main(){

	//menuPrincipal();

	Persona persoUno;

	persoUno.cargarPersona();
	persoUno.mostrarPersona();

    return 0;
}
