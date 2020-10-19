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
        void setApenom(char * ape_nom){strcpy(apenom, ape_nom);}
        void setNDoc();
        void setNDoc(int _nDoc){this->nDoc = _nDoc;}
        void setNacimiento();
        void setDomicilio();
        const char * getApenom(){return this->apenom;}
        int getNDoc(){return this->nDoc;}
        Fecha getNacimiento(){return this->fecNac;}
        Direccion getDomicilio(){return this->domicilio;}

};

#endif // PERSONA_H
