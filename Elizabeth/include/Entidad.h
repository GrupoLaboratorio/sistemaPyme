#ifndef Entidad_H
#define Entidad_H

#include "../Include/Persona.h"



class Entidad: public Persona{

	private:
        char mail[50];
        int tipoEntidad; /// -> diferencia a clientes de proveedores
        char razonSocial[50];
        char cuit[13];
    public:
         int idEntidad;
		Entidad();
		Entidad(char*, char*, int);
		//virtual ~Entidad();
		void cargarCliente();
		void cargarProveedor();
		void mostrarEntidad();
        void setRazonSocial(char *);
        void setMail(char *);
        void setTipoEntidad(int);
        bool grabarEnDisco(int);
        bool leerDeDisco(int, int);
        const char* getRazonSocial(){return this->razonSocial;}
        const char* getMail(){return this->mail;}
        int getTipoEntidad(){return this->tipoEntidad;}
        int getIdEntidad(){return this->idEntidad;}
        void listarEntidadesTabla(int); /// Lista todos los Entidads del archivo
        Entidad buscarRazonSocial(int);


};

void listarEntidadPorID(int); /// Lista un Entidad por un id que pregunta dentro de la funcion

int crearIdEntidades(int); /// Crea un id autonumerico para el Entidad

void listarEntidades(int); /// Lista todos los Entidads del archivo
#endif // Entidad_H
