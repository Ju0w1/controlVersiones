#ifndef VERSIONES_H
#define VERSIONES_H
#include <string>
#define MAX_CHAR 50
/*========Estructuras========*/
enum retorno{
	OK, ERROR, NO_IMPLEMENTADA
};

struct archivo{
	char* name;
	struct linea *lineas;
};

struct linea{
	char* contenido;
	int numero_linea;
	linea* siguiente;
};

/*========TypeDef========*/
typedef enum retorno TipoRet;
typedef archivo* Archivo;
typedef linea* Linea;
typedef char* Cadena;



/*========Definicion de funciones o procedimientos========*/
void menu();
void lecturaComando(Cadena, Archivo &, Linea &);
Archivo crearArchivo(Cadena);								// Crea el archivo.
Linea crearLinea(Cadena,int); 								// Crea las lineas para el archivo.
Linea cima(Linea);
void apilar(Linea &, Linea);
Linea desapilarLinea(Linea&);
TipoRet insertarLinea(Archivo&,Cadena,Cadena,int, Cadena); 	//Insertar Linea.
TipoRet mostrarTexto(Archivo, Cadena, Cadena); 				// Muestra el texto del archivo.
TipoRet borrarArchivo(Archivo &); 							// Borra el archivo.
TipoRet borrarLinea(Archivo &, Cadena,int, Cadena); 		// Borra el número de la linea que se indique.
void tipoRetorno(TipoRet);
#endif
