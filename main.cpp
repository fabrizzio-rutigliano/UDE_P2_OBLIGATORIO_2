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

    int seleccion, seleccionSubMenu, men, may, ig;
    AlumnoTree aTree;
    crearAlumnoTree(aTree);
    Lista regList;
    crearLista(regList);
    Alumno alu;
    Registro reg;
    long int ci;
    Fecha fe;
    String ape;
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


    do
    {
        desplegarMenuPrincipal();
        scanf("%d", &seleccion);
        switch(seleccion)
        {
            case 1:
                do
                {
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
                               break;
                           case 2:
                               cargarRegistro(reg);
                               if(esMayorFechas(darFechaFin(reg),darFechaFin(ultimoRegistro(regList))) || sonIgualesFechas(darFechaFin(reg),darFechaFin(ultimoRegistro(regList))))
                                   insBackLista(regList, reg);
                               break;
                           case 3:
                               cargarCedula(ci);
                               if(existeAlumnoTree(aTree, buscarNodoAlumnoPorCI(aTree, ci)->info))
                                   eliminarAlumno(aTree, ci);
                               if(existeAlumnoRegistro(regList, ci))
                                   eliminarOcurrenciaLista(regList, ci);
                               break;
                           default:
                               break;
                    }
                }while(seleccionSubMenu!=0);
            break;


            case 2:
                do
                {
                    //Menu de Listado
                    desplegarMenuListados();
                    scanf("%d", &seleccionSubMenu);
                    switch(seleccionSubMenu)
                    {
                        case 1:
                            ordenAlumnoTree(aTree);
                            break;
                        case 2:
                            listarAlumnosSinRegistros(aTree, regList);
                            break;
                        case 3:
                            cargarCedula(ci);
                            listarRegistrosDeAlumno(regList, ci);
                            break;
                        case 4:
                            cargarFecha(fe);
                            listarRegistrosPosterioresA(regList, fe);
                            break;
                        default:
                            break;
                    }
                }while(seleccionSubMenu!=0);
            break;
            case 3:
                do
                {
                    //Menu de Consultas
                    desplegarMenuConsultas();
                    scanf("%d", &seleccionSubMenu);
                    switch(seleccionSubMenu)
                    {
                        case 1:
                            cargarFecha(fe);
                            desplegarInt(contarAlumnosFechaNac(aTree,fe));
                        break;
                        case 2:
                            desplegarMenuApellido();
                            strCrear(ape);
                            strScan(ape);
                            contarAlumnosPorApellido(aTree, ape, men, may, ig);
                            desplegarMayMenIg(men, may, ig);
                        break;
                        case 3:
                            cargarFecha(fe);
                            desplegarInt(contarRegistrosEnFecha(regList,fe));
                        break;
                        case 4:


                        break;
                        case 5:

                        break;
                    }

                }while(seleccionSubMenu!=0);
            break;
        }


    }while(seleccion!=0);

















        //abrir y sobreescribir archivos con todos los datos
        //cerrar archivos

}

