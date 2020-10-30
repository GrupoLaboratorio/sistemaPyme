#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include "../Include/Producto.h"

using namespace std;

///ESTADO: CONTINUAR HACIENDO QUE LEA UN ARCHIVO DE PRODUCTOS QUE SERIA EL REGISTRO GENERAL DE PRODUCTOS.

const char * FILE_PRODUCTOS = "Archivos/Productos.dat";

   /*Producto::Producto(int cero,const char* nada){
        id=codProv=planCta=stock=stockMin=precioCosto=iva=cero;
        estado=cero;
        strcpy(descripcion,nada);
    }*/
    ///SETTERS
    void Producto::cargarProducto(){
        id=setId();
        getId();
        setCodProv();
        setStock();
        setDescripcion();
        setPlanCta();
        setPrecioCosto();
        setIva();
        setStockMin();
        setEstado();
        mostrarProducto();

        if(grabarEnDisco()==true){
            cout<<"Producto cargado con exito!";

        }else{
            cout<<"Error al guardar el Producto!";
            system("PAUSE");
            }
    }
    int Producto::setId(){
        int bytes, cant;
        FILE *p = fopen(FILE_PRODUCTOS, "rb");
        if (p == NULL){
            return 1;   ///dado que es el primer registro y no existe el archivo forzamos en nro 1
        }
        fseek(p, 0, SEEK_END);
        bytes = ftell(p);
        fclose(p);
        cant = bytes / sizeof(Producto);
        return cant+1;
    }
    void Producto::setCodProv(){
        cout<<"\nCodigo de Proveedor: ";
        cin>>codProv;
    }
    void Producto::setStock(){
        cout<<"\nIngresar el stock: ";
        cin>>stock;
    }
    void Producto::setDescripcion(){
        cin.ignore();
        cout<<"\nDescripcion: ";
        cin.getline(descripcion,50);
    }
    void Producto::setPlanCta(){
        cout<<"\nPlan de Cuenta: ";
        cin>>planCta;
    }
    void Producto::setPrecioCosto(){
        cout<<"\nPrecio: ";
        cin>>precioCosto;
    }
    void Producto::setIva(){
        cout<<"\nIva: ";
        cin>>iva;
    }
    void Producto::setStockMin(){
        cout<<"\nStock minimo: ";
        cin>>stockMin;
    }
    void Producto::setEstado(){
        int opc;
        cout<<"Elija la opcion correspondiente"<<endl;
        cout<<"1-ACTIVO \n2-INACTIVO"<<endl;
        cout<<"\nOpcion: ";
        cin>>opc;

        switch(opc){
    case 1:
        estado=true;
        break;
    case 2:
        estado=false;
        break;
    default:
        cout<<"Opcion invalida";
        break;
        }
    }
    ///DISCO
    bool Producto::grabarEnDisco(){

        system("cls");
        FILE *p;
        bool chequeo;

        p = fopen(FILE_PRODUCTOS,"ab");
        if(p==NULL){
            cout << "Error al abrir el archivo \n";
            return false;
        }
        chequeo = fwrite(this, sizeof(Producto),1,p);
        if(chequeo==1){

            //msj("Carga exitosa",WHITE,GREEN,130,TEXT_LEFT);
            //cout << "Registro exitoso";
            fclose(p);
            //system("pause");
            return true;
        }
        else{
            //cout << "El registro no pudo guardarse \n\n";
            fclose(p);
            //system("pause");
            return false;
        }
    }
    bool Producto::leerDeDisco(int posicion){
        bool leyo;
        FILE *p;
        p = fopen(FILE_PRODUCTOS, "rb");
        if (p == NULL){
            return false;
        }
        fseek(p, posicion * sizeof*this, 0);
        leyo = fread(this, sizeof(Producto), 1, p);
        fclose(p);
        //getProducto();
        return leyo;
    }
    ///GETTERS
    int Producto::getId(){
        return this->id;
    }
    int Producto::getCodProv(){
        return this->codProv;
    }
    char* Producto::getDescripcion(){
        return this->descripcion;
    }
    int Producto::getPlanCta(){
        return this->planCta;
    }
    int Producto::getStock(){
        return this->stock;
    }
    float Producto::getPrecioCosto(){
        return this->precioCosto;
    }
    float Producto::getIva(){
        return this->iva;
    }
    int Producto::getStockMin(){
        return this->stockMin;
    }
    bool Producto::getEstado(){
        return this->estado;
    }
    /*Producto Producto::getProducto(){/// FALTA!



    }*/

    void Producto::mostrarProducto(){
        cout<<getId()<<endl;
        cout<<getCodProv()<<endl;
        cout<<getDescripcion()<<endl;
        cout<<getPlanCta()<<endl;
        cout<<getStock()<<endl;
        cout<<getPrecioCosto()<<endl;
        cout<<getIva()<<endl;
        cout<<getStockMin()<<endl;
        cout<<getEstado()<<endl;
        system("PAUSE");
    }
    int Producto::buscarProdxId(int idAux){
        int contador=0;
        FILE *p;

        p = fopen(FILE_PRODUCTOS,"rb");

        if(p==NULL){
            return -1;///codigo de error de que no hall� el archivo.
        }
        while(fread(this, sizeof(Producto),1, p)==1){
            if(id == idAux){
                fclose(p);
                return contador;
            }
            contador++;
        }
        fclose(p);
        return -2;///codigo de error de rutina inexistente.

}
