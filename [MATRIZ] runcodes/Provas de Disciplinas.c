#include <stdio.h>

int main(void){
	
	int i=0, j=0, p=0, disciplina, verifica=0;
	int idade[8], codigo[5], prova[8][5];
	float media, somaidade=0, n=0;

	for(i=0;i<8;i++)
		scanf("%d",&idade[i]);
		
	for(i=0;i<5;i++)
		scanf("%d",&codigo[i]);
		
	for(i=0;i<8;i++){
		for(j=0;j<5;j++){
			scanf("%d",&prova[i][j]);
		}
	}
	
	scanf("%d", &disciplina);
	
	//fim dos inputs
	
	//A quantidade de alunos com idade entre 18 e 25 anos que fizeram mais de duas provas no código desciplina
	for(i=0;i<5;i++){
		if(codigo[i] == disciplina){
			j = i;
			verifica= 1;
		}		
	}
	
	if(verifica == 1){
		for(i=0;i<8;i++){
			if((idade[i]>= 18) && (idade[i] <= 25)){
				if(prova[i][j] > 2){
					p++;	
				}
			}		
		}
		
		printf("%d\n", p);	
		j=0;
				
	}else{
		printf("Erro\n");
	}
	
	//alunos que fizeram menos de três provas
	
	for(i=0;i<8;i++){
		for(j=0;j<5;j++){
			if(prova[i][j] < 3)
				printf("%d %d %d\n", i, idade[i],codigo[j]);
		}
	}
	
	//média dos que não fizeram nenhuma prova
	
	for(i=0;i<8;i++){
		for(j=0;j<5;j++){
			if(prova[i][j] == 0){
				n++;
				somaidade += idade[i];
				j=5;
			}
		}
	}
	
	media = somaidade/n;
	
	printf("%f", media);
	
}
