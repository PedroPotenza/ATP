#include <stdio.h>

int main(void){
	
	int idade, opiniao, i=0, soma=0, nr=0, nb=0, no=0;
	float porc;
	
	
	for(i=0;i<=14;i++)
	{
	
		scanf("%d", &idade);
		
		scanf("%d",&opiniao);	

		if(opiniao==1)
		{
			nr++;
		}
		else if(opiniao==2)
		{
			nb++;
		}
		else if(opiniao==3)
		{
			no++;
			soma = soma + idade;	
		}
	}
	
	porc = nb/(15*0.01);
	
	printf("%f %d %f%%", (float)soma/no, nr, porc);
	
}
