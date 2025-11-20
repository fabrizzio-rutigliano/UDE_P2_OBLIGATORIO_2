#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "Boolean.h"

const int MAX = 80;
typedef char * String;


/* crea un string vacío */
void strcrear (string &s);

/* libera la memoria usada por el string */
void strdestruir (string &s);

/* devuelve el largo del string s */
int strlar (string s);

/* copia el contenido del string s2 en s1 */
void strcop (string &s1, string s2);

/* lee el string s desde teclado */
void scan (string &s);

/* concatena el contenido de s2 al final de s1 */
void strcon (string &s1, string s2);

/* intercambia los contenidos de s1 y s2 */
void strswp (string &s1, string &s2);

/* imprime el string s por pantalla */
void print (string s);

/* determina si s1 es alfabéticamente menor que s2 */
boolean strmen (string s1, string s2);

/* determina si los strings s1 y s2 son iguales */
boolean streq (string s1, string s2);



#endif // STRING_H_INCLUDED
