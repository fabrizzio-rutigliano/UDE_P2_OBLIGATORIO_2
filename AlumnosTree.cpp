#include "AlumnosTree.h"

// Crear arbol vacío.
void crearAlumnoTree(AlumnoTree &a)
{
    a = NULL;
}

// Inserta un alumno manteniendo orden por cédula.
// Precondición: en el árbol NO existe un alumno con la misma cédula.
void insertarAlumnoOrdenado(AlumnoTree &a, Alumno alu)
{
    if (esVacioAlumnoTree(a))
    {
        a = new nodoABB;
        a->alu = alu;
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if (alu.ci < a->alu.ci)
        {
            insertarAlumnoOrdenado(a->hizq, alu);
        }
        else
        {
            insertarAlumnoOrdenado(a->hder, alu);
        }
    }
}

// Operacion que devuelve si es vacio
Boolean esVacioAlumnoTree(AlumnoTree a)
{
    Boolean esVacio = FALSE;
    if (a == NULL)
        esVacio = TRUE;
    return esVacio;
}

// operacion que devuelve la raiz del Arbol
// Precondicion: arbol no vacio
Alumno darRaizAlumnoTree(AlumnoTree a)
{
    return a->alu;
}

// operacion que devuelve el hijo izquierdo del Arbol
// precondicion: arbol no vacio
AlumnoTree hijoIzqAlumnoTree(AlumnoTree &a)
{
    return a->hizq;
}

// operacion que devuelve el hijo derecho del arbol
// precondicion: arbol no vacio
AlumnoTree hijoDerAlumnoTree(AlumnoTree &a)
{
    return a->hder;
}

// operacion que agrega elemento a la raiz del Arbol
// dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree consAlumnoTree(Alumno al, AlumnoTree izq, AlumnoTree der)
{
    AlumnoTree aux = new nodoABB;
    aux->alu = al;
    aux->hizq = izq;
    aux->hder = der;
    return aux;
}

// Recorre el árbol en preorden listando sus nodos por pantalla.
// Precondicion: arbol no vacio ?
void preOrdenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        printf("%d", a->alu);
        preOrdenAlumnoTree(a->hizq);
        preOrdenAlumnoTree(a->hder);
    }
}

// Recorre el árbol en orden listando sus nodos por pantalla.
void ordenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        preOrdenAlumnoTree(a->hizq);
        printf("%d", a->alu);
        preOrdenAlumnoTree(a->hder);
    }
}

// Recorre el árbol en posorden listando sus nodos por pantalla.
void postOrdenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        preOrdenAlumnoTree(a->hizq);
        preOrdenAlumnoTree(a->hder);
        printf("%d", a->alu);
    }
}

// Devuelve la cantidad de nodos que hay en el árbol.
int contarNodosAlumnoTree(AlumnoTree a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + contarNodosAlumnoTree(a->hizq) + contarNodosAlumnoTree(a->hder);
}
