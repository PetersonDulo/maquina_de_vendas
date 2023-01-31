#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MOEDAMAX  8
#define STOCKMAX  4
#define INTMAX  50

// Prototipos das funcoes
void cabecalho();
void apresentacaoCaixa(int moedas[]);
void apresentacaoStock(int stock[]);
void applicacao();
int opcoesCompra();
int contaTotal();
int introduzirNotas();
void retirarNoVector(int *vetor);
int estaVazio(int *notas);
int fazerCompra(int stock[], int produtoPreco[], int *preco);
int darTrocoV2(int quantNotas[], int contaTotal);
int printInteracoes(int saldo, int preco, char *nomeProduto, int vetorDeNotas[]);
char *nomeProduto(int n, int precos[]);
//
// funcoes de entrada de dados ou fazer compras
// funcionalidades de dar troco
// carregar notas ou entrar com as notas na maquina
// carregar quantidade de determinado produto
// carregar quantidade de determinado
//

int opcoesCompra()
{
	int op;
	printf("\nbotao 1: Coca-cola\nbotao 2: Pura\nbotao 3: Toblerone\nbotao 4: Maria\nbotao 5: devolucao do troco;\nOp:");
	scanf("%d", &op);
	if (op >= 0 && op <= 5)
		return op;
	return 6;
}

// Recebe e valida as notas
int introduzirNotas()
{
	int nota;
	int n = 0;
	int notas[MOEDAMAX] = {1000, 500, 200, 100, 50, 25, 10, 5};
	printf("\n Introduzir nota:");
	scanf("%d", &nota);

	// validacao da nota ou dinheiro
	for (int i = 0; i < MOEDAMAX; i++)
		if (notas[i] == nota)
			n++;

	if (n == 1)
		return nota;
	return -1;
}

// Recebe e valida as notas
int introduzirNotasV2(int vetorDeNotas[])
{
	int nota;
	int n = 0;
	int notas[MOEDAMAX] = {1000, 500, 200, 100, 50, 25, 10, 5};
	printf("\n Introduzir nota:");
	scanf("%d", &nota);

	// validacao da nota ou dinheiro
	for (int i = 0; i < MOEDAMAX; i++)
		if (notas[i] == nota){
			vetorDeNotas[n]=nota;
			n++;
		}

	if (n == 1)
		return nota;
	return -1;
}


//Le as notas 
//retorna o total de notas inseridas
int contaTotalV2(int vetorDeNotas[])
{
	int quantidadeTotal = 0;
	int nota = 0;
	int i=0;
	int n = 0;
	while (n != 2)
	{
		nota = introduzirNotas();
		if (nota != -1){
			quantidadeTotal += nota;
			if(vetorDeNotas[i]>0) 
				i++;
			else{
				vetorDeNotas[i] = nota;
				i++;
			}
		}
		else{
			printf("Nota Errada\n");
		}
		printf("Deseja continuar a introduzir notas? \n 1 - sim | 2 - Nao: ");
		scanf("%d", &n);
	}
	return quantidadeTotal;
}

int contaTotal()
{
	int quantidadeTotal = 0;
	int nota = 0;
	int n = 0;
	while (n != 2)
	{
		nota = introduzirNotas();
		if (nota != -1)
			quantidadeTotal += nota;
		else
			printf("Nota Errada\n");
		printf("Deseja continuar a introduzir notas? \n 1 - sim | 2 - Nao: ");
		scanf("%d", &n);
	}
	return quantidadeTotal;
}

void retirarNoVector(int *vetor)
{
	*vetor = *vetor - 1;
}

int estaVazio(int *notas)
{
	return *notas <= 0;
}

int darTrocoV2(int quantNotas[], int contaTotal)
{
	int notas[MOEDAMAX] = {1000, 500, 200, 100, 50, 25, 10, 5};
	int troco = contaTotal;
	int is = 0;
	for (int i = 0; i <= MOEDAMAX; i++)
	{
		if (estaVazio(&quantNotas[i]))
			continue;
		else if (troco >= notas[i])
		{
			troco = abs(notas[i] - troco);
			// printf(" %d moeda kz %d \n",troco, notas[i]);
			printf("moeda kz %d \n", notas[i]);
			retirarNoVector(&quantNotas[i]);
			//verifica se a mesma nota ainda serve para dar troco
			if(troco >= notas[i]) i--; 
		}
	}
	return troco;
}

int darTroco(int contaTotal)
{
	int notas[MOEDAMAX] = {1000, 500, 200, 100, 50, 25, 10, 5};
	int troco = contaTotal;
	int is = 0;

	while (troco != 0)
	{
		for (int i = is; i < 8; i++)
		{
			if (troco >= notas[i])
			{
				troco = abs(notas[i] - troco);
				printf("moeda kz %d \n", notas[i]);
				is = i;
			}
		}
	}
	return 0;
}

