#include <stdio.h>

main() {
	int i, j, k, l, n, hn, a , b;
	
	while(1) {
		scanf("%d", &n);	/* ler o numero de linhas x colunas */
		if(n==0) break; /* se for zero o programa se encerra*/
		int matriz[n][n]; /* crio uma matriz N x N*/
		hn = n/2; 
		if(n%2==1) hn++;
		a = 0;
		b = n-1; 
		
		
		/*CRIANDO A MATRIZ*/
		for (l=1; l <= hn; l++) {
			for(i=a; i <= b; i++) {
				for (j=a; j <= b; j++) {	
					matriz[i][j] = l;
				}
			}
			a++; b--;
		}	
		
		
		/*MOSTRANDO A MATRIZ*/
		for(i=0; i < n; i++) {
			for (j=0; j < n; j++) {
				if (j == 0) 
					printf ("%3d", matriz[i][j]);
				else
					printf (" %3d", matriz[i][j]);
			} printf("\n");
		} printf("\n");
	}
	
}
