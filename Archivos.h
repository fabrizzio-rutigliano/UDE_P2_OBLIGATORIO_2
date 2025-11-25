#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "AlumnosTree.h"
#include "RegistrosList.h"

/*
// ---------- CREAR --------------
// Agrega el nuevo entero al final del archivo
void crearArchivo(String nomArch);

// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(String nomArch);

// Determina si el archivo está vacío o no. Precondición: El archivo existe
Boolean esVacioArchivo(String nomArch);

// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(String nomArch, int entero);

// ---------- AB STRING ------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f);

// ---------- AB STRUCT ------------

// Escribe en el archivo los datos de la persona P.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Persona (Persona P, FILE * f );

// Lee desde el archivo los datos de la persona P.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Persona (Persona &P, FILE * f );

// ---------- AB LISTA ------------

// Abre el archivo para escritura y escribe los datos de todas las
// personas que están almacenadas en la lista
void Bajar_Lista (Lista L, String nomArch);

// Abre el archivo para lectura y carga en la lista los datos de
// todas las personas que están almacenadas en el archivo (llamando
// al procedimiento InsBack).
void Levantar_Lista (Lista &L, String nomArch);

// ---------- AB ABB ------------

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void Bajar_ABB_Aux (ABB a, FILE * f);

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void Bajar_ABB (ABB a, String nomArch);

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void Levantar_ABB (ABB &a, String nomArch);


*/
#endif // ARCHIVOS_H_INCLUDED

