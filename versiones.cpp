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
	cout<<"CrearArchivo"<<endl;
	cout<<"InsertarLinea"<<endl;
	cout<<"MostrarTexto"<<endl;
	cout<<"BorrarArchivo"<<endl;
	cout<<"BorrarLinea"<<endl;
	cout<<"Salir"<<endl;
	
}
/*========LecturaComando========*/
void lecturaComando(Cadena cmd, Archivo &arch, Linea &pila){
	Cadena cmdc = new char[50];
	int i = 0;
	
	
//	CrearArchivo("Hola.txt");
//	InsertarLinea("Hola.txt","1","primer linea",1);
//	BorrarLinea("hola","1",1);
//	BorrarArchivo("hola.txt")
//	MostrarTexto("hola.txt", "1");
//	BorrarArchivo("hola.txt")
		
	while(toascii(cmd[i]) != 40){
		cmdc[i] = cmd[i];
		i++;
	}
	cmdc[i] = '\0';
	cmdc = strlwr(cmdc);
	i= i+2;
	
	if(!strcmp(cmdc,"creararchivo")){	//CREAR ARCHIVO
		Cadena nombre = new char[50];
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombre[j] = cmd[i];
			j++;
			i++;
		}
		nombre[j] = '\0';
		
		arch = crearArchivo(nombre);
		arch->lineas = pila;
		cout<<"Lineas: "<<arch->lineas<<endl;
		cout<<"Nombre: "<<arch->name<<endl;
		
	}else if(!strcmp(cmdc,"insertarlinea")){	//INSERTAR LINEA
		Cadena nombreArch = new char[50];
		Cadena version = new char[50];
		Cadena linea = new char[5000];
		Cadena nro_linea = new char[50];
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
		insertarLinea(arch,version,linea,numLinea,error);
	}else if(!strcmp(cmdc,"mostrartexto")){
		Archivo aux = arch;
		Cadena nombreArch = new char[50];
		Cadena version = new char[50];
		Cadena error  = new char[50];
		
		int j = 0;
		
		while(toascii(cmd[i]) != 34){
			nombreArch[j] = cmd[i];
			j++;
			i++;
		}
		nombreArch[j] = '\0';
		mostrarTexto(aux, version, error);
	}
	

//	
//	if(!strcmp(cmdc,"creararchivo")){
//		preCrearArchivo(arch);
//	}
//	if(!strcmp(cmdc,"insertarlinea")){
//		preCrearLinea(pila,arch);
//	}
//	if(!strcmp(cmdc,"mostrartexto")){
//		mostrarTexto(arch);
//	}
//	if(!strcmp(cmdc,"borrarlinea")){
//		preBorrarLinea(arch);
//	}
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
			cout<<"Entro primer if"<<endl;	
			apilar(pila, crearLinea(cadena_linea, numero));
			arch->lineas = pila;
			return OK;
		}else if(numero - cima(pila)->numero_linea < 1 ){
			cout<<"Entro tercer if"<<endl;
			Linea auxLinea = NULL;
			apilar(auxLinea,crearLinea("",0));
			while(cima(auxLinea)->numero_linea != numero){
				cout<<"Entro"<<endl;
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
void mostrarTexto(Archivo arch, Cadena version, Cadena error){
	Linea aux = arch->lineas;
	Linea aux2 = NULL;
	cout<<"Entro a mostrar"<<endl;
	while(aux){
		cout<<"Desapilando"<<endl;
		apilar(aux2, crearLinea(cima(aux)->contenido,cima(aux)->numero_linea));
		delete(desapilarLinea(aux));
	}
	cout<<(arch->name)<<": "<<endl;
	while(aux2){
		cout<<aux2->numero_linea<<"\t"<<aux2->contenido<<endl;
		aux2 = aux2->siguiente;
//		apilar(aux, crearLinea(cima(aux2)->contenido,cima(aux2)->numero_linea));
//		delete(desapilarLinea(aux2));
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
				apilar(aux2,crearLinea(cima(aux)->contenido,cima(aux)->numero_linea)); 
				delete(desapilarLinea(aux));
			}
		}
		aux = NULL;
		while(aux2 != NULL){
			apilar(aux,crearLinea(cima(aux2)->contenido,numero_lin));
			numero_lin++;
			delete(desapilarLinea(aux2));
		}
		arch->lineas = aux; 
		tipoRetorno(OK);
	}
}

#endif
