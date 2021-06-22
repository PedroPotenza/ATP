#include <stdio.h>
#include <string.h>

typedef struct s_tipo{
	int codservico;
	char descricao[20];
}tipo;

typedef struct s_servico{
	int codservico;
	int numero;
	float valor;
	int codcliente;
}servico;


//------------------------------------------------------------------------------------------------//

void inicializa_tipo_serv (tipo *vet_tipo, int quant_tipo, int *c_servico_dia, servico mat_servico[][3], int max_serv_dia); 
int cadast_tipo_serv(tipo *vet_tipo, int c_tipo);
int cadast_serv(int *c_servico_dia, int dia, tipo *vet_tipo, int c_tipo, servico mat_servico[][3]);
void mostrar_serv_dia(int dia, servico mat_servico[][3],int *c_servico_dia);
void mostrar_serv_dia_intervalo( servico mat_servico[][3],int *c_servico_dia, int max_serv_dia);
void mostrar_tudo(int *c_servico_dia, int c_tipo, tipo *vet_tipo, servico mat_servico[][3]);

//------------------------------------------------------------------------------------------------//

int main(void){
	
	const int quant_tipo=4;//constantes 
	const int max_serv_dia=3;
	int opcao, fim = 0; //estrutura
	int c_tipo=0, rep, c_servico_dia[30], rol; //contadores ou controladores
	int dia, lixo;
	tipo vet_tipo[quant_tipo];
	servico mat_servico[30][max_serv_dia];
	
//	printf("Menu de opcoes:\n");
//	printf("1 - Cadastrar um dos quatro tipos de servicos\n");
//	printf("2 - Cadastrar um servico prestado em um determinado dia\n");
//	printf("3 - Mostrar todos os servicos prestados em um determinado dia\n");
//	printf("4 - Mostrar todos os servicos prestados dentro de um intervalo de valor\n");
//	printf("5 - Mostrar o relatorio geral (separado por dia), que exibe, inclusive, a descricao do tipo do servico\n");
//	printf("6 - Finalizar o programa\n\n");
	
	inicializa_tipo_serv (vet_tipo, quant_tipo,c_servico_dia, mat_servico, max_serv_dia);
	
	do{
	scanf (" %d", &opcao);
	
	switch(opcao){
		
		//Cadastrar um dos quatro tipos de servicos
		case 1:{
			
			if(c_tipo<quant_tipo){
				
				rep = cadast_tipo_serv(vet_tipo, c_tipo);
				if(rep)
					printf("Ja existe tipo de servico cadastrado com esse codigo\n");
				else{
					printf("Tipo de servico cadastrado com sucesso\n");
					c_tipo++;
				}
			}
			else{
				scanf(" %d", &lixo); //necessário para o runcodes (ele quer informar o código mesmo se o vetor de tipos de servico ja está lotado)
				printf("Cadastro de tipos de servicos lotado\n");
			}
			break;
		}
		
		//Cadastrar um servico prestado em um determinado dia
		case 2:{
			
//			printf("----- Cadastrando um Servico prestado -----\n");
//			printf("Digite o dia: ");
			scanf(" %d", &dia);
			
			if(c_servico_dia[dia-1]==max_serv_dia){
				printf("Todos os servicos prestados neste dia ja foram cadastrados\n");
			}else{
				
				rol = cadast_serv(c_servico_dia, dia, vet_tipo, c_tipo, mat_servico);
				if(rol)
					printf("Codigo de servico invalido\n");
				else{
					printf("Servico cadastrado com sucesso\n");
					c_servico_dia[dia-1]++;
				}	
			}	
			break;
		}
		
		//Mostrar todos os servicos prestados em um determinado dia		
		case 3:{
//			printf("----- Demonstrando os Servicos prestado em um determinado dia -----\n");
//			printf("Digite o dia: ");
			scanf(" %d", &dia);
			
			if(c_servico_dia[dia-1]==0)
				printf("Nenhum servico foi prestado neste dia\n");
			else{
				mostrar_serv_dia(dia, mat_servico, c_servico_dia);
				
			}
			break;
		}
			
		//Mostrar todos os servicos prestados dentro de um intervalo de valor		
		case 4:{
			
			mostrar_serv_dia_intervalo( mat_servico, c_servico_dia, max_serv_dia);
			
			break;
		}
		
		//Mostrar o relatorio geral (separado por dia), que exibe, inclusive, a descricao do tipo do servico		
		case 5:{
			mostrar_tudo(c_servico_dia, c_tipo, vet_tipo, mat_servico);
			break;
		}
		
		//finaliza o programa		
		case 6:{
			printf("Fim de execucao\n");
			fim = 1;
			break;
		}
		
		default: printf("Opcao invalida\n");
	}
	}while(fim == 0);
}

//////////////////////////////////////////////////////////////////////////////

void inicializa_tipo_serv (tipo *vet_tipo, int quant_tipo, int *c_servico_dia, servico mat_servico[][3], int max_serv_dia){
	
	int i,j;
	
	for(i=0;i<quant_tipo; i++){
		vet_tipo[i].codservico = 0;
		strcpy(vet_tipo[i].descricao, "");
	}	
	
	for(i=0;i<30;i++)
		c_servico_dia[i] = 0;
		
	for(i=0;i<30;i++){
		for(j=0;j<max_serv_dia;j++){
			mat_servico[i][j].codcliente = 0;
			mat_servico[i][j].codservico = 0;
			mat_servico[i][j].numero = 0.0;
			mat_servico[i][j].valor = 0;			
		}
	}
	
	
}

