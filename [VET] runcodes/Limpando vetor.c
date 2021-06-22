#include <stdio.h>

int main(void){
	
	int vetA[20], vetB[20];
	int i=0, j=0;
	
	for(i=0; i<20; i++){
		scanf("%d",&vetA[i]);
		
		if(vetA[i] > 0){
			vetB[j] = vetA[i];
			j++;
		}
	}
	
	for(i=0; i<j; i++)
		printf("%d ", vetB[i]);
	
}
