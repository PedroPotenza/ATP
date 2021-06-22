#include <stdio.h>
#include <string.h>

typedef struct s_endereco{
	
	char rua[50];
	int numero;
	char bairro[50];
	
}endereco;

typedef struct s_pessoa{
	
	char telefone[15];
	char nome[50];
	endereco endereco_pessoa;
	
}pessoa;

typedef struct s_cliente{
	
	pessoa p_cliente;
	
}cliente;

typedef struct s_motoqueiro{

	pessoa p_motoqueiro;
	int cod_motoqueiro;
	
}motoqueiro;

typedef struct s_pizza{
	
	int cod_pizza;
	char nome_pizza[50];
	float preco;
	
}pizza;

typedef struct s_pedido{
	
	int cod_pedido;
	char telefone_cliente[15];
	int cod_pizza;
	int cod_motoqueiro;
	int situcao;
	
}pedido;

// -------------------------------------------------------------- //

void inicializa(cliente *vet_cliente, motoqueiro *vet_motoqueiro, pizza *vet_pizza, pedido *vet_pedido, int max_cliente, int max_motoqueiro, int max_pizza, int max_pedido);
int cadastra_cliente(cliente *vet_cliente, int max_cliente, int c_cliente);
int cadastra_motoqueiro(motoqueiro *vet_motoqueiro, int max_motoqueiro, int c_motoqueiro);
int cadastra_pizza(pizza *vet_pizza, int max_pizza, int c_pizza);
int cadastra_pedido(pedido *vet_pedido, int max_pedido, int c_pedido, cliente *vet_cliente, int c_cliente, pizza *vet_pizza, int c_pizza);
int despacha_pizza(pedido *vet_pedido, int c_pedido, motoqueiro *vet_motoqueiro, int c_motoqueiro);
int recebe_pizza(pedido *vet_pedido, int c_pedido);
int pedido_situacao(pedido *vet_pedido, int c_pedido);
int pedido_cliente(pedido *vet_pedido, int c_pedido, cliente *vet_cliente, int c_cliente);
int pedido_motoqueiro(motoqueiro *vet_motoqueiro, int c_motoqueiro, pedido *vet_pedido, int c_pedido);

// --------------------------------------------------------------- // 

