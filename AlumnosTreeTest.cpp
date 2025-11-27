#include "AlumnosTreeTest.h"

// Test carga y despliege de alumnos
void testCargarDesplegarAlumnos(AlumnoTree &alTree)
{

    int i;
    for (i = 0; i < NUM_ALU; i++)
    {
        Alumno alu;

        cargarAlumno(alu);
        insertarAlumnoOrdenado(alTree, alu);
    }
    ordenAlumnoTree(alTree);
    printf("______________________\n");
}

// Test eliminar alumno
void testEliminarAlumno()
{
    AlumnoTree alTree;
    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);

    eliminarAlumno(alTree, 1234);
    printf("RESULTADO TEST\n");
    ordenAlumnoTree(alTree);
    printf("______________________\n");
}

// Test existe alumno en arbol
void testExisteAlumnoTree()
{
    AlumnoTree alTree;
    Boolean existe = FALSE;

    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);

    existe = existeAlumnoTree(alTree, alTree->info);
    printf("RESULTADO TEST\n");
    printf("Existe alumno? %d", existe);
}

// Test contar alumnos por fecha de nacimiento
void testContarAlumnosFechaNac()
{
    AlumnoTree alTree;
    int cant = 0;
    Fecha f;
    f.anio = 79;
    f.mes = 07;
    f.dia = 07;

    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);
    cant = contarAlumnosFechaNac(alTree, f);
    printf("RESULTADO TEST\n");
    printf("Cantidad de alumnos con misma fecha de nacimiento %d", cant);
}

// Test contar alumnos apellido
void testContarAlumnosPorApellido()
{
    AlumnoTree alTree;
    int men = 0, may = 0, ig = 0;
    String apellido;

    strCrear(apellido);
    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);

    printf("Ingrese el apellido: ");
    strScan(apellido);

    contarAlumnosPorApellido(alTree, apellido, men, may, ig);
    printf("RESULTADO TEST\n");
    printf("Apellidos menores|mayores|iguales %d|%d|%d", men, may, ig);
}

// Test obtener alumno mayor edad
void testObtenerAlumnoMayorEdad()
{
    AlumnoTree alTree;
    Alumno alumno;
    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);

    alumno = obtenerAlumnoMayorEdad(alTree);
    printf("RESULTADO TEST\n");
    desplegarAlumno(alumno);
}

// Test listar alumnos sin registros
void testListarAlumnosSinRegistros()
{
    Registro reg;
    AlumnoTree alTree;
    Lista lista;
    crearLista(lista);
    crearAlumnoTree(alTree);
    testCargarDesplegarAlumnos(alTree);

    cargarRegistro(reg);
    insBackLista(lista, reg);
    desplegarLista(lista);

    printf("RESULTADO TEST\n");
    listarAlumnosSinRegistros(alTree, lista);
}