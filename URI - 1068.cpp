#include <stdio.h>

int main() {	
	char expressao[1001], pAbre[1001], pFecha[1001];
	int topoA, topoF, i, err = 0;
	while(scanf("%s", &expressao) != EOF) { 
	  topoA=-1; 
	  topoF=-1;
	  for(i=0; expressao[i]!='\0'; i++) {
      if(expressao[i] == '(') {
				topoA++;
				pAbre[topoA] = expressao[i];
			}
      else if (expressao[i] == ')') {
      	if (topoA > topoF) {
      		topoF++;
					pFecha[topoF] = expressao[i];        	
				}
				else {
					err++;
				}
      }	
	  }
	  if(topoA == topoF && err == 0) printf("correct\n");
	  else printf("incorrect\n");
	}
return 0;



/* 

		     OR / OU          


int main() {	
	char expressao[1001];
	int i, abre, fecha;
	while(scanf("%s", &expressao) != EOF) { 
	  abre=0; 
	  fecha=0;
	  for(i=0; expressao[i]!='\0'; i++) {
      if(expressao[i] == '(') 
		abre++;
      	else if (expressao[i] == ')') {
          fecha++;
          if(abre>0){
            abre--;
            fecha--;
          }
       }
	   }
	  if(abre==0 && fecha==0) printf("correct\n");
	  else printf("incorrect\n");
	}
return 0;
}

*/


}
