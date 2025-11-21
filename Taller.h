#ifndef TALLER_H_INCLUDED
#define TALLER_H_INCLUDED
#include <stdio.h>

// def tipos de datos
typedef enum {PASTAS, PASTELERIA, MILANESAS, PIZZAS, ENSALADAS, CHIVITOS, HAMBURGUESAS, COCTELERIA} nomTaller;



void desplegarTaller(nomTaller b);

void cargarTaller(nomTaller &b);

#endif // TALLER_H_INCLUDED
