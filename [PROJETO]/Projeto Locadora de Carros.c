#include <stdio.h>
#include <string.h>

enum e_identificador{CPF=1,CNPJ};

struct s_endereco{
	
	char rua[50];
	int numero;
	char bairro[50];
	char cidade[50];
	
};

struct s_pessoa{
	
	char nome[50];
	struct s_endereco endereco;
	char telefone[15];
	
};

struct s_cliente_CPF{
	
	struct s_pessoa pessoa;
	char cpf[15];
	
};

struct s_cliente_CNPJ{
	
	struct s_pessoa pessoa;
	char cnpj[20];
	
};

union u_cliente{
	
	struct s_cliente_CPF cliente_CPF;
	struct s_cliente_CNPJ cliente_CNPJ;
	
};

typedef struct s_cliente{
	
	enum e_identificador identificador;
	union u_cliente cliente;	
	
}cliente;

enum e_cor{PRETA=1,BRANCA, PRATA};
enum e_categoria{HATCH=1,SEDAN,SUV,JIPE};

typedef struct s_carro{
	
	char renavam[12];
	char placa[9];
	char marca[50];
	char modelo[50];
	int ano;
	enum e_cor cor; 
	enum e_categoria categoria; 
	int em_locacao;
	
}carro;

typedef struct s_categoria{
	
	int categoria; //deveria ser um enum 
	float diaria;
	int pontos_fidelidade;
}categoria;

typedef struct s_data{
	
	int dia;
	int mes;
	int ano;
	
}data;

union u_cliente_key{
	
	char CPF[15];
	char CNPJ[20];
	
};

typedef struct s_cliente_locacao{
	
	enum e_identificador identificador;
	union u_cliente_key	key;
}cliente_locacao;

typedef struct s_locacao{
	
	int cod_locacao;
	cliente_locacao cliente;
	char renavam[12];
	data retirada;
	data devolucao;
	int aberta;
	int encerrada;
	int cancelada;
	
}locacao;

typedef struct s_indice{
	
	cliente_locacao cliente;
	int em_locacao;
	
}indice;

typedef struct s_ordem{
	
	enum e_categoria categoria;
	int contador;
	
}ordem;

// ---------------------------------- //

int cadastro_cliente(cliente *vet_cliente, int c_cliente, int max_cliente, int *c_cliente_CPF, int *c_cliente_CNPJ, indice *vet_indice, int *vet_quant_locacao_cliente);
int att_cadastro(cliente *vet_cliente, int c_cliente);
int mostra_cliente(cliente *vet_cliente, int c_cliente);
int cadastro_carro(carro *vet_carro, int c_carro, int max_carro);
int cadastro_categoria(categoria *vet_categoria);
int cadastro_locacao(locacao mat_locacao[][5], int *c_locacao, indice *vet_indice, int *vet_quant_locacao_cliente, carro *vet_carro, int c_carro, int c_cliente, int *c_HATCH_CPF, int *c_SEDAN_CPF, int *c_SUV_CPF, int *c_JIPE_CPF, int *c_HATCH_CNPJ, int *c_SEDAN_CNPJ, int *c_SUV_CNPJ, int *c_JIPE_CNPJ);
int devolve_carro(locacao mat_locacao[][5], int *c_locacao, indice *vet_indice, int *vet_quant_locacao_cliente, carro *vet_carro, int c_carro, int c_cliente, categoria *vet_categoria, int *c_HATCH_CPF, int *c_SEDAN_CPF, int *c_SUV_CPF, int *c_JIPE_CPF, int *c_HATCH_CNPJ, int *c_SEDAN_CNPJ, int *c_SUV_CNPJ, int *c_JIPE_CNPJ);
int mostra_locacao(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente);
int mostra_locacao_cliente(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente, int *vet_quant_locacao_cliente, indice *vet_indice);
int mostra_locacao_aberto(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente, int *vet_quant_locacao_cliente);
int freq_categoria(int c_HATCH_CPF, int c_SEDAN_CPF, int c_SUV_CPF, int c_JIPE_CPF, int c_HATCH_CNPJ, int c_SEDAN_CNPJ, int c_SUV_CNPJ, int c_JIPE_CNPJ);
void inicializa(locacao mat_locacao[][5], int max_cliente);

// ---------------------------------- //

