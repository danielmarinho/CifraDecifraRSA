#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[]) {
    int dois_bytes;
    FILE *ptr_entrada;
    FILE *ptr_saida;
    int chave_privada[] = {argv[2], argv[3]};


    ptr_entrada = fopen(argv[0], "rb");
    ptr_saida = fopen(argv[1], "wb");
    size_t bytes_lidos;

    bytes_lidos = fread(dois_bytes, 2, 1, ptr_entrada);
    if (bytes_lidos == 2) {
        printf("2 bytes lidos com sucesso!");
    } else { // error handling
        if (feof(ptr_entrada))
            printf("Erro: arquivo terminou inesperadamente\n");
        else if (ferror(ptr_entrada)) {
            perror("Erro ao ler arquivo");
        }
    }

}

