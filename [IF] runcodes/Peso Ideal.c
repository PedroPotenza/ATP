#include <stdio.h>

int main(void)
{
	float h, imc; 
	char s;
	
	scanf("%f %c", &h, &s);
	
	if(s == 'M'){
		imc = (72.7 * h) - 58;
		printf("%.3f", imc);
	}
	else
	
	if(s == 'F'){ 
		imc = (62.1 * h) - 44.7;
		printf("%.3f", imc);
	}
}
