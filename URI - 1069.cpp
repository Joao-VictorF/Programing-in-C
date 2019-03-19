



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
	char terra[1010], dAbre[1010], dFecha[1010];  
	//terra -> string que vai guardar a entrada. Ex: <..><<<.>>
	//dAbre e dFecha -> guardam os diamantes abrindo e fechando.
  int i, j, diamante, num; 
	// i e j = usados nos for's / diamante = contador de diamantes extraidos / num = quantidade de repetições
	int topoA, topoF;   
  
  scanf("%d", &num);
  while (num!= 0) {
      scanf("%s", terra);
      diamante = 0;
      for (i = 0; i < strlen(terra); i++) { //enquanto i for menor que o tamanho da string terra. (tamanho = qnt de caracteres)
          if (terra[i] == '\0')
              break;
          if (terra[i] == '<') {
          	topoA++;
          	dAbre[topoA] = terra[i]; //ce parou aqui. continua ai.
              for (j = i; j< strlen(terra); j++) { //enquanto j for menor que o tamanho da string terra. (tamanho = qnt de caracteres)
                  if (terra[j] == '>'){
                      diamante++;
                      terra[j] = '0';
                      break;
                  }
              }
          }
      }
      printf("%d\n", diamante);
      num--;
  }
  return 0;
  /* 

		     OR / OU          

	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main() {
    int i, j, diamante, rept; // i e j = usados nos for's / diamante = contador de diamantes extraidos / rept = quantidade de repetições 
    char terra[1010]; // string que vai guardar a entrada. Ex: <..><<<.>>
    scanf("%d", &rept);
    while (rept--){
        scanf("%s", terra);
        diamante = 0;
        for (i = 0; i < strlen(terra); i++) { //enquanto i for menor que o tamanho da string terra. (tamanho = qnt de caracteres)
            if (terra[i] == '\0')
                break;
            if (terra[i] == '<') {
                for (j = i; j< strlen(terra); j++) { //enquanto j for menor que o tamanho da string terra. (tamanho = qnt de caracteres)
                    if (terra[j] == '>'){
                        diamante++;
                        terra[j] = '0';
                        break;
                    }
                }
            }
        }
        printf("%d\n", diamante);
    }
    return 0;
	}

	*/

}
