#include "Archivos.h"

// ---------- CONSULTAR ------------
// Determina si existe o no un archivo con el nombre recibido por parámetro
Boolean existeArchivo(String nomArch)
{
    Boolean existe = FALSE;
    FILE * f;
    f = fopen (nomArch, "rb");

    if(f != NULL)
    {
        existe = TRUE;
        fclose(f);
    }
    return existe;
}
