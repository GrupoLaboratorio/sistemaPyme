#ifndef CLIENTE_H
#define CLIENTE_H

#include "../Include/Persona.h"



class Cliente: public Persona{

	private:
        char razonSocial[50];
        char mail[50];
        int tipoCliente;
	public:
		Cliente();
		Cliente(char*, char*, int);
		//virtual ~Cliente();
		void cargarCliente();
		void mostrarCliente();
        void setRazonSocial(char *);
        void setMail(char *);
        void setTipoCliente(int);
        bool grabarEnDisco();
        //bool leerDeDisco(int);
        const char* getRazonSocial(){return this->razonSocial;}
        const char* getMail(){return this->mail;}
        int getTipoCliente(){return this->tipoCliente;}

};

#endif // CLIENTE_H