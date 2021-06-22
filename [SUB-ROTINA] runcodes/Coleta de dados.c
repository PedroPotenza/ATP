#include <stdio.h>

void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam);
float media(float *salario, int tam);
void idades(int *idade, int *maior, int *menor, int tam);
int qtdade(char *sexo, int *filhos, float *salario, int tam);

int main(void)
{
	const int tam = 15;
	
	int idade[tam], filhos[tam];
	char sexo[tam]; // H ou M
	float salario[tam];
	
    int maior, menor;
    //int i;

    le_dados(idade, sexo, salario, filhos, tam);
    
    /* --- testes ---
    for(i=0; i<tam; i++)
    	printf("%d %c %f %d\n", idade[i], sexo[i], salario[i], filhos[i]);
    */ 
    
    printf("%.2f ", media(salario, tam));
    idades(idade, &maior, &menor, tam);
    printf("%d ", menor);
    printf("%d ", maior);
    printf("%d", qtdade(sexo, filhos, salario, tam)); 
	
    return 0;
}

/* FUNÇÕES */

void le_dados(int *idade, char *sexo, float *salario, int *filhos, int tam){
	
	int i; //contador
	
	for(i=0; i<tam; i++){
		
		scanf("%d %c %f %d", &idade[i], &sexo[i], &salario[i], &filhos[i]);
	}	
}

float media(float *salario, int tam){

	int i; //contador
	float soma=0, media;
	
	for(i=0; i<tam; i++){
		soma += salario[i];
	}
	
	media = soma / tam;
	
	return media;
}

void idades(int *idade, int *maior, int *menor, int tam){
	
	int i;//contador
	
	for(i=0;i<tam; i++){
		
		if(i == 0){
			*maior = idade[i];
			*menor = idade[i];
		}
		else{
			
			if(idade[i] > *maior)
				*maior = idade[i];
			if(idade[i] < *menor)
				*menor = idade[i];		
		}
		
	}	
}

int qtdade(char *sexo, int *filhos, float *salario, int tam){
	
	int i=0,k=0;
	
	for(i=0; i<tam; i++){
		if((sexo[i] == 'M') && (filhos[i] == 3) && (salario[i] <= 500))
			k++; 
	}
	
	return k;
	
}






