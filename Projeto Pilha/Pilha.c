#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"
#include "fila.h"

void FPVazia(TPilha *Pilha){
	Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
	Pilha->fundo = Pilha->topo;
	Pilha->topo->prox = NULL;
	Pilha->tamanho = 0;
}

int PVazia(TPilha Pilha){
	return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha){
	TCelula* Aux;
	Aux = (TCelula*) malloc(sizeof(TCelula));
	Pilha->topo->item = x;
	Aux->prox = Pilha->topo;
	Pilha->topo = Aux;
	Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item){
	TCelula* q;
	if(PVazia(*Pilha)){
		printf("\nErro: Pilha vazia!");
		return;
	}

	q = Pilha->topo;
	Pilha->topo = q->prox;
	*Item = q->prox->item;
	free(q);
	Pilha->tamanho--;
}

void ImprimirPilha(TPilha *Pilha){
    TProduto item;
    TPilha Pilha2;
    FPVazia(&Pilha2);

    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &item);
        Empilhar(item, &Pilha2);
    }

    while(!PVazia(Pilha2)){
        Desempilhar(&Pilha2, &item);
        ImprimirProduto(item);
        Empilhar(item, Pilha);
    }
    free(Pilha2.topo);
}

int PesquisarPilha(TPilha *Pilha, TProduto *x){
    TProduto y;
    TPilha Aux;
    FPVazia(&Aux);
    int flag = 0;

    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &y);
        if(strcmp(x->nome, y.nome) == 0){
            *x = y;
            flag = 1;
        }
        Empilhar(y, &Aux);
    }
    while(!PVazia(Aux)){
		Desempilhar(&Aux, &y);
		Empilhar(y, Pilha);
	}
	free(Aux.topo);

	if(flag == 1){
		return 1;

	} else {
		x->codigo = -1;
		return 0;
	}
}

void LiberarPilha(TPilha *Pilha){
     TProduto x;
    while(!PVazia(*Pilha)){
        Desempilhar(Pilha, &x);
    }
    free(Pilha->topo);
}

void InverterPrimeiros(TFila *Fila){
    TProduto x;
    int k, prod, i;
    TPilha Pilha;
    TFila FAux;
    FPVazia(&Pilha);
    FFVazia(&FAux);

    printf("\nInforme a quantidade de produtos a serem lidos: ");
    scanf("%d", &prod);

    for(i = 0; i < prod; i++){
        LerProduto(&x);
        Enfileirar(x, Fila);
    }

    printf("\nInforme a quantidade de produtos a serem invertidos: ");
    scanf("%d", &k);

     if(k > Fila->tamanho){
        printf("\nErro: O valor informado e maior que a Fila.");
    }

    for(i = 0; i < k; i++){
        Desenfileirar(Fila, &x);
        Empilhar(x, &Pilha);
    }

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
        Enfileirar(x, &FAux);
    }

    while(!PVazia(Pilha)){
        Desempilhar(&Pilha, &x);
        Enfileirar(x, Fila);
    }

    while(!Vazia(FAux)){
        Desenfileirar(&FAux, &x);
        Enfileirar(x, Fila);
    }
    ImprimirFila(Fila);
}

void ConverteNDecimal(int numero){
    TProduto x;
    TPilha Pilha;
    FPVazia(&Pilha);
    int resto, divisao, base;

    printf("\nInforme um numero para ser convertido em decimal: ");
    scanf("%d", &numero);

    printf("\nInforme o valor da base (deve estar entre 2 e 9): ");
    scanf("%d", &base);

    while(numero > 0){
        resto = numero % 2;
        divisao = numero/base;
        numero = divisao;
        x.quantidade = resto;
        Empilhar(x, &Pilha);
    }

    while(!PVazia(Pilha)){
        Desempilhar(&Pilha, &x);
        printf("Resultado: %d\n", x.quantidade);
    }
}

void TamanhoString(TPilha *Pilha){
    TProduto aux;
    int i = 0;
    int cont = 0;

    printf("\nInsira a quantidade de parenteses desejada: ");
    fflush(stdin);
    fgets(aux.descricao, 20, stdin);

    while(aux.descricao[i] != '\0'){
        if(aux.descricao[i] == '('){
            aux.parenteses = '(';
            Empilhar(aux, Pilha);
        }
        else if(Pilha->topo->prox != NULL){
            Desempilhar(Pilha, &aux);
            cont+= 2;
        }
        i++;
    }
    printf("\nRESULTADO: %d\n", cont);
}

void ParentesesDuplicados(TPilha *Pilha){
    TProduto Aux;
    int i = 0;
    int cont = 0;

    printf("\nInforme a expressao desejada: ");
    fflush(stdin);
    fgets(Aux.descricao, 20, stdin);

    while(Aux.descricao[i] != '\0'){
        if(Aux.descricao[i] == '(' || '+abcd'){
            Aux.parenteses = '(' || '+abcd';
            Empilhar(Aux, Pilha);

        } else if(Aux.descricao[i] == ')'){
            while(!PVazia(*Pilha)){
                Desempilhar(Pilha, &Aux);
                cont++;
            }
        }
        i++;
    }

    if(cont > 0){
        printf("A expressao e cercada por: %d pares de caracteres\n", cont);

    } else {
        printf("\nNao existe nenhuma ocorrencia de parenteses duplicados nessa expressao!\n");
    }
}
