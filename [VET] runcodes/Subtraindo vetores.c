#include <stdio.h>

int main(void){
	
	const int tam=5;
	int vetA[tam], vetB[tam];
	int i=0,j=tam-1,sub;
	
	for(i=0; i<tam; i++){
		scanf("%d", &vetA[i]);
	}
	
	for(i=0;i<tam;i++){
		scanf("%d",&vetB[i]);
	}
	
	for(i=0;i<tam;i++){
		sub = vetA[i] - vetB[j];
		j--;
		printf("%d ", sub);
	}
}
