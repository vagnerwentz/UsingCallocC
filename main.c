#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()  {
    setlocale(LC_ALL, "Portuguese");
    /* A declaração de uma matriz de 2 dimensões exige um ponteiro para ponteiro */

    int **p;
    int i, j, k, x;

    printf("Digite a dimensão da matriz ->");
    scanf("%d %d", &i, &j);

    /*
        Alocação da primeira dimensão. Internamente, a função calloc fará uma multiplicação da
        quantidade de elementos pelo tamanho de cada elemento para saber quanto de memória
        deve ser alocada.
    */

    p = calloc(i, sizeof(int));
    if(p == NULL) {
        printf("ERRO");
        exit(1);
    }

    for(k = 0; k < i; k++) {
        p[k] = calloc(j, sizeof(int));
        if(p[k] == NULL) {
            printf("\nERRO");
        }
    }

    for(k = 0; k < i; k++) {
        for(x = 0; x < j; x++) {
            printf("Digite o número para o índice [%d][%d] ->", k, x);
            scanf("%d", &p[k][x]);
        }
    }

    for(k = 0; k < i; k++) {
        for(x = 0; x < j; x++) {
            printf("\n[%d][%d] -> [%d]\n", k, x, p[k][x]);
        }
    }

    printf("Liberando memória alocada");
    for(k = 0; k < i; k++) {
        free(p[k]); // PRIMEIRO A LINHA DA MATRIZ
    }
    free(p); // DEPOIS LIBERAR A MEMÓRIA DO VETOR QUE CONTINHA AS LINHAS

    return 0;
}
