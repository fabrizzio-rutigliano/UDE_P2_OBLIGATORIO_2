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

// Cargar nombre taller
void cargarRegistro(Registro &reg);

// Cargar cedula, posible aux.
void cargarCedula(long int &ci);

// Cargar cantidad de dias entero, posible aux.
void cargarCantDias(int &d);

// ---------- DESPLIEGAR --------

// Desplegar elementos de registro
void desplegarRegistro(Registro reg);

// Devuelve taller
nomTaller darNombreTaller(Registro reg);

// Devuelve fecha_fin
Fecha darFechaFin(Registro reg);

// Devuelve cedula
long int darCedula(Registro reg);

// Devuelve cantidad de dias del taller
int darCantDias(Registro reg);

#endif // REGISTRO_H_INCLUDED
