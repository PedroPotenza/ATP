#include <stdio.h>

int main(void){
	
	int L[15], LP[10]; //variaveis
	int i=0, j=0; //contadores
	
	for(i=0;i<15;i++){ //logica
		scanf("%d", &L[i]);
	}
	
	for(i=0;i<10;i++){ //linguagem de programa��o
		scanf("%d", &LP[i]);
	}
	
	for(i=0;i<10;i++){ //repetir o segundo vetor para comparar cada matricula dele com a do primeiro vetor
		for(j=0; j<15; j++){ //repeti��o para comparar cada valor
			if(LP[i] ==  L[j]) //se for igual, printa, se n for, vai para o outro valor de L
				printf("%d ", LP[i]);	
		}	
	}
	
	
}
