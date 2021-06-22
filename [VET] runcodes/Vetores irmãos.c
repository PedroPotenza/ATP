#include <stdio.h>

int main(void){
	
	int vet1[10], vet2[5], soma=0; //variaveis
	int i=0, div=0, j=0; //contadores
	
	for(i=0; i<10; i++){
		scanf("%d", &vet1[i]);	
	}
	
	for(i=0; i<5; i++){
		scanf("%d", &vet2[i]);
		soma += vet2[i]; //soma de todos os valores de vet2
	}

	for(i=0; i<10; i++){ //percorrer o vet 1 todo descobrindo quem é par
		if(vet1[i] % 2 == 0)
			printf("%d ",vet1[i] + soma);	//se for ja printa somando
	}
	
	for(i=0; i<10; i++){ //percorrer o vet 1 todo descobrindo quem é impar
		div=0; //zero os divisores para poder fazer o proximo valor do vet 2 sem interferencias.
		if(vet1[i] % 2 != 0){
			for(j=0; j<5; j++){ //percorrer o vet 2 para ver quais valores são divisores do valor de vet 1
				if(vet1[i] % vet2[j] == 0)
				div++;				
			}
		printf("%d ", div);
		}
					
	}
	
	
}
