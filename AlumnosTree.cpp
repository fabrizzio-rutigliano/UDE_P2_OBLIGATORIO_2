#include "AlumnosTree.h"

// ---------- OPERACIONES CREACION/INSERCION ------------------------

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
        copAlu(a->info, alu);
        a->hizq = NULL;
        a->hder = NULL;
    }
    else
    {
        if (alu.ci < darCedulaAlumno(a->info))
        {
            insertarAlumnoOrdenado(a->hizq, alu);
        }
        else
        {
            insertarAlumnoOrdenado(a->hder, alu);
        }
    }
}

// Operacion que agrega elemento a la raiz del Arbol
// dados dos arboles, agregar un valor como raiz de los dos arboles
AlumnoTree consAlumnoTree(Alumno alu, AlumnoTree izq, AlumnoTree der)
{
    AlumnoTree aux = new nodoABB;
    aux->info = alu;
    aux->hizq = izq;
    aux->hder = der;
    return aux;
}

// ---------- OPERACIONES RECORRIDA  -------------------------------

// Recorre el árbol en preorden listando sus nodos por pantalla.
void preOrdenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        desplegarAlumno(a->info);
        preOrdenAlumnoTree(a->hizq);
        preOrdenAlumnoTree(a->hder);
    }
}

// Recorre el árbol en orden listando sus nodos por pantalla.
void ordenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        ordenAlumnoTree(a->hizq);
        desplegarAlumno(a->info);
        ordenAlumnoTree(a->hder);
    }
}

// Recorre el árbol en posorden listando sus nodos por pantalla.
void postOrdenAlumnoTree(AlumnoTree a)
{
    if (a != NULL)
    {
        postOrdenAlumnoTree(a->hizq);
        postOrdenAlumnoTree(a->hder);
        desplegarAlumno(a->info);
    }
}
// ---------- OPERACIONES ELIMINACION -------------------------------

// Elimina del árbol el alumno con cédula.
// Precondición: el alumno con la cédula 'ci' existe en el árbol.
void eliminarAlumno(AlumnoTree &a, long int ci){

    // ----- PASO 1: BUSCAR EL VALOR EN EL ABB -----
    if (ci < a->info.ci)
    {
        eliminarAlumno(a->hizq, ci);
    }
    else if (ci > a->info.ci)
    {
        eliminarAlumno(a->hder, ci);
    }
    else
    {
        // ----- LLEGAMOS AL NODO A ELIMINAR -----

        // PASO 2 y 3: una vez encontrado verificar si ambos hijos vacíos
        if (a->hizq == NULL && a->hder == NULL)
        {
            delete a;
            a = NULL;
        }
        // PASO 4: hijo derecho vacío → reemplazar por hijo izquierdo
        else if (a->hder == NULL)
        {
            AlumnoTree aux = a;
            a = a->hizq;
            delete aux;
        }
        // PASO 5: hijo izquierdo vacío → reemplazar por hijo derecho
        else if (a->hizq == NULL)
        {
            AlumnoTree aux = a;
            a = a->hder;
            delete aux;
        }
        // PASO 6: tiene dos hijos,  copiar en su lugar el valor mínimo de su hijo
        // derecho y posteriormente eliminar el valor mínimo del hijo derecho
        else
        {
            // mínimo del subárbol derecho = sucesor en orden
            AlumnoTree p = a->hder;
            while (p->hizq != NULL)
                p = p->hizq;

            long int ciSucesor = darCedulaAlumno(p->info);

            // Copiar el valor del mínimo del hijo derecho en el nodo actual
            a->info = p->info;

            // Eliminar el mínimo del hijo derecho
            eliminarAlumno(a->hder, ciSucesor);
        }
    }
}


// Libera toda la memoria del árbol y lo deja vacío (NULL).
void destruirAlumnoTree(AlumnoTree &a)
{
    if (a != NULL)
    {
        destruirAlumnoTree(a->hizq);
        destruirAlumnoTree(a->hder);

        // Libero la memoria del alumno (strings, etc.)
        destruirAlumno(a->info);

        delete a;
        a = NULL;
    }
}

// ---------- OPERACIONES CONSULTAR/DESPLEGAR -----------------------

// Operacion que devuelve si es vacio
Boolean esVacioAlumnoTree(AlumnoTree a)
{
    Boolean esVacio = FALSE;
    if (a == NULL)
        esVacio = TRUE;
    return esVacio;
}

