#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>


//Menu Principal
void desplegarMenuPrincipal();

//submenu de Altas y Bajas
void desplegarMenuAB();

//submenu de Listados
void desplegarMenuListados();

//submenu de consultas
void desplegarMenuConsultas();

//submenu que solicita CI
void desplegarMenuSolicitaCi();

//Precondicion: fecha valida
//submenu que pide fecha
void desplegarMenuFinalizadosFecha();

//submenu que pide apellido
void desplegarMenuApellido();

//Muestra un valor entero en pantalla
void desplegarInt(int a);

//Muestra los valores  menores, mayores e iguales para la consulta por apellidos
void desplegarMayMenIg(int men, int may, int ig);

//Muestra no existencia de alumno con cedula ci
void desplegarNoExisteAlumno(long int ci);

//Muestra la cantidad de alumnos nacidos nacidos
void desplegarCantAlumnosNacidosEnFecha(int cant);

//Muestra la cantidad de registros finalizados
void desplegarCantRegistrosFinalizados(int cant);

//Muestra la no existencia de taller popular
void desplegarNoExistenciaTallerPopular();

// Muestra si encontro un archivo de registro
void desplegarArchRegEncontrado();

// Muestra si encontro un archivo de alumnos
void desplegarArchAluEncontrado();

// Muestra que aún no hay registros en alumnos
void desplegarNoExisteArbolAlumno();

// Muestra que la fecha ingresada es invalida
void desplegarAdvertenciaFecha();

// Muestra que la fecha ingresada es menor a la ultima ingresada en la lista
void desplegarAdvertenciaFechaList();

#endif // MENU_H_INCLUDED
