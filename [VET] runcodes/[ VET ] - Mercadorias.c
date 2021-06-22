#include <stdio.h>

int main(void){
	
	const int tam=10;
	int vetCod[tam], vetEst[tam];
	int codCli=1, codProd, quant;
	int i=0,existe=0,j=0;
	
	for(i=0;i<tam;i++){
		scanf("%d", &vetCod[i]);
		scanf("%d", &vetEst[i]);
	}
	
	do
	{
		scanf("%d", &codCli);
			if(codCli ==0)
				break;
		scanf("%d", &codProd);
		scanf("%d", &quant);
		
		j=0;
		existe=0;
		
		for(i=0;i<tam;i++){
			if(codProd == vetCod[i]){
				existe=1;
				j = i;
			}
		}
		
		if(existe==1){
			if(vetEst[j] < quant){
					printf("Sem estoque suficiente para esta compra\n");
				} 
				else{
					printf("Pedido atendido. Obrigado e volte sempre\n");
					vetEst[j] -= quant;
				}	
		}
		else
			printf("Codigo inexistente\n");	
			
	}while(codCli!=0);
	
	for(i=0;i<tam;i++){
		printf("%d: %d\n",vetCod[i], vetEst[i]);
	}
	
}
