/*#include "AlumnoStruct.h"


//Devolver CI de alumno
long int darCiAlumno(alumno alu)
{
    return alu.ci;
}

//Devolver telefono alumno
long int darTelAlumno(alumno alu)
{
    return alu.telefono;
}

//Devolver nombre alumno
void darNomAlumno(alumno alu, String &s)
{
    strcop(s, alu.nombre);
}

//Devolver apellido alumno
void darApeAlumno(alumno alu, String &s)
{
    strcop(s, alu.apellido);
}

//Devolver fecha nacimiento alumno
Fecha darFechaAlumno(alumno alu)
{
    return alu.fNac;
}

//Devolver direccion alumno
void darDirAlumno(alumno alu, String &s)
{
    strcop(s, alu.direccion);
}

//Alta usuario, verificar que la fecha de nacimiento es valida
//Precondicion: el alumno no existe.
void cargarAlumno(alumno &alu)
{
    printf("\nIngrese el numero de cedula sin puntos ni guion: ");
    scanf("%ld", alu.ci);
    printf("\nIngrese el nombre: ");
    strscan(alu.nombre);
    printf("\nIngrese el apellido: ");
    strscan(alu.apellido);
    printf("\nIngrese la fecha de nacimiento (dd/mm/aaaa): ");
    cargarFecha(alu.fNac);
    printf("\nIngrese la direccion: ");
    strscan(alu.direccion);
    printf("\nIngrese el telefono: ");
    scanf("%ld", alu.telefono);
}
*/
