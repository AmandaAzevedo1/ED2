#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int *pilha; //declarando a pilha como ponteiro para a alocação dinâmica 
int topo = -1;
int tamMax = MAX_SIZE; //declarando uma variavel com o tam max

void push(int elemento) { //função para adicionar elementos na pilha
    
    if (topo < tamMax - 1) { // se não atingiu o tam max
        pilha[++topo] = elemento; 
    } else { // se atingiu o tam max
        tamMax *=2; // dobrando o tam
        int *novaPilha = realloc(pilha, tamMax * sizeof(int)); //expansão dinâmica
        
        pilha = novaPilha; // atualiza o ponteiro da pilha para o novo endereço de memória
        pilha[++topo] = elemento; // adiciona o novo elemento
    }
}  


int pop() { //função para remover o ultimo elemento inserido
    if (topo == -1) { //verificando se a pilha está vazia 
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--]; //chamando a operação conhecida como desimpilhar 
    }
}

int top() { // função para verificar qual o elemento do topo
    if (topo == -1) { //verificando se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];// retornando o elemento do topo
    }
}

void imprimir() { // função pra imprimir os elementos da pilhas
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) { // for para imprimir do ultimo inserido até o primeiro
        printf("%d ", pilha[i]);      // elemento inserido
    }
    printf("\n");
}

int pilhaVazia(){ //função implentada para verificar se a pilha etá vazia
    if(topo == -1){ // se o topo possui o valor inicializado, ainda não foi inserido nenhum valor
        printf("Pilha vazia!\n");
        return 1; 
    } return 0; // return 0 se não está vazia
}
int main() {
    pilha = malloc(tamMax * sizeof(int)); //alocação do tam inicial da pilha 
    pilhaVazia(); //chamando a função para verificar se a pilha está vazia
    push(10); // chamando a função de inserir elementoss
    push(20);
    push(30);
    push(40); //adicionando um novo elemento para ultrapassar o tam max 
    imprimir(); // imprimindo os valores inseridos na pilha 
    printf("Elemento no topo: %d\n", top()); //chamando e informando a função para o elemento do topo
    printf("Elemento removido: %d\n", pop()); // chamando a função para remover o último elemento inserido
    imprimir(); // imprimindo os valores da pilha sem o elemento removido
    return 0;
}