//dado preco retorna o nome do produto
char *nomeProduto(int n, int precos[]){
	if(n == precos[0]){
		return "Coca-cola";
	}
	else if(n == precos[1]){
		return "Pura";
	}
	else if(n == precos[2]){
		return "Toblerone";
	}
	else if(n == precos[3]){
		return "Bolacha Maria";
	}
	return "\0";
}

int fazerCompra(int stock[], int produtoPreco[], int *preco)
{
	int opcao = opcoesCompra();
	switch (opcao)
	{
	case 1: // Coca-cola
		if (!estaVazio(&stock[0]))
		{
			retirarNoVector(&stock[0]);
			*preco = produtoPreco[0];
		}
		break;
	case 2: // Pura
		if (!estaVazio(&stock[1]))
		{
			retirarNoVector(&stock[1]);
			*preco = produtoPreco[1];
		}
		break;
	case 3: // Toblerone
		if (!estaVazio(&stock[2]))
		{
			retirarNoVector(&stock[2]);
			*preco = produtoPreco[2];
		}
		break;
	case 4: // Bolacha Maria
		if (!estaVazio(&stock[3]))
		{
			retirarNoVector(&stock[3]);
			*preco = produtoPreco[3];
		}
		break;
	case 5: // dar troco
		return 0;
		break;
	default:
		printf("Opcao inesistente");
		break;
	}
	return *preco;
}

void apresentacaoCaixa(int moedas[])
{
	printf("\n\nCaixa:");
	printf("\nKz 10,00\t Kz 5,00\t Kz 2,00\t Kz 1,00\t Kz 0,50\t Kz 0,25\t kz0,10 \tkz0,05");
	printf("\n  %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
		   moedas[0], moedas[1], moedas[2], moedas[3], moedas[4], moedas[5], moedas[6], moedas[7]);
}

void apresentacaoStock(int stock[])
{
	printf("\n\nStock:");
	printf("\nCoca-cola\t Pura\t Toblerone\t Maria\n");
	printf("\n %d\t%d\t%d\t%d\n", stock[0], stock[1], stock[2], stock[3]);
	printf("\n\nPreco em Centavos:");
	printf("\n  Coca-cola\t Pura\t Toblerone\t Maria\n");
	printf("\n  250,00\t 120,00\t 320,00 \t 240,00\n");
}


int printInteracoes(int saldo, int preco, char *nomeProduto, int vetorDeNotas[]){
	int estado = 0;
	printf("/---------------------------- interacoes com o utilizador ----------------------------/\n");
	for(int i = 0; i<INTMAX; i++){
		if(vetorDeNotas[i]==0) 
			i=INTMAX;
		else{
			estado+=vetorDeNotas[i];
			printf("Recebeu de %d (saldo do utilizador %d)\n", vetorDeNotas[i],estado);
		}
	}
	printf("Venda de %s (Preco %d, Saldo do Utilizador: %d) \n",nomeProduto,preco,saldo);
	printf("Troco: %d (Saldo do Utilizador: %d)\n",(abs(saldo)),abs(saldo-saldo));
	printf("/-------------------------------------------------------------------------------------/\n");
	return estado;
}

int appEstado(){
	int estado;
	

	return estado;
}


void applicacao()
{
	int quantMoedas[MOEDAMAX] = {0, 10, 20, 43, 48, 80, 1, 1};
	int produtosPreco[STOCKMAX] = {250, 120, 320, 240};
	int quantStock[STOCKMAX] = {10, 20, 30, 25};
	int vetorDeNotas[INTMAX]={0};
	int preco = 0;
	int saldo = 0;
	int dinheiro = 0;
	int sair =0;

	//so sai se decidir sair ou se o dinheiro for insuficiente
	dinheiro = contaTotalV2(vetorDeNotas);
	saldo = dinheiro;
	while(sair != 3){	
		if(fazerCompra(quantStock, produtosPreco, &preco) == 0){
			if(darTrocoV2(quantMoedas, saldo) == 0) 
				break;
			else{
				printf("Compra n efetuada, estamos sem troco\n");
				break;
			}
		}else{
			saldo -= preco;
		}
		
		printf("Deseja inserir dinheiro? 1- sim | 2 nao: "); scanf("%d",&sair);
		if(sair == 1)
			saldo + contaTotalV2(vetorDeNotas);
		
		//saldo insuficiente
		if(saldo <= 0) break;


	}
	printf("/--------------------------------- Estado Inicial --------------------------------------/\n");
	apresentacaoCaixa(quantMoedas);
	apresentacaoStock(quantStock);
	printInteracoes(saldo,preco,nomeProduto(preco,produtosPreco),vetorDeNotas);
}

void cabecalho()
{
	printf("/*******************************/\n");
	printf("\t\tAlsizio\n");
	printf("/*******************************/\n");
}

int main(void)
{
	cabecalho();
	applicacao();
	return 0;
}

