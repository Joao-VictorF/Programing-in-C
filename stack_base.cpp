#include <stdio.h>
#include <stdlib.h>

struct Node{
	int num;
  struct Node *prox;
};
typedef struct Node node;

int tam;

void inicia(node *PILHA);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);

int main(void) {
	node *PILHA = (node *) malloc(sizeof(node));
	if(!PILHA) {
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else {
		inicia(PILHA);
	}
}

void inicia(node *PILHA) {
	PILHA->prox = NULL;
	tam=0;
}

int vazia(node *PILHA) {
	if(PILHA->prox == NULL) return 1;
	else return 0;
}

node *aloca() {
	node *novo=(node *) malloc(sizeof(node));
	if(!novo) {
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else {
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}

void exibe(node *PILHA) {
if(vazia(PILHA)){
	printf("PILHA vazia!\n\n");
	return ;
}

	node *tmp;
	tmp = PILHA->prox;
	printf("PILHA:");
	while (tmp != NULL) {
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n    ");
	int count;
	for(count=0 ; count < tam ; count++)
	printf("  ^  ");
	printf("\nOrdem:");
	for(count=0 ; count < tam ; count++)
	printf("%5d", count+1);
	
	
	printf("\n\n");
}

void libera(node *PILHA) {
	if(!vazia(PILHA)){
  	node *proxNode,
  	*atual;
  	atual = PILHA->prox;
  	while(atual != NULL){
   		proxNode = atual->prox;
   		free(atual);
   		atual = proxNode;
  	}
  }
}

void push(node *PILHA) {
	node *novo=aloca();
	novo->prox = NULL;
	
	if(vazia(PILHA)) PILHA->prox=novo;
	else {
		node *tmp = PILHA->prox;
		while(tmp->prox != NULL)
	 		tmp = tmp->prox;
		tmp->prox = novo;
		}
	tam++;
}


node *pop(node *PILHA) {
	if(PILHA->prox == NULL){
		printf("PILHA ja vazia\n\n");
		return NULL;
	}
	else {
		node *ultimo = PILHA->prox,
		*penultimo = PILHA;
		while(ultimo->prox != NULL){
			penultimo = ultimo;
		 	ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
		tam--;
		return ultimo;
		}
}

