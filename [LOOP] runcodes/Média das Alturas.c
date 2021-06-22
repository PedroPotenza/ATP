#include <stdio.h>

int main(void){
	
	float idade, h, soma=0, i=0;
	
	do{
		
		
		scanf("%f", &idade);
		if(idade<=0){
			break;
		}
		scanf("%f", &h);
		
		if(idade> 50){
		i++;
		soma = soma + h;
		}
		
	}while(idade >= 0);
	
	printf("%f", soma/i);
}
