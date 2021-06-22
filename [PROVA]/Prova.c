#include <stdio.h>
#include <string.h>
// ----------- ENUMS ----------------------- //

enum e_tipo_comida_restaurante{BRASILEIRA=1, ITALIANA, FRANCESA, MEXICANA, OUTRO};
enum e_tipo_servico{LA_CARTE=1, SELF_SERVICE};
enum e_tipo_comida_fast_food{PIZZARIA=1, SANDUICHERIA, TEMAKERIA, CAFETERIA, CREPERIA, DIVERSO};
enum e_tipo_estabelecimento{RESTAURANTE=1, FAST_FOOD, BUTECO};
enum e_estrela{UM=1, DOIS, TRES, QUATRO, CINCO};

// ----------- ESTRUTURAS ----------------------- //

struct s_estabelecimento{
	
	char nome[50];
	char localizacao[50];
	char contato[50];
	
};

struct s_restaurante{
	
	struct s_estabelecimento estabelecimento;
	enum e_tipo_comida_restaurante tipo_comida;
	enum e_tipo_servico tipo_servico;
	
};

struct s_fast_food{
	
	struct s_estabelecimento estabelecimento;
	enum e_tipo_comida_fast_food tipo_comida;
	char entrega;
	
};

struct s_buteco{
	
	struct s_estabelecimento estabelecimento;
	
};

union u_estabelecimento{
	
	struct s_restaurante restaurante;
	struct s_fast_food fast_food;
	struct s_buteco buteco;	
	
};

typedef struct s_estabelecimento_union{
	
	enum e_tipo_estabelecimento tipo_estabelecimento ;
	union u_estabelecimento union_estabelecimento;
	
}estabelecimento;

typedef struct s_avaliacao{
	
	estabelecimento tipo_estabelecimento;
	enum e_estrela estrela;	
	
}avaliacao;

// ------------- FUNÇÕES - CHAMADAS --------------------- //

void inicializa(int mat1[][11], int mat2[][11]);
int cadastra_avaliacao(int mat1[][11], int mat2[][11], avaliacao *vet_avaliacao, int c_avaliacao, int max_avaliacao);
void lista_tipo_estabelecimento(int mat1[][11]);
void lista_num_tipo_estrela(int mat1[][11], int mat2[][11], avaliacao *vet_avaliacao);
void lista_estrelas(int mat2[][11]);

// ------------ MAIN ---------------------- //

int main(void){
	
	const int max_avaliacao=10;
	int mat1[3][max_avaliacao+1];
	int mat2[5][max_avaliacao+1];
	int c_avaliacao=0;
	avaliacao vet_avaliacao[max_avaliacao];
	
	//variaveis diversas
	int sair=0, opcao, rolou;

	inicializa(mat1, mat2);
	
	do{
//		printf("Opcao: ");
		scanf(" %d", &opcao);
	
	
		switch(opcao){
		
		case 1:{
			
			rolou = cadastra_avaliacao(mat1, mat2, vet_avaliacao, c_avaliacao, max_avaliacao);
			if(rolou == 1)
				printf("Vetor cheio\n");
			if(rolou == 0){
				c_avaliacao++;
				printf("Avaliacao realizada com sucesso\n");
			}
			
			opcao=-1;
			break;
		}
		
		case 2:{
			
			lista_tipo_estabelecimento(mat1);
			
			opcao=-1;
			break;
		}
		
		case 3:{
			
			lista_num_tipo_estrela(mat1, mat2, vet_avaliacao);
			
			opcao=-1;
			break;
		}
		
		case 4:{
			
			lista_estrelas(mat2);
		
			opcao=-1;
			break;
		}
		
		case 5:{
			sair=1;
			printf("Encerrando...");
			opcao=-1;
			break;
		}	
		
		default: printf("Entrada invalida\n");
		
		}
		
	}while(sair==0);
	

}

// ------------- FUNÇÕES --------------------- //

