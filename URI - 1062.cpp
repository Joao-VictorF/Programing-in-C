#include <stdio.h>

struct pilha{ /* Criando struct padrão da pilha */
  int topo;
  int vet[1010];
};

struct pilha criapilha() { /* Função que ajuda a criar structs no padrão de pilha */
  struct pilha P;
  P.topo = -1;
  return P;
}

int pilhatopo(struct pilha P) { /* Função que retorna o elemento no topo da pilha */
  return P.vet[P.topo];
}

struct pilha push(int valor, struct pilha P) { /* Função que adiciona um valor à pilha (P) */
  P.topo++;
  P.vet[P.topo] = valor;
  return P;
}

struct pilha pop(struct pilha P) { /* Função que apaga o elemento do topo da pilha (P) */
  P.topo--;       
  return P;
}

main () {
	int i, j, cont, tam, valor; 
	/*i e j = usados nos for's 
	  cont = pra determinar se a resposta é NO ou YES 
	  tam = quantidade de vagões que serão lidos
	  valor = pra receber o numero do vagão
	*/
	struct pilha trem, tremaux, estacao; 
	/* criando as structs. 
	   trem -> os primeiros vagões.
	   tremaux -> que recebe os vagões que não podem ir pra estação ainda
	   estacao -> pilha final onde os vagões são agrupados.
	*/	 
	while(1) {
    scanf("%d", &tam); 
    if(tam == 0) //se o numero de vagões for 0, o programa encerra.
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


