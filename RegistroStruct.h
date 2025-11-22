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

}registro;

#endif // REGISTRO_H_INCLUDED