int main(void){
	
	//CONSTANTES
	const int max_cliente = 5;
	const int max_motoqueiro = 2;
	const int max_pizza = 3;
	const int max_pedido = 6;

	//CONTADORES
	int c_cliente=0;
	int c_motoqueiro=0;
	int c_pizza=0;
	int c_pedido=0;
	
	//VETORES
	cliente vet_cliente[max_cliente];
	motoqueiro vet_motoqueiro[max_motoqueiro];
	pizza vet_pizza[max_pizza];
	pedido vet_pedido[max_pedido];
	
	//VARIAVEIS DIVERSAS
	int sair=0, opcao, rolou;
	
	inicializa(vet_cliente, vet_motoqueiro, vet_pizza, vet_pedido, max_cliente, max_motoqueiro, max_pizza, max_pedido);

//	printf("------ MENU DE OPCOES ------\n");
//	printf("1 - Cadastra Cliente\n");
//	printf("2 - Cadastra Motoqueiro\n");
//	printf("3 - Cadastra Pizza\n");
//	printf("4 - Cadastra Pedido\n");
//	printf("5 - Despacha Pizza\n");
//	printf("6 - Recebe Pizza\n");
//	printf("7 - Pedidos por Situacao\n");
//	printf("8 - Pedidos por Cliente\n");
//	printf("9 - Motoqueiros Entregas\n");
//	printf("10 - Sair\n\n");
	
	do{
		//printf("opcao: ");
		scanf(" %d", &opcao);
		
		switch(opcao){
			
			case 1:{
				
				rolou = cadastra_cliente(vet_cliente, max_cliente, c_cliente);
				if(rolou == 2){
					printf("Numero maximo de clientes cadastrados\n");
				} else if(rolou == 1){
					printf("Cliente ja cadastrado\n");
				}else{
					printf("Cliente cadastrado com sucesso\n");
					c_cliente++;
				}
				opcao = -1;	
				break;
			}
			
			case 2:{
				
				rolou = cadastra_motoqueiro(vet_motoqueiro, max_motoqueiro, c_motoqueiro);
				if(rolou == 2){
					printf("Numero maximo de motoqueiros cadastrados\n");
				}else if(rolou == 1){
					printf("Motoqueiro ja cadastrado\n");
				}else{
					printf("Motoqueiro cadastrado com sucesso\n");
					c_motoqueiro++;
				}
				opcao = -1;
				break;
			}
			
			case 3:{
				
				rolou = cadastra_pizza(vet_pizza, max_pizza, c_pizza);
				if(rolou == 2){
					printf("Numero maximo de pizzas cadastrados\n");
				}else if(rolou == 1){
					printf("Pizza ja cadastrada\n");
				}else{
					printf("Pizza cadastrada com sucesso\n");
					c_pizza++;
				}
				opcao = -1;
				break;
			}
			
			case 4:{
				
				rolou = cadastra_pedido(vet_pedido, max_pedido, c_pedido, vet_cliente, c_cliente, vet_pizza, c_pizza);
				if(rolou == 3)
					printf("Cliente nao encontrado\n");
				if(rolou == 2)
					printf("Pizza nao cadastrada\n");
				if(rolou == 1)
					printf("Numero maximo de pedidos realizados\n");
				if(rolou == 0){
					printf("Pedido cadastrado\n");
					c_pedido++;
				}
				opcao = -1;
				break;
			}
			
			case 5:{
				
				rolou = despacha_pizza(vet_pedido, c_pedido, vet_motoqueiro, c_motoqueiro);
				if(rolou == 4)
					printf("Pedido nao encontrado\n");
				if(rolou == 3)
					printf("Motoqueiro nao encontrado\n");
				if(rolou == 2)
					printf("Pedido ja despachado\n");
				if(rolou == 1)
					printf("Pedido ja entregue\n");
				if(rolou == 0){
					printf("Despachando pedido\n");
				}
				opcao = -1;
				break;
			}
			
			case 6:{
				
				rolou = recebe_pizza(vet_pedido, c_pedido);
				if(rolou == 2)
					printf("Pedido nao encontrado\n");
				if(rolou == 1)
					printf("Entrega ja realizada\n");
				if(rolou == 0){
					printf("Pedido entregue\n");
				}
				opcao = -1;
				break;
			}
			
			case 7:{
				
				rolou = pedido_situacao(vet_pedido, c_pedido);
				if(rolou == 1)
					printf("Opcao invalida\n");
				opcao = -1;
				break;
			}
			
			case 8:{
				
				rolou = pedido_cliente(vet_pedido, c_pedido, vet_cliente, c_cliente);
				if(rolou == 2)
					printf("Cliente nao encontrado\n");
				if(rolou == 1)
					printf("Cliente sem pedidos\n");
				opcao = -1;
				break;
			}
			
			case 9:{
				
				rolou = pedido_motoqueiro(vet_motoqueiro, c_motoqueiro, vet_pedido, c_pedido);
				if(rolou == 2)
					printf("Motoqueiro nao encontrado\n");
				if(rolou == 1)
					printf("Motoqueiro sem pedidos\n");
				opcao = -1;
				break;
			}
			
			case 0:{
				printf("Encerrando sistema");
				sair=1;
				break;
			}
			
			default: printf("Opcao invalida\n");
		}
		
		
	}while (sair == 0);
	
}

// ------------------------------------------------------------- //

void inicializa(cliente *vet_cliente, motoqueiro *vet_motoqueiro, pizza *vet_pizza, pedido *vet_pedido, int max_cliente, int max_motoqueiro, int max_pizza, int max_pedido){
	
	int i;
	
	//zera vetor dos clientes
	for(i=0; i<max_cliente; i++){
		strcpy(vet_cliente[i].p_cliente.endereco_pessoa.bairro, "");
		vet_cliente[i].p_cliente.endereco_pessoa.numero = 0;
		strcpy(vet_cliente[i].p_cliente.endereco_pessoa.rua, "");
		strcpy(vet_cliente[i].p_cliente.nome, "");
		strcpy(vet_cliente[i].p_cliente.telefone, "");
	}
	
	//zera vetor dos motoqueiros
	for(i=0; i<max_motoqueiro; i++){
		vet_motoqueiro[i].cod_motoqueiro = -1; //DUVIDA AQUI
		strcpy(vet_motoqueiro[i].p_motoqueiro.endereco_pessoa.bairro, "");
		vet_motoqueiro[i].p_motoqueiro.endereco_pessoa.numero = 0;
		strcpy(vet_motoqueiro[i].p_motoqueiro.endereco_pessoa.rua, "");
		strcpy(vet_motoqueiro[i].p_motoqueiro.nome, "");
		strcpy(vet_motoqueiro[i].p_motoqueiro.telefone, "");
	}
	
	//zera vetor das pizzas 
	for(i=0; i<max_pizza; i++){
		vet_pizza[i].cod_pizza = -1; //DUVIDA AQUI
		strcpy(vet_pizza[i].nome_pizza, "");
		vet_pizza[i].preco = 0.00;
	}
	
	for(i=0; i<max_pedido; i++){
		vet_pedido[i].cod_motoqueiro = -1;
		vet_pedido[i].cod_pedido = -1;
		vet_pedido[i].cod_pizza = -1;
		vet_pedido[i].situcao = -1;
		strcpy(vet_pedido[i].telefone_cliente, "");		
	}	
}

