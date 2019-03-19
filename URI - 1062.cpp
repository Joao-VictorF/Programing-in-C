#include <stdio.h>

struct pilha{ /* Criando struct padr�o da pilha */
  int topo;
  int vet[1010];
};

struct pilha criapilha() { /* Fun��o que ajuda a criar structs no padr�o de pilha */
  struct pilha P;
  P.topo = -1;
  return P;
}

int pilhatopo(struct pilha P) { /* Fun��o que retorna o elemento no topo da pilha */
  return P.vet[P.topo];
}

struct pilha push(int valor, struct pilha P) { /* Fun��o que adiciona um valor � pilha (P) */
  P.topo++;
  P.vet[P.topo] = valor;
  return P;
}

struct pilha pop(struct pilha P) { /* Fun��o que apaga o elemento do topo da pilha (P) */
  P.topo--;       
  return P;
}

main () {
	int i, j, cont, tam, valor; 
	/*i e j = usados nos for's 
	  cont = pra determinar se a resposta � NO ou YES 
	  tam = quantidade de vag�es que ser�o lidos
	  valor = pra receber o numero do vag�o
	*/
	struct pilha trem, tremaux, estacao; 
	/* criando as structs. 
	   trem -> os primeiros vag�es.
	   tremaux -> que recebe os vag�es que n�o podem ir pra esta��o ainda
	   estacao -> pilha final onde os vag�es s�o agrupados.
	*/	 
	while(1) {
    scanf("%d", &tam); 
    if(tam == 0) //se o numero de vag�es for 0, o programa encerra.
      break;
    while(1) {
      cont = 0;
      trem = criapilha();
      tremaux = criapilha();
      estacao = criapilha();
      for(i=0;i<tam;i++){
        scanf("%d",&valor);
        if(valor==0)
          break;
        trem = push(valor, trem);
      }
      if(valor==0){
        printf("\n");
        break;
    	}
      for(i=0;i<tam;i++){
        tremaux = push(pilhatopo(trem),tremaux);
        trem = pop(trem);
      }

      for(i=1;i<=tam;i++){
        estacao = push(i, estacao);
        if(pilhatopo(estacao) == pilhatopo(tremaux)){
          estacao = pop(estacao);
          tremaux = pop(tremaux);
          cont++;
          for(j=i;j>=1;j--) {
            if(pilhatopo(estacao) == pilhatopo(tremaux)) {
                estacao = pop(estacao);
                tremaux = pop(tremaux);
                cont++;
            } 
						else
              break;
          }
        }
      }

      if(cont < tam)
        printf("No\n");
      else
        printf("Yes\n");
    }
  }
}


