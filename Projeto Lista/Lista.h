#ifndef LISTA_HEADER
#define LISTA_HEADER
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int codigo;
	char nome[80];
	char descricao[200];
	float preco;
	int quantidade;
	float peso;
} TProduto;



typedef struct celula{
	TProduto item;
	struct celula* prox;
} TCelula;

typedef struct {
	TCelula* primeiro;
	TCelula* ultimo;
	int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void Inserir(TProduto x, TLista *Lista);

void Imprimir(TLista Lista);

TCelula* Pesquisar(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

void ExcluirImpares(TLista *Lista);

void Liberar(TLista *Lista);

int Comparar(TLista Lista1, TLista Lista2);

void ConcatenarListas(TLista *Lista1, TLista *Lista2);

void DividirLista(TLista Lista1, TLista *Lista2, TLista *Lista3);

void ImprimirCelula(TLista *Lista, int numCel);

void RemoverCelula(TLista *Lista, int numCel);

#endif
