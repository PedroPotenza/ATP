#include <stdio.h>

int elemento(int *mat, int linha, int coluna);

int main(void)
{
	const int tam = 10;
	int linha = tam, coluna = tam;
    int i, j, mat[linha][coluna];

    for(i=0;i<linha;i++){
    	for(j=0;j<coluna;j++){
    		scanf("%d", &mat[i][j]);
		}
	}

    printf("%d", elemento(mat, linha, coluna));
    return 0;
}

int elemento(int *mat, int linha, int coluna){
	
	int i,j, maior=0;
	
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			if((j>i) && ((*(m + (i * colunas) + j) >= maior))  
				maior = *(m + (i * colunas) + j);
		}
	}
	
	return maior;
}


