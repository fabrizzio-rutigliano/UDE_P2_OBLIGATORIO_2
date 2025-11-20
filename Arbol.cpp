#include "Arbol.h"

//Operacion que crea arbol vacio
void Crear(Arbol &a)
{
    a=NULL;
}

//Operacion que devuelve si es vacio
Boolean EsVacio(Arbol a)
{
    Boolean esVacio = FALSE;
    if(a==NULL)
        esVacio=TRUE;
    return esVacio;
}

//operacion que devuelve la raiz del Arbol
//Precondicion: arbol no vacio
int DarRaiz(Arbol a)
{
    return a->info;
}

//operacion que devuelve el hijo izquierdo del Arbol
//precondicion: arbol no vacio
Arbol HijoIzq(Arbol a)
{
    return a->hizq;
}

//operacion que devuelve el hijo derecho del arbol
//precondicion: arbol no vacio
Arbol HijoDer(Arbol a)
{
    return a->hder;
}

//operacion que agrega elemento a la raiz del Arbol
//dados dos arboles, agregar un valor como raiz de los dos arboles
Arbol Cons(int valor, Arbol izq, Arbol der)
{
    Arbol aux = new nodo;
    aux->info = valor;
    aux->hizq = izq;
    aux->hder = der;
    return aux;
}

//Recorre el árbol en preorden listando sus nodos por pantalla.
//Precondicion: arbol no vacio ?
void PreOrden (Arbol a)
{
    if(a!=NULL)
    {
        printf("%d",a->info);
        PreOrden(a->hizq);
        PreOrden(a->hder);
    }
}

//Recorre el árbol en orden listando sus nodos por pantalla.
void Orden (Arbol a)
{
    if(a!=NULL)
    {
        PreOrden(a->hizq);
        printf("%d",a->info);
        PreOrden(a->hder);
    }
}

//Recorre el árbol en posorden listando sus nodos por pantalla.
void PostOrden (Arbol a)
{
    if(a!=NULL)
    {
        PreOrden(a->hizq);
        PreOrden(a->hder);
        printf("%d",a->info);
    }
}

//Devuelve la cantidad de nodos que hay en el árbol.
int ContarNodos (Arbol a)
{
    if(a==NULL)
        return 0;
    else
        return 1 + ContarNodos(a->hizq) + ContarNodos(a->hder);

}