int main(void){
	
	//CONSTANTES
	const int max_cliente=15; //quantidade correta: 15
	const int max_carro=10; //quantidade correta: 10
	const int max_categoria=4; //hatch, sedan, SUV, jipe
	
	//CONTADORES
	int c_cliente=0;
	int c_cliente_CPF=0 , c_cliente_CNPJ=0;
	int c_carro=0;
	int c_locacao=0;
	int c_HATCH_CPF=0, c_SEDAN_CPF=0, c_SUV_CPF=0, c_JIPE_CPF=0;
	int c_HATCH_CNPJ=0, c_SEDAN_CNPJ=0, c_SUV_CNPJ=0, c_JIPE_CNPJ=0;
	
	//VETORES
	cliente vet_cliente[max_cliente];
	carro vet_carro[max_carro];
	categoria vet_categoria[max_categoria];
	locacao mat_locacao[max_cliente][5]; 
	indice vet_indice[max_cliente];
	int vet_quant_locacao_cliente[max_cliente];
	
	//VARIAVEIS DIVERSAS	
	int opcao, sair=0, rolou;
	
	inicializa(mat_locacao, max_cliente);
	
	printf("--------------- MENU --------------- \n");
	printf("   1 - Cadastrar Cliente\n");
	printf("   2 - Atualizar cadastro\n");  
	printf("   3 - Mostrar Cliente\n");
	printf("   4 - Cadastrar Carro\n"); 
	printf("   5 - Cadastrar Categoria\n"); 
	printf("   6 - Cadastrar Locacao\n"); 
	printf("   7 - Devolver Carro\n");  
	printf("   8 - Mostrar Locacao\n"); 
	printf("   9 - Mostrar Locacao de um Cliente\n"); 
	printf("  10 - Mostrar Locacoes em aberto\n"); 
	printf("  11 - Mostrar frequencia de categoria por tipo de cliente\n"); 
	printf("   0 - Sair\n"); 
	printf("---------------------------------- \n");
	
	do{
		
//		printf("Opcao: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:{
				
				rolou = cadastro_cliente(vet_cliente, c_cliente, max_cliente, &c_cliente_CPF, &c_cliente_CNPJ, vet_indice, vet_quant_locacao_cliente);
				if(rolou == 3)
					printf("ERRO: sem espaco\n");
				if(rolou == 2)
					printf("ERRO: opcao invalida\n");
				if(rolou == 1)
					printf("ERRO: ja cadastrado\n");
				if(rolou == 0){
					printf("Cadastrado com Sucesso\n");
					c_cliente++;
				}
				opcao=-1;
				break;
			}
			
			case 2:{
				
				rolou = att_cadastro(vet_cliente, c_cliente);
				if(rolou==2)
					printf("ERRO: opcao invalida\n");
				if(rolou==1)
					printf("ERRO: nao cadastrado\n");
				if(rolou==0)
					printf("Cadastrado com Sucesso\n");
				opcao=-1;
				break;
			}
			
			case 3:{
				
				rolou = mostra_cliente(vet_cliente, c_cliente);
				if(rolou==2)
					printf("ERRO: opcao invalida\n");
				if(rolou==1)
					printf("ERRO: nao cadastrado\n");
				opcao=-1;
				break;
			}
			
			case 4:{
				
				rolou = cadastro_carro(vet_carro, c_carro, max_carro);
				if(rolou == 3)
					printf("ERRO: sem espaco\n");
				if(rolou == 2)
					printf("ERRO: opcao invalida\n");
				if(rolou == 1)
					printf("ERRO: ja cadastrado\n");
				if(rolou == 0){
					printf("Cadastrado com Sucesso\n");
					c_carro++;
				}			
				opcao=-1;
				break;
			}
			
			case 5:{
				
				rolou = cadastro_categoria(vet_categoria);
				if(rolou == 1)
					printf("ERRO: opcao invalida\n");
				if(rolou == 0)
					printf("Cadastrado com Sucesso\n");
				
				opcao=-1;
				break;
			}
			
			case 6:{
				
				rolou = cadastro_locacao(mat_locacao, &c_locacao, vet_indice, vet_quant_locacao_cliente, vet_carro, c_carro, c_cliente, &c_HATCH_CPF, &c_SEDAN_CPF, &c_SUV_CPF, &c_JIPE_CPF, &c_HATCH_CNPJ, &c_SEDAN_CNPJ, &c_SUV_CNPJ, &c_JIPE_CNPJ);
				if(rolou == 4)
					printf("ERRO: sem espaco\n");	
				if(rolou == 3)
					printf("ERRO: nao cadastrado\n");			
				if(rolou == 2)
					printf("ERRO: opcao invalida\n");
				if(rolou == 1)
					printf("ERRO: locacao em aberto\n");
				if(rolou == 0)
					printf("%d cadastrado com sucesso\n", 1001+(c_locacao-1));
		
				opcao=-1;
				break;
			}
			
			case 7:{
				
				rolou = devolve_carro(mat_locacao, &c_locacao, vet_indice, vet_quant_locacao_cliente, vet_carro, c_carro, c_cliente, vet_categoria, &c_HATCH_CPF, &c_SEDAN_CPF, &c_SUV_CPF, &c_JIPE_CPF, &c_HATCH_CNPJ, &c_SEDAN_CNPJ, &c_SUV_CNPJ, &c_JIPE_CNPJ);
				if(rolou == 5)
					printf("ERRO: opcao invalida\n");
				if(rolou == 4)
					printf("ERRO: nenhuma locacao em aberto\n");
				if(rolou == 3)
					printf("ERRO: nao cadastrado\n");
				if(rolou == 2)
					printf("ERRO: data invalida\n");
				if(rolou == 1)
					printf("Locacao cancelada\n");		
				
				opcao=-1;
				break;
				}
			
			case 8:{
				
				rolou = mostra_locacao(mat_locacao, vet_cliente, c_cliente, max_cliente);
				if(rolou==2)
					printf("ERRO: nao cadastrado\n");
				if(rolou==1)
					printf("ERRO: locacao foi cancelada\n"); //no sense
				
				opcao=-1;
				break;
			}
			
			case 9:{
				
				rolou = mostra_locacao_cliente(mat_locacao, vet_cliente, c_cliente, max_cliente, vet_quant_locacao_cliente, vet_indice);
				if(rolou == 3)
					printf("ERRO: nada cadastrado\n");
				if(rolou == 2)
					printf("ERRO: opcao invalida\n");
				if(rolou == 1)
					printf("ERRO: nao cadastrado\n");
				
				opcao=-1;
				break;
			}
			
			case 10:{
				
				rolou = mostra_locacao_aberto(mat_locacao, vet_cliente, c_cliente, max_cliente, vet_quant_locacao_cliente);
				if(rolou == 2)
					printf("ERRO: opcao invalida\n");
				if(rolou == 1)
					printf("ERRO: nenhum dado cadastrado\n");
				
				opcao=-1;
				break;
			}
			
			case 11:{
				
				rolou = freq_categoria(c_HATCH_CPF, c_SEDAN_CPF, c_SUV_CPF, c_JIPE_CPF, c_HATCH_CNPJ, c_SEDAN_CNPJ, c_SUV_CNPJ, c_JIPE_CNPJ);
				if(rolou == 1)
					printf("ERRO: opcao invalida\n");
				
				opcao=-1;
				break;
			}
			
			case 0:{
				sair=1;
				break;
			}
	
		default: printf("ERRO: opcao invalida\n");	
			
		}
		
	}while(sair==0);
	
	
}

// ------------------------------------------------------- //
/*

Coisas a melhorar:
Eu poderia ter criado uma função que verifica a existencia de um cliente/carro

*/
// ------------------------------------------------------- //

void inicializa(locacao mat_locacao[][5], int max_cliente){
	
	int i, j;
	
	for(i=0;i<max_cliente;i++){
		for(j=0;j<5;j++){
			mat_locacao[i][j].aberta = 2;		
			
		}
	}
}

// ------------------------------------------------------- //

