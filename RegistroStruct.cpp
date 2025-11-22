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
    printf("Ingrese nombre del taller:\n");
    cargarTaller(aux);
    reg.taller = aux;

    printf("Ingrese fecha de finalizacion en formato dd/mm/yy::\n");
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
    nomTaller t = darNombreTaller(reg);
    printf("---------------------------------\n");
    printf("Registro correspondiente a alumno con cedula: %ld\n", darCedula(reg));
    printf("Taller: ");
    desplegarTaller(t);

    printf("\nFinalizado en fecha:");
    mostrarFecha(reg.fecha_fin);
    printf("\nCantidad dias de curso: %d\n", darCantDias(reg));
}
