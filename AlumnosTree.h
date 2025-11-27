#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "AlumnoStruct.h"
#include "RegistrosList.h"

typedef struct nodoABB
{
    Alumno info;
    nodoABB * hizq;
    nodoABB * hder;
} nodoABB;

typedef nodoABB * AlumnoTree;

// =================================================================================================================

// ---------- OPERACIONES CREACION/INSERCION ------------------------

// Crear arbol vacío.
void crearAlumnoTree(AlumnoTree &a);

// Inserta un alumno manteniendo orden por cédula.
// Precondición: en el árbol NO existe un alumno con la misma cédula.
void insertarAlumnoOrdenado(AlumnoTree &a, Alumno alu);

// Operacion que agrega elemento a la raiz del Arbol
// Dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree consAlumnoTree(Alumno alu, AlumnoTree izq, AlumnoTree der);

// ---------- OPERACIONES RECORRIDA  -------------------------------
//Recorre el árbol en preorden listando sus nodos por pantalla.
void preOrdenAlumnoTree(AlumnoTree a);

//Recorre el árbol en orden listando sus nodos por pantalla.
void ordenAlumnoTree(AlumnoTree a);

//Recorre el árbol en posorden listando sus nodos por pantalla.
void postOrdenAlumnoTree(AlumnoTree a);

// ---------- OPERACIONES ELIMINACION -------------------------------

// Elimina del árbol el alumno con de cédula 'ci'.
// Precondición: el alumno con la cédula 'ci' existe en el árbol.
void eliminarAlumno(AlumnoTree &a, long int ci);

// Libera toda la memoria del árbol y lo deja vacío (NULL).
void destruirAlumnoTree(AlumnoTree &a);

// ---------- OPERACIONES CONSULTAR/DESPLEGAR -----------------------

// Operacion que devuelve si es vacio
Boolean esVacioAlumnoTree(AlumnoTree a);

// Devolver la raiz del Arbol
// Precondición: el arbol no es vacio
Alumno darRaizAlumnoTree(AlumnoTree a);

// Devuelve el hijo izquierdo del Arbol
// Precondición: el arbol no es vacio
AlumnoTree hijoIzqAlumnoTree(AlumnoTree a);

// Devuelve el hijo derecho del arbol
// Precondición: el arbol no es vacio
AlumnoTree hijoDerAlumnoTree(AlumnoTree a);

//Devuelve la cantidad de nodos que hay en el árbol.
int contarNodosAlumnoTree(AlumnoTree a);

//Verifica existencia de alumno en arbol, devolviendo Boolean
Boolean existeAlumnoTree(AlumnoTree a, Alumno alu);

// Devuelve el subárbol cuyo nodo raíz tiene la cédula.
// Precondicion: el arbol contiene la Cedula
AlumnoTree buscarNodoAlumnoPorCI(AlumnoTree a, long int ci);

// Contar alumnos que nacieron en una fecha dada
int contarAlumnosFechaNac(AlumnoTree a, Fecha f);

// Dado un apellido, cuenta:
// men: cuántos tienen apellido alfabéticamente menor
// may: cuántos tienen apellido alfabéticamente mayor
// ig:  cuántos tienen exactamente ese apellido
void contarAlumnosPorApellido(AlumnoTree a, String apellido, int &men, int &may, int &ig);

// Dar el alumno de mayor edad
// Precondición: el arbol no esta vacio
Alumno obtenerAlumnoMayorEdad(AlumnoTree a);

// Lista por pantalla todos los alumnos que NO tienen registros
void listarAlumnosSinRegistros(AlumnoTree a, Lista registros);

// ---------- AB ABB ------------

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void Bajar_AlumnoTree_Aux(AlumnoTree a, FILE * f);

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void Bajar_AlumnoTree(AlumnoTree a, String nomArch);

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void Levantar_AlumnoTree(AlumnoTree &a, String nomArch);

#endif // ARBOL_H_INCLUDED
