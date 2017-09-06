#include <stdio.h>
#include <stdlib.h>

struct Pilha {
	int topo; /* posição elemento topo */
	int capa;
	float *prox;
};

/******************************* MENU *******************************/
void imprimeMenu(){
	printf("\tEscolha sua opção:\n");
	printf("1. PILHA sequencial\n");
	printf("2. PILHA encadeada\n");
	printf("3. FILA sequencial\n");
	printf("4. FILA encadeada\n");
	printf("0. Sair\n> ");
}

void imprimeMenuPilha(){
    printf("\n\t Menu Pilha\n");
	printf("1. Empilhar\n");
	printf("2. Desempilhar\n");
	printf("3. Buscar qual elemento esta no topo da pilha\n");
	printf("4. Retornar o tamanho da pilha\n");
	printf("5. Imprimir toda a pilha\n");
	printf("0. Sair\n");
}

void imprimeMenuPilhaEncadeada(){
	printf("\n\t--- PILHA ENCADEADA ---\n");
	printf("1. Empilhar (push)\n");
	printf("2. Desempilhar (POP)\n");
	printf("3. Mostrar o topo \n");
	printf("4. Tamanho da Pilha\n");
	printf("0. Sair\n> ");
}

void imprimeMenuFilaEncadeada(){
	
}

/******************************* FUNÇÕES PILHA SEQUENCIAL*******************************/

/******************************* PILHA SEQUENCIAL *******************************/

/******************************* FUNÇÕES PILHA ENCADEADA *******************************/
void criarPilha( struct Pilha *p, int c ){
	p->topo = -1;
	p->capa = c;
	p->prox = (float*) malloc (c * sizeof(float));
 }

 int pilhaCheia ( struct Pilha *p ){
	if (p->topo == p->capa - 1)
		return 1;
	else
		return 0;
}

int pilhaVazia( struct Pilha *p ){
	if( p-> topo == -1 )
	   return 1;   // true
	else
	   return 0;   // false
 }

 void empilhar ( struct Pilha *p, float v){
	p->topo++;
	p->prox [p->topo] = v;
}

float desempilhar ( struct Pilha *p ){
	float aux = p->prox [p->topo];
	p->topo--;
	return aux;
 
 }

 float retornaTopo ( struct Pilha *p ){
	return p->prox [p->topo];
 }

/******************************* PILHA ENCADEADA *******************************/
void pilhaEncadeada(){
	struct Pilha pEncadeada;
	int capacidade, op;
	float valor;

	printf( "\nCapacidade da pilha: " );
	scanf( "%d", &capacidade );

	criarPilha (&pEncadeada, capacidade);
	
	while( 1 ) { /*** LOOP INFINITO ***/
		imprimeMenuPilhaEncadeada();
		scanf("%d", &op);
	
		switch(op){
			case 1:
			/************ EMPILHAR (PUSH) ************/
				if( pilhaCheia( &pEncadeada ) == 1 )
					printf("\nPILHA CHEIA! \n");
				else {
					printf("\nValor:\n> ");
					scanf("%f", &valor);
					empilhar (&pEncadeada, valor);
				}
				break;
			case 2:
			/************ DESEMPILHAR (POP) ************/
				if ( pilhaVazia(&pEncadeada) == 1 )
					printf( "\nPILHA VAZIA! \n" );
				else{
					valor = desempilhar (&pEncadeada);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				break;
			case 3:
				if ( pilhaVazia (&pEncadeada) == 1 )
					printf( "\nPILHA VAZIA!\n" );
				else {
					valor = retornaTopo (&pEncadeada);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
			case 4:
				printf("case 4");
				break;
			case 0:
				exit(0);
			default:
				printf("Opção Invalida.");
		}
	}
	
}

/******************************* FUNÇÕES FILA SEQUENCIAL *******************************/

/******************************* FILA SEQUENCIAL *******************************/

/******************************* FUNÇÕES FILA ENCADEADA *******************************/

/******************************* FILA ENCADEADA *******************************/

//----------------------------------  MAIN ---------------------------------- //
int main(){
	int op = 0;
	
	do{
		imprimeMenu();
		scanf("%d", &op);
	
		switch(op){
			case 0: 
			/**************** SAIR ****************/
				printf("Saindo...\n");
				break;
			case 1:	
			/**************** PILHA SEQUENCIAL ****************/
				imprimeMenuPilha();
				break;
			case 2:	
			/**************** PILHA ENCADEADA ****************/
				pilhaEncadeada();
				break;
			case 3:	
			/**************** FILA SEQUENCIAL ****************/
				printf("Fila Sequencial\n");
				break;
			case 4:	
			/**************** FILA ENCADEADA ****************/
				printf("Fila Encadeada\n");
				imprimeMenuFilaEncadeada();
				break;
			default:
				printf("Opção invalida.\n");
		}
	}while(op != 0);
	
    return 0;
}
