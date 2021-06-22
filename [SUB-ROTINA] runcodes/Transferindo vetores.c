#include <stdio.h>

void maior_menor(int *x, int *a, int *b, int tam, int *v1, int *v2);

int main(void)
{
	const int tam = 30;
    int a=tam, b=tam;
	int i, x[tam], v1[tam], v2[tam];
    for(i=0; i<tam; i++)
    	scanf("%d", &x[i]);

    maior_menor(x, &a, &b, tam, v1, v2);

    for(i=0;i<a;i++){
		printf("%d ", v1[i]);
	}

    for(i=0;i<b;i++){
		printf("%d ", v2[i]);
	}

    return 0;
}

void maior_menor(int *x, int *a, int *b, int tam, int *v1, int *v2){
	
	int i,j=0,k=0;
	
	for(i=0;i<tam;i++){
		
		if(x[i] > 0){
			*b = *b - 1; // *b--; n vai
			v1[j] = x[i];
			j++;
		}
		
		if(x[i] <= 0){
			*a = *a - 1;
			v2[k] = x[i];
			k++;
		}		
	}
	
}
