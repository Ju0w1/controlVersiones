#include<iostream>
#include "versiones.hpp"
#include <cstdio>
#include <cstring>
#include "String.h"
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[]) {
	/*========Variables========*/
	Cadena cmd = new char[MAX_CHAR];
	Archivo archivo = NULL;
	Linea pila = NULL;
	/*========Uso de funciones/procedimientos========*/
	
	
	do{
		menu();
		gets(cmd);
		lecturaComando(cmd, archivo, pila);
	}while(strcmp(strlwr(cmd), "salir") != 0);
	
	
	return 0;
}

