#include <stdio.h>

int main(void)
{
	int idade;
	
	scanf("%d", &idade);
	
	if(idade >= 5 && idade <= 7) { 
	printf("Infantil");
	}
	
	if(idade >= 8 && idade <= 10) { 
	printf("Juvenil");
	}
	
	if(idade >= 11 && idade <= 15) { 
	printf("Adolescente");
	}
	
	if(idade >= 16 && idade <= 30) { 
	printf("Adulto");
	}
	
	if(idade > 30) { 
	printf("Mestre");
	}
}
