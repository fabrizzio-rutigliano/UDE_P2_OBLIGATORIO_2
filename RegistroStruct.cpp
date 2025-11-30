#include "RegistroStruct.h"

// ---------- CARGAR ------------

void cargarCedula(long int &ci)
{
    printf("Ingrese cedula: ");
    scanf("%ld", &ci);
}

void cargarCantDias(int &d)
{
    printf("Ingrese cantidad de dias del taller: ");
    scanf("%d", &d);
}

void cargarRegistro(Registro &reg)
{
    nomTaller aux;
    printf("Ingrese nombre del taller: \n");
    cargarTaller(aux);
    reg.taller = aux;

    printf("Ingrese fecha de finalizacion: \n");
    do
    {
        cargarFecha(reg.fecha_fin);
    } while (!esValidaFecha(reg.fecha_fin));

    cargarCedula(reg.cedula);
    cargarCantDias(reg.cant_dias);
}

// ---------- DESPLEGAR --------

nomTaller darNombreTaller(Registro reg)
{
    return reg.taller;
}

Fecha darFechaFin(Registro reg)
{
    return reg.fecha_fin;
}

long int darCedula(Registro reg)
{
    return reg.cedula;
}

int darCantDias(Registro reg)
{
    return reg.cant_dias;
}

void desplegarRegistro(Registro reg)
{

    printf("\n");
    printf("| %ld | ", darCedula(reg));
    nomTaller t = darNombreTaller(reg);
    desplegarTaller(t);
    printf(" | ");
    mostrarFecha(reg.fecha_fin);
    printf(" | %d | ", darCantDias(reg));
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
