#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdio.h>
#include <stdlib.h>

//Estruturas

typedef struct {
	int codigo;
	char nome[80];
	char descricao[200];
	float preco;
	int quantidade;
	float peso;
	char parenteses;
} TProduto;

typedef struct celula{
	TProduto item;
	struct celula *prox;
} TCelula;

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

#endif
