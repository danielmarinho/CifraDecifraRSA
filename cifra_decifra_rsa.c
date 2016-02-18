#include <stdio.h>
#include <stdlib.h>


/*
 * Argumentos:
 * - b: base da exponenciação.
 * - e: expoente.
 * - n: módulo (n > 1).
 * Retorna: b^e (mod n).
 */

unsigned short binExp(unsigned short b, int e, unsigned short n) {

    unsigned int res = b;
    unsigned int y = 1;

    /* Caso base. */
    if (e == 0) return (1);

    while (e > 1) {

        if (e & 1) {

            /*
             * Caso especial: expoente é ímpar.
             * Acumular uma potência de ’res’ em ’y’.
             */
            y = (y * res) % (unsigned int) n;
            e = e - 1;
        }

        /*
         * Elevamos ’res’ ao quadrado, dividimos expoente por 2.
         */
        res = (res * res) % (unsigned int) n;
        e = e / 2;
    }

    return ((unsigned short) ((res * y) % n));
}

void cifra(){
    
}

void decifra(){
    
}

int main(int argc, char** argv) {
    printf("Ola Mundo");
    return (EXIT_SUCCESS);
}

