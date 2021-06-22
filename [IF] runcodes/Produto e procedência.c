#include <stdio.h>

int main(void)
{
	int cod;
	
	scanf("%d", &cod);
	
	if(cod==1) { 
	printf("Sul");
	}
	
	if(cod==2) { 
	printf("Norte");
	}
	
	if(cod==3) { 
	printf("Leste");
	}
	
	if(cod==4) { 
	printf("Oeste");
	}
	
	if(cod==5 || cod==6) { 
	printf("Noroeste");
	}
	
	if(cod >= 7 && cod <= 9) { 
	printf("Sudeste");
	}
	
	if(cod >= 10 && cod <= 20) { 
	printf("Centro-oeste");
	}
	
	if(cod >= 21 && cod <= 30) { 
	printf("Nordeste");
	}
}
