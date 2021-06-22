#include <stdio.h>

int main(void){

	int i, j, linha, coluna, empate=0;
	char tabuleiro[3][3]={{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
	
	for(i=0;i<9;i++){
		do{
		scanf("%d %d", &linha, &coluna);
		
		if((linha < 0) || (linha >= 3) || (coluna <0) || (coluna >=3) || (tabuleiro[linha][coluna] == 'x') || (tabuleiro[linha][coluna] == 'o')){
		j = 0;
		printf("Erro\n");
		}
		else{
			j = 1;
			if(i%2==0){
			tabuleiro[linha][coluna] = 'x';
			} else {
				tabuleiro[linha][coluna] = 'o';
			}
		}	
	}while(j==0);
	
	if(i >= 4){
		//verificar por vitorias em linhas
		//jogador 1
		if((tabuleiro[0][0] == 'x') && (tabuleiro[0][1] == 'x') && (tabuleiro[0][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Linha 0\n");
			empate = 1;
			break;
		}
		if((tabuleiro[1][0] == 'x') && (tabuleiro[1][1] == 'x') && (tabuleiro[1][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Linha 1\n");
			empate = 1;
			break;
		}
		if((tabuleiro[2][0] == 'x') && (tabuleiro[2][1] == 'x') && (tabuleiro[2][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Linha 2\n");
			empate = 1;
			break;
		}
		
		//jogador2
		if((tabuleiro[0][0] == 'o') && (tabuleiro[0][1] == 'o') && (tabuleiro[0][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Linha 0\n");
			empate = 1;
			break;
		}
		if((tabuleiro[1][0] == 'o') && (tabuleiro[1][1] == 'o') && (tabuleiro[1][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Linha 1\n");
			empate = 1;
			break;
		}
		if((tabuleiro[2][0] == 'o') && (tabuleiro[2][1] == 'o') && (tabuleiro[2][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Linha 2\n");
			empate = 1;
			break;
		}
		
		//verificar por vitorias em colunas
		//jogador 1
		if((tabuleiro[0][0] == 'x') && (tabuleiro[1][0] == 'x') && (tabuleiro[2][0] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Coluna 0\n");
			empate = 1;
			break;
		}
		if((tabuleiro[0][1] == 'x') && (tabuleiro[1][1] == 'x') && (tabuleiro[2][1] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Coluna 1\n");
			empate = 1;
			break;
		}
		if((tabuleiro[0][2] == 'x') && (tabuleiro[1][2] == 'x') && (tabuleiro[2][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Coluna 2\n");
			empate = 1;
			break;
		}
		
		//jogador 2
		if((tabuleiro[0][0] == 'o') && (tabuleiro[1][0] == 'o') && (tabuleiro[2][0] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Coluna 0\n");
			empate = 1;
			break;
		}
		if((tabuleiro[0][1] == 'o') && (tabuleiro[1][1] == 'o') && (tabuleiro[2][1] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Coluna 1\n");
			empate = 1;
			break;
		}
		if((tabuleiro[0][2] == 'o') && (tabuleiro[1][2] == 'o') && (tabuleiro[2][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Coluna 2\n");
			empate = 1;
			break;
		}
		
		//verificar vitorias em diagonais
		//jogador 1
		if((tabuleiro[0][0] == 'x') && (tabuleiro[1][1] == 'x') && (tabuleiro[2][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Diagonal principal\n");
			empate = 1;
			break;
		}
		if((tabuleiro[2][0] == 'x') && (tabuleiro[1][1] == 'x') && (tabuleiro[0][2] == 'x')){
			printf("Jogador 1 venceu\n");
			printf("Diagonal secundaria\n");
			empate = 1;
			break;
		}
		
		//jogador 2
		if((tabuleiro[0][0] == 'o') && (tabuleiro[1][1] == 'o') && (tabuleiro[2][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Diagonal principal\n");
			empate = 1;
			break;
		}
		if((tabuleiro[2][0] == 'o') && (tabuleiro[1][1] == 'o') && (tabuleiro[0][2] == 'o')){
			printf("Jogador 2 venceu\n");
			printf("Diagonal secundaria\n");
			empate = 1;
			break;
		}
	}	
}

	if(empate == 0)
		printf("Empate\n");
 	
 	printf("%c%c%c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
	printf("%c%c%c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
	printf("%c%c%c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);

}
