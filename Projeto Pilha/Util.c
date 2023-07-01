#include <stdio.h>
#include <stdlib.h>

#include "util.h"

void LerProduto(TProduto *x){

	printf("\n-------- LEITURA DE DADOS DO PRODUTO --------\n");

	printf("Informe o nome do produto: ");
	fflush(stdin);
	fgets(x->nome, 80, stdin);

	printf("Informe o codigo do produto: ");
	scanf("%d", &x->codigo);

	printf("Informe a descricao: ");
	fflush(stdin);
	fgets(x->descricao, 200, stdin);

	printf("Informe o preco: ");
	scanf("%f", &x->preco);

	printf("Informe a quantidade: ");
	scanf("%d", &x->quantidade);

	printf("Informe o peso: ");
	scanf("%f", &x->peso);
}

void ImprimirProduto(TProduto x){

	printf("\n-------- SAIDA DE DADOS DO PRODUTO --------\n");

	printf("Codigo: %d\n", x.codigo);
	printf("Nome: %s\n", x.nome);
	printf("Descricao: %s\n", x.descricao);
	printf("Preco: %.2f\n", x.preco);
	printf("Quantidade: %d\n", x.quantidade);
	printf("Peso: %.2f\n", x.peso);

}
