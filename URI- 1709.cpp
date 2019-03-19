#include <stdio.h>
int main() {
	int n, posicao, QuantEmbaralhamentos;
	posicao = 2; 
	QuantEmbaralhamentos = 1;
	scanf("%d", &n);
  	while (n < 2 || n > 200000) {
  		scanf("%d", &n); 
	}
  	if (n%2 == 0) {
  		while(posicao != 1) {
			if(posicao <= n/2) {
	      		posicao += posicao;
	    	}
			else {
		     	posicao -= (n - posicao + 1);
			}
			QuantEmbaralhamentos++;
		}
	}
	else 
		n = 0;	  	    	 	 	  	
	printf("%d", QuantEmbaralhamentos);
}
