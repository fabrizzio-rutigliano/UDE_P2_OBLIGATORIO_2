#include <iostream>
//------includes utilizados por los modulos de testing, evaluar su eliminación en versión final.
/*
#include "RegistroStructTest.h"
#include "TallerTest.h"
#include "AlumnoStructTest.h"
#include "RegistrosListTest.h"
#include "AlumnosTreeTest.h"

int main()
{

    // Prueba taller
    //testCargarDesplegarTaller();

    // Prueba carga y despliegue registro
    //testCargaDespliegeRegistro();

    // Prueba carga y despliegue alumno
    testCargaDespliegeAlumno();

    // Pruebas sobre RegistrosList
    //testListarRegistrosDeAlumno();
    //testListarRegistrosPosterioresA();
    //testContarRegistrosEnFecha();
    //testTallerMasPopular();

    //AlumnoTree alTree;
    //crearAlumnoTree(alTree);
    //testCargarDesplegarAlumnos(alTree);
    //testEliminarAlumno();
    //testExisteAlumnoTree();
    //testContarAlumnosFechaNac();
    //testContarAlumnosPorApellido();
    //testObtenerAlumnoMayorEdad();
    //testListarAlumnosSinRegistros();
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
    String fAlu, fReg, straux;
    strCrear(fAlu);
    strCrear(fReg);
    strCop(fAlu,"Alumnos.txt");
    strCop(fReg,"Registros.txt");
    int seleccion, seleccionSubMenu, men, may, ig;
    AlumnoTree aTree;
    crearAlumnoTree(aTree);
    Lista regList;
    crearLista(regList);
    Alumno alu;
    Registro reg;
    long int ci;
    Fecha fe;
    nomTaller tall;

    //validar existencia archivo Alumnos,
    //cargar en memoria alumnos tree
    if (existeArchivo(fAlu))
    {
        printf("\nya existe Alumnos");
        Levantar_AlumnoTree(aTree, fAlu);
    }



    //validar existencia archivo registros
    //cargar en memoria registroslist
    if (existeArchivo(fReg))
    {
        printf("\nya existe Registros");
        Levantar_Lista(regList, fReg);

    }








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
                               if(existeAlumnoTreeCi(aTree,reg.cedula))
                               {
                                   if(esListaVacia(regList))
                                        insBackLista(regList, reg);
                                   else if(esMayorFechas(darFechaFin(reg),darFechaFin(ultimoRegistro(regList))) || sonIgualesFechas(darFechaFin(reg),darFechaFin(ultimoRegistro(regList))))
                                       insBackLista(regList, reg);
                                }
                                else
                                    noExisteAlumno();
                               break;
                           case 3:
                               cargarCedula(ci);
                               if(existeAlumnoTreeCi(aTree, ci))
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
                            strCrear(straux);
                            strScan(straux);
                            contarAlumnosPorApellido(aTree, straux, men, may, ig);
                            desplegarMayMenIg(men, may, ig);
                        break;
                        case 3:
                            cargarFecha(fe);
                            desplegarInt(contarRegistrosEnFecha(regList,fe));
                        break;
                        case 4:
                            tallerMasPopular(regList, tall, ig);
                            desplegarTaller(tall);
                            desplegarInt(ig);

                        break;
                        case 5:
                            desplegarAlumno(obtenerAlumnoMayorEdad(aTree));
                        break;
                    }

                }while(seleccionSubMenu!=0);
            break;
        }


    }while(seleccion!=0);





    //abrir y sobreescribir archivos con todos los datos
    Bajar_AlumnoTree(aTree, fAlu);
    Bajar_Lista(regList, fReg);

    //destruir elementos creados
    strDestruir(fAlu);
    strDestruir(fReg);
    destruirAlumnoTree(aTree);
    destruirLista(regList);










}

