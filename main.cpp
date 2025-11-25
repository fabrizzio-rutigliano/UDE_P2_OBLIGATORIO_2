#include <iostream>
//------includes utilizados por los modulos de testing, evaluar su eliminación en versión final.
/*
#include "RegistroStructTest.h"
#include "TallerTest.h"
#include "AlumnoStructTest.h"
#include "RegistrosListTest.h"

int main()
{

    // Prueba taller
    //testCargarDesplegarTaller();

    // Prueba carga y despliegue registro
    //testCargaDespliegeRegistro();

    // Prueba carga y despliegue alumno
    //testCargaDespliegeAlumno();

    // Pruebas sobre RegistrosList
    //testListarRegistrosDeAlumno();
    //testListarRegistrosPosterioresA();
    //testContarRegistrosEnFecha();
    testTallerMasPopular();

    return 0;
}
*/


#include "Archivos.h"
#include "AlumnosTree.h"
#include "RegistrosList.h"
#include "Menu.h"

//using namespace std;

int main()
{

    int seleccion, seleccionSubMenu;
    AlumnoTree aTree;
    crearAlumnoTree(aTree);
    Lista regList;
    crearLista(regList);
    Alumno alu;
    //validar existencia archivo Alumnos, sino crearlo.
    /*
    if (!existeArchivo("Alumnos.txt"))
    {
        crearArchivo("Alumnos.txt");
        printf("\nse crea archivo Alumnos");

    }
    else
        printf("\nya existe Alumnos");

    //cargar en memoria alumnosTree







    //validar existencia archivo registros, sino crearlo.
    if (!existeArchivo("Registros.txt"))
    {
        crearArchivo("Registros.txt");
        printf("\nse crea archivo Registros");

    }
    else
        printf("\nya existe Registros");

    //cargar en memoria registroslist
*/




    //Menu inicial con opciones AB, Listado y Consultas

    desplegarMenuPrincipal();
    scanf("%d", &seleccion);
    switch(seleccion)
    {
        case 1:
            //Menu AB
            desplegarMenuAB();
            scanf("%d", &seleccionSubMenu);
            switch(seleccionSubMenu)
            {
                case 1:

                    cargarAlumno(alu);
                    if(!existeAlumnoTree(aTree, alu))
                        insertarAlumnoOrdenado(aTree, alu);
                    destruirAlumno(alu);
                case 2:

                    cargarAlumno(alu);
                    insertarAlumnoOrdenado(aTree, alu);
                    destruirAlumno(alu);
            }
        break;
        case 2:
            //Menu de Listado
            desplegarMenuListados();
            scanf("%d", &seleccionSubMenu);
        break;
        case 3:
            //Menu de Consultas
            desplegarMenuConsultas();
            scanf("%d", &seleccionSubMenu);
        break;
    }




















    //abrir y sobreescribir archivos con todos los datos
    //cerrar archivos

}

