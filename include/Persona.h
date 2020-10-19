#ifndef PERSONA_H
#define PERSONA_H

#include "Direccion.h"
#include "Fecha.h"

class Persona{

    protected:
        char apenom[50];
        int nDoc;
        bool activo;
        Fecha fecNac;
        Direccion domicilio;
    public:
        Persona();
        //~Persona();
        void cargarPersona();
        void mostrarPersona();
        void setApenom();
        void setNDoc();
        void setNacimiento();
        void setDomicilio();
        const char * getApenom(){return this->apenom;}
        int getNDoc(){return this->nDoc;}
//        Fecha getNacimiento();
//        Direccion getDomicilio();
};

#endif // PERSONA_H
