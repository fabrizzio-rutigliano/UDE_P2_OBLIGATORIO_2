#include "Fecha.h"

// Cargar
void cargarFecha(Fecha &fecha)
{
    printf("Ingrese un dia: ");
    scanf("%d", &fecha.dia);
    printf("Ingrese un mes: ");
    scanf("%d", &fecha.mes);
    printf("Ingrese un anio: ");
    scanf("%d", &fecha.anio);
}

// Desplegar
void mostrarFecha(Fecha fecha)
{
    printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
}

// Selectoras
int darDia(Fecha fecha)
{
    return fecha.dia;
}
int darMes(Fecha fecha)
{
    return fecha.mes;
}
int darAnio(Fecha fecha)
{
    return fecha.anio;
}

// Validez de la fecha ingresada
Boolean esValidaFecha(Fecha fecha)
{

    Boolean check = FALSE;

    // validamos rango de dias por mes
    switch(fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (fecha.dia >= 1 && fecha.dia <= 31)
            check = TRUE;
        else
            check = FALSE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (fecha.dia >= 1 && fecha.dia <= 30)
            check = TRUE;
        else
            check = FALSE;
        break;
    case 2:// validamos que el a�o sea biciesto
        if (fecha.anio % 4 == 0)
        {
            if (fecha.dia >= 1 && fecha.dia <= 29)
                check = TRUE;
            else
                check = FALSE;
        }
        else
        {
            if (fecha.dia  >= 1 && fecha.dia  <= 28)
                check = TRUE;
            else
                check = FALSE;
        }
        break;
    default:
        check = FALSE;
    }

    return check;

}

Boolean esMayorFechas(Fecha a, Fecha b)
{
    Boolean check = FALSE;

    if (darAnio(a) > darAnio(b))
        check = TRUE;
    else if ((darAnio(a) == darAnio(b)) && (darMes(a)  > darMes(b)))
        check = TRUE;
    else if ((darAnio(a) == darAnio(b)) && (darMes(a) == darMes(b)) && (darDia(a) > darDia(b)))
        check = TRUE;

    return check;
}

Boolean sonIgualesFechas(Fecha a, Fecha b)
{

    if((darAnio(a) == darAnio(b)) && (darMes(a) == darMes(b)) && (darDia(a) == darDia(b)) )
    {
        return TRUE;
    }
    return FALSE;
}

// Copia una fecha en otra fecha
void copFecha(Fecha &fec1, Fecha fec2)
{
    fec1.dia = darDia(fec2);
    fec1.mes = darMes(fec2);
    fec1.anio = darAnio(fec2);
}

