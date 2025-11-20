#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Boolean.h"

typedef struct nodoA
{
    int info;
    nodoA * hizq;
    nodoA * hder;
} nodo;

typedef nodo * Arbol;

//Operacion que crea arbol vacio
void Crear(Arbol &a);

//Operacion que devuelve si es vacio
Boolean EsVacio(Arbol a);
//operacion que devuelve la raiz del Arbol
//Precondicion: arbol no vacio
int DarRaiz(Arbol a);

//operacion que devuelve el hijo izquierdo del Arbol
//precondicion: arbol no vacio
Arbol HijoIzq(Arbol a);

//operacion que devuelve el hijo derecho del arbol
//precondicion: arbol no vacio
Arbol HijoDer(Arbol a);

//operacion que agrega elemento a la raiz del Arbol
//dados dos arboles, agregar un valor como raiz de los dos arboles
Arbol Cons(int valor, Arbol izq, Arbol der);

//Recorre el árbol en preorden listando sus nodos por pantalla.
void PreOrden (Arbol a);

//Recorre el árbol en orden listando sus nodos por pantalla.
void Orden (Arbol a);

//Recorre el árbol en posorden listando sus nodos por pantalla.
void PostOrden (Arbol a);

//Devuelve la cantidad de nodos que hay en el árbol.
int ContarNodos (Arbol a);



#endif // ARBOL_H_INCLUDED
