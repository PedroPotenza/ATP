#include <stdio.h>

int qtdade(int *x, int tam);

int main(void)
{
	const int tam=30;
    int i, x[tam];
     
	 for(i=0;i<tam;i++)
	 	scanf("%d", &x[i]);

    printf("%d", qtdade(x, tam));
    return 0;
}

int qtdade(int *x, int tam){
	
	int i, par=0;
	
	for(i=0; i<tam; i++){
		if(x[i]%2 == 0)
			par++;
	}
	
	return par;
}
