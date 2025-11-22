#include "Menu.h"



 //Menu inicial con opciones AB, Listado y Consultas
void desplegarMenuPrincipal()
{
    printf("\nBienvenido al sistema de gestion de talleres...");
    printf("\n1 - Alta y Baja de alumnos");
    printf("\n2 - Listados");
    printf("\n3 - Consultas");
}

void desplegarMenuAB()
{
    printf("\nMenu de Altas y Bajas...");
    printf("\n1 - Alta alumno");
    printf("\n2 - Alta de registro de finalizacion de taller");
    printf("\n3 - Baja de alumno");//Borrarlo de AlumnosTree y RegistrosList
}

void desplegarMenuListados()
{
    printf("\nMenu de Listados...");
    printf("\n1 - Listar todos los alumnos registrados"); //orden CI menor a mayor
    printf("\n2 - Listar alumnos que no han completado ningun taller");//orden CI menor a mayor, datos del alumno todos en misma linea
    printf("\n3 - Listar talleres finalizados por un alumno"); //submenu que solicita CI, ordenados en forma cronológica, datos de cada registro en misma linea
    printf("\n3 - Listar Talleres finalizados despues de una fecha"); //submenu que pide fecha, ordena cronologicamente, datos de cada registro en misma linea
}

void desplegarMenuConsultas()
{
    printf("\nMenu de Consultas...");
    printf("\n1 - Mostrar cantidad de alumnos nacidos en una fecha");//submenu pide fecha
    printf("\n2 - Mostrar apellidos menores, mayores e iguales");//submenu pide apellido
    printf("\n3 - Mostrar registros de finalizacion en una fecha"); //submenu que solicita fecha
    printf("\n3 - Mostrar taller mas popular"); //mostrar nombre y cantidad de registros, si hay mas de uno, mostrar uno solo
}


//submenu que solicita CI
void desplegarMenuSolicitaCi()
{
    printf("\nIngrese la CI: ");
}


//submenu que pide fecha
void desplegarMenuFinalizadosFecha()
{
    printf("\nIngrese la fecha: ");
}

//submenu que pide apellido
void desplegarMenuApellido()
{
    printf("\nIngrese el apellido: ");
}
