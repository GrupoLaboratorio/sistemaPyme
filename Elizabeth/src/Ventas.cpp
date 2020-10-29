#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
using namespace std;
#include "Ventas.h"
#include "Fecha.h"
#include "DetalleFactura.h"
#include "Calculadora.h"
#include "Producto.h"
#include "../Utilidades/centrarTabla.h"
#include "../Utilidades/ui.h"
#include "../Utilidades/rlutil.h"


const char * FILE_VENTAS = "Archivos/Ventas.dat";
const char * FILE_FACTURAA = "Archivos/FacturaA.dat";
const char * FILE_FACTURAB = "Archivos/FacturaB.dat";

///----------------------------METODOS CLASE VENTAS---------------------------
Ventas::Ventas()
{
    idVenta=0;
    idCliente=0;
}

void Ventas::cargarVtas()
{
    int opc;
    int continuar=1;
    while(true)
    {
        system("cls");
        cout<<"1 - Consultar el precio de un producto : "<<endl;
        cout<<"2 - Venta : "<<endl;
        cout<<"0 -  Finalizar : "<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            int codigo;
            cout<<"Ingrese codigo producto : ";
            cin>>codigo;
            prod.buscarProdxId(codigo);
            prod.getProducto();
            system("pause");
            break;
        case 2:
            setIdVenta();
            setTipoFact();
            setNroFact();
            grabarEnDisco() ;
          do{
            cout<<"Ingrese codigo producto : ";
            cin>>codigo;
            prod.buscarProdxId(codigo);
            prod.getPrecioCosto();
            prod.setStock();
            prod.getStock();
            // dato.guardarEnDiscoDetalle(idVenta);
            system("pause");
           cout<<"Comprar otro producto :    1- si , 0 - no " ;
           cin>> continuar;
            } while(continuar==1);
            break;
        case 0:
            return;
            break;
        default:
            cout<<"Opcion Incorrecta ";
            break;
        }
    }
}

void Ventas::finalVenta()
{
    int opc;
    system("cls");
    if(tipoFactura == 'A')
    {
        cout<<"Precio de costo: " <<550<<endl;
        cout<<"Impuesto aplicado : "<< 115.5<<endl;
        cout<<"Total a pagar : "<<665.5<<endl;
        cout<<"1- Abonar el total "<<endl ;
        cout<<"2- Modificar  venta "<<endl ;
        cin>>opc;

        if(opc == 1)
        {
            setOpcionPago();
            ///listado_facturas();    para imprimir la factura
        }
        else
        {
            if(opc==2)
            {
                ///modificar cantidad de un producto o dar de baja de la venta
            }
        }
    }
    else
    {
        if(tipoFactura == 'B')
        {
            cout<<"Total a pagar : "<<665.5<<endl;
            cout<<"1- Abonara el total "<<endl ;
            cout<<"2- Modificar venta "<<endl ;
            cin>>opc;

            if(opc == 1)
            {
                setOpcionPago();
                ///listado_facturas();    para imprimir la factura
            }
            else
            {
                if(opc==2)
                {
                    ///modificar cantidad de un producto o dar de baja de la venta
                }
            }
        }
    }
}

void Ventas::mostrarVtas(int posicion)
{
    cout<<"Fecha : "<<fecha.getDia()<<"-"<<fecha.getMes()<<endl;
    cout<<"Id de ventas : "<<getIdVenta()<<endl;
    cout<<"Id de cliente : "<<idCliente<<endl;
    cout<<"Tipo de factura" <<tipoFactura<<endl;
    cout<<"Numero de factura" <<nroFactura<<endl;
}


void Ventas::setIdVenta()
{
    this->idVenta=crearIdVentas();
}

int Ventas::getIdVenta()
{
    return idVenta;
}

void Ventas::setIdCliente(char tipo)
{

    if(tipo=='A')
    {
        cliente.buscarRazonSocial(1) ;
        this->idCliente=cliente.idEntidad;
    }
    else
    {
        if(tipo=='B')
        {
            return;
        }
    }
}

int Ventas::getIdCliente()
{
    return idCliente;
}


void Ventas::setTipoFact()
{
    char tipo;
    cout<<"Tipo de factura : ";
    cin>>tipo;
    while(!(tipo == 'A'  || tipo == 'B' ))
    {
        cout<<"Tipo de factura incorrecta";
        system("pause");
        system("cls");
        cout<<"Tipo de factura : ";
        cin>>tipo;
    }
    int crearIdXFact(tipo);
    setIdCliente(tipo);
    this ->tipoFactura=tipo;
}

