#include "Archivos.h"
/*
// ---------- CREAR --------------
// Crear archivo
void crearArchivo(String nomArch)
{
    FILE * f;
    f = fopen (nomArch, "wb");
    fclose(f);
}
// ---------- CONSULTAR ------------
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
Boolean esVacioArchivo(String nomArch){
    Boolean archivoVacio = FALSE;
    FILE * f = fopen (nomArch, "rb");
    fseek (f, 0, SEEK_END);
    if (ftell (f) == 0)
        archivoVacio = TRUE;
    fclose (f);
    return archivoVacio;
}


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(String nomArch, int entero){
    Boolean esta = FALSE;
    FILE * f = fopen (nomArch, "rb");
    int buffer;
    fread (&buffer, sizeof(int), 1, f);
    while (!feof(f) && !esta)
    {
        if (buffer == entero)
            esta = TRUE;
        else
            fread (&buffer, sizeof(int), 1, f);
    }
    fclose (f);
    return esta;
}

// ---------- AB STRING ------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f){S
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite (&s[i], sizeof(char), 1, f);
}

// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto para lectura.
void Levantar_String (String &s, FILE * f){
    int i=0;
    String aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    if (feof(f))
        aux[i] = '\0';
    strcop (s, aux);
    delete [] aux;
}

// ---------- AB STRUCT ------------

// Escribe en el archivo los datos de la persona P.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Persona (Persona P, FILE * f ){
    Bajar_String(P.nombre, f);
    fwrite (&P.edad, sizeof(int), 1, f);
    fwrite (&P.cedula, sizeof(long int), 1, f);
}

// Lee desde el archivo los datos de la persona P.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Persona (Persona &P, FILE * f ){
    strcrear (P.nombre);
    Levantar_String (P.nombre, f);
    fread (&P.edad, sizeof(int), 1, f);
    fread (&P.cedula, sizeof(long int), 1, f);
}

// ---------- AB LISTA ------------

// Abre el archivo para escritura y escribe los datos de todas las
// personas que están almacenadas en la lista
void Bajar_Lista (Lista L, String nomArch){
    FILE * f = fopen (nomArch, "wb");
    while (L != NULL)
    {
        Bajar_Persona (L -> info, f);
        L = L -> sig;
    }
    fclose (f);
}

// Abre el archivo para lectura y carga en la lista los datos de
// todas las personas que están almacenadas en el archivo (llamando
// al procedimiento InsBack).
void Levantar_Lista (Lista &L, String nomArch){

    FILE * f = fopen (nomArch, "rb");
    Persona buffer;
    Crear (L);
    Levantar_Persona (buffer, f);
    while (!feof(f))
    {
        InsBack (L, buffer);
        Levantar_Persona (buffer, f);
    }
    fclose (f);

}

// ---------- AB ABB ------------

// Escribe en el archivo los datos de todos los enteros del árbol
// en forma recursiva. // Precondición: El archivo viene abierto para escritura.
void Bajar_ABB_Aux (ABB a, FILE * f){
    if (a != NULL)
    {
        fwrite (&(a -> info), sizeof (int), 1, f);
        Bajar_ABB_Aux (a -> hizq, f);
        Bajar_ABB_Aux (a -> hder, f);
 }
}

// Abre el archivo para escritura y escribe los datos de todos los
// enteros del árbol (llamando al procedimiento anterior)
void Bajar_ABB (ABB a, String nomArch){
    FILE * f = fopen (nomArch, "wb");
    Bajar_ABB_Aux (a, f);
    fclose (f);
}

// Abre el archivo para lectura e inserta en el árbol todos los
// enteros están en el archivo (llamando al procedimiento Insert).
// Precondición: El archivo existe.
void Levantar_ABB (ABB &a, String nomArch){
    FILE * f = fopen (nomArch, "rb");
    int buffer;
    Crear (a);
    fread (&buffer, sizeof (int), 1, f);
    while (!feof(f))
    {
        Insert (a, buffer);
        fread (&buffer, sizeof (int), 1, f);
    }
    fclose (f);
}

*/
