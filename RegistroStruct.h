#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED
#include "Taller.h"
#include "Fecha.h"

typedef struct
{
    nomTaller taller;
    Fecha fecha_fin;
    long int cedula;
    int cant_dias;

} Registro;

// ============================================================================

// ---------- CARGAR ------------

// Cargar cedula
//Precondicion: la cedula pertenece a un alumno existente en el sistema
void cargarCedula(long int &ci);

// Cargar cantidad de dias entero
void cargarCantDias(int &d);

// Cargar un registro
void cargarRegistro(Registro &reg);

// ---------- DESPLEGAR --------

// Devuelve taller
nomTaller darNombreTaller(Registro reg);

// Devuelve fecha_fin
Fecha darFechaFin(Registro reg);

// Devuelve cedula
long int darCedula(Registro reg);

// Devuelve cantidad de dias del taller
int darCantDias(Registro reg);

// Desplegar elementos de registro
void desplegarRegistro(Registro reg);

#endif // REGISTRO_H_INCLUDED
