#include "RegistrosList.h"

// ---------- OPERACIONES CREACION/INSERCION ------------------------

// Crear lista.
void crearLista(Lista &L)
{
    L = NULL;
}

// Agrega un nodo nuevo al principio de la lista.
void insFrontLista(Lista &L, Registro reg)
{
    Lista aux = new NodoL;
    aux->info = reg;
    aux->sig = L;
    L = aux;
}

// Insertar registro al final de la lista
void insBackLista(Lista &L, Registro reg)
{
    Lista aux = new NodoL;
    aux->info = reg;
    aux->sig = NULL;
    if (esListaVacia(L))
    {
        L = aux;
    }
    L->sig = aux;
}

// ---------- OPERACIONES ELIMINACION --------------------------------

// Borra el primer nodo y deja la lista apuntando al segundo
// Pre: lista NO vacía */
void eliminarPrimeroLista(Lista &L)
{

    Lista aux = L;
    L = L->sig;
    delete aux;
}

// Eliminar registros con una cedula dada
void eliminarOcurrenciaLista(Lista &L, long int ci)
{
    if (L != NULL)
    {
        if (darCedula(L->info) == ci)
        {
            NodoL *aux;
            aux = L;
            L = L->sig;
            delete aux;
            eliminarOcurrenciaLista(L, ci);
        }
        else
        {

            eliminarOcurrenciaLista(L->sig, ci);
        }
    }
}

// Elimina todos los nodos de la lista y la deja vacía (NULL)
void destruirLista(Lista &L)
{
    NodoL *aux;
    while (L != NULL)
    {
        aux = L;
        L = L->sig;
        delete (aux);
    }
}

// ---------- OPERACIONES CONSULTAR/DESPLEGAR ------------------------

// Devuelve verdadero si la lista está vacía.
Boolean esListaVacia(Lista L)
{
    Boolean es = FALSE;
    if (L == NULL)
        es = TRUE;
    return es;
}

// Devuelve TRUE si el alumno existe en la lista
Boolean existeAlumnoRegistro(Lista L, long int ci)
{
    Boolean es = FALSE;
    while(es==FALSE && L!=NULL)
    {
        if(darCedula(L->info)==ci)
            es=TRUE;
        L=L->sig;
    }
    return es;
}

// Devuelve la cantidad de elementos de la lista.
int largoLista(Lista L)
{
    int largo = 0;
    while (L != NULL)
    {
        largo++;
        L = L->sig;
    }
    return largo;
}

// Desplegar elementos de la lista
void desplegarLista(Lista L)
{
    while (L != NULL)
    {
        desplegarRegistro(L->info);
        L = L->sig;
    }
}

// Devuelve el primer elemento de la lista
// Pre: lista NO vacía
Registro primerRegistro(Lista L)
{
    return L->info;
}

// Devuelve el ultimo elemento de la lista
// Pre: lista NO vacía
Registro ultimoRegistro(Lista L)
{
    if (L->sig == NULL)
        return L->info;
    else
        return ultimoRegistro(L->sig);
}

// Listar todos los registros de un alumno (en orden cronológico).
// Pre: el alumno con esa cédula existe.
void listarRegistrosDeAlumno(Lista L, long int ci)
{
    while (L != NULL)
    {
        Registro reg = L->info;
        if (reg.cedula == ci)
        {
            desplegarRegistro(L->info);
        }
        L = L->sig;
    }
}

// Listar todos los registros posteriores a una fecha dada.
// Pre: la fecha es válida.
void listarRegistrosPosterioresA(Lista L, Fecha f)
{
    while ((!esMayorFechas(darFechaFin(L->info), f)) && (L->sig != NULL))
    {
        L = L->sig;
    }
    if (esMayorFechas(darFechaFin(L->info), f))
    {
        while (L != NULL)
        {
            desplegarRegistro(L->info);
            L = L->sig;
        }
    }
}

// Contar cuántos registros fueron ingresados en una fecha dada.
// Pre: la fecha es válida.
int contarRegistrosEnFecha(Lista L, Fecha f)
{
    int cantidad = 0;
    while (L != NULL && (!sonIgualesFechas(darFechaFin(L->info), f)))
    {
        L = L->sig;
    }
    while (L != NULL && (sonIgualesFechas(darFechaFin(L->info), f)))
    {
        cantidad++;
        L = L->sig;
    }

    return cantidad;
}

// Obtener el taller más popular y su cantidad.
// Pre: la lista NO está vacía.
void tallerMasPopular(Lista L, nomTaller &taller, int &cantidad)
{
    cantidad = 0;
    int pastas = 0, pasbas = 0, pasava = 0, panaderia = 0, vegana = 0, mediterranea = 0, parrilla = 0, reposteria = 0, oriental = 0;
    while (L != NULL)
    {
        switch (darNombreTaller(L->info))
        {
        case PASTAS:
            pastas++;
            break;
        case PASTELERIA_BASICA:
            pasbas++;
            break;
        case PASTELERIA_AVANZADA:
            pasava++;
            break;
        case PANADERIA:
            panaderia++;
            break;
        case VEGANA:
            vegana++;
            break;
        case MEDITERRANEA:
            mediterranea++;
            break;
        case PARRILLA:
            parrilla++;
            break;
        case REPOSTERIA:
            reposteria++;
            break;
        case ORIENTAL:
            oriental++;
            break;
        }
        L = L->sig;
        if (cantidad < pastas)
        {
            cantidad = pastas;
            taller = PASTAS;
        }
        if (cantidad < pasbas)
        {
            cantidad = pasbas;
            taller = PASTELERIA_BASICA;
        }
        if (cantidad < pasava)
        {
            cantidad = pasava;
            taller = PASTELERIA_AVANZADA;
        }
        if (cantidad < panaderia)
        {
            cantidad = panaderia;
            taller = PANADERIA;
        }
        if (cantidad < vegana)
        {
            cantidad = vegana;
            taller = VEGANA;
        }
        if (cantidad < mediterranea)
        {
            cantidad = mediterranea;
            taller = MEDITERRANEA;
        }
        if (cantidad < parrilla)
        {
            cantidad = parrilla;
            taller = PARRILLA;
        }
        if (cantidad < reposteria)
        {
            cantidad = reposteria;
            taller = REPOSTERIA;
        }
        if (cantidad < oriental)
        {
            cantidad = oriental;
            taller = ORIENTAL;
        }
    }
}
