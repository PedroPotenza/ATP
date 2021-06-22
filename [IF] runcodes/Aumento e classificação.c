#include <stdio.h>

int main(void)
{
	float p, a, n;
	
	scanf("%f", &p);
	
	if(p<50){
		a=p*0.05;
		n=p+a;
		printf("%.2f\n", n);
	}else{
		
		if(p>=50.00 && p <100.00){
			a=p*0.1;
			n=p+a;
			printf("%.2f\n", n);
		}else{
			
			if(p>=100.00){
				a=p*0.15;
				n=p+a;
				printf("%.2f\n", n);
			}
		}
	}
	
	
	if(n<80.00){
		printf("Barato");
	}
	
	if(n>=80.00 && n<=119.99){
		printf("Normal");
	}
	
	if(n>=120.00 && n<= 199.99){
		printf("Caro");
	}
	
	if(n>=200.00){
		printf("Muito Caro");
	}
	
	
}
