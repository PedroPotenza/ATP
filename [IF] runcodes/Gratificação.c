#include <stdio.h>

int main(void)
{
	int h, e, f;
	
	scanf("%d %d", &e, &f);
	
	h=e-(0.75*f);
	
	if(h<=600){
		printf("100.00");
	}
	
	if(h>=601 && h<=1200){
		printf("200.00");
	}
	
	if(h>=1201 && h<=1800){
		printf("300.00");
	}
	
	if(h>=1801 && h<=2400){
		printf("400.00");
	}
	
	if(h>2400){
		printf("500.00");
	}
}
