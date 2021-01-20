# Sistema de administración contable para PYMEs
TP LAB 2 2020 UTN FRGP

**[Integrantes:]**
------------------------------
**AREVALO, R. Eugenio**

**AROSTEGUI, Isidoro**

**AYALA, Elizabeth C.**

**QUINTEROS, David**

VIDEO PRESENTACION
-------------------
*Video:*
<a href="https://youtu.be/KXJ7ZKgU1tY">https://youtu.be/KXJ7ZKgU1tY</a>

------------------------------

INTRODUCCION
------------
El sistema a desarrollar permitirá simular la administración contable de una Pyme. Contará con un menú principal y una serie de submenúes que serán la interfaz grafica
para la gestión de contabilidad , compras, ventas y stock.
*Menues:*
!["Menues"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/menus.png?raw=true "Libro Diario")

CONTABILIDAD
------------
El objetivo principal del programa es llevar a cabo el registro contable de la empresa. Se registrarán mediante asientos automaticos y manuales, utilizando un pseudo “Plan de Cuentas”, permitiendo clasificar las cuentas para poder ser registradas en el debe y haber del archivo de movimientos contables, es decir, indicará si la operación proviene del
sistema de compras o de ventas, asientos manuales, u otra operación. Calculará, además descuentos, recargos e impuestos del 10,5%, 21% según corresponda. Por otro lado, estos
impuestos se verán reflejados tanto en facturas A en forma discriminadas y en el tipo B en el total final.
*Libro Diario:*
!["Libro Diario"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/libro%20diario1.JPG?raw=true "Libro Diario")

ENTIDADES
------------
La clase Entidad contendrá datos de los CLientes y Proveedores distinguiendolos con un campo TipoEntidad, y utilizaría un unico archivo para donde guardar los datos. 

*Entidades:*
!["Entidades"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/entdidades.JPG?raw=true )

COMPRAS
------------
El sistema registrará las operaciones que impliquen la adquisición de bienes y/o servicios, imputados mediante el código de proveedor y discriminando los ítems de
la FC según corresponda, impactará en el listado de productos para el sistema de stock y resolverá los asientos automaticamente bajo la imputacion COMPRAS

*Compras:*
!["Compras"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/productos.JPG?raw=true )

VENTAS
------------
Este módulo de ventas será para personas juridicas y fisicas, responsables inscriptos y consumidores finales, por lo tanto, en la gestión de ventas se emitirán facturas del tipo A y B. La factura A detallará el CUIT del comprador, nombre y apellido o razón social y discriminando el Impuesto del Valor Agregado, y resolverá los asientos automaticamente bajo la imputacion VENTAS
entre otros.

*Facturas y Detalle:*
!["Facturas y Detalle"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/detalleweb.png?raw=true "Detalle de facturas y facturas")


STOCK - PRODUCTOS
------------
Este sistema presentará un modelo de stock basado en el archivos de Productos, del cual podremos listar todos los productos de un proveedor, como asi también realizar reportes de productos con el stock minimo afectado, de manera que se pueda emitir una orden de compras.
*Sotck:*
!["Prodcutos"](https://github.com/reugenioarevalo/proyecto_gestion/blob/master/readme/productos.JPG?raw=true )


MODULOS
------------
Contaría con los siguientes módulos estimativos

CONTABILIDAD
------------
- Libro Mayor de una Cuenta
- Libro Diario
- Asientos Manuales
- Sumas y saldos
- Cierre de caja
- Apertura de caja


VENTAS
------------
- Registro de Ventas
- Emisión de comprobante


COMPRAS
------------
- Orden de compras
- Pagos a proveedores


STOCK/PRODUCTOS
------------
- Inventario
- Carga de almacén


