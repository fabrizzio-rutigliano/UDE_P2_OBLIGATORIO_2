#include "Archivos.h"

// Agrega el nuevo entero al final del archivo
void Agregar (string nomArch, int entero)
{

}

// Determina si existe o no un archivo con el nombre recibido por parámetro
boolean Existe (string nomArch);


// Determina si el archivo está vacío o no. Precondición: El archivo existe
boolean Vacio (string nomArch);


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
boolean Pertenece (string nomArch, int entero);


// Devuelve la cantidad de enteros almacenados en el archivo. Precondición: El archivo existe
int Largo (string nomArch);


// Devuelve el k-ésimo entero almacenado en el archivo. Precondición: El archivo existe
// y su largo es  k.
int K-esimo (string nomArch, int k);


// Despliega por pantalla los enteros almacenados en el archivo. Precondición: El archivo existe
void Desplegar (string nomArch);
