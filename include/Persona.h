#ifndef PERSONA_H
#define PERSONA_H


class Persona
{
    protected:
        char apenom[50];
        int nDoc;
        bool activo;
//        Fecha nacimiento;
       // Domicilio direccion;
    public:
        Persona();
        //~Persona();
        void cargarPersona();
        void mostrarPersona();
        void setApenom();
        void setNDoc();
        void setNacimiento();
        void setDomicilio();
        const char * getApenom();
        int getNDoc();
//        Fecha getNacimiento();
//        Direccion getDomicilio();
};

#endif // PERSONA_H
