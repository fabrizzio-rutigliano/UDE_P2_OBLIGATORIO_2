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
void CrearAlumnoTree(AlumnoTree &a);

//Operacion que devuelve si es vacio
Boolean EsVacio(AlumnoTree a);

//operacion que devuelve la raiz del Arbol
//Precondicion: arbol no vacio
alumno DarRaizAlumnoTree(AlumnoTree a);

//operacion que devuelve el hijo izquierdo del Arbol
//precondicion: arbol no vacio
AlumnoTree HijoIzqAlumnoTree(AlumnoTree a);

//operacion que devuelve el hijo derecho del arbol
//precondicion: arbol no vacio
AlumnoTree HijoDerAlumnoTree(AlumnoTree a);

//operacion que agrega elemento a la raiz del Arbol
//dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree ConsAlumnoTree(int valor, AlumnoTree izq, AlumnoTree der);

//Recorre el árbol en preorden listando sus nodos por pantalla.
void PreOrdenAlumnoTree(AlumnoTree a);

//Recorre el árbol en orden listando sus nodos por pantalla.
void OrdenAlumnoTree(AlumnoTree a);

//Recorre el árbol en posorden listando sus nodos por pantalla.
void PostOrdenAlumnoTree(AlumnoTree a);

//Devuelve la cantidad de nodos que hay en el árbol.
int ContarNodosAlumnoTree(AlumnoTree a);



#endif // ARBOL_H_INCLUDED
