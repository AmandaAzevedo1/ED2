/*
O/*
O código abaixo realiza a impressão do vetor na ordem inversa.
1 - comente o código
2 - faça uma modificação para que seja possível inserir um vetor de n elementos.
*/

#include <stdio.h>

int main() {
    //declaração das variaveis fixas
    int vetor[5] = {0, 1, 2, 3, 4};
    int i, temp;
    int n=5;

    //for para inverter o vetor
    // n/2 para dividir o vetor e conseguir inverter as duas metades 
    for (i = 0; i < (n/2); i++) {
        temp = vetor[i];
        vetor[i] = vetor[n -1  - i]; //mudando as posições dos elementos
        vetor[n-1 - i] = temp;
    }
    
    //impressão do vetor invertido
    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
