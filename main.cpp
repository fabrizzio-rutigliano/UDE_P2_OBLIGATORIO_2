#include "Archivos.h"
#include "AlumnosTree.h"
#include "RegistrosList.h"

using namespace std;

int main()
{

    //validar existencia archivo Alumnos, sino crearlo.
    if (!existeArchivo("Alumnos.txt"))
    {
        crearArchivo("Alumnos.txt");
        printf("\nse crea archivo Alumnos");

    }
    else
        printf("\nya existe Alumnos");
    //abrir archivo alumnos, cargar en memoria alumnosTree


    //cerrar archivo alumnos




    //validar existencia archivo registros, sino crearlo.
    if (!existeArchivo("Registros.txt"))
    {
        crearArchivo("Registros.txt");
        printf("\nse crea archivo Registros");

    }
    else
        printf("\nya existe Registros");
    //abrir archivo registro, cargar en memoria registroslist


    //cerrar archivo registros


    //Menu inicial con opciones AB, Listado y Consultas


    //Menu de AB

    //Menu de Listado

    //Menu de Consultas















    //abrir y sobreescribir archivos con todos los datos
    //cerrar archivos

}
