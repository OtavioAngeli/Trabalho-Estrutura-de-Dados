#include <stdio.h>
#include <stdlib.h>

/********************** PILHA ENCADEADA **********************/
struct Pilha {
	int topo; /* posição elemento topo */
	int capa;
	float *prox;
};

/********************** FILA ENCADEADA **********************/
struct Fila {
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens; 
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
	printf("\n\t--- PILHA ---\n");
	printf("1. Empilhar (push)\n");
	printf("2. Desempilhar (POP)\n");
	printf("3. Mostrar o topo \n");
	printf("4. Imprimir Pilha\n");
	printf("5. Tamanho da Pilha\n");
	printf("0. Sair\n> ");
}

void imprimeMenuFila(){
	printf("\n\t--- FILA ---\n");
	printf("1. Inserir elemento\n");
	printf("2. Remover elemento\n");
	printf("3. Mostrar Fila\n");
	printf("0. Sair\n> ");
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
		imprimeMenuPilha();
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
			case 5:
				printf("case 5");
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
void criarFila( struct Fila *f, int c ) { 
	f->capacidade = c;
	f->dados = (float*) malloc (f->capacidade * sizeof(float));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0; 
}

void inserir(struct Fila *f, int v) {
	if(f->ultimo == f->capacidade-1)
		f->ultimo = -1;
	f->ultimo++;
	f->dados[f->ultimo] = v; // incrementa ultimo e insere
	f->nItens++; // mais um item inserido
}

int remover( struct Fila *f ) { // pega o item do começo da fila
	int temp = f->dados[f->primeiro++]; // pega o valor e incrementa o primeiro
	if(f->primeiro == f->capacidade)
		f->primeiro = 0;
	f->nItens--;  // um item retirado
	return temp;
}

int estaVazia( struct Fila *f ) { // retorna verdadeiro se a fila está vazia
	return (f->nItens==0);
}

int estaCheia( struct Fila *f ) { // retorna verdadeiro se a fila está cheia
	return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){
		printf("%.2f\t",f->dados[i++]);
		if (i == f->capacidade)
			i=0;
	}
	printf("\n\n");
}

/******************************* FILA ENCADEADA *******************************/
void filaEncadeada(){
	int opcao, capa;
	float valor;
	struct Fila fEncadeada;

	// criar a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capa);

	criarFila(&fEncadeada, capa);

	while( 1 ){	
		imprimeMenuFila();
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0: 
				exit(0);
			case 1:
			/**************** INSERIR ELEMENTO ****************/
				if (estaCheia(&fEncadeada)){
					printf("\nFila Cheia!!!\n\n");
				}else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					inserir(&fEncadeada,valor);
				}
				break;
		
			case 2:
			/**************** REMOVER ELEMENTO ****************/
				if (estaVazia(&fEncadeada)){
					printf("\nFila vazia!!!\n\n");
				}else {
					valor = remover(&fEncadeada);
					printf("\n%1f removido com sucesso\n\n", valor) ; 
				}
				break;
		
			case 3:
			/**************** MOSTRAR FILA ****************/
				if (estaVazia(&fEncadeada)){
					printf("\nFila vazia!!!\n\n");
				}else {
					printf("\nConteudo da fila => ");
					mostrarFila(&fEncadeada);
				}
				break;
		
			default:
				printf("\nOpcao Invalida\n\n");
		}
	}
}

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
				imprimeMenuFila();
				break;
			case 4:	
			/**************** FILA ENCADEADA ****************/
				filaEncadeada();
				break;
			default:
				printf("Opção invalida.\n");
		}
	}while(op != 0);
	
    return 0;
}
