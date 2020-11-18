#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"
#include "Contable.h"
#include "DetalleCompra.h"
#include "DetalleVenta.h"
using namespace rlutil;
    ///setters
    void Contable::setOperacion(int _tipo){  this->operacion =_tipo;}
    void Contable::setNroFact(int _nFac){ this->nroFact = _nFac;}
    void Contable::setNroCta(int _nCta){ this->nroCta= _nCta;}
    void Contable::setDebe(float _debe){ this->debe = _debe; }
    void Contable::setHaber(float _haber){ this->haber= _haber;}
    void Contable::setSaldo(float _saldo){ this->saldo= _saldo;}
    void Contable::setSaldoAnterior(){
        Contable reg;
        this->saldoAnterior=0;
        int bytes, cant=0;
        FILE *p = fopen(FILE_MOVIMIENTOS, "rb");
        if (p == NULL){ return ; }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        cant = bytes / sizeof(Contable);
        reg.leerDeDisco(cant-1);
        if(cant>0){
            this->saldoAnterior=reg.getSaldo();
        }
        fclose(p);
        return;
    }
    void Contable::setFechaDesde(){}
    void Contable::setFechaHasta(){}

    ///getters
    int  Contable::getOperacion(){  return operacion;}
    int  Contable::getNroFact(){ return nroFact;}
    int  Contable::getNroCta(){ return nroCta;}
    float   Contable::getDebe(){return debe;}
    float   Contable::getHaber(){return haber;}
    float   Contable::getSaldo(){return saldo;}
    float   Contable::getSaldoAnterior(){return saldoAnterior;}

    Fecha Contable::getFechaDesde(){}
    Fecha Contable::getFechaHasta(){}

    ///funciones
    void Contable::imputarCta(  int _nroFactura, int _cant,  int _tipoOp, int _idProd ){


            calculadora calc;
            Producto prod;
            prod.buscarProdxId(_idProd);
             //-------**si es Ventas realizamos las imputaciones de vtas.**------
            if(_tipoOp==1){///ESTO HAY Q SIMPLIFICARLO CON LOS BOOLEANOS.

                //-----**seteo valores para usar desde cacluladora **------
                ///Revisar si no conviene usar un destructors
                    calc.setExtraeIva(prod.getIva());///Valores a ingrear :10.5, 21
                    calc.setImporteBruto(prod.getPrecioCosto());///Importe con iva incluido-
                    calc.setImponible(_cant);/// Vende X cant de articulos y va el precio bruto
                    calc.setDescuento(0);/// Descuento d euna venta por pago en efectivo
                    calc.setDescuentoAplicado();///Aplica el descuento
                    calc.setImpuesto(prod.getIva());///iva a calcular
                    calc.setImpuestoAplicado();///aplica el impuesto



                //-----**Fin del seteo de valores  **------

                //----------** imputación en Debe la salida de mercaderia **---------
                    setSaldoAnterior();
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(_tipoOp);
                    setNroFact(_nroFactura);
                     setNroCta(405); ///REVISAR CUENTA DE GANANCIAS EN EL PLAN
                    setDebe(0.00);
                    setHaber(calc.getImponible());
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());

                        //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe la salida de mercaderia **---------

                //----------** imputación en Debe el IVA debito fiscal **---------
                    setSaldoAnterior();
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(_tipoOp);
                    setNroFact(_nroFactura);
                    setNroCta(201);
                    setDebe(0.00);
                    setHaber(calc.getImpuesto());
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());

                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe el IVA debito fiscal **---------

                 //----------** Imputación en Haber la cuenta CAJA A+ **---------
                    setSaldoAnterior();
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(_tipoOp);
                   setNroFact(_nroFactura);
                    setNroCta(102);
                    setDebe(calc.getImpuestoAplicado());
                    setHaber(0.00);
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());

                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de Imputación  en Haber la cuenta CAJA A+**---------

            }
