#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()  {
    setlocale(LC_ALL, "Portuguese");
    /* A declara��o de uma matriz de 2 dimens�es exige um ponteiro para ponteiro */

    int **p;
    int i, j, k, x;

    printf("Digite a dimens�o da matriz ->");
    scanf("%d %d", &i, &j);

    /*
        Aloca��o da primeira dimens�o. Internamente, a fun��o calloc far� uma multiplica��o da
        quantidade de elementos pelo tamanho de cada elemento para saber quanto de mem�ria
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
            printf("Digite o n�mero para o �ndice [%d][%d] ->", k, x);
            scanf("%d", &p[k][x]);
        }
    }

    for(k = 0; k < i; k++) {
        for(x = 0; x < j; x++) {
            printf("\n[%d][%d] -> [%d]\n", k, x, p[k][x]);
        }
    }

    printf("Liberando mem�ria alocada");
    for(k = 0; k < i; k++) {
        free(p[k]); // PRIMEIRO A LINHA DA MATRIZ
    }
    free(p); // DEPOIS LIBERAR A MEM�RIA DO VETOR QUE CONTINHA AS LINHAS

    return 0;
}
