#include <stdio.h>

enum e_tipo{LIVRO=1, TESE, PERIODICO};
enum e_modalidade{MESTRADO=1, DOUTORADO};


struct s_livro{
	
	char autor[30];
	char titulo[30];//
	int ano;//
	char editora[30];
	char cidade[30];
	
};

struct s_tese{
	
	char titulo[30];//
	char autor[30];
	int mes;
	int ano;//
	char universidade[30];
	char pos_graduacao[30];
	enum e_modalidade modalidade;
	char orientador[30];
	
};

struct s_periodico{
	
	char titulo[30];//
	int volume;
	int mes;
	int ano;//
	char editora[30];
	char cidade[30];
	int paginas;
	
};

union u_obra{
	
	struct s_livro livro;
	struct s_tese tese;
	struct s_periodico periodico;	
	
};

typedef struct s_obra{
	
	enum e_tipo tipo; 	
	union u_obra obra;
	
}obra;

// ----------------------------------------------------------------------------------------------- //
	
int cadastra_obra(obra *vet_obra, int c_obra, int max_obra);
void consulta_obra(obra *vet_obra, int c_obra, int max_obra);	

// ----------------------------------------------------------------------------------------------- //

int main(void){
	
	int const max_obra=5;
	int c_obra=0;
	int opcao, rolou, sair=0;
	obra vet_obra[max_obra];
		
//	printf("------------------ MENU -----------------\n");	
//	printf("1 - Cadastrar um dos tres tipos de obras\n");
//	printf("2 - Consultar um dos tres tipos de obras\n");
//	printf("3 - Finalizar o programa\n");
//	printf("-----------------------------------------\n");	
	
	do{
		
//		printf("Opcao: ");
		scanf(" %d", &opcao);
		
		switch(opcao){
			
			case 1:{
				rolou = cadastra_obra(vet_obra, c_obra, max_obra);
				if(rolou == 1)
					printf("Limite de cadastros excedido!\n");	
				if(rolou == 0)
					c_obra++;
				opcao=0;
				break;
			}
			
			case 2:{
				consulta_obra(vet_obra, c_obra, max_obra);
				
				opcao=0;
				break;
			}
				
			case 3:{
				printf("Fim de execucao\n");
				sair=1;
				opcao=0;
				break;
			}
			
			default: printf("Opcao invalida\n");
				
		}
		
		
	}while(sair==0);
	
}

// ------------------------------------------------------------------------------------------//

int cadastra_obra(obra *vet_obra, int c_obra, int max_obra){
	
	int op,x;
	
	if(c_obra == max_obra)
		return 1;
	else{
		
//		printf("\n----------- TIPOS -------------\n");
//		printf("1 - Cadastrar Livro\n");
//		printf("2 - Cadastrar Tese\n");
//		printf("3 - Cadastrar Periodico\n");
//		printf("-------------------------------\n\n");
		
		scanf(" %d", &op);
		
		switch(op){
			
			case LIVRO:{
				
				vet_obra[c_obra].tipo = (enum e_tipo)op;
				scanf(" %[^\n]",vet_obra[c_obra].obra.livro.autor);
				scanf(" %[^\n]",vet_obra[c_obra].obra.livro.titulo);
				scanf(" %d",&vet_obra[c_obra].obra.livro.ano);
				scanf(" %[^\n]",vet_obra[c_obra].obra.livro.editora);
				scanf(" %[^\n]",vet_obra[c_obra].obra.livro.cidade);
				printf("-----Livro Cadastrado!-----\n");
				
				break;
			}
			
			case TESE:{
				
				vet_obra[c_obra].tipo = (enum e_tipo)op;
				scanf(" %[^\n]",vet_obra[c_obra].obra.tese.autor);
				scanf(" %[^\n]",vet_obra[c_obra].obra.tese.titulo);
				scanf(" %d",&vet_obra[c_obra].obra.tese.mes);
				scanf(" %d",&vet_obra[c_obra].obra.tese.ano);
				scanf(" %[^\n]",vet_obra[c_obra].obra.tese.universidade);
				scanf(" %[^\n]",vet_obra[c_obra].obra.tese.pos_graduacao);
				scanf(" %[^\n]",vet_obra[c_obra].obra.tese.orientador);
				scanf(" %d",&x);
				vet_obra[c_obra].obra.tese.modalidade = (enum e_modalidade)x;
				printf("-----Tese Cadastrada!-----\n");
				
				break;
			}
			
			case PERIODICO:{
				
				vet_obra[c_obra].tipo = (enum e_tipo)op;
				scanf(" %[^\n]",vet_obra[c_obra].obra.periodico.titulo);
				scanf(" %d",&vet_obra[c_obra].obra.periodico.volume);
				scanf(" %d",&vet_obra[c_obra].obra.periodico.mes);
				scanf(" %d",&vet_obra[c_obra].obra.periodico.ano);
				scanf(" %[^\n]",vet_obra[c_obra].obra.periodico.editora);
				scanf(" %[^\n]",vet_obra[c_obra].obra.periodico.cidade);
				scanf(" %d",&vet_obra[c_obra].obra.periodico.paginas);
				printf("-----Periodico Cadastrado!-----\n");
				
				break;
			}
				
			default: printf("Opcao invalida\n");
			
		}
		
		return 0;
	}
}

