#include "Taller.h"

//cargar datos de Taller

//PASTAS, PASTELERIA, MILANESAS, PIZZAS, ENSALADAS, CHIVITOS, HAMBURGUESAS, COCTELERIA

void cargarTaller(nomTaller &b){
    int valor;
    do{
        printf ("\nIngrese la opcion deseada \n0 - Pastas, 1 - Pasteleria,  2 - Milanesas, 3 - Pizzas, 4 - Ensaladas, 5 - Chivitos, 6 - Hamburguesas, 7 - Cocteleria: ");
        scanf ("%d",& valor);

        switch(valor)
        {
            case 0:
                    b = PASTAS;
                break;
            case 1:
                    b = PASTELERIA;
                break;
            case 2:
                    b = MILANESAS;
                break;
            case 3:
                    b = PIZZAS;
                break;
            case 4:
                    b = ENSALADAS;
                break;
            case 5:
                    b = CHIVITOS;
                break;
            case 6:
                    b = HAMBURGUESAS;
                break;
            case 7:
                    b = COCTELERIA;
                break;
            default:
            break;
        }

    } while (valor != 0 && valor != 1 && valor != 2 && valor != 3 && valor != 4 && valor != 5 && valor != 6 && valor != 7);
}

void desplegarTaller(nomTaller b){
     switch(b)
        {
            case PASTAS:
                    printf("\nPastas");
                break;
            case PASTELERIA:
                    printf("\nPasteleria");
                break;
            case MILANESAS:
                    printf("\nMilanesas");
                break;
            case PIZZAS:
                    printf("\nPizzas");
                break;
            case ENSALADAS:
                    printf("\nEnsaladas");
                break;
            case CHIVITOS:
                    printf("\nChivitos");
                break;
            case HAMBURGUESAS:
                    printf("\nHamburguesas");
                break;
            case COCTELERIA:
                    printf("\nCocteleria");
                break;
            default:
            break;
        }
}
