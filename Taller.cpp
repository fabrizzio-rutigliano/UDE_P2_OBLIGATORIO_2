#include "Taller.h"

// Cargar valor de taller desde teclado
void cargarTaller(nomTaller &t)
{
    int opcion;

    printf("Seleccione el taller:\n");
    printf(" 0 - PASTAS\n");
    printf(" 1 - PASTELERIA BASICA\n");
    printf(" 2 - PASTELERIA AVANZADA\n");
    printf(" 3 - PANADERIA\n");
    printf(" 4 - VEGANA\n");
    printf(" 5 - MEDITERRANEA\n");
    printf(" 6 - PARRILLA\n");
    printf(" 7 - REPOSTERIA\n");
    printf(" 8 - ORIENTAL\n");
    printf(":");

    scanf("%d", &opcion);

    while (opcion < 0 || opcion > 8)
    {
        printf("Opcion invalida. Ingrese un valor entre 0 y 8: ");
        scanf("%d", &opcion);
    }

    switch (opcion)
    {
    case 0:
        t = PASTAS;
        break;
    case 1:
        t = PASTELERIA_BASICA;
        break;
    case 2:
        t = PASTELERIA_AVANZADA;
        break;
    case 3:
        t = PANADERIA;
        break;
    case 4:
        t = VEGANA;
        break;
    case 5:
        t = MEDITERRANEA;
        break;
    case 6:
        t = PARRILLA;
        break;
    case 7:
        t = REPOSTERIA;
        break;
    case 8:
        t = ORIENTAL;
        break;
    }
}

// Mostrar valor de taller en pantalla
void desplegarTaller(nomTaller t)
{
    switch (t)
    {
    case PASTAS:
        printf("\nPASTAS ");
        break;
    case PASTELERIA_BASICA:
        printf("\nPASTELERIA BASICA ");
        break;
    case PASTELERIA_AVANZADA:
        printf("\nPASTELERIA AVANZADA ");
        break;
    case PANADERIA:
        printf("\nPANADERIA ");
        break;
    case VEGANA:
        printf("\nVEGANA ");
        break;
    case MEDITERRANEA:
        printf("\nMEDITERRANEA ");
        break;
    case PARRILLA:
        printf("\nPARRILLA ");
        break;
    case REPOSTERIA:
        printf("\nREPOSTERIA ");
        break;
    case ORIENTAL:
        printf("\nORIENTAL ");
        break;
    }
}
