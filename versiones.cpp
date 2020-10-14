#ifndef VERSIONES_CPP
#define VERSIONES_CPP
#include "versiones.hpp"
#include<iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*========Menu========*/
void menu(){
	cout<<"console/> ";
}
/*========LecturaComando========*/
void lecturaComando(Cadena cmd, Archivo &arch, Linea &pila){
	Cadena cmdc = new char[100];
	int i = 0;

	while(toascii(cmd[i]) != 40){
		cmdc[i] = cmd[i];
		i++;
	}
	cmdc[i] = '\0';
	cmdc = strlwr(cmdc);
	i= i+2;
	
	if(!strcmp(cmdc,"creararchivo")){			//CREAR ARCHIVO
		Cadena nombre = new char[MAX_CHAR];
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombre[j] = cmd[i];
			j++;
			i++;
		}
		nombre[j] = '\0';
		if(arch == NULL)
		{
			arch = crearArchivo(nombre);
			arch->lineas = pila;
			cout<<arch->name<<endl;
		}else{
			tipoRetorno(NO_IMPLEMENTADA);
		}
		
	}else if(!strcmp(cmdc,"insertarlinea")){	//INSERTAR LINEA
		Cadena nombreArch = new char[MAX_CHAR];
		Cadena version = new char[MAX_CHAR];
		Cadena linea = new char[5000];
		Cadena nro_linea = new char[MAX_CHAR];
		int numLinea;
		Cadena error = new char[500];
		
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombreArch[j] = cmd[i];
			j++;
			i++;
		}
		nombreArch[j] = '\0';
		i = i+3;
		j = 0;
		while(toascii(cmd[i]) != 34){
			version[j] = cmd[i];
			j++;
			i++;
		}
		version[j] = '\0';
		i = i+3;
		j = 0;
		while(toascii(cmd[i]) != 34){
			linea[j] = cmd[i];
			j++;
			i++;
		}
		linea[j] = '\0';
		i = i + 2;
		j = 0;
		while(toascii(cmd[i]) != 41){
			nro_linea[j] = cmd[i];
			j++;
			i++;
		}
		nro_linea[j] = '\0';
		numLinea = atoi(nro_linea);
		
		if(arch == NULL){
			error = "Archivo sin crear\0";
		}else if(strcmp(arch->name, nombreArch)){
			error = "Nombre de archivo no coincide\0";
		}else if(numLinea < 1){
			error = "El numero de linea debe ser 1 o mayor\0";
		}else if(arch->lineas != NULL){
			if( (numLinea - cima(arch->lineas)->numero_linea ) > 1){
				strcpy(error,"El numero de linea: ");
				strcat(error,nro_linea);
				strcat(error," no debe ser mayor a ");
				Cadena dev = new char[35];
				itoa((cima(arch->lineas)->numero_linea+1),dev,10);
				strcat(error, dev);
			}else{
				error[0] = '\0';
			}
		}else{
			error[0] = '\0';
		}
		tipoRetorno(insertarLinea(arch,version,linea,numLinea,error));
	}else if(!strcmp(cmdc,"mostrartexto")){			//MOSTRAR TEXTO
		Archivo aux = arch;
		Cadena nombreArch = new char[MAX_CHAR];
		Cadena version = new char[MAX_CHAR];
		Cadena error  = new char[MAX_CHAR];
		
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombreArch[j] = cmd[i];
			j++;
			i++;
		}
		nombreArch[j] = '\0';
		
		if(arch == NULL){
			error = "Archivo sin crear\0";
		}else if(strcmp(arch->name, nombreArch)){
			error = "Nombre de archivo no coincide\0";
		}else{
			error[0] = '\0';
		}
		tipoRetorno(mostrarTexto(aux, version, error));
	}else if(!strcmp(cmdc,"borrarlinea")){			//BORRAR LINEA
		Cadena nombreArch = new char[MAX_CHAR];
		Cadena version = new char[MAX_CHAR];
		Cadena nro_linea = new char[MAX_CHAR];
		int numLinea;
		Cadena error  = new char[MAX_CHAR];
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombreArch[j] = cmd[i];
			j++;
			i++;
		}
		nombreArch[j] = '\0';
		i = i+3;
		j = 0;
		while(toascii(cmd[i]) != 34){
			version[j] = cmd[i];
			j++;
			i++;
		}
		version[j] = '\0';
		i = i+2;
		j = 0;
		while(toascii(cmd[i]) != 41){
			nro_linea[j] = cmd[i];
			j++;
			i++;
		}
		nro_linea[j] = '\0';

		numLinea = atoi(nro_linea);
		if(arch == NULL){
			error = "Archivo sin crear\0";
		}else if(strcmp(arch->name, nombreArch)){
			error = "Nombre de archivo no coincide\0";
		}else if(numLinea < 1){
			error = "El numero de linea debe ser 1 o mayor\0";
		}else if(arch->lineas == NULL){
			error = "No hay niguna linea ingresada\0";
		}else if(cima(arch->lineas)->numero_linea < numLinea){
			error = "El numero de linea no existe\0";
		}else{
			error[0] = '\0';
		}
		tipoRetorno(borrarLinea(arch,version,numLinea,error));
	}else if(!strcmp(cmdc,"borrararchivo")){ 		//BORRAR ARCHIVO Y TODO SU CONTENIDO
		Cadena nombreArch = new char[MAX_CHAR];
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombreArch[j] = cmd[i];
			j++;
			i++;
		}
		nombreArch[j] = '\0';
		tipoRetorno(borrarArchivo(arch));
	}
	

}
	
	
/*========Archivo========*/
Archivo crearArchivo(Cadena nombre){
	Archivo arch = new archivo;
	if(arch){
		arch->name = nombre;
		arch->lineas = NULL;
		tipoRetorno(OK);
		return arch;
	}else{
		cout<<"Error arch"<<endl;
		tipoRetorno(ERROR);
		return NULL;
	}
}

