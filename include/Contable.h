#ifndef CONTABLE_H
#define CONTABLE_H
#include "Fecha.h"
#include "Calculadora.h"

class Contable
{
    private:
        int operacion, nroCta;
        float debe, haber, saldo;
        Fecha f;
    public:

        ///setters
        void setOperacion(int);
        void setNroCta(int);
        void  setDebe(float);
        void  setHaber(float);
        void  setSaldo(float);
        void setFechaDesde();
        void setFechaHasta();

        ///getters
        int getOperacion();
        int gettNroCta();
        float  getDebe();
        float  getHaber();
        float  getSaldo();
        Fecha getFechaDesde();
        Fecha getFechaHasta();

        ///funciones
        void imputarCta(Fecha, int, bool, bool, float );///recibe parametros
        void grabarEnDisco();///graba la imputacion linea por linea con "rb+"
        void listarLibroDiario();///lista todas las cuentas  de una fecha determinada
        void listarLibroMayor(Fecha, Fecha, int);  ///de  un determinado mes y una determinada cuenta contable.
};

#endif // CONTABLE_H
