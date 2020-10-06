#ifndef VERSIONES_H
#define VERSIONES_H
#include <string>

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
void preCrearArchivo(Archivo &, Linea &);
Archivo crearArchivo(Cadena, Linea &);// Crea el archivo.
Linea crearLinea(Cadena,int); // Crea las lineas para el archivo.
Linea cima(Linea);
Linea desapilarLinea(Linea&);
void insertarLinea(Linea&,Linea, Archivo &); //Apilar Linea
void mostrarTexto(Archivo); // Muestra el texto del archivo.
void borrarArchivo(Archivo); // Borra el archivo.
void borrarLinea(Archivo,int); // Borra el número de la linea que se 

#endif
