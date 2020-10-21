#ifndef CLIENTE_H
#define CLIENTE_H

#include "../Include/Persona.h"



class Cliente: public Persona{

	private:
        char razonSocial[50];
        char mail[50];
        int tipoCliente;
        int idCliente;
	public:
		Cliente();
		Cliente(char*, char*, int);
		//virtual ~Cliente();
		void cargarCliente();
		void mostrarCliente();
        void setRazonSocial(char *);
        void setMail(char *);
        void setTipoCliente();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        const char* getRazonSocial(){return this->razonSocial;}
        const char* getMail(){return this->mail;}
        int getTipo(){return this->tipoCliente;}
        int getIdCliente(){return this->idCliente;}

};

void listarClientePorID(); /// Lista un cliente por un id que pregunta dentro de la funcion

int crearIdClientes(); /// Crea un id autonumerico para el cliente

void listarClientes(); /// Lista todos los clientes del archivo

#endif // CLIENTE_H