//        listarMovimientos();


            if(_tipoOp==2){
                 //-----**seteo valores para usar desde cacluladora **------
                ///Revisar si no conviene usar un destructors
                    calc.setExtraeIva(prod.getIva());///Valores a ingrear :10.5, 21
                    calc.setImporteBruto(prod.getPrecioCosto());///Importe con iva incluido-
                    calc.setImponible(_cant);/// Vende X cant de articulos y va el precio bruto
                    calc.setDescuento(0);/// Descuento d euna venta por pago en efectivo
                    calc.setDescuentoAplicado();///Aplica el descuento
                    calc.setImpuesto(prod.getIva());///iva a calcular
                    calc.setImpuestoAplicado();///aplica el impuesto



                //-----**Fin del seteo de valores  **------

                //----------** imputación en Debe la salida de mercaderia **---------
                setSaldoAnterior();
                    ///setFechaDesde(deComp.getFecha()),
                    setOperacion(_tipoOp);
                    setNroFact(_nroFactura);
                    setNroCta(102);
                    setDebe(0.00);
                    setHaber(calc.getImpuestoAplicado());///DEBITAMOS CAJA POR LA COMPRA
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());
                        //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe la salida de mercaderia **---------

                //----------** imputación en Debe el IVA debito fiscal **---------
                setSaldoAnterior();
                    ///setFechaDesde(deComp.getFecha()),
                    setOperacion(_tipoOp);
                    setNroFact(_nroFactura);
                    setNroCta(204);
                    setDebe(calc.getImpuesto());///CARGAMOS IVA CREDITO FISCAL
                    setHaber(0.00);
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());

                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe el IVA debito fiscal **---------

                 //----------** Imputación en Haber la cuenta CAJA A+ **---------
                 setSaldoAnterior();
                    ///setFechaDesde(deComp.getFecha()),
                    setOperacion(_tipoOp);
                    setNroFact(_nroFactura);
                    setNroCta(501); ///IMPUTAMOS A CTA DE GASTOS POR COMPRAS DE MERCA
                    setDebe(calc.getImponible());
                    setHaber(0.00);
                    setSaldo(getSaldoAnterior()-getHaber()+getDebe());

                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de Imputación  en Haber la cuenta CAJA A+**---------

            }

        }///recibe parametros
    bool Contable::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_MOVIMIENTOS, "rb");
        if (p == NULL){return false;}
        fseek(p, posicion * sizeof(Contable), 0);
        leyo = fread(this, sizeof(Contable), 1, p);
        fclose(p);
        return leyo;
    }
    bool Contable::grabarEnDisco(){
        FILE *p;
        bool chequeo;
        p = fopen(FILE_MOVIMIENTOS,"ab");
        if(p==NULL){return false;}
        chequeo = fwrite(this, sizeof(Contable),1,p);
        if(chequeo==1){
            fclose(p);
            return true;
        }else{
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);
            system("pause");
            return false;
        }
   }///graba la imputacion linea por linea con "rb+"
    void Contable::listarMovimientos(){
        Contable mov;
        int i = 0;
        cls();
        title("MAESTRO DE MOVIMIENTOS ",WHITE, RED);
        cout<<endl;
        setBackgroundColor(DARKGREY);
        cout<<" "<<setw(15)<<centrar("Fecha", 15)<<"|";
        cout<<" "<<setw(15)<<centrar("Operacion", 15)<<"|";
        cout<<" "<<setw(10)<<centrar("Cuenta", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("#Documento", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("Debe", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("Haber", 10)<<"|";
        cout<<" "<<setw(15)<<centrar("Saldo", 15)<<"|";
        cout<<" "<<setw(15)<<centrar("S. Anterior", 15)<<"|"<<endl;
        setBackgroundColor(BLACK);

        while (mov.leerDeDisco(i++)){

        cout<<" "<<setw(16)<<centrar("11/11/2015", 16);
        cout<<" "; if(mov.getOperacion()==1){cout<<setw(15)<<centrar("Venta",15);}else{cout<<setw(15)<<centrar("Compra",15);}
        cout<<" "<<setw(11)<<centrarInt(mov.getNroCta(),11);
        cout<<" "<<setw(11)<<centrarInt(mov.getNroFact(),11);
        cout<<right;
        cout<<setfill(' ');
        cout<<" "<<setw(11)<<mov.getDebe();
        cout<<" "<<setw(11)<<mov.getHaber();
        cout<<" "<<setw(16)<<mov.getSaldoAnterior()-mov.getHaber()+mov.getDebe();
        cout<<" "<<setw(16)<<mov.getSaldoAnterior()<<endl;
         }
        cout<<"|"<<setw(85)<<setfill(' ')<<"|"<<endl;
        system("pause");
    }
    void Contable::listarLibroDiario(){}///lista todas las cuentas  de una fecha determinada
    void Contable::listarLibroMayor(int cta){
       Contable mov;
       float aux=0;
        int i = 0;
        cls();
        title("MAESTRO DE MAYOR DE UNA CTA ",WHITE, RED);
        cout<<endl;
        setBackgroundColor(DARKGREY);
        cout<<" "<<setw(15)<<centrar("Fecha", 15)<<"|";
        cout<<" "<<setw(15)<<centrar("Operacion", 15)<<"|";
        cout<<" "<<setw(10)<<centrar("Cuenta", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("#Documento", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("Debe", 10)<<"|";
        cout<<" "<<setw(10)<<centrar("Haber", 10)<<"|";
        cout<<" "<<setw(15)<<centrar("Saldo", 15)<<"|"<<endl;
        setBackgroundColor(BLACK);

        while (mov.leerDeDisco(i++)){
        if(mov.getNroCta()==cta){
        cout<<" "<<setw(16)<<centrar("11/11/2015", 16);
        cout<<" "; if(mov.getOperacion()==1){cout<<setw(15)<<centrar("Venta",15);}else{cout<<setw(15)<<centrar("Compra",15);}
        cout<<" "<<setw(11)<<centrarInt(mov.getNroCta(),11);
        cout<<" "<<setw(11)<<centrarInt(mov.getNroFact(),11);
        cout<<right;
        cout<<setfill(' ');
        cout<<" "<<setw(11)<<mov.getDebe();
        cout<<" "<<setw(11)<<mov.getHaber();
        cout<<" "<<setw(16)<<mov.getDebe()-mov.getHaber()<<endl;
            aux+=mov.getDebe()-mov.getHaber();
         }
         }
         cout<<endl;
         cout<<endl;
        cout<<" "<<setw(75)<<setfill(' ')<<"Mayor de la cuenta numero :"<< cta <<" Saldo $" <<aux<<" ";
        cout<<endl<<endl;
        cout<<endl<<endl;
        system("pause");
    }