int cadastro_cliente(cliente *vet_cliente, int c_cliente, int max_cliente, int *c_cliente_CPF, int *c_cliente_CNPJ, indice *vet_indice, int *vet_quant_locacao_cliente){
	
	int i, x, existe=0;
	char y[15], z[20];
	
	if(c_cliente == max_cliente)
		return 3;
	else{
		
//		printf("O Cliente possui CPF (1) ou CNPJ (2)? ");
		scanf("%d", &x);
		
		if((x<=0)||(x>2))
			return 2;
			
			switch(x){
				
				case CPF:{
					
					existe=0;
//					printf("CPF: ");
						scanf(" %s", y);
					
						for(i=0; i<c_cliente; i++){
						if(strcmp(vet_cliente[i].cliente.cliente_CPF.cpf,y)==0)
						existe=1;
						}
						if(existe==1)
							return 1;
					
						if(existe==0){
							
							vet_cliente[c_cliente].identificador = (enum e_identificador)x;		
							strcpy(vet_cliente[c_cliente].cliente.cliente_CPF.cpf, y);
//							printf("Nome: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.nome);
//							printf("Rua: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.endereco.rua);
//							printf("Numero: ");
							scanf("%d", &vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.endereco.numero);
//							printf("Bairro: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.endereco.bairro);
//							printf("Cidade: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.endereco.cidade);
//							printf("Telefone: ");
							scanf(" %s", vet_cliente[c_cliente].cliente.cliente_CPF.pessoa.telefone);
							
							
							vet_indice[c_cliente].em_locacao = 0;
							vet_quant_locacao_cliente[c_cliente]=0;
							strcpy(vet_indice[c_cliente].cliente.key.CPF, y);
							vet_indice[c_cliente].cliente.identificador = (enum e_identificador)x;
							
							(*c_cliente_CPF)++;
							
							return 0;					
							
						}
					break;
				}
				
				case CNPJ:{
					
					existe=0;
//					printf("CNPJ: ");
						scanf(" %s", z);
					
						for(i=0; i<c_cliente; i++){
						if(strcmp(vet_cliente[i].cliente.cliente_CNPJ.cnpj,z)==0)
						existe=1;
						}
						if(existe==1)
							return 1;
					
						if(existe==0){
							vet_cliente[c_cliente].identificador = (enum e_identificador)x;
							strcpy(vet_cliente[c_cliente].cliente.cliente_CNPJ.cnpj, z);		
//							printf("Nome: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.nome);
//							printf("Rua: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.endereco.rua);
//							printf("Numero: ");
							scanf("%d", &vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.endereco.numero);
//							printf("Bairro: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.endereco.bairro);
//							printf("Cidade: ");
							scanf(" %[^\n]%*c", vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.endereco.cidade);
//							printf("Telefone: ");
							scanf(" %s", vet_cliente[c_cliente].cliente.cliente_CNPJ.pessoa.telefone);
						
							vet_indice[c_cliente].em_locacao = 0;
							vet_quant_locacao_cliente[c_cliente]=0;
							strcpy(vet_indice[c_cliente].cliente.key.CNPJ, z);
							vet_indice[c_cliente].cliente.identificador = (enum e_identificador)x;
							
							(*c_cliente_CNPJ)++;		
							
							return 0;		
						}
					
					
					break;
				}
			}	
	}
	return 7; 
	//warning: control reaches end of non-void function [-Wreturn-type]
}

// ------------------------------------------------------- //

int att_cadastro(cliente *vet_cliente, int c_cliente){
	
	int i, x, y, existe=0;
	char CPF_local[15], CNPJ_local[20], telefone_local[15];
	char rua_local[50], bairro_local[50], cidade_local[50];
	int numero_local;
	
	
//	printf("CPF (1) ou CNPJ (2)? ");
		scanf("%d", &x);
	if(x<=0 || x>2)
		return 2;
	else{
		
		
		switch(x){
			case CPF:{
				
					existe=0;
//					printf("CPF: ");
						scanf(" %s", CPF_local);
							
					for(i=0; i<c_cliente; i++){
						if(strcmp(vet_cliente[i].cliente.cliente_CPF.cpf,CPF_local)==0){
							existe=1;
							
						
//								printf("endereco (1) ou telefone (2)? ");
								scanf("%d", &y);
								switch(y){
								
									case 1:{
										
//										printf("Rua: ");
										scanf(" %[^\n]%*c", rua_local);
//										printf("Numero: ");
										scanf("%d", &numero_local);
//										printf("Bairro: ");
										scanf(" %[^\n]%*c", bairro_local);
//										printf("Cidade: ");
										scanf(" %[^\n]%*c", cidade_local);
										
										strcpy(vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.rua, rua_local);
										vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.numero = numero_local;
										strcpy(vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.bairro, bairro_local);
										strcpy(vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.cidade, cidade_local);
										return 0;
										
										break;
									}
									
									case 2:{
										
							
//										printf("Telefone: ");
										scanf(" %s", telefone_local);
										strcpy(vet_cliente[i].cliente.cliente_CPF.pessoa.telefone, telefone_local);
										return 0;
										
										break;
									}
										
									default: return 2;
								}	
						}
					}
					if(existe==0)
						return 1;	
																		
				break;
			}
			
			case CNPJ:{
					
				
					existe=0;
//					printf("CNPJ: ");
						scanf(" %s", CNPJ_local);
							
					for(i=0; i<c_cliente; i++){
						if(strcmp(vet_cliente[i].cliente.cliente_CNPJ.cnpj,CNPJ_local)==0){
							existe=1;
							
//								printf("endereco (1) ou telefone (2)? ");
								scanf("%d", &y);
								switch(y){
								
									case 1:{
										
									
//										printf("Rua: ");
										scanf(" %[^\n]%*c", rua_local);
//										printf("Numero: ");
										scanf("%d", &numero_local);
//										printf("Bairro: ");
										scanf(" %[^\n]%*c", bairro_local);
//										printf("Cidade: ");
										scanf(" %[^\n]%*c", cidade_local);
										
										strcpy(vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.rua, rua_local);
										vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.numero = numero_local;
										strcpy(vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.bairro, bairro_local);
										strcpy(vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.cidade, cidade_local);
										return 0;
										
										break;
									}
									
									case 2:{
										
//										printf("Telefone: ");
										scanf(" %s", telefone_local);
										strcpy(vet_cliente[i].cliente.cliente_CNPJ.pessoa.telefone, telefone_local);
										return 0;
										
										break;
									}
										
									default: return 2;
								}
						}
					}
					if(existe==0)
						return 1;															
				break;
			}
		}		
	}
	return 7;
	//warning: control reaches end of non-void function [-Wreturn-type]	
}

// ------------------------------------------------------- //

