#include <iostream>
#include "Taller.cpp"

int main()
{
    //cout << "Hello world" << endl;
    //return 0;

    // Prueba de taller enumerado
    nomTaller t;
    cargarTaller(t);
    desplegarTaller(t);

}

/*#include "Archivos.h"
#include "AlumnosTree.h"
#include "RegistrosList.h"

using namespace std;

int main()
{
    int seleccion;
    //validar existencia archivo Alumnos, sino crearlo.
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





    //Menu inicial con opciones AB, Listado y Consultas

    desplegarMenuPrinciapal();
    scanf(&seleccion);
    switch(seleccion)
    {
        case 1:
            int seleccionSubMenu;
            //Menu AB
            desplegarMenuAB();
            scanf(&seleccionSubMenu);
        break;
        case 2:
            int seleccionSubMenu;
            //Menu de Listado
            desplegarMenuListados();
            scanf(&seleccionSubMenu);
        break;
        case 3:
            int seleccionSubMenu;
            //Menu de Consultas
            desplegarMenuConsultas();
            scanf(&seleccionSubMenu);
        break;
    }




















    //abrir y sobreescribir archivos con todos los datos
    //cerrar archivos

}
*/
