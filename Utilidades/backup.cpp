//#include <iostream>
//#include <ctime>
//#include <string.h>
//using namespace std;
//#include "ui.h"
//#include "rlutil.h"
//using namespace rlutil;
//
//#include "Entidad.h"
//#include "Ventas.h"
//#include "Compras.h"
//#include "DetalleVenta.h"
//#include "DetalleFactura.h"
//#include "DetalleCompra.h"
//#include "Producto.h"
//#include "Productos.h"
//
////const char * FILE_PROVEEDORES = "Archivos/Proveedores.dat";
////const char * FILE_CLIENTES = "Archivos/Clientes.dat";
////const char * FILE_DETALLE="Archivos/DetalleVentas.dat" ;
////const char * FILE_VENTAS = "Archivos/Ventas.dat";
////const char * FILE_COMPRAS="Archivos/Compras.dat";
////const char * FILE_PRODUCTOS = "Archivos/Productos.dat";
////const char * FILE_DET_COMPRAS="Archivos/DetalleCompras.dat";
//
//
//void backupArchivos(int opcion){
//
//	   title("BACKUP", WHITE, CYAN);
//       switch(opcion){
//		case 1:
//			CopyFile(FILE_PROVEEDORES,"Backup/Proveedores.bkp" , FALSE);
//			break;
//		case 2:
//			CopyFile(FILE_CLIENTES,"Backup/Clientes.bkp", FALSE);//			break;
//		case 3:
//			CopyFile(FILE_DETALLE,"Backup/DetalleVentas.bkp", FALSE);
//			CopyFile(FILE_VENTAS,"Backup/Ventas.bkp", FALSE);
//			break;
//		case 4:
//			CopyFile(FILE_DET_COMPRAS,"Backup/DetalleCompras.bkp", FALSE);
//			CopyFile(FILE_COMPRAS,"Backup/Compras.bkp", FALSE);//			break;
//		case 5:
//			CopyFile(FILE_PRODUCTOS,"Backup/Productos.bkp", FALSE);
//			CopyFile(FILE_PRODUCTOS,"Backup/Productos.bkp", FALSE);
//			break;
//		case 6:
//			cout << "Plan de cuentas";
//			break;
//
//       }
//
//	return;
//}

//void  restaurarCopia(){
//        int opcion;
//      title("RESTAURAR COPIA DE SEGURIDAD DE COPIA A ARCHIVOS",BLACK,CYAN);
//       gotoxy(1,3);
//      cout<<"1. RESTAURAR COPIA"<<endl;
//      cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
//      cin>>opcion;
//      if(opcion==1){
//        CopyFile( "archivos/Entrenamientos.bkp", "archivos/Entrenamientos.dat", FALSE);
//        CopyFile("archivos/usuarios.bkp", "archivos/usuarios.dat",  FALSE);
//        cout<<"\n\t\t\tse realizo la restauracion  de  la copia de seguridad correctamente"<<endl;
//        system("PAUSE");
//      }else{
//          menu();
//      }
//
//        }
