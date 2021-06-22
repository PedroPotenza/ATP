#include <stdio.h>

int main(void)
{
	float s, c,x;
	
	do{
//		printf("Valor de saldo: ");
		scanf("%f", &s);
		
		if(s==0)
			x=1;
	
	if(s<=199.99){
		c=s*0.1;
	}
	else{
		
		if(s>=200.00 && s<=299.99){
			c=s*0.2;			
		}
		else{
			if(s>=300.00 && s<=399.99){
				c=s*0.25;
			}
			else{
				if(s>=400){
					c=s*0.3;
				}
			}
			
		}
		
		
	}
	
//	printf("Valor de Credito: %.2f\n\n", c);
	printf("%.2f", c);
	}while(x!=0);
	
}
