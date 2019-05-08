#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct arvore {
	char Nome[100];
	int telefone;
	struct arvore *esq;
	struct arvore *dir;
};
typedef struct arvore Arvore;

void inserir(Arvore **raiz, char string[]);
void imprimir(Arvore *raiz);
void busca(Arvore *raiz,char string[]);
void Altera( Arvore **raiz, char *string);
void excluir(Arvore **raiz,char string[]);
Arvore** menor_dir(Arvore *raiz);
Arvore** maior_esq (Arvore *raiz);
void ler_string(char string[]);
void ler_telefone(int *telefone);

void inserir(Arvore **raiz , char string[]) {
 int telefone;
 if(*raiz == NULL) { // Se a raiz não existir, um nó é criado.
  *raiz = (Arvore*) malloc (sizeof(Arvore));
  strcpy((*raiz)->Nome, string);
  ler_telefone(&telefone);
  (*raiz)->telefone = telefone;
  (*raiz)->esq = NULL;
  (*raiz)->dir = NULL;
 }
 else {
  if(strcasecmp((*raiz)->Nome, string) > 0) { // Se o nome for maior q o nome da raiz
  	inserir(&(*raiz)->esq, string);
	}
		else {
    	if(strcasecmp((*raiz)->Nome,string) < 0) { // Se o nome for menor q o nome da raiz
      	inserir(&(*raiz)->dir, string);
      }
				else {
          if(strcmp((*raiz)->Nome,string) == 0) { // Se o nome existir na lista
             printf("Nome ja foi registrado\n");
             getch();
					}
				}
		}
	}
}

void imprimir(Arvore *raiz) {
	if(raiz!=NULL) {
	  imprimir((raiz)->esq);
	  printf("\n\nNome = ");
	  printf("%s",(raiz)->Nome);
	  printf("\nTelefone = ");
	  printf("%d",(raiz)->telefone);
	  imprimir((raiz)->dir);	
	}
}

void busca(Arvore *raiz, char string[]) {
 	if(raiz!=NULL) {
		if(strcasecmp((raiz)->Nome, string) > 0) {
  		busca((raiz)->esq, string);
    }	 
			else {
      	if(strcasecmp((raiz)->Nome,string) < 0) {
          busca((raiz)->dir,string);
    		} 
				else {
          if(strcmp((raiz)->Nome,string) == 0) {
	          system("cls");
	          printf("REGISTRO ENCONTRADO!!\n");
	          printf("\n\nNome = ");
	          printf("%s",(raiz)->Nome);
	          printf("\nTelefone = ");
	          printf("%d",(raiz)->telefone);
	          getch();
					}
				}
			}
	}
		else {
	  	system("cls");
		  printf("*-----------------------*\n");
		  printf("| Nome nao encontrado!! |\n");
		  printf("*-----------------------*\n");
		  getch();
		}
}

void Altera( Arvore **raiz, char *string) {
	if((*raiz)!=NULL) {
		if(strcasecmp((*raiz)->Nome, string) > 0) {
    	Altera(&(*raiz)->esq, string);
  	}
			else {
      	if(strcasecmp((*raiz)->Nome,string) < 0) {
          Altera(&(*raiz)->dir, string);
    		}
				else {
        	if(strcmp((*raiz)->Nome,string) == 0) {
	          system("cls");
	          int telefone;
	          printf("REGISTRO ENCONTRADO!!\n");
	          printf("\n\nNome = ");
	          printf("%s",(*raiz)->Nome);
	          printf("\nNovo Telefone = ");
	          scanf("%d",&telefone);
	          (*raiz)->telefone= telefone;
	          Sleep(1000);
	          system("cls");
	           
	          printf("*-----------------*\n");
	          printf("| Dado Alterado!! |\n");
	          printf("*-----------------*\n");
	          getch();
					}
				}
			}
		}
		else {
			system("cls");
		  printf("*-----------------------*\n");
		  printf("| Nome nao encontrado!! |\n");
		  printf("*-----------------------*\n");
		  getch();
		}	
}

void excluir(Arvore **raiz,char string[]) {
	Arvore **aux2, *aux3;
	if(*raiz!=NULL) {
		if( strcasecmp((*raiz)->Nome, string) == 0 ) {
		  if((*raiz)->esq == (*raiz)->dir) {
			  free(*raiz);
			  *raiz = NULL;
	   	} 
				else {
			    if((*raiz)->esq != NULL) {
						aux2 = maior_esq(*raiz);
						aux3 = *aux2;
						(*aux2) = (*aux2)->esq;
			  	}
						else { 
			        aux2 = menor_dir(*raiz);
			        aux3 = *aux2;
			        (*aux2) = (*aux2)->dir;
			      }
			    strcpy((*raiz)->Nome, aux3->Nome);
			    (*raiz)->telefone = aux3->telefone;
			    free(aux3); aux3 = NULL;
	  		}
			}
			else {
		    if (strcasecmp(string,(*raiz)->Nome)<0) {
		       excluir(&(*raiz)->esq, string);
		    } 
					else {
			      excluir(&(*raiz)->dir, string);
			    }
	  	}
	}
  else { // Caso não encontre o nome
    system("cls");
    printf("*-----------------------*\n");
    printf("| Nome nao encontrado!! |\n");
    printf("*-----------------------*\n");
    getch();
  }
}

Arvore** maior_esq (Arvore *raiz) {
	Arvore **aux = &(raiz);
	if((*aux)->esq != NULL) {
		aux = &(*aux)->esq;
	 	while( (*aux)->dir != NULL ) {
	  	aux = &(*aux)->dir;
		}
	}
	return aux;
}

Arvore** menor_dir(Arvore *raiz) {
  Arvore **aux = &(raiz);
  if((*aux)->dir != NULL) {
    aux = &(*aux)->dir;
    while((*aux)->esq != NULL) {
      aux=&(*aux)->esq;
    }
	}
  return aux;
}

void ler_telefone(int *telefone) { // ler o telefone
 printf("\nDigite o Telefone = ");
 scanf("%d",telefone);
}

void ler_string(char string[]) { // ler uma string
	printf("\nDigite o Nome = ");
	fflush(stdin);
	gets(string);
}

