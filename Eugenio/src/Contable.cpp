
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#include "Contable.h"
#include "DetalleCompra.h"
#include "DetalleVenta.h"

        ///setters
        void Contable::setOperacion(int _tipo){ this-> operacion=_tipo;}
        void Contable::setNroFact(int _nFac){ this->nroFact=_nFac;}
        void Contable::setNroCta(int _nCta){ this->nroCta=_nCta;}
        void Contable::setDebe(float _debe){ this->debe = _debe; }
        void Contable::setHaber(float _haber){ this->haber= _haber;}
        void Contable::setSaldo(float _saldo){ this->saldo= _saldo;}
        void Contable::setFechaDesde(){}
        void Contable::setFechaHasta(){}

        ///getters
        int  Contable::getOperacion(){}
        int  Contable::getNroFact(){}
        int  Contable::getNroCta(){}
        float   Contable::getDebe(){return debe;}
        float   Contable::getHaber(){return haber;}
        float   Contable::getSaldo(){return saldo;}
        Fecha Contable::getFechaDesde(){}
        Fecha Contable::getFechaHasta(){}

        ///funciones
//        void Contable::imputarCta( int _pos, Fecha _fecha, int _cta, bool _deb, bool _hab, float _importe ){
        void Contable::imputarCta(  int _pos, int _cant,  int _tipoOp, int _idProd ){
            bool _deb;
            bool _hab;
            calculadora calc;
            Producto prod;
            prod.buscarProdxId(_idProd);

            DetalleCompra deComp;
            DetalleVenta deVtas;
            deVtas.leerDeDiscoD(_pos-1);

             //-------**si es Ventas realizamos las imputaciones de vtas.**------
            if(_tipoOp==1){

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
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(1);
                    setNroFact(deVtas.getNroFactura());
                    setNroCta(501);
                    setDebe(0.00);
                    setHaber(calc.getImponible());
                    setSaldo(getDebe()-getHaber());
                        //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe la salida de mercaderia **---------

                //----------** imputación en Debe el IVA debito fiscal **---------
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(1);
                    setNroFact(deVtas.getNroFactura());
                    setNroCta(201);
                    setDebe(0.00);
                    setHaber(calc.getImpuesto());
                    setSaldo(getDebe()-getHaber());
                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de imputación en Debe el IVA debito fiscal **---------

                 //----------** Imputación en Haber la cuenta CAJA A+ **---------
                    ///setFechaDesde(deVtas.getFecha()),
                    setOperacion(1);
                    setNroFact(deVtas.getNroFactura());
                    setNroCta(101);
                    setDebe(calc.getImpuestoAplicado());
                    setHaber(0.00);
                    setSaldo(getDebe()-getHaber());
                    //------**grabamos el registro en disco**------
                            grabarEnDisco();

                //----------** Fin de Imputación  en Haber la cuenta CAJA A+**---------

            }

            if(_tipoOp==2){

            }

        }///recibe parametros

    bool Contable::grabarEnDisco(){

        //    system("cls");
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


        void Contable::listarLibroDiario(){
            calculadora cal;
            DetalleVenta  detVta;
            int i=0;
            while(detVta.leerDeDiscoD(i++)){
                     setDebe(detVta.getPrecio());
                     setHaber(0);
                     setSaldo( getHaber() - getDebe());
                    cout<<"DEBE: "<<getDebe()<<endl;
                    cout<<"HABER: "<<getHaber()<<endl;
                    cout<<"SALDO: "<<getSaldo()<<endl;
            }

        }///lista todas las cuentas  de una fecha determinada
        void Contable::listarLibroMayor(Fecha, Fecha, int){}
