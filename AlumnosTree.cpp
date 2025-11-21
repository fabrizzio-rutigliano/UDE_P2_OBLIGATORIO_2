#include "AlumnosTree.h"

//Operacion que crea arbol vacio
void CrearAlumnoTree(AlumnoTree &a)
{
    a=NULL;
}

//Operacion que devuelve si es vacio
Boolean EsVacioAlumnoTree(AlumnoTree a)
{
    Boolean esVacio = FALSE;
    if(a==NULL)
        esVacio=TRUE;
    return esVacio;
}

//operacion que devuelve la raiz del Arbol
//Precondicion: arbol no vacio
alumno DarRaizAlumnoTree(AlumnoTree a)
{
    return a->alu;
}

//operacion que devuelve el hijo izquierdo del Arbol
//precondicion: arbol no vacio
AlumnoTree HijoIzqAlumnoTree(AlumnoTree a)
{
    return a->hizq;
}

//operacion que devuelve el hijo derecho del arbol
//precondicion: arbol no vacio
AlumnoTree HijoDerAlumnoTree(AlumnoTree a)
{
    return a->hder;
}

//operacion que agrega elemento a la raiz del Arbol
//dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree ConsAlumnoTree(alumno al, AlumnoTree izq, AlumnoTree der)
{
    AlumnoTree aux = new nodoAlumno;
    aux->alu = al;
    aux->hizq = izq;
    aux->hder = der;
    return aux;
}

//Recorre el árbol en preorden listando sus nodos por pantalla.
//Precondicion: arbol no vacio ?
void PreOrdenAlumnoTree(AlumnoTree a)
{
    if(a!=NULL)
    {
        printf("%d",a->alu);
        PreOrdenAlumnoTree(a->hizq);
        PreOrdenAlumnoTree(a->hder);
    }
}

//Recorre el árbol en orden listando sus nodos por pantalla.
void OrdenAlumnoTree(AlumnoTree a)
{
    if(a!=NULL)
    {
        PreOrdenAlumnoTree(a->hizq);
        printf("%d",a->alu);
        PreOrdenAlumnoTree(a->hder);
    }
}

//Recorre el árbol en posorden listando sus nodos por pantalla.
void PostOrdenAlumnoTree(AlumnoTree a)
{
    if(a!=NULL)
    {
        PreOrdenAlumnoTree(a->hizq);
        PreOrdenAlumnoTree(a->hder);
        printf("%d",a->alu);
    }
}

//Devuelve la cantidad de nodos que hay en el árbol.
int ContarNodosAlumnoTree(AlumnoTree a)
{
    if(a==NULL)
        return 0;
    else
        return 1 + ContarNodosAlumnoTree(a->hizq) + ContarNodosAlumnoTree(a->hder);

}




