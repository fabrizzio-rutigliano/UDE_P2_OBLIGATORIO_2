#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "AlumnoStruct.h"
#include "RegistrosList.h"

typedef struct nodoABB
{
    Alumno alu;
    nodoABB * hizq;
    nodoABB * hder;
} nodoABB;

typedef nodoABB * AlumnoTree;

// =================================================================================================================

// ---------- OPERACIONES CREACION/INSERCION ------------------------

// Crear arbol vacío.
void crearAlumnoTree(AlumnoTree &a);

// Inserta un alumno manteniendo orden por cédula.
// Pre: en el árbol NO existe un alumno con la misma cédula.
void insertarAlumnoOrdenado(AlumnoTree &a, Alumno alu);

// ---------- OPERACIONES RECORRIDA  -------------------------------
//Recorre el árbol en preorden listando sus nodos por pantalla.
void preOrdenAlumnoTree(AlumnoTree a);

//Recorre el árbol en orden listando sus nodos por pantalla.
void ordenAlumnoTree(AlumnoTree a);

//Recorre el árbol en posorden listando sus nodos por pantalla.
void postOrdenAlumnoTree(AlumnoTree a);

// ---------- OPERACIONES ELIMINACION -------------------------------

// Elimina del árbol el alumno con esa cédula.
// Pre: el alumno con esa cédula existe en el árbol.
void eliminarAlumno(AlumnoTree &a, long int ci);

// Libera toda la memoria del árbol y lo deja vacío (NULL).
void destruirAlumnoTree(AlumnoTree &a);

// ---------- OPERACIONES CONSULTAR/DESPLEGAR -----------------------

// Operacion que devuelve si es vacio
Boolean esVacioAlumnoTree(AlumnoTree a);

// Devolver la raiz del Arbol
// Pre: arbol no vacio
Alumno darRaizAlumnoTree(AlumnoTree a);

// Devuelve el hijo izquierdo del Arbol
// Pre: arbol no vacio
AlumnoTree hijoIzqAlumnoTree(AlumnoTree a);

// Devuelve el hijo derecho del arbol
// Pre: arbol no vacio
AlumnoTree hijoDerAlumnoTree(AlumnoTree a);

//Devuelve la cantidad de nodos que hay en el árbol.
int contarNodosAlumnoTree(AlumnoTree a);

// Devuelve el subárbol cuyo nodo raíz tiene la cédula (o NULL si no está).
AlumnoTree buscarNodoAlumnoPorCI(AlumnoTree a, long int ci);

// Contar alumnos que nacieron en una fecha dada
int contarAlumnosFechaNac(AlumnoTree a, Fecha f);

// Dado un apellido, cuenta:
// men: cuántos tienen apellido alfabéticamente menor
// may: cuántos tienen apellido alfabéticamente mayor
// ig:  cuántos tienen exactamente ese apellido
void contarAlumnosPorApellido(AlumnoTree a, String apellido, int &men, int &may, int &ig);

// Dar el alumno de mayor edad
// Pre: el arbol no esta vacio
Alumno obtenerAlumnoMayorEdad(AlumnoTree a);

// Lista por pantalla todos los alumnos que NO tienen registros
void listarAlumnosSinRegistros(AlumnoTree a, Registros r);

#endif // ARBOL_H_INCLUDED
