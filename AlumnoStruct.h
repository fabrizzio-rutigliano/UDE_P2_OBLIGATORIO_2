#ifndef ALUMNOS_H_INCLUDED
#define ALUMNOS_H_INCLUDED
#include "String.h"
#include "Fecha.h"

typedef struct
{
    long int ci;
    String nombre;
    String apellido;
    Fecha fecha_nacimiento;
    String direccion;
    long int telefono;

}alumno;

//Devolver CI de alumno
long int darCiAlumno(alumno alu);

//Devolver telefono alumno
long int darTelAlumno(alumno alu);

//Devolver nombre alumno
void darNomAlumno(alumno alu, String &s);

//Devolver apellido alumno
void darApeAlumno(alumno alu, String &s);

//Devolver fecha nacimiento alumno
Fecha darFechaAlumno(alumno alu);

//Devolver direccion alumno
void darDirAlumno(alumno alu, String &s);

//Alta usuario, verificar que la fecha de nacimiento es valida
//Precondicion: el alumno no existe.
void cargarAlumno(alumno &alu);





#endif // ALUMNOS_H_INCLUDED