int mostra_cliente(cliente *vet_cliente, int c_cliente){
	
	int i, x,existe=0;
	char CPF_local[15], CNPJ_local[20];
	
//	printf("CPF (1) ou CNPJ (2)?\n");
		scanf("%d", &x);
		
		
	switch(x){
		case CPF:{
			
			
				existe=0;
//				printf("CPF: ");
				scanf(" %s", CPF_local);
				
				for(i=0;i<c_cliente;i++){
					if(strcmp(vet_cliente[i].cliente.cliente_CPF.cpf, CPF_local)==0){
						existe=1;
					
					printf("nome: %s\n",vet_cliente[i].cliente.cliente_CPF.pessoa.nome);
					printf("rua: %s\n",vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.rua);
					printf("num: %d\n",vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.numero);
					printf("bairro: %s\n",vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.bairro);
					printf("cidade: %s\n",vet_cliente[i].cliente.cliente_CPF.pessoa.endereco.cidade);
					printf("telefone: %s\n",vet_cliente[i].cliente.cliente_CPF.pessoa.telefone);
					return 0;
					
				}
			}
			if(existe==0)
				return 1;
			break;
		}
		
		case CNPJ:{
			
			
				existe=0;
//				printf("CNPJ: ");
				scanf(" %s", CNPJ_local);
				
				for(i=0;i<c_cliente;i++){
					if(strcmp(vet_cliente[i].cliente.cliente_CNPJ.cnpj, CNPJ_local)==0){
						existe=1;
					
					printf("nome: %s\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.nome);
					printf("rua: %s\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.rua);
					printf("num: %d\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.numero);
					printf("bairro: %s\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.bairro);
					printf("cidade: %s\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.endereco.cidade);
					printf("telefone: %s\n",vet_cliente[i].cliente.cliente_CNPJ.pessoa.telefone);
					return 0;
					
				}
			}
			if(existe==0)
				return 1;
			break;
		}
		
		default: return 2;
	}
	return 7;
	//warning: control reaches end of non-void function [-Wreturn-type]
	
}

// ------------------------------------------------------- //

int cadastro_carro(carro *vet_carro, int c_carro, int max_carro){
	
	int i, x, y,existe=0;
	char renavam_local[12];
	
	if(c_carro == max_carro)
		return 3;
	else{
//			printf("Renavam: ");
			scanf(" %s", renavam_local);
			for(i=0;i<c_carro;i++){
				if(strcmp(vet_carro[i].renavam, renavam_local)==0)
				existe=1;
			}
			if(existe==1)
				return 1;
	
			strcpy(vet_carro[c_carro].renavam, renavam_local);
//			printf("Qual a categoria do carro?\n");
//			printf("(1)hatch  (2)sedan  (3)suv  (4)jipe\n");
			scanf("%d", &x);
			if(x<=0 || x>4)
				return 2;
			else
				vet_carro[c_carro].categoria = (enum e_categoria)x;
//			printf("Qual a cor do carro?\n");
//			printf("(1)preto  (2)branco  (3)prata\n");
			scanf("%d", &y);
			if(y<=0 || y>3)
				return 2;
			else
				vet_carro[c_carro].cor = (enum e_cor)y;
//			printf("Placa: ");
				scanf(" %[^\n]%*c", vet_carro[c_carro].placa);
//			printf("Marca: ");
				scanf(" %[^\n]%*c", vet_carro[c_carro].marca);
//			printf("Modelo: ");
				scanf(" %[^\n]%*c", vet_carro[c_carro].modelo);
//			printf("Ano: ");
				scanf("%d", &vet_carro[c_carro].ano);
			vet_carro[c_carro].em_locacao=0;
			return 0;		
	}	
	return 7;
}

// ------------------------------------------------------- //

int cadastro_categoria(categoria *vet_categoria){
	
	int x;
	
//	printf("Qual a categoria a ser cadastrada?\n ");
//	printf("(1)Hatch  (2)Sedan  (3)SUV  (4)Jipe \n");
//	printf("Categoria: ");
	scanf("%d", &x);
	
	switch(x){
		
		case HATCH:{
			
			vet_categoria[HATCH-1].categoria=HATCH;
//			printf("Valor da Diaria: ");
			scanf("%f", &vet_categoria[HATCH-1].diaria);
//			printf("Pontos de fidelidade: ");
			scanf("%d", &vet_categoria[HATCH-1].pontos_fidelidade);
			return 0;
			
			break;
		}
		
		case SEDAN:{
			
			vet_categoria[SEDAN-1].categoria=SEDAN;
//			printf("Valor da Diaria: ");
			scanf("%f", &vet_categoria[SEDAN-1].diaria);
//			printf("Pontos de fidelidade: ");
			scanf("%d", &vet_categoria[SEDAN-1].pontos_fidelidade);
			return 0;
			
			break;
		}
		
		case SUV:{
			
			vet_categoria[SUV-1].categoria=SUV;
//			printf("Valor da Diaria: ");
			scanf("%f", &vet_categoria[SUV-1].diaria);
//			printf("Pontos de fidelidade: ");
			scanf("%d", &vet_categoria[SUV-1].pontos_fidelidade);
			return 0;
			
			break;
		}
		
		case JIPE:{
			
			vet_categoria[JIPE-1].categoria=JIPE;
//			printf("Valor da Diaria: ");
			scanf("%f", &vet_categoria[JIPE-1].diaria);
//			printf("Pontos de fidelidade: ");
			scanf("%d", &vet_categoria[JIPE-1].pontos_fidelidade);
			return 0;
			
			break;
		}
		
		default: return 1;
		
	}
	return 7;
}

// ------------------------------------------------------- //

int cadastro_locacao(locacao mat_locacao[][5], int *c_locacao, indice *vet_indice, int *vet_quant_locacao_cliente, carro *vet_carro, int c_carro, int c_cliente, int *c_HATCH_CPF, int *c_SEDAN_CPF, int *c_SUV_CPF, int *c_JIPE_CPF, int *c_HATCH_CNPJ, int *c_SEDAN_CNPJ, int *c_SUV_CNPJ, int *c_JIPE_CNPJ){
	
	int i, k, existe=0;
	int carro_selecionado; //valor referente ao vet_carro
	int cliente_selecionado; //valor referente ao vet_indice
	int tipo_cliente;
	char renavam_local[12], CPF_local[15], CNPJ_local[20];
	
//	printf("Renavam: ");
	scanf(" %s", renavam_local);
	
	for(i=0;i<c_carro;i++){
		if(strcmp(vet_carro[i].renavam,renavam_local)==0){
			existe=1;
			carro_selecionado=i;
		}
	}
	
	if(existe==0)
		return 3;
	if(vet_carro[carro_selecionado].em_locacao==1)
		return 1;
		
//	printf("Tipo cliente: (1)CPF (2) CNPJ\n");
	scanf("%d", &tipo_cliente);
	
	switch(tipo_cliente){
		
		case CPF:{
			
//			printf("CPF: ");
			scanf(" %s", CPF_local);
			
			existe=0;
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_indice[i].cliente.key.CPF,CPF_local)==0){
					existe=1;
					cliente_selecionado=i;
				}
			}
			
			if(existe==0)
				return 3;
			if(vet_indice[cliente_selecionado].em_locacao==1)
				return 1;
			if(vet_quant_locacao_cliente[cliente_selecionado]==5)
				return 4;
				
			strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].renavam, renavam_local);
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cliente.identificador = (enum e_identificador)tipo_cliente;
			strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cliente.key.CPF, CPF_local);
//			printf("Dia: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.dia);
//			printf("Mes: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.mes);
//			printf("Ano: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.ano);
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cod_locacao = 1001 + *c_locacao;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].aberta=1;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].encerrada = 0;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=0;
			
			k = (int)vet_carro[carro_selecionado].categoria;
		
			if(k == 1)
				(*c_HATCH_CPF)++;
			if(k == 2)
				(*c_SEDAN_CPF)++;
			if(k == 3)
				(*c_SUV_CPF)++;	
			if(k == 4)
				(*c_JIPE_CPF)++;	
			
			vet_quant_locacao_cliente[cliente_selecionado]++;
			vet_indice[cliente_selecionado].em_locacao++;
			vet_carro[carro_selecionado].em_locacao++;
			(*c_locacao)++;
			
			
			return 0;			
			break;
		}
		
		case CNPJ:{
			
			
//			printf("CNPJ: ");
			scanf(" %s", CNPJ_local);
			
			existe=0;
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_indice[i].cliente.key.CNPJ,CNPJ_local)==0){
					existe=1;
					cliente_selecionado=i;
				}
			}
			
			if(existe==0)
				return 3;
			if(vet_indice[cliente_selecionado].em_locacao==1)
				return 1;
				
			strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].renavam, renavam_local);
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cliente.identificador = (enum e_identificador)tipo_cliente;
			strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cliente.key.CNPJ, CNPJ_local);
