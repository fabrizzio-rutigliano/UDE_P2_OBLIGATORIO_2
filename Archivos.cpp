#include "Archivos.h"

// Agrega el nuevo entero al final del archivo
void crearArchivo(String nomArch)
{
    FILE * f;
    f = fopen (nomArch, "wb");
    fclose(f);
}

// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(String nomArch)
{
    Boolean existe = FALSE;
    FILE * f;
    f = fopen (nomArch, "rb");

    if(f != NULL)
    {
        existe = TRUE;
        fclose(f);
    }
    return existe;
}


// Determina si el archivo está vacío o no. Precondición: El archivo existe
Boolean esVacioArchivo(String nomArch);


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(String nomArch, int entero);


// Devuelve la cantidad de enteros almacenados en el archivo. Precondición: El archivo existe
int largoArchivo(String nomArch);


// Devuelve el k-ésimo entero almacenado en el archivo. Precondición: El archivo existe
// y su largo es  k.
int KesimoArchivo(String nomArch, int k);


// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe
void desplegarArchivo(String nomArch);
