#include <stdio.h>
#include <stdlib.h>

// declaração da célula Node do tipo struct
typedef struct Node {
    int data; // atributo do nó do tipo inteiro
    struct Node* next; //ponteiro para o proximo elemento
    struct Node* prev; // ponteiro para o elemento anterior
} Node;

//lista inicialemnte vazia
Node* head = NULL;

// função para inserir elementos no inicio da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //alocação dinamica do novo elemento
    newNode->data = value; // atribui o valor fornecido ao novo nó
    newNode->next = head;
    newNode->prev = NULL; //newNode é o inicio, então o anterior é null
    
    if (head != NULL)
       head->prev = newNode;
  
    head = newNode;
    //printf("Elemento inserido na lista\n");
}

//função para deletar elemento da lista
void deleteNode(Node* node) {
    if (node == head) // verifica se é o primeiro elemento
        head = node->next;
    if (node->next != NULL) // verfica se tem um nó depois do a ser deletado
        node->next->prev = node->prev; //ajusta a ordem
    if (node->prev != NULL) // verfica se tem um nó antes do ser deletado
        node->prev->next = node->next; //ajusta a ordem
    free(node); // libera memória 
}

// função para imprimir toda a lista
void printList() {
    Node* temp = head; //começa a imprimir o valores pelo inicio
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; //passa para o proximo elemento
    }
    printf("\n");
}

void buscarElemento (int elemento){
    Node* nodeAtual = head; // começa a busca a partir do início da lista

    while (nodeAtual != NULL) { // percorre a lista até o fim
        if (nodeAtual->data == elemento) { // verifica se o nó atual contém o valor desejado
            // verifica se o nó anterior ou próximo existe para evitar acesso de ponteiro nulo
            printf("Valor %d encontrado. ", elemento);
            printf("Prev: %d, Next: %d\n", 
                nodeAtual->prev ? nodeAtual->prev->data : -1 , // imprime o valor do nó anterior ou -1 se for nulo
                nodeAtual->next ? nodeAtual->next->data : -1 ); // imprime o valor do nó próximo ou -1 se for nulo
            return; 
        }
        nodeAtual = nodeAtual->next; // move para o próximo nó
    }
}

int main() { 
    // declaração das variaveis
    int value; // elementos da lista 
    int num;
    int buscar; //elemento a ser buscado
    // chamando as funções 
    do { //loop para a inserção de elementos 
    printf ("Informe o elemento a ser inserido na lista: ");
    scanf("%d", &value);
    insertFront(value);
    
    printf("Digite o O se deseja parar e inserir elementos e 1 se deseja continuar: ");
    scanf("%d", &num);
    
    
    } while ( num == 1);
    printList(); //impressão da lisa
    printf("Informe o elemento a ser buscado na lista: ");
    scanf("%d", &buscar);
    buscarElemento(buscar); //chmamando a função buscar
    return 0;
}
