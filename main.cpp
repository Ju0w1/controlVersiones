#include<iostream>
#include "versiones.hpp"
#include <cstdio>
#include <cstring>
#include "String.h"
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[]) {
	/*========Variables========*/
	Cadena cmd = new char[50];
	Archivo archivo = NULL;
	Linea pila = NULL;
	/*========Uso de funciones/procedimientos========*/
	menu();
	
	gets(cmd);
	
	lecturaComando(cmd, archivo, pila);
	
	
	return 0;
}

