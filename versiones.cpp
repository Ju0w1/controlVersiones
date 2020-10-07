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
	cmd = strlwr(cmd);
	puts(cmd);
	
	Cadena cmdc = new char[50];
	Cadena nombre = new char[50];
	int i = 0;
	
	//cmd = "CrearArchivo("hola.txt");"
	
	while(toascii(cmd[i]) != 40){
		cmdc[i] = cmd[i];
		i++;
	}
	cmdc[i] = '\0';
	puts(cmdc);
	
	cout<<(cmd[i])<<endl;
	if(toascii(cmd[i]) != 34){
		while(toascii(cmd[i]) != 34){
			i++;
		}
	}
	i++;
	cout<<(cmd[i])<<endl;
	while(toascii(cmd[i]) != 34){
		nombre[i] = cmd[i];
		i++;
	}
	nombre[i] = '\0';
	//strcat(nombre, nombre);
	puts(nombre);
	/*
	
	if(!strcmp(cmdc,"creararchivo")){
		preCrearArchivo(arch);
	}
	if(!strcmp(cmdc,"insertarlinea")){
		preCrearLinea(pila,arch);
	}
	if(!strcmp(cmdc,"mostrartexto")){
		mostrarTexto(arch);
	}
	if(!strcmp(cmdc,"borrarlinea")){
		preBorrarLinea(arch);
	}
//	if(!strcmp(cmdc,"borrarlinea")){
//		borrarArchivo();
//	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
//	if(!strcmp(cmdc,"creararchivo")){
//		//crearArchivo();
//	}
	*/
}
	
	
/*========Archivo========*/
void preCrearArchivo(Archivo &arch){
	Cadena nombre= new char[50];
	cout<<"Ingrese el nombre del archivo: "<<endl;
	gets(nombre);
	arch = crearArchivo(nombre);
	cout<<arch->name<<endl;
	tipoRetorno(OK);
}

Archivo crearArchivo(Cadena nombre){
	Archivo arch = new archivo;
	if(arch){
		arch->name = nombre;
		arch->lineas = NULL;
		return arch;
	}else{
		tipoRetorno(ERROR);
		return NULL;
	}
}

/*========Lineas========*/
Linea cima(Linea lin){
	return (lin);
}

void preCrearLinea(Linea &pila, Archivo &arch){
	Cadena cadena = new char[5000];
	int numero;
	if(pila == NULL){
		numero = 0;
	}else{
		numero = cima(pila)->numero_linea + 1;
	}
	cout<<"Ingrese la linea de caracteres: "<<endl;
	gets(cadena);
	insertarLinea(pila, crearLinea(cadena, numero));
	arch->lineas = pila;
	tipoRetorno(OK);
}

Linea crearLinea(Cadena cadena, int numero){
	Linea auxLinea = new linea;
	if(auxLinea){
		auxLinea->contenido = cadena;
		auxLinea->numero_linea = numero;
		auxLinea->siguiente = NULL;
		return auxLinea;
	}else{
		tipoRetorno(ERROR);
		return NULL;
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
			cout<<"OK"<<endl;
			break;
		case ERROR:
			cout<<"ERROR"<<endl;
			break;
		case NO_IMPLEMENTADA:
			cout<<"NO IMPLEMENTADA"<<endl;
			break;
	}
}

Linea desapilarLinea(Linea &pila){
	Linea aux, dev=new linea;
	aux=pila;
	if(!pila) return NULL;
	dev->contenido = pila->contenido;
	dev->numero_linea = pila->numero_linea;
	pila = pila->siguiente;
	delete(aux);
	return dev;
}

/*========MostrarTexto========*/
void mostrarTexto(Archivo arch){
	Linea aux = arch->lineas;
	Linea aux2 = NULL;
	while(aux){
		insertarLinea(aux2, crearLinea(cima(aux)->contenido,cima(aux)->numero_linea));
		delete(desapilarLinea(aux));
	}
	cout<<(arch->name)<<": "<<endl;
	while(aux2){
		cout<<aux2->numero_linea<<"\t"<<aux2->contenido<<endl;
		insertarLinea(aux, crearLinea(cima(aux2)->contenido,cima(aux2)->numero_linea));
		delete(desapilarLinea(aux2));
	}
}

/*========BorrarArchivo========*/
void borrarArchivo(Archivo &arch){
	while(arch->lineas){
		delete(desapilarLinea(arch->lineas));
	}
	delete(arch);
}


/*========BorrarLinea========*/
void preBorrarLinea(Archivo &arch){
	int num;
	cout<<"Ingrese el numero de linea a eliminar: "<<endl;
	cin>>num;
	borrarLinea(arch,num);
}

void borrarLinea(Archivo &arch, int num){
	Linea aux = arch->lineas;
	Linea aux2 = NULL;
	int numero_lin = 0;
	if(aux == NULL){
		tipoRetorno(NO_IMPLEMENTADA);
	}else{
		while(aux != NULL){
			if(aux->numero_linea == num){
				delete(desapilarLinea(aux));
			}else{
				insertarLinea(aux2,crearLinea(cima(aux)->contenido,cima(aux)->numero_linea)); 
				delete(desapilarLinea(aux));
			}
		}
		aux = NULL;
		while(aux2 != NULL){
			insertarLinea(aux,crearLinea(cima(aux2)->contenido,numero_lin));
			numero_lin++;
			delete(desapilarLinea(aux2));
		}
		arch->lineas = aux; 
		tipoRetorno(OK);
	}
}

#endif