/////////////////////////////////////////////////////////////////////////////

int cadast_tipo_serv(tipo *vet_tipo, int c_tipo){
	
	int i;
	
//	printf("----- Cadastrando um Tipo de Servico -----\n");
//  printf("Digite o codigo do servico: ");
  	scanf(" %d", &(vet_tipo[c_tipo].codservico));
  		
		for(i=0;i<c_tipo;i++){
			if(vet_tipo[c_tipo].codservico==vet_tipo[i].codservico)
				return 1;
		} 
		
  	int clear;
	while ((clear = getchar()) != '\n' && clear != EOF) {} //limpar buffer
//	printf("Digite a descricao do servico: ");
	fgets(vet_tipo[c_tipo].descricao, 20, stdin); //ler descricao
	
	return 0;
  	
}

/////////////////////////////////////////////////////////////////////////////

int cadast_serv(int *c_servico_dia, int dia, tipo *vet_tipo, int c_tipo, servico mat_servico[][3]){
	
	int existe=0, x, i, y;
	
//	printf("Digite o codigo do servico: ");
  	scanf(" %d", &x);
	
	for(i=0;i<c_tipo;i++){
		if(x == vet_tipo[i].codservico)
			existe = 1;
	}
	
	if(existe == 1){
		
		y = c_servico_dia[dia-1];
		
		mat_servico[dia-1][y].codservico = x;
//		printf("Digite o numero do servico: ");
		scanf(" %d", &(mat_servico[dia-1][y].numero));
//		printf("Digite o valor do servico: ");
		scanf(" %f", &(mat_servico[dia-1][y].valor));
//		printf("Digite o codigo do cliente: ");
		scanf(" %d", &(mat_servico[dia-1][y].codcliente));
		
		return 0;
	}
	else{
		return 1;
	}

}

/////////////////////////////////////////////////////////////////////////////

void mostrar_serv_dia(int dia, servico mat_servico[][3],int *c_servico_dia){
	
	int y, i;
	
	y = c_servico_dia[dia-1];
	
	for(i=0;i<y;i++)
		printf("%d %d %.2f\n", mat_servico[dia-1][i].codservico, mat_servico[dia-1][i].numero, mat_servico[dia-1][i].valor);
}

/////////////////////////////////////////////////////////////////////////////

void mostrar_serv_dia_intervalo(servico mat_servico[][3],int *c_servico_dia, int max_serv_dia){
	
	int i, j, foi=0, matriz[30][3];
	float valor_ini, valor_fim;
	
	for(i=0;i<30;i++){
		for(j=0;j<max_serv_dia; j++){
			matriz[i][j] = 0;
		}
	}
	
//	printf("----- Demonstrando os Servicos prestado em um determinado intervalo de valor -----\n");
//		printf("Digite o valor do inicio do intervalo: ");
		scanf(" %f", &valor_ini);
//		printf("Digite o valor do fim do intervalo: ");
		scanf(" %f", &valor_fim);
	
	for(i=0;i<30;i++){
		for(j=0;j<c_servico_dia[i];j++){
			if((mat_servico[i][j].valor >= valor_ini) && (mat_servico[i][j].valor <= valor_fim)){
				matriz[i][j] = 1;	
				foi=1;
			}
			if((mat_servico[i][j].valor >= valor_fim) && (mat_servico[i][j].valor <= valor_ini)){
				matriz[i][j] = 1;	
				foi=1;
			}
		}	
	}
		
	if(foi==1){
		for(i=0; i<30; i++){
			for(j=0; j<max_serv_dia; j++){
				if(matriz[i][j] == 1)
				printf("%d %d %.2f\n", mat_servico[i][j].codservico, mat_servico[i][j].numero, mat_servico[i][j].valor);
			}
		}
	}
	else
		printf("Nenhum servico prestado esta entre os valores citados\n");
}

/////////////////////////////////////////////////////////////////////////////

void mostrar_tudo(int *c_servico_dia, int c_tipo, tipo *vet_tipo, servico mat_servico[][3]){

	int i, j, p=0, h, existe=0;
	
///	printf("----- RELATORIO-----\n");
	for(i=0;i<30;i++){
		if(c_servico_dia[i]>0)
			existe=1;		
	}
	
	if(existe==1){
		for(i=0;i<30;i++){
			for(j=0;j<c_servico_dia[i];j++){
				
				for(h=0;h<c_tipo;h++){
					if(vet_tipo[h].codservico == mat_servico[i][j].codservico)
					p = h;
				}
				
				printf("Dia: %d | %d | %d | %.2f | %d | %s", i+1, mat_servico[i][j].codservico, mat_servico[i][j].numero, mat_servico[i][j].valor, mat_servico[i][j].codcliente, vet_tipo[p].descricao);
			}	
		}
		
	}else{
		printf("Nenhum servico prestado foi cadastrado\n");
		
	}
	
	
}