// ------------------------------------------------------------------- //

int cadastra_cliente(cliente *vet_cliente, int max_cliente, int c_cliente){
	
	int i=0;
	char tel[15];
	
	if(c_cliente == max_cliente)
		return 2;
	else{
		
		scanf(" %[^\n]", tel);
		
		for(i=0;i<c_cliente;i++){
			if(strcmp(vet_cliente[i].p_cliente.telefone, tel) == 0){ 
				return  1;
			}
		}
		
		strcpy(vet_cliente[c_cliente].p_cliente.telefone, tel);
		scanf(" %[^\n]", vet_cliente[c_cliente].p_cliente.nome);
		scanf(" %[^\n]", vet_cliente[c_cliente].p_cliente.endereco_pessoa.rua);
		scanf(" %d", &vet_cliente[c_cliente].p_cliente.endereco_pessoa.numero);
		scanf(" %[^\n]", vet_cliente[c_cliente].p_cliente.endereco_pessoa.bairro);
		return 0;
	}	
}

// ------------------------------------------------------------------- //

int cadastra_motoqueiro(motoqueiro *vet_motoqueiro, int max_motoqueiro, int c_motoqueiro){
	
	int i, x=0;
	
	if(c_motoqueiro == max_motoqueiro)
		return 2;
	else{
		
		scanf(" %d", &x);
		
		for(i=0;i<c_motoqueiro;i++){
			if(vet_motoqueiro[i].cod_motoqueiro == x)
			return 1;
		}
		
		vet_motoqueiro[c_motoqueiro].cod_motoqueiro = x;
		scanf(" %[^\n]", vet_motoqueiro[c_motoqueiro].p_motoqueiro.telefone);
		scanf(" %[^\n]", vet_motoqueiro[c_motoqueiro].p_motoqueiro.nome);
		scanf(" %[^\n]", vet_motoqueiro[c_motoqueiro].p_motoqueiro.endereco_pessoa.rua);
		scanf(" %d", &vet_motoqueiro[c_motoqueiro].p_motoqueiro.endereco_pessoa.numero);
		scanf(" %[^\n]", vet_motoqueiro[c_motoqueiro].p_motoqueiro.endereco_pessoa.bairro);
		return 0;
	}
}

// ------------------------------------------------------------------- //

int cadastra_pizza(pizza *vet_pizza, int max_pizza, int c_pizza){
	
	int i, x=0;
	
	if(c_pizza == max_pizza)
		return 2;
	else{
		
		scanf(" %d", &x);
		
		for(i=0; i<c_pizza; i++){
			if(vet_pizza[i].cod_pizza == x)
			return 1;
		}
		
		vet_pizza[c_pizza].cod_pizza = x;
		scanf(" %[^\n]", vet_pizza[c_pizza].nome_pizza);
		scanf(" %f", &vet_pizza[c_pizza].preco);
		return 0;
	}
}

// ------------------------------------------------------------------- //

int cadastra_pedido(pedido *vet_pedido, int max_pedido, int c_pedido, cliente *vet_cliente, int c_cliente, pizza *vet_pizza, int c_pizza){
	
	int i, x;
	int existe_cliente=0, existe_pizza=0;
	char tel[15];

	vet_pedido[c_pedido].cod_pedido = c_pedido;
	
	if(c_pedido == max_pedido)
		return 1;
	
	scanf(" %[^\n]", tel);
	for(i=0;i<c_cliente;i++){
		if(strcmp(vet_cliente[i].p_cliente.telefone, tel) == 0)
			existe_cliente=1;
	}
	
	if(existe_cliente == 0)
		return 3;
	
	scanf(" %d", &x);
	for(i=0; i<c_pizza; i++){
		if(vet_pizza[i].cod_pizza == x)
			existe_pizza=1;
	}
	
	if(existe_pizza == 0)
		return 2;
	
	strcpy(vet_pedido[c_pedido].telefone_cliente, tel);
	vet_pedido[c_pedido].cod_pizza=x;
	vet_pedido[c_pedido].situcao=1;
	vet_pedido[c_pedido].cod_motoqueiro=0;
	return 0;
		
}

// ------------------------------------------------------------------- //

