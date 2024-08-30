#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, soma = 0;
    int colunas =3;
    int linhas = 3;
    int **matriz;
    
    //alocação dinamica usando malloc
    matriz = malloc ( sizeof (int*) *linhas);
    for (int i=0; i <linhas;  i++){
        matriz[i] = malloc ( sizeof (int) * colunas );
    } 
    printf("Insira os elementos da matriz 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }
    

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    free(matriz); //liberando a memoria 
    return 0;
}

