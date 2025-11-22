#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED
#include "RegistroStruct.h"

typedef struct nodoL
{
    Registro info;
    nodoL * sig;
} NodoL;
// Mantiene uso de NodoL para evitar confusion con Nodo de ABB posterior.

typedef NodoL * Lista;

// =================================================================================================================

// ---------- OPERACIONES CREACION/INSERCION ------------------------

// Crear lista.
void crearLista(Lista &L);

// Agrega un nodo nuevo al principio de la lista.
void insFrontLista(Lista &L, Registro reg);

// Insertar registro al final de la lista
void insBackLista(Lista &L, Registro reg);

// ---------- OPERACIONES ELIMINACION --------------------------------

// Borra el primer nodo y deja la lista apuntando al segundo
// Pre: lista NO vacía */
void eliminarPrimeroLista(Lista &L);

// Eliminar registros con una cedula dada
void eliminarOcurrenciaLista(Lista &L, long int ci);

// Elimina todos los nodos de la lista y la deja vacía (NULL)
void destruirLista(Lista &L);

// ---------- OPERACIONES CONSULTAR/DESPLEGAR ------------------------

// Devuelve verdadero si la lista está vacía.
Boolean esListaVacia(Lista L);

// Devuelve la cantidad de elementos de la lista.
int largoLista(Lista L);

// Desplegar elementos de la lista
void desplegarLista(Lista L);

// Devuelve el primer elemento de la lista
// Pre: lista NO vacía
Registro primerRegistro(Lista L);

// Devuelve el ultimo elemento de la lista
// Pre: lista NO vacía
Registro ultimoRegistro(Lista L);

// Listar todos los registros de un alumno (en orden cronológico por ordenacion previa de la lista).
// Pre: el alumno con esa cédula existe.
void listarRegistrosDeAlumno(Lista L, long int ci);

// Listar todos los registros posteriores a una fecha dada.
// Pre: la fecha es válida.
void listarRegistrosPosterioresA(Lista L, Fecha f);

// Contar cuántos registros fueron ingresados en una fecha dada.
// Pre: la fecha es válida.
int contarRegistrosEnFecha(Lista L, Fecha f);

// Obtener el taller más popular y su cantidad.
// Pre: la lista NO está vacía.
void tallerMasPopular(Lista L, nomTaller &taller, int &cantidad);

#endif // REGISTROS_H_INCLUDED
