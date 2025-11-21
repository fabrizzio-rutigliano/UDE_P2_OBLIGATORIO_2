#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "Boolean.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

// Cargar fecha por teclado
void cargarFecha(Fecha &fecha);

// Mostrar por pantalla la fecha ingresada
void mostrarFecha(Fecha fecha);

// Funciones que retorna el atributo especificado en el header de la fecha
int darDia(Fecha fecha);
int darMes(Fecha fecha);
int darAnio(Fecha fecha);

// Retorna que la fecha sea valida
Boolean esValidaFecha(Fecha fecha);

Boolean esMayorFechas(Fecha a, Fecha b);

Boolean sonIgualesFechas(Fecha a, Fecha b);

#endif // FECHA_H_INCLUDED
