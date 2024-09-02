#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // representação de um elemento da fila
    int data; // para armazenamento de elementos inteiros 
    struct Node* next; // ponteiro para o proximo elemento
} Node;

typedef struct Queue { //declaração do tipo de fila
    Node* front; //ponteiro para o elemento do inicio da fila
    Node* rear; //ponteiro para o elemento do fim da fila
} Queue;

Queue* createQueue() { //função para criar a fila
    Queue* q = (Queue*)malloc(sizeof(Queue)); //alocação dinâmica da fila
    if (q == NULL) { //verificando a alocação da fila
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;//fila inicialemnte vazia
    return q;
}

void enqueue(Queue* q, int value) { //função para adicionar elemento/nó a fila
    Node* newNode = (Node*)malloc(sizeof(Node)); //alocação dinâmica para o novo nó
    if (newNode == NULL) { //verificando a alocação do nó
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;//atribuindo valor ao novo nó
    newNode->next = NULL; //novo nó é o ultimo elemento
    if (q->rear == NULL) { //if para verfificar se a fila esta vazia
        q->front = q->rear = newNode; // se estiver, o novo nó é o inicio e fim da fila
    } else { // se a fila não está vazia 
        q->rear->next = newNode; //o ultimo elemento da fila vira o novo nó
        q->rear = newNode;
    }
}

int dequeue(Queue* q) { // função pra remover o primeiro elemento da fila 
    if (q->front == NULL) { //if para verificar se a fila está vazia 
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front; //atribuindo ao ponteiro temp o endereço do elemento inicial
    int data = temp->data; //atribuindo o valor do elemento inicial 
    q->front = q->front->next; //mudando o elemento inial da fila
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);//liberando memória
    return data;
}

int isEmpty(Queue* q) {  //função para verificar se a fila está vazia 
    return q->front == NULL; //o inicio esta vazio
}

void printQueue(Queue* q) { //função para imprimir os elementos da fila
    if (isEmpty(q)) { //if para verificar se a fila esta vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front; //atribuindo ao ponteiro temp o enderenço do elemento do inicio da fila
    printf("Elementos da fila: ");
    while (temp != NULL) { //estrutura para imprimir os elementos 
        printf("%d ", temp->data); //atribuindo o valor de cada elemento
        temp = temp->next; //passando o endereço do proximo elemento da fila
    }
    printf("\n");
}

void limparFila (Queue* q){ //função para limpar a fila 
    if (isEmpty(q)) { //if para verificar se a fila esta vazia
        printf("A fila está vazia.\n");
        return;
    } else {
        Node* temp= q->front; //declarando uma variavel aux
        do {
            q->front =q->front->next; //estrutura de repetição 
            free(temp);                // que passará por todos os elementos da fila 
            temp = q->front;           //atribuindo os valores do inicio a varievel aux e depois liberando memoria
        } while (temp!=NULL); //interromper somente quando o aux não tiver nenhum elemento
        printf("Fila esvaziada\n");
    }
    
}
void contarElementos (Queue* q){ //função para contar os elementos da fila 
    if (isEmpty(q)) { //if para verificar se a fila esta vazia
        printf("A fila está vazia.\n");
        return;
    } else {
        int contador =0; //declarando o contador e iniciando como 0
        Node* temp = q->front; //declarando uma variavel aux
        do {
            q->front =q->front->next; //estrutura de repetição 
            free(temp);               //que passará por todos os elementos da fila   
            temp = q->front;          //atribuindo os valores do inicio a varievel aux e depois liberando memoria
            contador++;   //aumentando o valor do contador cada vez que a estrutura é repetida
        } while(temp!=NULL); //interromper somente quando o aux não tiver nenhum elemento
        printf("A fila possui %d elementos\n", contador);
    }
    
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);//inserindo elementos na fila 
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);//imprimindo a fila 
    printf("Desenfileirado: %d\n", dequeue(q));//retirando o primeiro elemento da fila
    printQueue(q); //imprimindo os valores da fila após a retirada
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    enqueue(q, 40);//inserindo novos elementos na fila para ultilizar a função limpar 
    enqueue(q, 50);
    enqueue(q, 60);
    printQueue(q);
    contarElementos(q);//chamando a função contar elementos 
    limparFila(q);//chamando a função limpar fila
    

    return 0;
}
