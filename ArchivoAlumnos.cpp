#include "Archivos.h"

// Agrega el nuevo entero al final del archivo
void Agregar (String nomArch, int entero)
{

}

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe (String nomArch);


// Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean Vacio (String nomArch);


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
boolean Pertenece (String nomArch, int entero);


// Devuelve la cantidad de enteros almacenados en el archivo. Precondición: El archivo existe
int Largo (String nomArch);


// Devuelve el k-ésimo entero almacenado en el archivo. Precondición: El archivo existe
// y su largo es  k.
int Kesimo (String nomArch, int k);


// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe
void Desplegar (String nomArch);