//			printf("Dia: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.dia);
//			printf("Mes: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.mes);
//			printf("Ano: ");
			scanf("%d", &mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].retirada.ano);
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].cod_locacao = 1001 + *c_locacao;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].aberta=1;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]].encerrada = 0;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=0;
			
			k = (int)vet_carro[carro_selecionado].categoria;
		
			if(k == 1)
				(*c_HATCH_CNPJ)++;
			if(k == 2)
				(*c_SEDAN_CNPJ)++;
			if(k == 3)
				(*c_SUV_CNPJ)++;	
			if(k == 4)
				(*c_JIPE_CNPJ)++;	
			
			vet_quant_locacao_cliente[cliente_selecionado]++;
			vet_indice[cliente_selecionado].em_locacao++;
			vet_carro[carro_selecionado].em_locacao++;
			(*c_locacao)++;
			
			return 0;
			break;
		}
		
		default: return 2;
	}
	
	return 7;
}

// ------------------------------------------------------- //

int devolve_carro(locacao mat_locacao[][5], int *c_locacao, indice *vet_indice, int *vet_quant_locacao_cliente, carro *vet_carro, int c_carro, int c_cliente, categoria *vet_categoria, int *c_HATCH_CPF, int *c_SEDAN_CPF, int *c_SUV_CPF, int *c_JIPE_CPF, int *c_HATCH_CNPJ, int *c_SEDAN_CNPJ, int *c_SUV_CNPJ, int *c_JIPE_CNPJ){
	
	int i, p, existe=0;
	float k;
	int cliente_selecionado; //valor referente ao vet_indice
	int carro_selecionado, carro_passado; //valor referente ao vet_carro
	int tipo_cliente, categoria_carro, categoria_carro_passado;
	int quant_dia, quant_mes, troca_mes, quant_desc;
	int locacao_passada=0;
	float valor_real, desc_porc, desc_final;
//	float valor_final;
	char CPF_local[15], CNPJ_local[20], renavam_local[12], renavam_passado[12];
	int dia_local, mes_local, ano_local;
	
	
	
//	printf("Tipo cliente: (1)CPF (2) CNPJ\n");
	scanf("%d", &tipo_cliente);
	
	switch(tipo_cliente){
		
		case CPF:{
			
//			printf("CPF: ");
			scanf(" %s", CPF_local);
			
			existe=0;
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_indice[i].cliente.key.CPF, CPF_local)==0){
					existe=1;
					cliente_selecionado=i;
				}
			}
			
			if(existe==0)
				return 3;
			if(vet_indice[cliente_selecionado].em_locacao==0)
				return 4;
			
			strcpy(renavam_local,mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].renavam);
			
			for(i=0;i<c_carro;i++){
				if(strcmp(vet_carro[i].renavam,renavam_local)==0){
					carro_selecionado=i;
				}
			}
			
//			printf("Dia: ");
			scanf("%d", &dia_local);
//			printf("Mes: ");
			scanf("%d", &mes_local);
