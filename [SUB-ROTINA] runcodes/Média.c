#include <stdio.h>

// Elabore uma sub-rotina que leia um número não determinado de valores
// positivos e retorne a média aritmética desses valores. 
// A condição de parada se dá ao entrar um valor negativo.
float media(void);

int main(void)
{
	printf("%.2f", media());	
	
	return 0;
}

float media(){
	
	int x,i=0;
	float soma=0, media;
	
	do{
		
		scanf("%d",&x);
		if(x<0)
			break;
		else{
			
			i++;
			soma += x;
			
		}
		
	}while(x>0); 
	
	media = soma / i;
	
	return media;
	
}