int despacha_pizza(pedido *vet_pedido, int c_pedido, motoqueiro *vet_motoqueiro, int c_motoqueiro){
	
	int i, x, y, z;
	int existe_pedido=0, existe_motoqueiro=0;

	scanf(" %d", &x);	
	for(i=0;i<c_pedido;i++){
		if(vet_pedido[i].cod_pedido == x){
			y = i;
			existe_pedido=1;
		}
	}
	if(existe_pedido == 0)
		return 4;
	else{
		
		if(vet_pedido[y].situcao == 2)
			return 2;
		if(vet_pedido[y].situcao == 3)
			return 1;	
		
		scanf(" %d", &z);
		for(i=0; i<c_motoqueiro; i++){
			if(vet_motoqueiro[i].cod_motoqueiro == z)
				existe_motoqueiro=1;
		}
		if(existe_motoqueiro == 0)
			return 3;
		else{
			vet_pedido[y].situcao = 2;
			vet_pedido[y].cod_motoqueiro = z;
			return 0;			
		}	
	}		
}

// ------------------------------------------------------------------- //

int recebe_pizza(pedido *vet_pedido, int c_pedido){
	
	int i, x, y;
	int existe_pedido=0;
	
	scanf(" %d", &x);	
	for(i=0;i<c_pedido;i++){
		if(vet_pedido[i].cod_pedido == x){
			y = i;
			existe_pedido=1;
		}
	}
	if(existe_pedido == 0)
		return 2;
	else{
		
		if(vet_pedido[y].situcao == 3)
			return 1;	
		else{
			vet_pedido[y].situcao = 3;
			return 0;			
		}	
	}		
}
	
// ------------------------------------------------------------------- //	
	
int pedido_situacao(pedido *vet_pedido, int c_pedido){
	
	int i, x;
	int existe_pedido=0;
	
	scanf(" %d", &x);
	
	if((x<=0) || (x>3))
		return 1;
	
	for(i=0;i<c_pedido;i++){
		if(vet_pedido[i].situcao == x){
			printf("Pedido: %d\n", vet_pedido[i].cod_pedido);
			printf("Cliente: %s\n", vet_pedido[i].telefone_cliente);
			printf("Pizza: %d\n", vet_pedido[i].cod_pizza);
			printf("Motoq: %d\n", vet_pedido[i].cod_motoqueiro);
			existe_pedido=1;
		}
	}
	
	if(existe_pedido==0)
		printf("Sem itens nessa situacao\n");
	
	return 0;
}
	
// ------------------------------------------------------------------- //
	
int pedido_cliente(pedido *vet_pedido, int c_pedido, cliente *vet_cliente, int c_cliente){
	
	int i, existe_pedido = 0, existe_cliente = 0;
	char tel[15];
	
	scanf(" %[^\n]", tel);
	
	for(i=0;i<c_cliente;i++){
		if(strcmp(vet_cliente[i].p_cliente.telefone, tel) == 0){ 
			existe_cliente = 1;
		}
	}

	if(existe_cliente == 1){
		
			for(i=0;i<c_pedido;i++){
			if(strcmp(vet_pedido[i].telefone_cliente, tel) == 0){ 
				printf("Pedido: %d\n", vet_pedido[i].cod_pedido);
				printf("Situacao: %d\n", vet_pedido[i].situcao);
				printf("Pizza: %d\n", vet_pedido[i].cod_pizza);
				printf("Motoq: %d\n", vet_pedido[i].cod_motoqueiro);
				existe_pedido = 1;
			}
		}
		
		if(existe_pedido==0)
			return 1;
			
		return 0;
		
	} 
	else{
		return 2;		
	}

}	
	
// ------------------------------------------------------------------- //

int pedido_motoqueiro(motoqueiro *vet_motoqueiro, int c_motoqueiro, pedido *vet_pedido, int c_pedido){
	
	int i, x;
	int existe_motoqueiro=0, existe_pedido=0;
	
	scanf(" %d", &x);
	
	for(i=0; i<c_motoqueiro; i++){
		if(vet_motoqueiro[i].cod_motoqueiro == x)
			existe_motoqueiro=1;
	}
	
	if(existe_motoqueiro == 1){
		
		for(i=0; i<c_pedido; i++){
			if(vet_pedido[i].cod_motoqueiro == x){
				printf("Pedido: %d\n", vet_pedido[i].cod_pedido);
				printf("Situacao: %d\n", vet_pedido[i].situcao);
				existe_pedido=1;
			}
		}
		
		if(existe_pedido==0)
			return 1;
		
		return 0;
	}
	else {
		return 2;
	}
}

	
	
	
	
	
	
	
	
	
	
