#include <stdio.h>
main () {
	int n, i, j;
	
	
	while(scanf("%d",&n) != EOF) {
		while (n < 3 || n > 70 ) {
			scanf("%d",&n);
		}
		int matriz[n][n];
		
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++){
				if(i+j == n-1) {
					matriz[i][j] = 2;
				} 
				else 
					if (i == j) {
						matriz[i][j] = 1;	
					}
					else {
						matriz[i][j] = 3;	
					}
			}
		}
		
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				printf ("%2d", matriz[i][j]);
			} printf("\n");
		} printf("-------------------------\n");
	}
}
