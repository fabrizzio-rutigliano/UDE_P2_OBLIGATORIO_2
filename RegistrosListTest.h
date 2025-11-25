#ifndef REGISTROLISTTEST_H_INCLUDED
#define REGISTROLISTTEST_H_INCLUDED
#include "RegistrosList.h"

const int NUM_REG = 3;

//Test registros de finalización por alumno
void testListarRegistrosDeAlumno();

//Test registros finalizados posteriores a fecha
void testListarRegistrosPosterioresA();

//Test cuantos registros en fecha
void testContarRegistrosEnFecha();

//Test obtener nombre taller más popular
void testTallerMasPopular();

//Test cargar registros
void testCargaRegistros(Lista &lista);

#endif // REGISTROLISTTEST_H_INCLUDED