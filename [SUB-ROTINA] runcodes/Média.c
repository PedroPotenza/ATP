#include <stdio.h>

// Elabore uma sub-rotina que leia um n�mero n�o determinado de valores
// positivos e retorne a m�dia aritm�tica desses valores. 
// A condi��o de parada se d� ao entrar um valor negativo.
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