// --------------------------------------------------------------------------- //

void consulta_obra(obra *vet_obra, int c_obra, int max_obra){
	
	int i, op;
	
//	printf("\n----------- TIPOS -------------\n");
//	printf("1 - Consultar Livro\n");
//	printf("2 - Consultar Tese\n");
//	printf("3 - Consultar Periodico\n");
//	printf("-------------------------------\n\n");
		
	scanf(" %d", &op);
	
	switch(op){
		
		case LIVRO:{
			for(i=0;i<c_obra;i++){
				if(vet_obra[i].tipo == LIVRO){
					printf("Autor: %s\n", vet_obra[i].obra.livro.autor);
					printf("Titulo: %s\n", vet_obra[i].obra.livro.titulo);
					printf("Ano: %d\n", vet_obra[i].obra.livro.ano);
					printf("Editora: %s\n", vet_obra[i].obra.livro.editora);
					printf("Cidade: %s\n", vet_obra[i].obra.livro.cidade);
					printf("-----------------\n");;			
				}
			}
			break;
		}
		
		case TESE:{
			for(i=0;i<c_obra;i++){
				if(vet_obra[i].tipo == TESE){
					printf("Autor: %s\n", vet_obra[i].obra.tese.autor);
					printf("Titulo: %s\n", vet_obra[i].obra.tese.titulo);
					printf("Mes: %d\n", vet_obra[i].obra.tese.mes);
					printf("Ano: %d\n", vet_obra[i].obra.tese.ano);
					printf("Universidade: %s\n", vet_obra[i].obra.tese.universidade);
					printf("Programa: %s\n", vet_obra[i].obra.tese.pos_graduacao);
					printf("Orientador: %s\n", vet_obra[i].obra.tese.orientador);
					printf("Graduacao: %d\n", vet_obra[i].obra.tese.modalidade);
					printf("-----------------\n");
				}	
			}
			break;
		}
		
		case PERIODICO:{
			for(i=0;i<c_obra;i++){
				if(vet_obra[i].tipo == PERIODICO){
					printf("Titulo: %s\n", vet_obra[i].obra.periodico.titulo);
					printf("Volume: %d\n", vet_obra[i].obra.periodico.volume);
					printf("Mes: %d\n", vet_obra[i].obra.periodico.mes);
					printf("Ano: %d\n", vet_obra[i].obra.periodico.ano);
					printf("Editora: %s\n", vet_obra[i].obra.periodico.editora);
					printf("Cidade: %s\n", vet_obra[i].obra.periodico.cidade);
					printf("Numero de paginas: %d\n", vet_obra[i].obra.periodico.paginas);
					printf("-----------------\n");				
				}	
			}
			break;
		}
		
		default: printf("Opcao invalida\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}