//			printf("Ano: ");
			scanf("%d", &ano_local);
			
			if(dia_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia && mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano){
								
								strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].renavam, "");
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cliente.identificador = (enum e_identificador)0;
								strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cliente.key.CPF, "");
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].aberta=2;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].encerrada=2;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=1;
								
								p = (int)vet_carro[carro_selecionado].categoria;
								
									if(p == 1)
										(*c_HATCH_CPF)--;
									if(p == 2)
										(*c_SEDAN_CPF)--;
									if(p == 3)
										(*c_SUV_CPF)--;	
									if(p == 4)
										(*c_JIPE_CPF)--;	
														
								vet_indice[cliente_selecionado].em_locacao--;
								vet_carro[carro_selecionado].em_locacao--;
								
								return 1;	
							}
			
			if(dia_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia && mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
			
			if(mes_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
				
			if(ano_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
			
			if(mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes)
				quant_dia = dia_local - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia;
			else{
				if(ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano){
					
					troca_mes = 30 - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia;
					quant_mes = mes_local - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes;
					quant_dia = troca_mes + (quant_mes-1)*30 + dia_local;
	
				}
				// deveria fazer a quantidade de dias com o ano. (mas n é obrigatorio)
			}
			
			if(vet_quant_locacao_cliente[cliente_selecionado]>1)
				locacao_passada=1;
			
			if(locacao_passada==1){
				
				strcpy(renavam_passado,mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-2].renavam);
				
				for(i=0;i<c_carro;i++){
					if(strcmp(vet_carro[i].renavam,renavam_passado)==0){
						carro_passado=i;
					}	
				}
				
				categoria_carro = (int)vet_carro[carro_selecionado].categoria;
				categoria_carro_passado = (int)vet_carro[carro_passado].categoria;
				
				k = vet_categoria[categoria_carro_passado-1].pontos_fidelidade/1000;
				quant_desc = (int)k;
							
				valor_real = vet_categoria[categoria_carro-1].diaria * quant_dia;
				
				desc_porc = valor_real*0.3;
				
				if(desc_porc < quant_desc*50){
					
				//	valor_final = valor_real - desc_porc;
					desc_final = desc_porc;
					
				}else{
					
				//	valor_final = valor_real - quant_desc*50;
					desc_final = quant_desc*50;
				}
			
			}else{
				
				categoria_carro = (int)vet_carro[carro_selecionado].categoria;
				valor_real = vet_categoria[categoria_carro-1].diaria * quant_dia;
				
			}
				
			printf("Valor devido: %.2f\n", valor_real);
			printf("Desconto: %.2f\n", desc_final);	
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.dia = dia_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.mes = mes_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.ano = ano_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].aberta=0;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].encerrada = 1;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=0;
			vet_indice[cliente_selecionado].em_locacao--;
			vet_carro[carro_selecionado].em_locacao--;
			
			break;
		}
		
		case CNPJ:{
			
//			printf("CNPJ: ");
			scanf(" %s", CNPJ_local);
			
			existe=0;
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_indice[i].cliente.key.CNPJ, CNPJ_local)==0){
					existe=1;
					cliente_selecionado=i;
				}
			}
			
			if(existe==0)
				return 3;
			if(vet_indice[cliente_selecionado].em_locacao==0)
				return 4;
			
			strcpy(renavam_local,mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].renavam);
			
			for(i=0;i<c_carro;i++){
				if(strcmp(vet_carro[i].renavam,renavam_local)==0){
					carro_selecionado=i;
				}
			}
			
//			printf("Dia: ");
			scanf("%d", &dia_local);
//			printf("Mes: ");
			scanf("%d", &mes_local);
//			printf("Ano: ");
			scanf("%d", &ano_local);
			
			if(dia_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia && mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano){
								
								strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].renavam, "");
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cliente.identificador = (enum e_identificador)0;
								strcpy(mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cliente.key.CPF, "");
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano=0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cod_locacao = 0;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].aberta=2;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].encerrada=2;
								mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=1;
								
								p = (int)vet_carro[carro_selecionado].categoria;
								
									if(p == 1)
										(*c_HATCH_CNPJ)--;
									if(p == 2)
										(*c_SEDAN_CNPJ)--;
									if(p == 3)
										(*c_SUV_CNPJ)--;	
									if(p == 4)
										(*c_JIPE_CNPJ)--;	
								
								vet_indice[cliente_selecionado].em_locacao--;
								vet_carro[carro_selecionado].em_locacao--;
							
								
								return 1;	
							}
			
			if(dia_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia && mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
			
			if(mes_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes && ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
				
			if(ano_local < mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano)
				return 2;
			
			if(mes_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes)
				quant_dia = dia_local - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia;
			else{
				if(ano_local == mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.ano){
					
					troca_mes = 30 - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.dia;
					quant_mes = mes_local - mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].retirada.mes;
					quant_dia = troca_mes + (quant_mes-1)*30 + dia_local;
	
				}
				// deveria fazer a quantidade de dias com o ano.
			}
			
			if(vet_quant_locacao_cliente[cliente_selecionado]>1)
				locacao_passada=1;
			
			if(locacao_passada==1){
				
				strcpy(renavam_passado,mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-2].renavam);
				
				for(i=0;i<c_carro;i++){
					if(strcmp(vet_carro[i].renavam,renavam_passado)==0){
						carro_passado=i;
					}	
				}
				
				categoria_carro = (int)vet_carro[carro_selecionado].categoria;
				categoria_carro_passado = (int)vet_carro[carro_passado].categoria;
				
				k = vet_categoria[categoria_carro_passado-1].pontos_fidelidade/1000;
				quant_desc = (int)k;
							
				valor_real = vet_categoria[categoria_carro-1].diaria * quant_dia;
				
				desc_porc = valor_real*0.3;
				
				if(desc_porc < quant_desc*50){
					
				//	valor_final = valor_real - desc_porc;
					desc_final = desc_porc;
					
				}else{
					
				//	valor_final = valor_real - quant_desc*50;
					desc_final = quant_desc*50;
				}
			
			}else{
				
				categoria_carro = (int)vet_carro[carro_selecionado].categoria;
				valor_real = vet_categoria[categoria_carro-1].diaria * quant_dia;
				
			}
				
			printf("Valor devido: %.2f\n", valor_real);
			printf("Desconto: %.2f\n", desc_final);	
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.dia = dia_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.mes = mes_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].devolucao.ano = ano_local;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].aberta=0;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].encerrada = 1;
			mat_locacao[cliente_selecionado][vet_quant_locacao_cliente[cliente_selecionado]-1].cancelada=0;
			vet_indice[cliente_selecionado].em_locacao--;
			vet_carro[carro_selecionado].em_locacao--;
			
			break;
		}
		
		default: return 5;
	}
	return 7;	
}

// ------------------------------------------------------- //

int mostra_locacao(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente){
	
	int i, j, cod_local, existe=0;
	int cliente_selecionado;
	int linha, coluna;
	
//	printf("Codigo da locacao: ");
	scanf("%d", &cod_local);
	
	for(i=0; i<max_cliente; i++){
		for(j=0; j<5; j++){
			if(mat_locacao[i][j].cod_locacao == cod_local){
			linha = i;			
			coluna = j;
			existe=1;	
			}	
		}
	}
	
	if(existe==0)
		return 2;
	
	if(existe==1){
		
		if(mat_locacao[linha][coluna].cancelada==1)
			return 1;
		
		if(mat_locacao[linha][coluna].cliente.identificador == CPF){
			
			for(i=0;i<c_cliente;i++){
				if(strcmp(mat_locacao[linha][coluna].cliente.key.CPF, vet_cliente[i].cliente.cliente_CPF.cpf)==0)
				cliente_selecionado=i;					
			}
		
			printf("codigo da locacao: %d\n",cod_local);
			printf("cpf: %s\n", mat_locacao[linha][coluna].cliente.key.CPF); 
			printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CPF.pessoa.nome);
			printf("renavam: %s\n",mat_locacao[linha][coluna].renavam);
			printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][coluna].retirada.dia, mat_locacao[linha][coluna].retirada.mes, mat_locacao[linha][coluna].retirada.ano);
			printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][coluna].devolucao.dia, mat_locacao[linha][coluna].devolucao.mes, mat_locacao[linha][coluna].devolucao.ano);
			return 0;
		}
		
		if(mat_locacao[linha][coluna].cliente.identificador == CNPJ){
			
			
			for(i=0;i<c_cliente;i++){
				if(strcmp(mat_locacao[linha][coluna].cliente.key.CNPJ, vet_cliente[i].cliente.cliente_CNPJ.cnpj)==0)
				cliente_selecionado=i;					
			}
		
			printf("codigo da locacao: %d\n",cod_local);
			printf("cnpj: %s\n", mat_locacao[linha][coluna].cliente.key.CNPJ); 
			printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CPF.pessoa.nome);
			printf("renavam: %s\n",mat_locacao[linha][coluna].renavam);
			printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][coluna].retirada.dia, mat_locacao[linha][coluna].retirada.mes, mat_locacao[linha][coluna].retirada.ano);
			printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][coluna].devolucao.dia, mat_locacao[linha][coluna].devolucao.mes, mat_locacao[linha][coluna].devolucao.ano);
			return 0;
		}
			
	}
	return 7;
}