int cadastra_avaliacao(int mat1[][11], int mat2[][11], avaliacao *vet_avaliacao, int c_avaliacao, int max_avaliacao){
	
	int opcao, x, y, z,rolou=0, w=0, p=0;
	char entrega;
	
	if(c_avaliacao == max_avaliacao)
		return 1;
	
	do{
//		printf("Tipo do estabelecimento: ");
		scanf(" %d", &opcao);
	
		switch(opcao){
			
			case RESTAURANTE:{
				w=1;
				vet_avaliacao[c_avaliacao].tipo_estabelecimento.tipo_estabelecimento = (enum e_tipo_estabelecimento)opcao;
				
//				printf("Nome: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.estabelecimento.nome);
//				printf("Localizacao: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.estabelecimento.localizacao);
//				printf("Contato: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.estabelecimento.contato);
				
				do{
//					printf("Tipo de comida: ");
					scanf(" %d", &x);
					
					rolou=0;
					switch(x){
						
						case BRASILEIRA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_comida = (enum e_tipo_comida_restaurante)x;
							rolou=1;
							break;
						}
						
						case ITALIANA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_comida = (enum e_tipo_comida_restaurante)x;
							rolou=1;					
							break;
						}
						
						case FRANCESA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_comida = (enum e_tipo_comida_restaurante)x;
							rolou=1;
							break;
						}
						
						case MEXICANA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_comida = (enum e_tipo_comida_restaurante)x;
							rolou=1;
							break;
						}
						
						case OUTRO:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_comida = (enum e_tipo_comida_restaurante)x;
							rolou=1;
							break;
						}	
						
						default: printf("Entrada invalida\n");
					}					
				}while(rolou==0);
				
				do{
//					printf("Tipo de Servico: ");
					scanf(" %d", &y);
					
					rolou=0;
					switch(y){
						
						case LA_CARTE:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_servico = (enum e_tipo_servico)y;
							rolou=1;
							break;
						}
						
						case SELF_SERVICE:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.restaurante.tipo_servico = (enum e_tipo_servico)y;
							rolou=1;
							break;
						}
						
						default: printf("Entrada invalida\n");
					}	
				}while(rolou==0);
				
				mat1[0][0]++;
				mat1[0][c_avaliacao+1] = c_avaliacao;
				
				do{
//					printf("Estrelas: ");
					scanf(" %d", &z);
					
					switch(z){
						
						case UM:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[0][0]++;
							mat2[0][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case DOIS:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[1][0]++;
							mat2[1][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case TRES:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[2][0]++;
							mat2[2][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case QUATRO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[3][0]++;
							mat2[3][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case CINCO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[4][0]++;
							mat2[4][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						default: printf("Entrada invalida\n");
					}
				}while(p==0);
				
				break;
			}
			
			case FAST_FOOD:{
				w=1;
				vet_avaliacao[c_avaliacao].tipo_estabelecimento.tipo_estabelecimento = (enum e_tipo_estabelecimento)opcao;
				
//				printf("Nome: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.estabelecimento.nome);
//				printf("Localizacao: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.estabelecimento.localizacao);
//				printf("Contato: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.estabelecimento.contato);
				
				do{
//					printf("Tipo de comida: ");
					scanf(" %d", &x);
					
					rolou=0;
					switch(x){
						
						case PIZZARIA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;
							break;
						}
						
						case SANDUICHERIA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;					
							break;
						}
						
						case TEMAKERIA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;
							break;
						}
						
						case CAFETERIA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;
							break;
						}
						
						case CREPERIA:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;
							break;
						}	
						
						case DIVERSO:{
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = (enum e_tipo_comida_fast_food)x;
							rolou=1;
							break;
						}	
						
						default: printf("Entrada invalida\n");
					}					
				}while(rolou==0);
				
				do{
					rolou=0;
//					printf("Entrega: [s] [n]\n");
					scanf(" %c", &entrega);
					
					if(entrega == 's'){
						rolou=1;
						vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = entrega;
					}else{
						if(entrega == 'n'){
							rolou=1;
							vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.fast_food.tipo_comida = entrega;
						}else{
							
							printf("Entrada invalida\n");
						}	
					}
				}while(rolou==0);
				
				mat1[1][0]++;
				mat1[1][c_avaliacao+1] = c_avaliacao;
				
				do{
//					printf("Estrelas: ");
					scanf(" %d", &z);
					
					switch(z){
						
						case UM:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[0][0]++;
							mat2[0][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case DOIS:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[1][0]++;
							mat2[1][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case TRES:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[2][0]++;
							mat2[2][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case QUATRO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[3][0]++;
							mat2[3][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case CINCO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[4][0]++;
							mat2[4][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						default: printf("Entrada invalida\n");
					}
				}while(p==0);	
			
				break;
			}
			
			case BUTECO:{
				w=1;
				vet_avaliacao[c_avaliacao].tipo_estabelecimento.tipo_estabelecimento = (enum e_tipo_estabelecimento)opcao;
				
//				printf("Nome: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.buteco.estabelecimento.nome);
//				printf("Localizacao: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.buteco.estabelecimento.localizacao);
//				printf("Contato: ");
				scanf(" %[^\n]%*c", vet_avaliacao[c_avaliacao].tipo_estabelecimento.union_estabelecimento.buteco.estabelecimento.contato);

				p=0;		
				mat1[2][0]++;
				mat1[2][c_avaliacao+1] = c_avaliacao;
				do{
//					printf("Estrelas: ");
					scanf(" %d", &z);
				
					switch(z){
						
						case UM:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[0][0]++;
							mat2[0][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case DOIS:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[1][0]++;
							mat2[1][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case TRES:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[2][0]++;
							mat2[2][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case QUATRO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[3][0]++;
							mat2[3][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						case CINCO:{
							p=1;
							vet_avaliacao[c_avaliacao].estrela = (enum e_estrela)z;
							mat2[4][0]++;
							mat2[4][c_avaliacao+1] = c_avaliacao;
							
							break;
						}
						
						default: printf("Entrada invalida\n");
					}
				}while(p==0);	
				
				break;
			}
			
			default: printf("Entrada invalida\n");
		}
		
	}while(w==0);
	
	
	return 0;	
}

// --------------------------------------------------------------- //

void lista_tipo_estabelecimento(int mat1[][11]){
	
	printf("Restaurantes: %d\n", mat1[0][0]);
	printf("Fast-Food: %d\n", mat1[1][0]);
	printf("Butecos: %d\n", mat1[2][0]);
	
}

void inicializa(int mat1[][11], int mat2[][11]){
	
	int i;
	
	for(i=0;i<3;i++)
		mat1[i][0]=0;
	
	for(i=0;i<5;i++)
		mat2[i][0]=0;	
	
}

// ---------------------------------------------------------------- //

void lista_estrelas(int mat2[][11]){
	
	printf("Estrelas: 1: %d\n", mat2[0][0]);
	printf("Estrelas: 2: %d\n", mat2[1][0]);
	printf("Estrelas: 3: %d\n", mat2[2][0]);
	printf("Estrelas: 4: %d\n", mat2[3][0]);
	printf("Estrelas: 5: %d\n", mat2[4][0]);

}

// ---------------------------------------------------------------- //

void lista_num_tipo_estrela(int mat1[][11], int mat2[][11], avaliacao *vet_avaliacao){
	
	int i, x,tipo;
	int estrela1=0, estrela2=0, estrela3=0, estrela4=0, estrela5=0;
	
//	printf("Tipo do estabelecimento: ");
	scanf(" %d", &tipo);
	
	switch(tipo){
		
		case RESTAURANTE:{
				
				for(i=0;i<10;i++){
					if(vet_avaliacao[i].tipo_estabelecimento.tipo_estabelecimento == RESTAURANTE){
						
					x = (int)vet_avaliacao[i].estrela;
					
						switch(x){
							
							case UM:{
								
								estrela1++;
								
								break;
							}
							
							case DOIS:{
								
								estrela2++;
								
								break;
							}
							
							case TRES:{
								
								estrela3++;
								
								break;
							}
							
							case QUATRO:{
								
								estrela4++;
								
								break;
							}
							
							case CINCO:{
								
								estrela5++;
								
								break;
							}
							
						}	
					}
				}
				
				printf("Estrelas: 1: %d\n", estrela1);
				printf("Estrelas: 2: %d\n", estrela2);
				printf("Estrelas: 3: %d\n", estrela3);
				printf("Estrelas: 4: %d\n", estrela4);
				printf("Estrelas: 5: %d\n", estrela5);
				
			break;
		}
		
		case FAST_FOOD:{
				
				for(i=0;i<10;i++){
					if(vet_avaliacao[i].tipo_estabelecimento.tipo_estabelecimento == FAST_FOOD){
						
					x = (int)vet_avaliacao[i].estrela;
					
						switch(x){
							
							case UM:{
								
								estrela1++;
								
								break;
							}
							
							case DOIS:{
								
								estrela2++;
								
								break;
							}
							
							case TRES:{
								
								estrela3++;
								
								break;
							}
							
							case QUATRO:{
								
								estrela4++;
								
								break;
							}
							
							case CINCO:{
								
								estrela5++;
								
								break;
							}
							
						}	
					}
				}
				
				printf("Estrelas: 1: %d\n", estrela1);
				printf("Estrelas: 2: %d\n", estrela2);
				printf("Estrelas: 3: %d\n", estrela3);
				printf("Estrelas: 4: %d\n", estrela4);
				printf("Estrelas: 5: %d\n", estrela5);
				
			break;
		}
		
		case BUTECO:{
				
				for(i=0;i<10;i++){
					if(vet_avaliacao[i].tipo_estabelecimento.tipo_estabelecimento == BUTECO){
						
					x = (int)vet_avaliacao[i].estrela;
					
						switch(x){
							
							case UM:{
								
								estrela1++;
								
								break;
							}
							
							case DOIS:{
								
								estrela2++;
								
								break;
							}
							
							case TRES:{
								
								estrela3++;
								
								break;
							}
							
							case QUATRO:{
								
								estrela4++;
								
								break;
							}
							
							case CINCO:{
								
								estrela5++;
								
								break;
							}
							
						}	
					}
				}
				
				printf("Estrelas: 1: %d\n", estrela1);
				printf("Estrelas: 2: %d\n", estrela2);
				printf("Estrelas: 3: %d\n", estrela3);
				printf("Estrelas: 4: %d\n", estrela4);
				printf("Estrelas: 5: %d\n", estrela5);
				
			break;
		}
		
		default: printf("Entrada invalida\n"); 
	}

}
