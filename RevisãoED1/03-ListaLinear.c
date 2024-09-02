//Escolhi implementar a função adicional buscar 
#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

//Implementação da função buscar
void buscar(int elemento) {
  int posicao;
  for (int i =0; i< tamanho; i++){
    if (lista[i] == elemento){
      posicao=i;
      printf("Posição: %d\n", posicao);
    }
  }
}
int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    buscar(30);
    imprimir();
    remover(1);
    imprimir();
    return 0;
}
