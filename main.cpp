#include <iostream>
#include "Archivos.h"
#include "AlumnosTree.h"
#include "Menu.h"

int main()
{
    String fAlu, fReg, straux;
    strCrear(fAlu);
    strCrear(fReg);
    strCop(fAlu, "Alumnos.txt");
    strCop(fReg, "Registros.txt");
    int seleccion, seleccionSubMenu, men, may, ig, numTaller;
    AlumnoTree aTree;
    crearAlumnoTree(aTree);
    Lista regList;
    crearLista(regList);
    Alumno alu;
    Registro reg;
    long int ci;
    Fecha fe;
    nomTaller tall;

    // validar existencia archivo Alumnos,
    // cargar en memoria alumnos tree
    if (existeArchivo(fAlu))
    {
        desplegarArchAluEncontrado();
        Levantar_AlumnoTree(aTree, fAlu);
    }

    // validar existencia archivo registros
    // cargar en memoria registroslist
    if (existeArchivo(fReg))
    {
        desplegarArchRegEncontrado();
        Levantar_Lista(regList, fReg);
    }

// Menu inicial con opciones AB, Listado y Consultas

    do
    {
        desplegarMenuPrincipal();
        scanf("%d", &seleccion);
        switch (seleccion)
        {
        case 1:
            do
            {
                // Menu AB
                desplegarMenuAB();
                scanf("%d", &seleccionSubMenu);
                switch (seleccionSubMenu)
                {
                case 1:
                    cargarAlumno(alu);
                    if (!existeAlumnoTree(aTree, alu))
                        insertarAlumnoOrdenado(aTree, alu);
                    destruirAlumno(alu);
                    break;
                case 2:
                    cargarRegistro(reg);
                    if (existeAlumnoTreeCi(aTree, darCedula(reg)))
                    {
                        if (esListaVacia(regList))
                            insBackLista(regList, reg);
                        else if (esMayorFechas(darFechaFin(reg), darFechaFin(ultimoRegistro(regList))) || sonIgualesFechas(darFechaFin(reg), darFechaFin(ultimoRegistro(regList))))
                            insBackLista(regList, reg);
                        else
                            desplegarAdvertenciaFechaList();
                    }
                    else
                        desplegarNoExisteAlumno(darCedula(reg));
                    break;
                case 3:
                    cargarCedula(ci);
                    if (existeAlumnoTreeCi(aTree, ci))
                        eliminarAlumno(aTree, ci);
                    else
                        desplegarNoExisteAlumno(ci);
                    if (existeAlumnoRegistro(regList, ci))
                        eliminarOcurrenciaLista(regList, ci);
                    break;
                default:
                    break;
                }
            } while (seleccionSubMenu != 0);
            break;

        case 2:
            do
            {
                // Menu de Listado
                desplegarMenuListados();
                scanf("%d", &seleccionSubMenu);
                switch (seleccionSubMenu)
                {
                case 1:
                    if (!esVacioAlumnoTree(aTree))
                        ordenAlumnoTree(aTree);
                    else
                        desplegarNoExisteArbolAlumno();
                    break;
                case 2:
                    if (esVacioAlumnoTree(aTree))
                        desplegarNoExisteArbolAlumno();
                    else
                        listarAlumnosSinRegistros(aTree, regList);
                    break;
                case 3:
                    cargarCedula(ci);
                    if (existeAlumnoTreeCi(aTree, ci))
                    {
                        listarRegistrosDeAlumno(regList, ci);
                    }
                    else
                    {
                        desplegarNoExisteAlumno(ci);
                    }
                    break;
                case 4:
                    do
                    {
                        cargarFecha(fe);
                        if(!esValidaFecha(fe))
                            desplegarAdvertenciaFecha();
                    } while (!esValidaFecha(fe));
                    listarRegistrosPosterioresA(regList, fe);
                    break;
                default:
                    break;
                }
            } while (seleccionSubMenu != 0);
            break;
        case 3:
            do
            {
                // Menu de Consultas
                desplegarMenuConsultas();
                scanf("%d", &seleccionSubMenu);
                switch (seleccionSubMenu)
                {
                case 1:
                    do
                    {
                        cargarFecha(fe);
                        if(!esValidaFecha(fe))
                            desplegarAdvertenciaFecha();
                    } while (!esValidaFecha(fe));
                    desplegarCantAlumnosNacidosEnFecha(contarAlumnosFechaNac(aTree, fe));
                    break;
                case 2:
                    desplegarMenuApellido();
                    strCrear(straux);
                    strScan(straux);
                    men = 0;
                    may = 0;
                    ig = 0;
                    contarAlumnosPorApellido(aTree, straux, men, may, ig);
                    desplegarMayMenIg(men, may, ig);
                    break;
                case 3:
                    do
                    {
                        cargarFecha(fe);
                        if(!esValidaFecha(fe))
                            desplegarAdvertenciaFecha();
                    } while (!esValidaFecha(fe));
                    desplegarCantRegistrosFinalizados(contarRegistrosEnFecha(regList, fe));
                    break;
                case 4:
                    numTaller = 0;
                    tallerMasPopular(regList, tall, numTaller);
                    if (numTaller == 0)
                    {
                        desplegarNoExistenciaTallerPopular();
                    }
                    else
                    {
                        desplegarTaller(tall);
                        desplegarInt(numTaller);
                    }
                    break;
                case 5:
                    if (!esVacioAlumnoTree(aTree))
                        desplegarAlumnoReducido(obtenerAlumnoMayorEdad(aTree));
                    else
                        desplegarNoExisteArbolAlumno();
                    break;
                }

            } while (seleccionSubMenu != 0);
            break;
        }

    } while (seleccion != 0);

    // Abrir y sobreescribir archivos con todos los datos
    Bajar_AlumnoTree(aTree, fAlu);
    Bajar_Lista(regList, fReg);

    // Destruir elementos creados
    strDestruir(fAlu);
    strDestruir(fReg);
    destruirAlumnoTree(aTree);
    destruirLista(regList);
}
