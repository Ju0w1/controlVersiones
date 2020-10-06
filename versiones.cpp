#ifndef VERSIONES_CPP
#define VERSIONES_CPP
#include "versiones.hpp"
#include<iostream>
#include <string>
#include <cstdio>
using namespace std;


/*========Menu========*/
void menu(){
	cout<<"CrearArchivo"<<endl;
	cout<<"InsertarLinea"<<endl;
	cout<<"MostrarTexto"<<endl;
	cout<<"BorrarArchivo"<<endl;
	cout<<"BorrarLinea"<<endl;
	cout<<"Salir"<<endl;
	
}
/*========LecturaComando========*/
void lecturaComando(Cadena cmd, Archivo &arch, Linea &pila){
	Cadena cmdc= new char[50];
	cmdc = strlwr(cmd);
	if(!strcmp(cmdc,"creararchivo")){
		preCrearArchivo(arch,pila);
	}
	if(!strcmp(cmdc,"creararchivo")){
		insertarLinea();
	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
}
/*========Archivo========*/
void preCrearArchivo(Archivo &arch, Linea &pila){
	Cadena nombre= new char[50];
	cout<<"Ingrese el nombre del archivo: "<<endl;
	gets(nombre);
	arch = crearArchivo(nombre,pila);
	cout<<arch->name<<endl;
}

Archivo crearArchivo(Cadena nombre, Linea &pila){
	Archivo arch = new archivo;
	if(arch){
		arch->name = nombre;
		arch->lineas = pila;
		return arch;
	}else{
		return NULL;
	}
}

/*========Lineas========*/
Linea cima(Linea lin){
	return (lin);
}

void preCrearLinea(Linea &pila){
	Cadena cadena = new char[5000];
	int numero;
	if(pila == NULL){
		numero = 0;
	}else{
		numero = cima(pila)->numero_linea + 1;
	}
	cout<<"Ingrese la linea de caracteres: "<<endl;
	gets(cadena);
	insertarLinea(pila, crearLineas(cadena, numero));
}

Linea crearLinea(Cadena cadena, int numero){
	Linea auxLinea = new linea;
	if(auxLinea){
		auxLinea->contenido = cadena;
		auxLinea->numero_linea = numero;
		auxLinea->siguiente = NULL;
		return auxLinea;
	}
}

void insertarLinea(Linea &pila,Linea linea){
	linea->siguiente = pila;
	pila = linea;
}

/*========Retorno========*/
void tipoRetorno(TipoRet respuesta){
	switch (respuesta) {
		case OK:
			
			break;
		case ERROR:
		
			break;
		case NO_IMPLEMENTADA:
			
			break;
}

/*========MostrarTexto========*/




/*========BorrarArchivo========*/



/*========BorrarLinea========*/

#endif
