#ifndef TALLER_H_INCLUDED
#define TALLER_H_INCLUDED
#include <stdio.h>

typedef enum {
    PASTAS,
    PASTELERIA_BASICA,
    PASTELERIA_AVANZADA,
    PANADERIA,
    VEGANA,
    MEDITERRANEA,
    PARRILLA,
    REPOSTERIA,
    ORIENTAL
}
nomTaller;

//===================================================================================================================

// Mostrar valor de taller en pantalla
void desplegarTaller(nomTaller t);

// Cargar valor de taller desde teclado
void cargarTaller(nomTaller &t);

#endif // TALLER_H_INCLUDED
