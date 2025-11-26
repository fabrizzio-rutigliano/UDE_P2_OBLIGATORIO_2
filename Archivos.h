#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include "AlumnosTree.h"
#include "RegistrosList.h"

/*
// ---------- CREAR --------------
// Agrega el nuevo entero al final del archivo
void crearArchivo(string nomArch);

// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(string nomArch);

// Determina si el archivo está vacío o no. Precondición: El archivo existe
Boolean esVacioArchivo(string nomArch);

// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(string nomArch, int entero);

// ---------- AB STRING ------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f);

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f);

// ---------- ARCHIVO STRUCT FECHA --------------

// Escribe en el archivo los datos de fecha.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Fecha(Fecha fec, FILE * f );

// Lee desde el archivo los datos de la fecha.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Fecha(Fecha &fec, FILE * f );

// ---------- ARCHIVO STRUCT ALUMNO --------------

// Escribe en el archivo los datos del alumno alu.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Alumno(Alumno alu, FILE * f );

// Lee desde el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Alumno(Alumno &alu, FILE * f );

// ---------- ARCHIVO STRUCT REGISTRO ------------

// Escribe en el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Registro (Registro reg, FILE * f);

// Lee desde el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Registro(Registro &reg, FILE * f );

// ---------- AB LISTA ------------

// Abre el archivo para escritura y escribe los datos de registros
void Bajar_Lista(Lista L, string nomArch);

// Abre el archivo para lectura y carga en la lista todos los registros
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