// ------------------------------------------------------- //

int mostra_locacao_cliente(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente, int *vet_quant_locacao_cliente, indice *vet_indice){
	
	int i, existe=0, opcao;
	int tipo_cliente, cliente_selecionado;
	int linha;
	char CPF_local[15], CNPJ_local[20];
	
//	printf("Tipo cliente: (1)CPF (2) CNPJ\n");
	scanf("%d", &tipo_cliente);
	
	switch(tipo_cliente){
		
		case CPF:{
			
//			printf("CPF: ");
			scanf(" %s", CPF_local);
			
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_cliente[i].cliente.cliente_CPF.cpf, CPF_local)==0){
					existe=1;
					cliente_selecionado=i;		
				}	
				
				if(strcmp(vet_indice[i].cliente.key.CPF, CPF_local)==0)
					linha = i;
			}
			
			if(existe==0)
				return 1;
			
//			printf("(1)todas (2)encerradas (3)abertas\n");
			scanf("%d", &opcao);
			existe=0;
			
			switch(opcao){
				
				case 1:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						
						if(mat_locacao[linha][i].cancelada!=1){
							existe=1;
							printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
							printf("cpf: %s\n", mat_locacao[linha][i].cliente.key.CPF); 
							printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CPF.pessoa.nome);
							printf("renavam: %s\n",mat_locacao[linha][i].renavam);
							printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
							printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);	
						}				
					}
					if(existe==0)
						return 3;
					return 0;
					
					break;
				}
				
				case 2:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						if(mat_locacao[linha][i].encerrada==1){
							existe=1;
							printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
							printf("cpf: %s\n", mat_locacao[linha][i].cliente.key.CPF); 
							printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CPF.pessoa.nome);
							printf("renavam: %s\n",mat_locacao[linha][i].renavam);
							printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
							printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);	
						}
					}
					if(existe==0)
						return 3;
					return 0;
									
					break;
				}
					
				case 3:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						if(mat_locacao[linha][i].aberta==1){
							existe=1;
							printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
							printf("cpf: %s\n", mat_locacao[linha][i].cliente.key.CPF); 
							printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CPF.pessoa.nome);
							printf("renavam: %s\n",mat_locacao[linha][i].renavam);
							printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
							printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);	
						}
					}
					if(existe==0)
						return 3;
					return 0;
					
					break;
				}
				
				default: return 2;
			}

			break;
		}
		
		case CNPJ:{
			
			
//			printf("CNPJ: ");
			scanf(" %s", CNPJ_local);
			
			for(i=0;i<c_cliente;i++){
				if(strcmp(vet_cliente[i].cliente.cliente_CNPJ.cnpj, CNPJ_local)==0){
					existe=1;
					cliente_selecionado=i;		
				}	
				
				if(strcmp(vet_indice[i].cliente.key.CNPJ, CNPJ_local)==0)
					linha = i;
			}
			
			if(existe==0)
				return 1;
			
//			printf("(1)todas (2)encerradas (3)abertas\n");
			scanf("%d", &opcao);
			
			switch(opcao){
				
				case 1:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
						printf("cnpj: %s\n", mat_locacao[linha][i].cliente.key.CNPJ); 
						printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CNPJ.pessoa.nome);
						printf("renavam: %s\n",mat_locacao[linha][i].renavam);
						printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
						printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);
						
					}
					return 0;

					break;
				}
				
				case 2:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						if(mat_locacao[linha][i].encerrada==1){
							printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
							printf("cnpj: %s\n", mat_locacao[linha][i].cliente.key.CNPJ);
							printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CNPJ.pessoa.nome);
							printf("renavam: %s\n",mat_locacao[linha][i].renavam);
							printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
							printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);	
						}
					}
					return 0;
					
					break;
				}
					
				case 3:{
					
					for(i=0;i<vet_quant_locacao_cliente[linha];i++){
						if(mat_locacao[linha][i].aberta==1){
							printf("codigo da locacao: %d\n",mat_locacao[linha][i].cod_locacao);
							printf("cnpj: %s\n", mat_locacao[linha][i].cliente.key.CNPJ);
							printf("nome: %s\n", vet_cliente[cliente_selecionado].cliente.cliente_CNPJ.pessoa.nome);
							printf("renavam: %s\n",mat_locacao[linha][i].renavam);
							printf("data retirada: %02d/%02d/%02d\n", mat_locacao[linha][i].retirada.dia, mat_locacao[linha][i].retirada.mes, mat_locacao[linha][i].retirada.ano);
							printf("data entrega: %02d/%02d/%02d\n", mat_locacao[linha][i].devolucao.dia, mat_locacao[linha][i].devolucao.mes, mat_locacao[linha][i].devolucao.ano);	
						}
					}
					return 0;
					
					break;
				}
				
				default: return 2;
			}
			
			
			break;
		}	
		
		default: return 2;
		
	}
	return 7;
}

// ------------------------------------------------------- //

