#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

#include<stdio.h>

// def constantes simbolicas

// def tipos de datos
typedef enum {FALSE, TRUE} Boolean;

// Cabezales sintacticos de subprogramas

void cargar(Boolean &b); // cargar valor boolean desde teclado

void despliegue(Boolean b); // mostrar valor booleano en pantalla

#endif // BOOLEAN_H_INCLUDED
