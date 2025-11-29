#include "AlumnoStruct.h"

// ---------- CARGAR ---------------------------------------------

// Precondicion: el alumno no existe. Esto no va aca, es del Tree
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
    } while (!esValidaFecha(alu.fecha_nacimiento));
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
    String nombre, apellido, direccion;
    strCrear(nombre);
    strCrear(apellido);
    strCrear(direccion);
    darNombreAlumno(alu, nombre);
    darApellidoAlumno(alu, apellido);
    darDireccionAlumno(alu, direccion);
    printf("\n");
    printf("| ");
    strPrint(nombre);
    printf(" | ");
    strPrint(apellido);
    printf("| %ld | ", darCedulaAlumno(alu));
    mostrarFecha(alu.fecha_nacimiento);
    printf(" | ");
    strPrint(direccion);
    printf(" | %ld ", darTelefonoAlumno(alu));
    strDestruir(nombre);
    strDestruir(apellido);
    strDestruir(direccion);
}

// Desplegar datos de cedula, nomre y apellido alumno
void desplegarAlumnoReducido(Alumno alu)
{
    String nombre, apellido;
    strCrear(nombre);
    strCrear(apellido);
    darNombreAlumno(alu, nombre);
    darApellidoAlumno(alu, apellido);
    printf("\n");
    printf(" | ");
    strPrint(nombre);
    printf(" | ");
    strPrint(apellido);
    printf("| %ld | ", darCedulaAlumno(alu));
    strDestruir(nombre);
    strDestruir(apellido);
}

// Devolver CI de alumno
long int darCedulaAlumno(Alumno alu)
{
    return alu.ci;
}

// Devolver nombre alumno
void darNombreAlumno(Alumno alu, String &s)
{
    strCop(s, alu.nombre);
}

// Devolver apellido alumno
void darApellidoAlumno(Alumno alu, String &s)
{
    strCop(s, alu.apellido);
}

// Devolver fecha nacimiento alumno
Fecha darFechaNacAlumno(Alumno alu)
{
    return alu.fecha_nacimiento;
}

// Devolver direccion alumno
void darDireccionAlumno(Alumno alu, String &s)
{
    strCop(s, alu.direccion);
}

// Devolver telefono alumno
long int darTelefonoAlumno(Alumno alu)
{
    return alu.telefono;
}

// Copiar un Alumno en otro
void copAlu(Alumno &al1, Alumno al2)
{
    crearAlumno(al1);
    darNombreAlumno(al2, al1.nombre);
    darApellidoAlumno(al2, al1.apellido);
    darDireccionAlumno(al2, al1.direccion);
    al1.ci = al2.ci;
    al1.telefono = al2.telefono;
    copFecha(al1.fecha_nacimiento, al2.fecha_nacimiento);
}

// ---------- ARCHIVO STRUCT ALUMNO --------------

// Escribe en el archivo los datos del alumno alu.
// Precondición: El archivo viene abierto para escritura.
void Bajar_Alumno(Alumno alu, FILE *f)
{
    fwrite(&alu.ci, sizeof(long int), 1, f);
    Bajar_String(alu.nombre, f);
    Bajar_String(alu.apellido, f);
    Bajar_Fecha(alu.fecha_nacimiento, f);
    Bajar_String(alu.direccion, f);
    fwrite(&alu.telefono, sizeof(long int), 1, f);
}

// Lee desde el archivo los datos del registro reg.
// Precondición: El archivo viene abierto para lectura.
void Levantar_Alumno(Alumno &alu, FILE *f)
{
    // Cedula
    fread(&alu.ci, sizeof(long int), 1, f);
    // Nombre
    strCrear(alu.nombre);
    Levantar_String(alu.nombre, f);
    // Apellido
    strCrear(alu.apellido);
    Levantar_String(alu.apellido, f);
    // Fecha
    Levantar_Fecha(alu.fecha_nacimiento, f);
    // Direccion
    strCrear(alu.direccion);
    Levantar_String(alu.direccion, f);
    // Telefono
    fread(&alu.telefono, sizeof(long int), 1, f);
}
