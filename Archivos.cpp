#include "Archivos.h"

/*
// ---------- CREAR/ABRIR--------------

// Crear archivo
void crearArchivo(string nomArch)
{
    FILE * f;
    f = fopen(nomArch, "wb");
    fclose(f);
}


/* Abrir archivo con tipos de lectura
FILE * fopen (string filename, string mode)
"rb" Abre el archivo solo para lectura. Precondición: El archivo debe existir.
"wb" Crea un archivo solo para escritura. Si un archivo con ese nombre
ya existe, será sobreescrito.
"ab" Append; abre un archivo solo para escritura de nuevos datos



// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(string nomArch)
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
Boolean esVacioArchivo(string nomArch){
    Boolean archivoVacio = FALSE;
    FILE * f = fopen (nomArch, "rb");
    fseek (f, 0, SEEK_END);
    if (ftell (f) == 0)
        archivoVacio = TRUE;
    fclose (f);
    return archivoVacio;
}


// Determina si el entero recibido está en el archivo. Precondición: El archivo existe
Boolean perteneceArchivo(string nomArch, int entero){
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

// ---------- ARCHIVO STRING --------------------------------------
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Bajar_String (String s, FILE * f){
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
    strCop (s, aux);
    delete [] aux;
}

// ---------- AB STRUCT ------------

// ---------- ARCHIVO STRUCT FECHA --------------

// Escribe en el archivo los datos de fecha.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Fecha(Fecha fec, FILE * f ){
    fwrite(&fec.dia, sizeof(int), 1, f);
    fwrite(&fec.mes, sizeof(int), 1, f);
    fwrite(&fec.anio, sizeof(int), 1, f);
}

// Lee desde el archivo los datos de la fecha.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Fecha(Fecha &fec, FILE * f ){
    fread(&fec.dia, sizeof(int), 1, f);
    fread(&fec.mes, sizeof(int), 1, f);
    fread(&fec.anio, sizeof(int), 1, f);
}

// ---------- ARCHIVO STRUCT ALUMNO --------------

// Escribe en el archivo los datos del alumno alu.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Alumno(Alumno alu, FILE * f ){
    fwrite(&alu.ci, sizeof(long int), 1, f);
    Bajar_String(alu.nombre, f);
    Bajar_String(alu.apellido, f);
    Bajar_Fecha(alu.fecha_nacimiento, f);
    Bajar_String(alu.direccion, f);
    fwrite(&alu.telefono, sizeof(long int), 1, f);
}

// Lee desde el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Alumno(Alumno &alu, FILE * f ){
    //Cedula
    fread(&alu.ci, sizeof(long int), 1, f);
    //Nombre
    strCrear(alu.nombre);
    Levantar_String(alu.nombre, f);
    //Apellido
    strCrear(alu.apellido);
    Levantar_String(alu.apellido, f);
    //Fecha
    Levantar_Fecha(alu.fecha_nacimiento, f);
    //Direccion
    strCrear(alu.direccion);
    Levantar_String(alu.direccion, f);
    //Telefono
    fread(&alu.telefono, f);
}

// ---------- ARCHIVO STRUCT REGISTRO ------------
// Escribe en el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Registro (Registro reg, FILE * f){
    fwrite(&reg.taller, sizeof(int), 1, f);
    Bajar_Fecha(reg.fecha_fin, f);
    fwrite(&reg.cedula, sizeof(long int), 1, f);
    fwrite(&reg.cant_dias, sizeof(int), 1, f);
}

// Lee desde el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Registro(Registro &reg, FILE * f ){
    fread(&reg.taller, sizeof(int), 1, f);
    Levantar_Fecha(reg.fecha_fin, f);
    fread(&reg.cedula, sizeof(long int), 1, f);
    fread(&reg.cant_dias, sizeof(int), 1, f);
}

// ---------- AB LISTA REGISTRO ------------
// Abre el archivo para escritura y escribe los datos de registros
void Bajar_Lista(Lista L, string nomArch){
    FILE * f = fopen (nomArch, "wb");
    while (L != NULL)
    {
        Bajar_Registro(L -> info, f);
        L = L -> sig;
    }
    fclose (f);
}

// Abre el archivo para lectura y carga en la lista todos los registros
void Levantar_Lista (Lista &L, String nomArch){

    FILE * f = fopen (nomArch, "rb");
    Registro buffer;
    crearLista(L);
    Levantar_Registro(buffer, f);
    while (!feof(f))
    {
        insBackLista(L, buffer);
        Levantar_Registro(buffer, f);
    }
    fclose (f);
}

// ---------- AB ABB ------------
/*
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
