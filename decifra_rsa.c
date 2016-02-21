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
    int dois_bytes[2];
    FILE *ptr_entrada;
    FILE *ptr_saida;
    char *end1;
    char *end2;
    int chave_privada[] = {strtol(argv[3], &end1, 10), strtol(argv[4], &end2, 10)};
    printf("%d %d", chave_privada[0], chave_privada[1]);
    printf("Hello World");

    ptr_entrada = fopen(argv[1], "rb");
    ptr_saida = fopen(argv[2], "wb");
    //size_t bytes_lidos;

    //bytes_lidos = fread(dois_bytes, 2, 1, ptr_entrada);
    while (fread(dois_bytes, 2, 1, ptr_entrada) == 2) {
        int m[2] = {binExp(dois_bytes[0],chave_privada[1],chave_privada[0]),binExp(dois_bytes[1],chave_privada[1],chave_privada[0])};
        fwrite(m,1,1,ptr_saida);
        
    }

    if (feof(ptr_entrada))
        printf("Erro: arquivo terminou inesperadamente\n");
    else if (ferror(ptr_entrada)) {
        perror("Erro ao ler arquivo");
    }

}

