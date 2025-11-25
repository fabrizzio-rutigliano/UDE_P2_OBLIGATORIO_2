#include "AlumnoStruct.h"

// ---------- CARGAR ---------------------------------------------

//Precondicion: el alumno no existe. Esto no va aca, es del Tree
void cargarAlumno(Alumno &alu)
{
    crearAlumno(alu);
    printf("\nIngrese el numero de cedula sin puntos ni guion: ");
    scanf("%ld", &alu.ci);
    fflush(stdin);

    printf("Ingrese el nombre: ");
    strScan(alu.nombre);

    printf("Ingrese el apellido: ");
    strScan(alu.apellido);

    printf("Ingrese la fecha de nacimiento (dd/mm/aaaa): ");
    do
    {
        cargarFecha(alu.fecha_nacimiento);
    }while (!esValidaFecha(alu.fecha_nacimiento));
    fflush(stdin);

    printf("Ingrese la direccion: ");
    strScan(alu.direccion);

    printf("Ingrese el telefono: ");
    scanf("%ld", &alu.telefono);
    fflush(stdin);
}

// Crear alumno, crea los strings del alumno
void crearAlumno(Alumno &alu)
{
    strCrear(alu.nombre);
    strCrear(alu.apellido);
    strCrear(alu.direccion);
}

// Libera la memoria de los strings del alumno
void destruirAlumno(Alumno &alu)
{
    strDestruir(alu.nombre);
    strDestruir(alu.apellido);
    strDestruir(alu.direccion);
}

// ---------- DESPLEGAR ---------------------------------------------

// Desplegar todos los datos del alumno por pantalla
void desplegarAlumno(Alumno alu)
{
    String nombre,apellido,direccion;
    strCrear(nombre);
    strCrear(apellido);
    strCrear(direccion);
    darNombreAlumno(alu, nombre);
    darApellidoAlumno(alu, apellido);
    darDireccionAlumno(alu, direccion);
    printf("---------------------------------\n");
    printf("Nombre: %s\n", nombre);
    printf("Apellido: %s\n", apellido);
    printf("Cedula: %ld\n", darCedulaAlumno(alu));
    printf("Fecha nacimiento:");
    mostrarFecha(alu.fecha_nacimiento);
    printf("\nDireccion: %s\n", direccion);
    printf("Telefono: %ld\n", darTelefonoAlumno(alu));
}

//Devolver CI de alumno
long int darCedulaAlumno(Alumno alu)
{
    return alu.ci;
}

//Devolver nombre alumno
void darNombreAlumno(Alumno alu, String &s)
{
    strCop(s, alu.nombre);
}

//Devolver apellido alumno
void darApellidoAlumno(Alumno alu, String &s)
{
    strCop(s, alu.apellido);
}

//Devolver fecha nacimiento alumno
Fecha darFechaNacAlumno(Alumno alu)
{
    return alu.fecha_nacimiento;
}

//Devolver direccion alumno
void darDireccionAlumno(Alumno alu, String &s)
{
    strCop(s, alu.direccion);
}

//Devolver telefono alumno
long int darTelefonoAlumno(Alumno alu)
{
    return alu.telefono;
}
