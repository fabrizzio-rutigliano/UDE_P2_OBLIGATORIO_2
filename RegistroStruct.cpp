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
    cargarTaller(aux);
    printf("Ingrese nombre del taller:\n");
    reg.taller = aux;

    printf("Ingrese fecha de finalizacion:\n");
    cargarFecha(reg.fecha_fin);

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
    int dia = darDia(reg.fecha_fin);
    int mes = darMes(reg.fecha_fin);
    int anio = darAnio(reg.fecha_fin);

    nomTaller t = darNombreTaller(reg);
    printf("Taller: ");
    desplegarTaller(t);

    printf("  |  Fecha fin: %d/%d/%d", dia, mes, anio);
    printf("  |  Cedula: %ld", reg.cedula);
    printf("  |  Cant. dias: %d\n", reg.cant_dias);
}
