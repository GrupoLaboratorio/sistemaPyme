#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
    private:
        int id,codProv,planCta,stock,stockMin;
        float precioCosto,iva;
        bool estado;
        char descripcion[50];
    public:
        void cargarProducto();

        ///SETTERS
        int setId();
        void setCodProv();
        void setDescripcion();
        void setPlanCta();
        void setStock();
        void setPrecioCosto();
        void setIva();
        void setStockMin();
        void setEstado();

        ///DEVUELVEN:
        int getId();
        int getCodProv();
        char* getDescripcion();
        int getPlanCta();
        int getStock();
        float getPrecioCosto();
        float getIva();
        int getStockMin();
        bool getEstado();
        Producto getProducto(int idProd);/// Devuelve un producto producto recibiendo su id como parametro.


        bool grabarEnDisco();///GRABA EN UN ARCHIVO UN REGISTRO DE TIPO PRODUCTO **HECHA**
        bool leerDeDisco(int posicion);///Lee de disco un producto cuya posicion se pasa como parámetro **HECHA
        void mostrarProducto();///muestra un producto
        int buscarProdxId(int idAux);///DEVUELVE LA POSICION DE UN PRODUCTO POR ID QUE ES PASADO COMO PARAMETRO **HECHA

};

#endif // PRODUCTO_H
