#include "RegistrosListTest.h"

//Test registros de finalización por alumno
void testListarRegistrosDeAlumno(){
    Lista lista;
    crearLista(lista);
    testCargaRegistros(lista);
    printf("RESULTADO TEST\n");
    listarRegistrosDeAlumno(lista, 1234);
}

//Test registros finalizados posteriores a fecha
void testListarRegistrosPosterioresA(){
    Lista lista;
    Fecha f;
    f.anio = 26;
    f.mes = 04;
    f.dia = 01;
    crearLista(lista);
    testCargaRegistros(lista);
    printf("RESULTADO TEST\n");
    listarRegistrosPosterioresA(lista, f);
}

//Test cuantos registros en fecha
void testContarRegistrosEnFecha(){
    Lista lista;
    Fecha f;
    f.anio = 26;
    f.mes = 10;
    f.dia = 10;
    int count;
    crearLista(lista);
    testCargaRegistros(lista);
    count = contarRegistrosEnFecha(lista, f);
    printf("RESULTADO TEST\n");
    printf("Cantidad de registros en fecha %d", count);
}

//Test obtener nombre taller más popular
void testTallerMasPopular(){
    Lista lista;
    Fecha f;
    f.anio = 25;
    f.mes = 10;
    f.dia = 01;
    nomTaller t;
    int cantidad = 0;

    crearLista(lista);
    testCargaRegistros(lista);
    tallerMasPopular(lista, t, cantidad);
    printf("RESULTADO TEST\n");
    printf("El taller mas popular es %d, con cantidad de registros %d", t, cantidad);
}

// Test cargar registros
void testCargaRegistros(Lista &lista)
{
    int i;
    for (i = 0; i < NUM_REG; i++)
    {
        Registro reg;
        cargarRegistro(reg);
        insBackLista(lista, reg);
    }
    desplegarLista(lista);
}
