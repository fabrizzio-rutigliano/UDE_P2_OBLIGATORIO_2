#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "AlumnoStruct.h"

typedef struct nodoAlu
{
    alumno alu;
    nodoAlu * hizq;
    nodoAlu * hder;
} nodoAlumno;

typedef nodoAlumno * AlumnoTree;

//Operacion que crea arbol vacio
void crearAlumnoTree(AlumnoTree &a);

//Operacion que devuelve si es vacio
Boolean esVacio(AlumnoTree a);

//operacion que devuelve la raiz del Arbol
//Precondicion: arbol no vacio
alumno darRaizAlumnoTree(AlumnoTree a);

//operacion que devuelve el hijo izquierdo del Arbol
//precondicion: arbol no vacio
AlumnoTree hijoIzqAlumnoTree(AlumnoTree a);

//operacion que devuelve el hijo derecho del arbol
//precondicion: arbol no vacio
AlumnoTree hijoDerAlumnoTree(AlumnoTree a);

//operacion que agrega elemento a la raiz del Arbol
//dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree honsAlumnoTree(int valor, AlumnoTree izq, AlumnoTree der);

//Recorre el árbol en preorden listando sus nodos por pantalla.
void preOrdenAlumnoTree(AlumnoTree a);

//Recorre el árbol en orden listando sus nodos por pantalla.
void ordenAlumnoTree(AlumnoTree a);

//Recorre el árbol en posorden listando sus nodos por pantalla.
void postOrdenAlumnoTree(AlumnoTree a);

//Devuelve la cantidad de nodos que hay en el árbol.
int contarNodosAlumnoTree(AlumnoTree a);



#endif // ARBOL_H_INCLUDED