// Operacion que devuelve la raiz del Arbol
// Precondicion: arbol no vacio
Alumno darRaizAlumnoTree(AlumnoTree a)
{
    return a->info;
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

// Devuelve la cantidad de nodos que hay en el árbol.
int contarNodosAlumnoTree(AlumnoTree a)
{
    if (a == NULL)
        return 0;
    else
        return 1 + contarNodosAlumnoTree(a->hizq) + contarNodosAlumnoTree(a->hder);
}

//Verifica existencia de alumno en arbol, devolviendo Boolean
//TODO VALIDAR
Boolean existeAlumnoTree(AlumnoTree a, Alumno alu)
{
    if(!esVacioAlumnoTree(a))
    {
        if (darCedulaAlumno(alu) == darCedulaAlumno(darRaizAlumnoTree(a)))
            return TRUE;
        else if (darCedulaAlumno(alu) < darCedulaAlumno(darRaizAlumnoTree(a)))
        {
            return FALSE;
            existeAlumnoTree(a->hizq, alu);
        }
        else
        {
            return FALSE;
            existeAlumnoTree(a->hder, alu);
        }
    }
    else
        return FALSE;
}

// Devuelve el subárbol cuyo nodo raíz tiene la cédula.
// Precondicion: el arbol contiene la Cedula
AlumnoTree buscarNodoAlumnoPorCI(AlumnoTree a, long int ci){

    if (ci == darCedulaAlumno(a->info))
        return a;
    else if (ci < darCedulaAlumno(a->info))
        return buscarNodoAlumnoPorCI(a->hizq, ci);
    else
        return buscarNodoAlumnoPorCI(a->hder, ci);
}

// Contar alumnos que nacieron en una fecha dada
int contarAlumnosFechaNac(AlumnoTree a, Fecha f)
{
    if (a == NULL)
        return 0;

    return (sonIgualesFechas(darFechaNacAlumno(a->info), f) == TRUE)
           + contarAlumnosFechaNac(a->hizq, f)
           + contarAlumnosFechaNac(a->hder, f);

    /*if(sonIgualesFechas(darFechaNacAlumno(a->alu), f))
        return 1 + contarAlumnosFechaNac(a->hizq, f) + contarAlumnosFechaNac(a->hder, f);
    else
        return contarAlumnosFechaNac(a->hizq, f) + contarAlumnosFechaNac(a->hder, f);*/
}

// Dado un apellido, cuenta:
// men: cuántos tienen apellido alfabéticamente menor
// may: cuántos tienen apellido alfabéticamente mayor
// ig:  cuántos tienen exactamente ese apellido
//precondicion: pasar variables int en 0;
void contarAlumnosPorApellido(AlumnoTree a, String apellido, int &men, int &may, int &ig)
{
    if (a!=NULL)
    {
        String apeAux;
        strCrear(apeAux);
        darApellidoAlumno(a->info, apeAux);
        if (strEq(apeAux,apellido))
        {
            ig++;

        }
        else if (strMen(apeAux,apellido))
        {
            men++;

        }
        else
        {
            may++;

        }
        strDestruir(apeAux);
        contarAlumnosPorApellido(a->hizq, apellido, men, may, ig);
        contarAlumnosPorApellido(a->hder, apellido, men, may, ig);
    }

}

// Dar el alumno de mayor edad.
// Precondición: el arbol no esta vacio
Alumno obtenerAlumnoMayorEdad(AlumnoTree a){
    //Buscamos obtener la fecha "mas menor/antigua de nacimiento".

    Alumno mayor = a->info; // Caso base.

    if (a->hizq != NULL)
    {
        Alumno aluIzq = obtenerAlumnoMayorEdad(a->hizq);
        // Si la fecha de nacimiento actual es mayor (más reciente) que la de mejorIzq,
        // entonces mejorIzq es más viejo (fecha más antigua), lo reemplazo.
        if (esMayorFechas(darFechaNacAlumno(mayor), darFechaNacAlumno(aluIzq)))
            mayor = aluIzq;
    }

    if (a->hder != NULL)
    {
        Alumno aluDer = obtenerAlumnoMayorEdad(a->hder);
        if (esMayorFechas(darFechaNacAlumno(mayor), darFechaNacAlumno(aluDer)))
            mayor = aluDer;
    }

    return mayor;

}

/*
void mayorPorNacimientoRec(ABB a, ABB &maxNodo)
{
    if(a!=NULL)
    {
        if (esMasViejo(darFecha(a->info), darFecha(maxNodo->info))
            maxNodo = a; // recorrer sin variables temporales locales adicionales
        mayorPorNacimientoRec(a->hizq, maxNodo);
        mayorPorNacimientoRec(a->hder, maxNodo);
    }

}

void DesplegarMayor(Arbol a)
{
    Arbol maxNodo = a;
    mayorPorNacimientoRec(a, maxNodo);
    DesplegarDatosAlumno(maxNodo->info);
}

*/

// Lista por pantalla todos los alumnos que NO tienen registros
void listarAlumnosSinRegistros(AlumnoTree a, Lista registros)
{
    if (a != NULL)
    {
        listarAlumnosSinRegistros(a->hizq, registros);
        if(!existeAlumnoRegistro(registros, darCedulaAlumno(a->info)))
            desplegarAlumno(a->info);
        listarAlumnosSinRegistros(a->hder, registros);
    }
}


// ---------- AB ABB ------------

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void Bajar_AlumnoTree_Aux(AlumnoTree a, FILE * f){
    if (a != NULL)
    {
        Bajar_Alumno(a->info,f);
        Bajar_AlumnoTree_Aux(a -> hizq, f);
        Bajar_AlumnoTree_Aux(a -> hder, f);
 }
}

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void Bajar_AlumnoTree(AlumnoTree a, String nomArch){
    FILE * f = fopen(nomArch, "wb");
    Bajar_AlumnoTree_Aux(a, f);
    fclose(f);
}

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void Levantar_AlumnoTree(AlumnoTree &a, String nomArch){
    FILE * f = fopen(nomArch, "rb");
    Alumno aluBuffer;
    crearAlumnoTree(a);
    Levantar_Alumno(aluBuffer, f);
    while(!feof(f))
    {
        insertarAlumnoOrdenado(a, aluBuffer);
        Levantar_Alumno(aluBuffer, f);
    }
    fclose (f);
}