/*========Lineas========*/
Linea cima(Linea lin){
	return (lin);
}

Linea crearLinea(Cadena cadena_linea, int numero){
	Linea auxLinea = new linea;
	if(auxLinea){
		auxLinea->contenido = cadena_linea;
		auxLinea->numero_linea = numero;
		auxLinea->siguiente = NULL;
		return auxLinea;
	}else{
		return NULL;
	}
}

void apilar(Linea &pila, Linea nodo){
	nodo->siguiente = pila;
	pila = nodo;
}

TipoRet insertarLinea(Archivo &arch,Cadena version,Cadena cadena_linea, int numero, Cadena error){
	if(!strcmp(error,"")){
		Linea pila = arch->lineas;
		if((numero == 1  && pila == NULL) || (numero > 1 && (numero - cima(pila)->numero_linea) == 1)){
			apilar(pila, crearLinea(cadena_linea, numero));
			arch->lineas = pila;
			return OK;
		}else if(numero - cima(pila)->numero_linea < 1 ){
			Linea auxLinea = NULL;
			apilar(auxLinea,crearLinea("",0));
			while(cima(auxLinea)->numero_linea != numero){
				apilar(auxLinea,crearLinea(cima(pila)->contenido,cima(pila)->numero_linea));
				delete(desapilarLinea(pila));
			}
			apilar(pila,crearLinea(cadena_linea,numero));
			while(auxLinea->numero_linea != 0){			
				apilar(pila,crearLinea(cima(auxLinea)->contenido,cima(auxLinea)->numero_linea+1));
				delete(desapilarLinea(auxLinea));
			}
			delete(desapilarLinea(auxLinea));
			arch->lineas = pila;
			return OK;
		}
	}else{
		cout<<error<<endl;
		return ERROR;
	}
}

TipoRet borrarLinea(Archivo &arch,Cadena version,int numero,Cadena error){
	if(!strcmp(error,"")){
		Linea pila = arch->lineas;
		if(numero == cima(pila)->numero_linea){
			delete(desapilarLinea(pila));
			arch->lineas = pila;
			return OK;
		}else if(numero < cima(pila)->numero_linea){
			Linea auxLinea = NULL;
			apilar(auxLinea,crearLinea("",0));
			while(cima(pila)->numero_linea != numero){
				apilar(auxLinea,crearLinea(cima(pila)->contenido,cima(pila)->numero_linea));
				delete(desapilarLinea(pila));
			}
			delete(desapilarLinea(pila));
			while(auxLinea->numero_linea != 0){			
				apilar(pila,crearLinea(cima(auxLinea)->contenido,cima(auxLinea)->numero_linea-1));
				delete(desapilarLinea(auxLinea));
			}
			delete(desapilarLinea(auxLinea));
			arch->lineas = pila;
			return OK;
		}
	}else{
		cout<<error<<endl;
		return ERROR;
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

/*========MostrarTexto========*/
TipoRet mostrarTexto(Archivo arch, Cadena version, Cadena error){
	if(!strcmp(error,"")){
		cout<<(arch->name)<<": "<<endl;
		if(arch->lineas == NULL){
			cout<<"No contiene lineas"<<endl;
		}else{
			Linea aux = NULL;
			Linea aux2 = NULL;
			while(arch->lineas){
				apilar(aux, crearLinea(cima(arch->lineas)->contenido,cima(arch->lineas)->numero_linea));
				apilar(aux2, crearLinea(cima(arch->lineas)->contenido,cima(arch->lineas)->numero_linea));
				delete(desapilarLinea(arch->lineas));
			}
			while(aux2){
				cout<<aux2->numero_linea<<"\t"<<aux2->contenido<<endl;
				delete(desapilarLinea(aux2));
			}
			while(aux){
				apilar(arch->lineas, crearLinea(cima(aux)->contenido,cima(aux)->numero_linea));
				delete(desapilarLinea(aux));
			}
		}
		return OK;
	}else{
		cout<<error<<endl;
		return ERROR;
	}
}

/*========BorrarArchivo========*/
TipoRet borrarArchivo(Archivo &arch){
	if(arch == NULL){
		return NO_IMPLEMENTADA;
	}else{
		while(arch->lineas){
			delete(desapilarLinea(arch->lineas));
		}
		delete(arch);
		arch = NULL;
		return OK;
	}
}


#endif