int mostra_locacao_aberto(locacao mat_locacao[][5], cliente *vet_cliente, int c_cliente, int max_cliente, int *vet_quant_locacao_cliente){


	int i, j;
	int existe=0;
	int tipo_cliente;
	
//	printf("Tipo cliente: (1)CPF (2)CNPJ\n");
	scanf("%d", &tipo_cliente);
	
	switch(tipo_cliente){
		
		case CPF:{
			
			for(i=0;i<max_cliente;i++){
				for(j=0;j<5;j++){
					if(mat_locacao[i][j].aberta==1){
						existe=1;
						printf("codigo da locacao: %d\n",mat_locacao[i][j].cod_locacao);
						printf("cpf: %s\n", mat_locacao[i][j].cliente.key.CPF);
						printf("nome: %s\n", vet_cliente[i].cliente.cliente_CPF.pessoa.nome); 
						printf("renavam: %s\n",mat_locacao[i][j].renavam);
						printf("data retirada: %02d/%02d/%02d\n", mat_locacao[i][j].retirada.dia, mat_locacao[i][j].retirada.mes, mat_locacao[i][j].retirada.ano);
						printf("data entrega: %02d/%02d/%02d\n", mat_locacao[i][j].devolucao.dia, mat_locacao[i][j].devolucao.mes, mat_locacao[i][j].devolucao.ano);	
					}
				}		
			}		
			
			if(existe==0)
				return 1;
			
			return 0;
			
			break;
		}
		
		case CNPJ:{
			
			for(i=0;i<max_cliente;i++){
				for(j=0;j<5;j++){
					if(mat_locacao[i][j].aberta==1){
						existe=1;
						printf("codigo da locacao: %d\n",mat_locacao[i][j].cod_locacao);
						printf("cnpj: %s\n", mat_locacao[i][j].cliente.key.CNPJ);
						printf("nome: %s\n", vet_cliente[i].cliente.cliente_CNPJ.pessoa.nome); 
						printf("renavam: %s\n",mat_locacao[i][j].renavam);
						printf("data retirada: %02d/%02d/%02d\n", mat_locacao[i][j].retirada.dia, mat_locacao[i][j].retirada.mes, mat_locacao[i][j].retirada.ano);
						printf("data entrega: %02d/%02d/%02d\n", mat_locacao[i][j].devolucao.dia, mat_locacao[i][j].devolucao.mes, mat_locacao[i][j].devolucao.ano);	
					}
				}		
			}		
			
			if(existe==0)
				return 1;
			
			return 0;
			
			break;
		}
		
		default: return 2;
	}
	return 7;
}

// ------------------------------------------------------- //

int freq_categoria(int c_HATCH_CPF, int c_SEDAN_CPF, int c_SUV_CPF, int c_JIPE_CPF, int c_HATCH_CNPJ, int c_SEDAN_CNPJ, int c_SUV_CNPJ, int c_JIPE_CNPJ){
	
	int i, j, max, x;
	ordem vet_CPF[4], vet_CNPJ[4];
	enum e_categoria y;
	int tipo_cliente;
	
//	printf("Tipo cliente: (1)CPF (2) CNPJ\n");
	scanf("%d", &tipo_cliente);
	
	switch(tipo_cliente){
		
		case CPF:{

			for(i=0;i<4;i++){
				vet_CPF[i].categoria = (enum e_categoria)(i+1);
				
				switch(vet_CPF[i].categoria){
					
					case HATCH:{
						vet_CPF[i].contador = c_HATCH_CPF;
						break;
					}
					
					case SEDAN:{
						vet_CPF[i].contador = c_SEDAN_CPF;
						break;
					}
					
					case SUV:{
						vet_CPF[i].contador = c_SUV_CPF;
						break;
					}
					
					case JIPE:{
						vet_CPF[i].contador = c_JIPE_CPF;
						break;
					}	
				}
			}
			
			for(i=0; i<4; i++){
				max = i;
				for(j=i+1; j<4; j++){
					if(vet_CPF[j].contador > vet_CPF[max].contador)
					max = j;
				}		
				
				x = vet_CPF[i].contador;
				y = vet_CPF[i].categoria;
				vet_CPF[i].contador = vet_CPF[max].contador;
				vet_CPF[i].categoria = vet_CPF[max].categoria;
				vet_CPF[max].contador = x;
				vet_CPF[max].categoria = y;
				
			}
			
			for(i=0;i<4;i++){
				switch(vet_CPF[i].categoria){
					
					case HATCH:{
						printf("Categoria hatch: %d\n", vet_CPF[i].contador);
						break;
					}
					
					case SEDAN:{
						printf("Categoria sedan: %d\n", vet_CPF[i].contador);
						break;
					}
					
					case SUV:{
						printf("Categoria suv: %d\n", vet_CPF[i].contador);
						break;
					}
					
					case JIPE:{
						printf("Categoria jipe: %d\n", vet_CPF[i].contador);
						break;
					}	
				}		
			}
		
		
			break;
		}
		
		case CNPJ:{
			
			for(i=0;i<4;i++){
				vet_CNPJ[i].categoria = (enum e_categoria)(i+1);
				
				switch(vet_CNPJ[i].categoria){
					
					case HATCH:{
						vet_CNPJ[i].contador = c_HATCH_CNPJ;
						break;
					}
					
					case SEDAN:{
						vet_CNPJ[i].contador = c_SEDAN_CNPJ;
						break;
					}
					
					case SUV:{
						vet_CNPJ[i].contador = c_SUV_CNPJ;
						break;
					}
					
					case JIPE:{
						vet_CNPJ[i].contador = c_JIPE_CNPJ;
						break;
					}	
				}
			}
			
			for(i=0; i<4; i++){
				max = i;
				for(j=i+1; j<4; j++){
					if(vet_CNPJ[j].contador > vet_CNPJ[max].contador)
					max = j;
				}		
				
				x = vet_CNPJ[i].contador;
				y = vet_CNPJ[i].categoria;
				vet_CNPJ[i].contador = vet_CNPJ[max].contador;
				vet_CNPJ[i].categoria = vet_CNPJ[max].categoria;
				vet_CNPJ[max].contador = x;
				vet_CNPJ[max].categoria = y;
				
			}
			
			for(i=0;i<4;i++){
				switch(vet_CNPJ[i].categoria){
					
					case HATCH:{
						printf("Categoria hatch: %d\n", vet_CNPJ[i].contador);
						break;
					}
					
					case SEDAN:{
						printf("Categoria sedan: %d\n", vet_CNPJ[i].contador);
						break;
					}
					
					case SUV:{
						printf("Categoria suv: %d\n", vet_CNPJ[i].contador);
						break;
					}
					
					case JIPE:{
						printf("Categoria jipe: %d\n", vet_CNPJ[i].contador);
						break;
					}	
				}		
			}

			break;
		}
		
		default: return 1;
	}	
	return 7;
}
