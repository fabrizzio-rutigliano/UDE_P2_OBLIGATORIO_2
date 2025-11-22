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

} Alumno;

// =================================================================================================================

// ---------- CARGAR ------------------------

//Alta usuario, verificar que la fecha de nacimiento es valida
//Precondicion: el alumno no existe.
void cargarAlumno(Alumno &alu);

// Libera la memoria de los strings del alumno
void destruirAlumno(Alumno &alu);

// ---------- DESPLEGAR ---------------------

// Desplegar todos los datos del alumno por pantalla
void desplegarAlumno(Alumno alu);

//Devolver CI de alumno
long int darCedulaAlumno(Alumno alu);

//Devolver nombre alumno
void darNombreAlumno(Alumno alu, String &s);

//Devolver apellido alumno
void darApellidoAlumno(Alumno alu, String &s);

//Devolver fecha nacimiento alumno
Fecha darFechaNacAlumno(Alumno alu);

//Devolver direccion alumno
void darDirAlumno(Alumno alu, String &s);

//Devolver telefono alumno
long int darTelAlumno(Alumno alu);

#endif // ALUMNOS_H_INCLUDED
