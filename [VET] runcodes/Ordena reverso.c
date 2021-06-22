#include <stdio.h>

int main(void){
	
	int vet1[10], vet2[10], vet3[20]; //vetores
	int i, j; //contadores
	int max, y;

	for(i=0; i<10; i++){ //vetor 1
		scanf("%d", &vet1[i]);
	}
	
	for(i=0; i<10; i++){ //vetor 2
		scanf("%d", &vet2[i]);
	}
	
	//ele para aqui
	
	j=0;
	for(i=0; i<10; i++){ //unindo os dois vetores intercalando eles
		vet3[j] = vet1[i];
		j++;
		vet3[j] = vet2[i];
		j++;
	}
	
	j=0;
	for(i=0; i<20; i++){ //ordenação
		max = i; 
		for(j=i+1;j<20;j++){
			if(vet3[j] > vet3[max])
			max = j;
		}
		

		y = vet3[i];
		vet3[i] = vet3[max];
		vet3[max] = y;
				
	}
		
	for (i=0;i<20;i++)
	   printf("%d ", vet3[i]);
	   
}