char Ventas::getTipoFact()
{
    return tipoFactura;
}

void Ventas::setNroFact()
{
    this->nroFactura=crearIdXFact(tipoFactura) ;
}

int Ventas::getNroFact()
{
    return nroFactura;
}

void Ventas::setOpcionPago()
{
    int modo;
    float desc=0.1;
    system("cls");
    cout<<"Opciones de pago :"<<endl;
    cout<<"1- Efectivo "<<endl;
    cout<<" 2- Transferencia "<<endl ;
    cout<<" 3 - Tarjeta de credito "<<endl;
    cin>>modo;
    switch(modo)
    {
    case 1:
        this->modoPago=modo;
        cout<< "Descuento del 5%"<<endl;
        calculo.setDescuento(desc);
        calculo.getDescuentoAplicado();
        cout<< "Total a pagar : "<<598.95<<endl;
        break;

    case 2:
        this->modoPago=modo;
        cout<<"No posee descuentos ni recargos"<<endl;
        calculo.setTotlaImponible(5, 50);
        break;

    case 3:
        this->modoPago=modo;
        cout<<"Recargo del 0.05 "<<endl;
        ///calculo. Recargo o setDescuento?
        break;

    default:
        cout<<"Opcion de pago incorrecto ";
        break;
    }
}

int Ventas::getOpcionPago()
{
    return modoPago;
}

bool Ventas::grabarEnDisco()
{

    system("cls");
    FILE *p;
    bool chequeo;
    switch(getTipoFact())
    {
    case 'A'  :
        p = fopen(FILE_FACTURAA,"ab");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        break;
    case 'B' :
        p = fopen(FILE_FACTURAB,"ab");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        break;
    }
    chequeo = fwrite(this, sizeof(Ventas),1,p);
    if(chequeo==1)
    {

        cout<< "Carga exitosa";
        fclose(p);
        system("pause");
        return true;
    }
    else
    {
        cout << "El registro no pudo guardarse \n\n";
        fclose(p);
        system("pause");
        return false;

    }
}

bool Ventas::leerDeDisco(int posicion)
{
    FILE *p;
    bool chequeo;
    setTipoFact();
    switch(getTipoFact())
    {
    case 'A'  :
        p = fopen(FILE_FACTURAA,"rb");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        fseek(p,posicion*sizeof(Ventas),SEEK_SET);
        chequeo=fread(this, sizeof(Ventas),1,p);

        if( chequeo == 1)
        {
            mostrarVtas(posicion);
            fclose(p);

            system("pause");
            return true;
        }
        else
        {
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);

            system("pause");
            return false;
        }
        break;

    case 'B' :
        p = fopen(FILE_FACTURAB,"rb");
        if(p==NULL)
        {
            cout << "Error al abrir el archivo \n";
            return false;
        }
        fseek(p,posicion*sizeof(Ventas),SEEK_SET);
        chequeo=fread(this, sizeof(Ventas),1,p);

        if( chequeo == 1)
        {
            mostrarVtas(posicion);
            fclose(p);

            system("pause");
            return true;
        }
        else
        {
            cout << "El registro no pudo guardarse \n\n";
            fclose(p);

            system("pause");
            return false;
        }
        break;
    }
}


///--------------------------------------FUNCIONES GLOBALES------------------------------------

int crearIdVentas()
{
    int bytes, cant;
    FILE *p = fopen(FILE_VENTAS, "rb");
    if (p == NULL)
    {
        return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant=bytes / sizeof(Ventas);
    return cant+1;
}


int crearIdXFact(char tipo='B')
{
    int bytes, cant;

    if(tipo == 'A' || tipo == 'a')
    {
        FILE *p = fopen(FILE_FACTURAA, "rb");
        if (p == NULL)
        {
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);
    }
    else
    {
        FILE *p = fopen(FILE_FACTURAB, "rb");
        if (p == NULL)
        {
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);
    }
    cant = bytes / sizeof(Ventas);
    return cant+1;
}

void  listarVentas()
{
    int i=0;
    bool chequeo;
    Ventas reg;
    while(reg.leerDeDisco(i++))
    {
//          cout<<reg.getIdVenta()<<endl;
//         cout<< reg.getTipoFact()<<endl;
//          cout<<reg.getNroFact()<<endl;
    }
    return;
}
