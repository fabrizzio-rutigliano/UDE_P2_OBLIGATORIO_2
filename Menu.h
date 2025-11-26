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

#endif // MENU_H_INCLUDED
