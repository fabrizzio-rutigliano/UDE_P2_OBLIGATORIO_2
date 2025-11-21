#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED
#include "Boolean.h"

typedef struct nodoL
{
    int info;
    nodoL * sig;
} nodo;

typedef nodo * Lista;

void Crear(Lista &L);

Boolean Vacia (Lista L);

//EJ4

/* Precondición: lista NO vacía */
float Primero (Lista L);

/* Precondición: lista NO vacía */
void Resto (Lista & L);

void InsFront (Lista & L, float e);

int LargoIter(Lista L);

void DesplegarIter(Lista L);

int UltimoIter(Lista L);

int ContarIter(Lista L, int a);

Boolean PerteneceIter(Lista L, int a);

void SustituirIter(Lista &L, int a, int b);

int MaximoIter(Lista L);

void ParesImparesIter(Lista L, Lista &A, Lista &B);

void InsBackIter(Lista &L, int a);

//EJ5

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista).
int LargoRecu(Lista L);

//Dada una lista, despliega sus valores por pantalla.
void DesplegarRecu(Lista L);

//Dada una lista, devuelve su último elemento.
//Precondicion: lista no vacia
int UltimoRecu(Lista L);

//Dada una lista y un número entero, devuelve la cantidad de veces que dicho entero aparece en la lista.
int ContarRecu(Lista L, int a);

//Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
Boolean PerteneceRecu(Lista L, int a);

//Dada una lista y dos números enteros, sustituye cada ocurrencia del primer entero en la lista por el segundo entero.
void SustituirRecu(Lista &L, int a, int b);

//Dada una lista, devuelve el mayor entero almacenado en ella.
int MaximoRecu(Lista L);

/*Dada una lista, devuelve dos nuevas listas, la primera conteniendo
todos los valores pares de la lista original, y la segunda conteniendo todos los valores impares
de la lista original (se permite usar la operación básica InsFront para esta parte). No se
debe modificar la lista original.*/
void ParesImparesRecu(Lista L, Lista &A, Lista &B);

//Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackRecu(Lista &L, int a);


//EJ6

/*
Dada una lista y un número entero, borra todas las ocurrencias de
dicho valor en la lista, liberando la memoria dinámica de cada nodo donde aparece. En caso
de que el entero no aparezca ninguna vez, la lista no debe sufrir modificación alguna.
*/
void BorrarOcurrencias(Lista &L, int a);

/*
Dada una lista, devuelve TRUE si tiene algún elemento que esté repetido o
FALSE si no tiene ninguno (es decir, si los elementos de la lista son todos diferentes entre sí).
*/
Boolean HayRepetidos(Lista L);

/*
Dada una lista, clona todos sus valores, Por ejemplo, si la lista contiene
los valores [3, 7, 4] entonces debe quedar así [3, 3, 7, 7, 4, 4] (con los valores en ese orden)
luego de completada la operación.
*/
void ClonarValores(Lista &L);

/*
Dada una lista y un entero n > 0, devuelve una nueva lista conteniendo
los primeros n valores de la lista original, en el mismo orden en que aparecen en ella. Puede
suponer que la lista original tiene al menos n valores. Por ejemplo, si la lista original contiene
los valores [3, 7, 4, 2, 5] y n = 3, entonces la operación debe devolver una nueva lista formada
por los valores [3, 7, 4] (en ese orden).
*/
//Precondiocion: largo de lista mayor o igual a n
Lista TomarPrimeros(Lista L, int n);


#endif // REGISTROS_H_INCLUDED
