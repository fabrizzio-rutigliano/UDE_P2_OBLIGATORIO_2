/*#include "RegistrosList.h"

void Crear (Lista &L)
{
    L = NULL;
}

Boolean Vacia (Lista L)
{
    Boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

// Precondición: lista NO vacía
float Primero (Lista L)
{
    return L -> info;
}

// Precondición: lista NO vacía
void Resto (Lista & L)
{
    Lista aux = L;
    L = L -> sig;
    delete aux;
}

void InsFront (Lista & L, float e)
{
    Lista aux = new nodo;
    aux -> info = e;
    aux -> sig = L;
    L = aux;
}

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista).
int LargoIter(Lista L)
{
    int i=0;
    while(L != NULL)
    {
        i++;
        L=L->sig;
    }
    return i;
}

//Dada una lista, despliega sus valores por pantalla.
void DesplegarIter(Lista L)
{
    while(L != NULL)
    {
        printf("%d",L->info);
        L=L->sig;
    }
}

//Dada una lista, devuelve su último elemento.
//Precondicion: lista no puede estar vacia.
int UltimoIter(Lista L)
{
    while(L->sig!=NULL)
        L=L->sig;
    return L->info;
}

//Dada una lista y un número entero, devuelve la cantidad de veces que dicho entero aparece en la lista.
int ContarIter(Lista L, int a)
{
    int i=0;
    while(L != NULL)
    {
        if(L->info==a)
            i++;
        L=L->sig;
    }
    return i;
}

//Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
Boolean PerteneceIter(Lista L, int a)
{
    Boolean pertenece=FALSE;
    while(L!=NULL && !pertenece)
    {
        if(L->info==a)
            pertenece=TRUE;
        else
            L=L->sig;
    }
    return pertenece;
}

//Dada una lista y dos números enteros, sustituye cada ocurrencia del primer entero en la lista por el segundo entero.
void SustituirIter(Lista &L, int a, int b)
{
    Lista aux = L;
    while(aux!=NULL)
    {
        if(aux->info==a)
            aux->info=b;
        aux=aux->sig;
    }
}

//Dada una lista, devuelve el mayor entero almacenado en ella.
//Precondicion: lista no vacia
int MaximoIter(Lista L)
{
    int mayor=L->info;
    L=L->sig;
    while(L!=NULL)
    {
        if(L->info>mayor)
            mayor=L->info;
        L=L->sig;
    }
    return mayor;
}

//Dada una lista, devuelve dos nuevas listas, la primera conteniendo
todos los valores pares de la lista original, y la segunda conteniendo todos los valores impares
de la lista original (se permite usar la operación básica InsFront para esta parte). No se
debe modificar la lista original.
void ParesImparesIter(Lista L, Lista &A, Lista &B)
{
    Crear(A);
    Crear(B);
    while(L!=NULL)
    {
        if(L->info%2==0)
            InsFront(A,L->info);
        else
            InsFront(B,L->info);
        L=L->sig;
    }
}

//Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackIter(Lista &L, int a)
{
    if(L==NULL)
    {
        L = new nodo;
        L->info = a;
        L->sig = NULL;
    }
    else
    {
        Lista aux=L;
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig = new nodo;
        aux=aux->sig;
        aux->info=a;
        aux->sig=NULL;
    }
}

//EJ5

//Dada una lista, devuelve su largo (la cantidad de elementos de la lista).
int LargoRecu(Lista L)
{
    if(L==NULL)
        return 0;
    else
        return L->info + LargoRecu(L->sig);
}

//Dada una lista, despliega sus valores por pantalla.
void DesplegarRecu(Lista L)
{
    if(L!=NULL)
    {
        printf("%d",L->info);
        DesplegarRecu(L->sig);
    }
}

//Dada una lista, devuelve su último elemento.
//Precondicion: lista no vacia
int UltimoRecu(Lista L)
{
    if(L->sig==NULL)
        return L->info;
    else
        return UltimoRecu(L->sig);
}

//Dada una lista y un número entero, devuelve la cantidad de veces que dicho entero aparece en la lista.
int ContarRecu(Lista L, int a)
{
    if(L==NULL)
        return 0;
    else
    {
        if(L->info == a)
            return 1 + ContarRecu(L->sig, a);
        else
            return ContarRecu(L->sig, a);
    }
}

//Dada una lista y un número entero, devuelve TRUE si dicho entero pertenece a la lista y FALSE en caso contrario.
Boolean PerteneceRecu(Lista L, int a)
{
    if(L == NULL)
        return FALSE;
    else
    {
        if(L->info == a)
            return TRUE;
        else
            return PerteneceRecu(L->sig, a);
    }

}

//Dada una lista y dos números enteros, sustituye cada ocurrencia del primer entero en la lista por el segundo entero.
void SustituirRecu(Lista &L, int a, int b)
{
    if(L!=NULL)
    {
        if(L->info == a)
            L->info = b;
        SustituirRecu(L->sig, a, b);
    }
}

//Dada una lista, devuelve el mayor entero almacenado en ella.
int MaximoRecu(Lista L)
{
    if(L==NULL)
        return 0;
    else
    {
        int maxi = MaximoRecu(L->sig);
        if(L->info > maxi)
            return L->info;
        else
            return maxi;
    }

}

//Dada una lista, devuelve dos nuevas listas, la primera conteniendo
todos los valores pares de la lista original, y la segunda conteniendo todos los valores impares
de la lista original (se permite usar la operación básica InsFront para esta parte). No se
debe modificar la lista original.
//Precondicion: A y B existen vacias
void ParesImparesRecu(Lista L, Lista &A, Lista &B)
{
    if(L!=NULL)
    {
        if(L->info%2 == 0)
            InsFront(A, L->info);
        else
            InsFront(B, L->info);
        ParesImparesRecu(L->sig, A, B);
    }
}

//Dada una lista y un número entero, agrega dicho entero al final de la lista.
void InsBackRecu(Lista &L, int a)
{
    if(L==NULL)
    {
        L = new nodo;
        L->info = a;
        L->sig = NULL;
    }
    else
        InsBackRecu(L->sig, a);
}



//EJ6

//
Dada una lista y un número entero, borra todas las ocurrencias de
dicho valor en la lista, liberando la memoria dinámica de cada nodo donde aparece. En caso
de que el entero no aparezca ninguna vez, la lista no debe sufrir modificación alguna.

// varios detalles a revisar, caso primero, no avanza a verificar los demas. no se debe desplazar sobre L, porque se sierde acceso. conviene hacerla recursiva.
void BorrarOcurrencias(Lista &L, int a)
{
    nodo * aux, anterior = L;
    if(L->info == a)
    {
        aux = L;
        L=L->sig;
        delete aux;
    }
    else
    {
        L=L->sig;
        while(L != NULL)
        {
            if(L->info==a)
            {
                aux = L;
                L=L->sig;
                anterior->sig = L;
                delete aux;
                anterior=anterior->sig;
            }
            else
            {
                L = L->sig;
                anterior=anterior->sig;
            }
        }
    }
}

//
Dada una lista, devuelve TRUE si tiene algún elemento que esté repetido o
FALSE si no tiene ninguno (es decir, si los elementos de la lista son todos diferentes entre sí).

Boolean HayRepetidos(Lista L)
{

}

//
Dada una lista, clona todos sus valores, Por ejemplo, si la lista contiene
los valores [3, 7, 4] entonces debe quedar así [3, 3, 7, 7, 4, 4] (con los valores en ese orden)
luego de completada la operación.

void ClonarValores(Lista &L);

//
Dada una lista y un entero n > 0, devuelve una nueva lista conteniendo
los primeros n valores de la lista original, en el mismo orden en que aparecen en ella. Puede
suponer que la lista original tiene al menos n valores. Por ejemplo, si la lista original contiene
los valores [3, 7, 4, 2, 5] y n = 3, entonces la operación debe devolver una nueva lista formada
por los valores [3, 7, 4] (en ese orden).

//Precondiocion: largo de lista mayor o igual a n
Lista TomarPrimeros(Lista L, int n);
*/
