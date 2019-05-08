#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "funcoes.h"

void Menu(int *num);
void Menu_1();
void Menu_2();
void Menu_3();
void Menu_4();
void Menu_5();
void opcao(char op[]);

void Menu(int *num) {
 printf("\nAGENDA\n\n");

 printf("*---------------------------*\n");
 printf("| 1 - Insere Contatos       |\n");
 printf("|---------------------------|\n");
 printf("| 2 - Imprime Contatos      |\n");
 printf("|---------------------------|\n");
 printf("| 3 - Busca de Contatos     |\n");
 printf("|---------------------------|\n");
 printf("| 4 - Retira Contato        |\n");
 printf("|---------------------------|\n");
 printf("| 5 - Altera Contato        |\n");
 printf("|---------------------------|\n");
 printf("| 6 - Sair                  |\n");
 printf("*---------------------------*\n");

 printf("\nDigite uma opcao = ");
 scanf("%d",num);
 getchar();
}

void Menu_1() {
 system("cls");
 printf("*------------------*\n");
 printf("| INSERIR CONTATOS |\n");
 printf("*------------------* \n");
}

void Menu_2() {
 system("cls");
 printf("*---------------------*\n");
 printf("| VIZUALIZAR CONTATOS |\n");
 printf("*---------------------* \n");
}

void Menu_3() {
 system("cls");
 printf("*-------------------*\n");
 printf("| PESQUIZAR CONTATO |\n");
 printf("*-------------------* \n");
}

void Menu_4() {
 system("cls");
 printf("*-------------------*\n");
 printf("|  EXCLUIR CONTATO  |\n");
 printf("*-------------------* \n");
}

void Menu_5() {
	system("cls");
	printf("*-------------------*\n");
	printf("|  ALTERAR CONTATO  |\n");
	printf("*-------------------* \n");
}

void opcao(char op[]) {
  printf("\n\nDeseja continuar sim = s ou nao = n\n");
  fflush(stdin);
  gets(op);
}


main() {
 int num;
 char Nome[100], op[2];

 Arvore *raiz;
 raiz = NULL;

 while(num!=6) {
  Menu(&num);
  switch(num) {
    case 1:
		  do {
		  	Menu_1();
		  	ler_string(Nome);
		   	inserir(&raiz, Nome);
		   	opcao(op);
		  } while(*op == 's' || *op =='S');
      break;
      
    case 2:
	    Menu_2();
	    imprimir(raiz);
	    getch();
	    break;
	    
    case 3:
    	Menu_3();
    	ler_string(Nome);
     	busca(raiz,Nome);
     	break;
     	
    case 4:
      do {
       	Menu_4();
       	ler_string(Nome);
       	opcao(op);
       	if(*op == 'n' || *op =='N') break;
        	excluir(&raiz,Nome);break;
       } while(*op =='s' || *op =='S');
      break;
      
    case 5:
    	Menu_5();
    	ler_string(Nome);
    	Altera(&raiz,Nome);
    	break;
    } 
		system("cls");
 }
}
