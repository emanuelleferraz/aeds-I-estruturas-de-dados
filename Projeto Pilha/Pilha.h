#ifndef PILHA_HEADER
#define PILHA_HEADER
#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "util.h"

typedef struct pilha{
	TCelula *fundo;
	TCelula *topo;
	int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void ImprimirPilha(TPilha *Pilha);

int PesquisarPilha(TPilha *Pilha, TProduto *x);

void LiberarPilha(TPilha *Pilha);

void InverterPrimeiros(TFila *Fila);

void ConverteNDecimal(int numero);

void TamanhoString(TPilha *Pilha);

#endif
