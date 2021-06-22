#include <stdio.h>

int main(void){
	
	
	float x, soma=0, i=0;
	
	scanf("%f", &x);
	
	for(i=1;i<=x; i++)
	{
		soma = soma + 1/i;	
	}

	printf("%f", soma);
	
}
