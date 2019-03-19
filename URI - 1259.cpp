#include <stdio.h>

void intercalarPares (int v[], int aux[], int inicio1, int inicio2, int fim2) {
	int ini1 = inicio1, ini2 = inicio2, fim1 = ini2-1, auxi=0, i;
	
 	while(ini1 <= fim1 && ini2 <= fim2) {
 		if (v[ini1] < v[ini2]) {
  			aux[auxi++] = v[ini1++];
  		}
  		else {
			aux[auxi++] = v[ini2++];
  		}
 	}
 	
	while(ini1 <= fim1) {
		aux[auxi++] = v[ini1++];
	}
	
 	while(ini2 <= fim2) {
  		aux[auxi++] = v[ini2++];
	}
 
 	for(i=0; i < auxi; i++) {
  		v[i + inicio1] = aux[i];
	}
}

void intercalarImpares (int v[], int aux[], int inicio1, int inicio2, int fim2) {
	int ini1 = inicio1, ini2 = inicio2, fim1 = ini2-1, auxi=0, i;
	
 	while(ini1 <= fim1 && ini2 <= fim2) {
 		if (v[ini1] > v[ini2]) {
  			aux[auxi++] = v[ini1++];
  		}
  		else {
			aux[auxi++] = v[ini2++];
  		}
 	}
 	
	while(ini1 <= fim1) {
		aux[auxi++] = v[ini1++];
	}
	
 	while(ini2 <= fim2) {
  		aux[auxi++] = v[ini2++];
	}
 
 	for(i=0; i < auxi; i++) {
  		v[i + inicio1] = aux[i];
	}
}

void mergeSortPares (int v[], int aux[], int parte1, int parte2) {
	int meio, i;
	if(parte1 < parte2) {
		meio = (parte1 + parte2)/2;
		mergeSortPares(v, aux, parte1, meio);
		mergeSortPares(v, aux, meio+1, parte2);
		intercalarPares(v, aux, parte1, meio+1, parte2);  
	}
}

void mergeSortImpares (int v[], int aux[], int parte1, int parte2) {
	int meio, i;
	if(parte1 < parte2) {
		meio = (parte1 + parte2)/2;
		mergeSortImpares(v, aux, parte1, meio);
		mergeSortImpares(v, aux, meio+1, parte2);
		intercalarImpares(v, aux, parte1, meio+1, parte2);  
	}
}
main() 
{
	int num, i, n;
	int npar=0, nimpar=0; 
	scanf("%d", &n);
	int pares[n], impares[n], aux[n];
	
	/* Separando pares e impares no ato de leitura*/
	for (i=0; i<n; i++) {
		scanf("%d", &num);
		if(num%2 == 0) {
			pares[npar] = num;
			npar++;
		}
		else {
			impares[nimpar] = num;	
			nimpar++;
		}
	}

	/*ordenando os pares*/
	mergeSortPares(pares, aux, 0, npar-1);	
	
	/*ordenando os impares*/
	mergeSortImpares(impares, aux, 0, nimpar-1);	
	
	
	for (i=0; i<npar; i++) {
		printf("%d - ", pares[i]);
	}
	puts("---");
	for (i=0; i<nimpar; i++) {
		printf("%d - ", impares[i]);
	}
}
