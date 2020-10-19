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

	Cliente cliente1;

	cliente1.cargarCliente();
	cliente1.mostrarCliente();

    return 0;
}
