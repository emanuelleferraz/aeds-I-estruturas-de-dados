#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

void FFVazia(TFila *Fila){
	Fila->frente = (TCelula*) malloc(sizeof(TCelula));
	Fila->tras = Fila->frente;
	Fila->frente->prox = NULL;
	Fila->tamanho = 0;
}

int Vazia(TFila Fila){
	return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila){
	Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
	Fila->tras = Fila->tras->prox;
	Fila->tras->item = x;
	Fila->tras->prox = NULL;
	Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
	TCelula* Aux;
	if(!Vazia(*Fila)){
		Aux = Fila->frente->prox;
		Fila->frente->prox = Aux->prox;
		*Item = Aux->item;
		free(Aux);

		if(Fila->frente->prox == NULL){
			Fila->tras = Fila->frente;
		}
		Fila->tamanho--;
	}
}


int PesquisarFila(TFila *Fila, TProduto *Item){
    TProduto y;
	TFila Aux;
	FFVazia(&Aux);
	int flag = 0;

	while(!Vazia(*Fila)){
		Desenfileirar(Fila, &y);
		if(strcmp(Item->nome, y.nome) == 0){
			flag = 1;
			*Item = y;
		}
		Enfileirar(y, &Aux);
	}
	while(!Vazia(Aux)){
		Desenfileirar(&Aux, &y);
		Enfileirar(y, Fila);
	}
	free(Aux.frente);

	if(flag == 1){
		return 1;

	} else {
		Item->codigo = -1;
		return 0;
	}
}

void ImprimirFila(TFila *Fila){
	TProduto item;
	int n = Fila->tamanho;
	int i;
	for(i = 0; i < n; i++){
		Desenfileirar(Fila, &item);
		ImprimirProduto(item);
		Enfileirar(item, Fila);
	}
}

void ImprimirFila2(TFila *Fila){
	TProduto item;
	TFila Fila2;
	FFVazia(&Fila2);
	while(!Vazia(*Fila)){
		Desenfileirar(Fila, &item);
		ImprimirProduto(item);
		Enfileirar(item, &Fila2);
	}

	while(!Vazia(Fila2)){
		Desenfileirar(&Fila2, &item);
		Enfileirar(item, Fila);
	}
}

void Excluir(TFila *Fila, TProduto x){
	TProduto item;
	TFila Fila2;
	FFVazia(&Fila2);
	while (!Vazia(*Fila)){
		Desenfileirar(Fila, &item);
		if(item.codigo != x.codigo){
			Enfileirar(item, &Fila2);
		}
	}
	while (!Vazia(Fila2)){
		Desenfileirar(&Fila2, &item);
		Enfileirar(item, Fila);
	}
}

void LiberarFila(TFila *Fila){
    TProduto x;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

int CompararFila(TFila *Fila, TFila *Fila2){
    TProduto x, y;
    TFila Aux1, Aux2;
    FFVazia(&Aux1);
    FFVazia(&Aux2);
    int contador = 0;

    if(Fila->tamanho != Fila2->tamanho){
        printf("\nAs filas são  de tamanhos diferentes!\n");
        return 0;
    }

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
        while(!Vazia(*Fila2)){
            Desenfileirar(Fila2, &y);
            if(x.codigo == y.codigo){
                contador++;
            }
            Enfileirar(y, &Aux2);
        }
        Enfileirar(x, &Aux1);

        while(!Vazia(Aux2)){
            Desenfileirar(&Aux2, &y);
            Enfileirar(y, Fila2);
        }
    }

    while(!Vazia(Aux1)){
        Desenfileirar(&Aux1, &x);
        Enfileirar(x, Fila);
    }

    if(contador == Fila->tamanho){
        printf("\nFilas iguais!\n");
        return 1;

    } else {
        printf("\nFilas são diferentes!\n");
        return 0;
    }
}

void Remover(TFila *Fila, int n){
    TProduto item;
    TFila Aux;
    FFVazia(&Aux);

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &item);
        if(item.codigo == n){
            printf("\nProduto foi encontrado e sera removido!\n");

        } else {
            Enfileirar(item, &Aux);
        }
    }

    while(!Vazia(Aux)){
        Desenfileirar(&Aux, &item);
        Enfileirar(item, Fila);
    }
}

void Intersecao(TFila *Fila, TFila *Fila2, TFila *Fila3){
    TProduto x, y;
    TFila Aux1, Aux2;
    FFVazia(&Aux1);
    FFVazia(&Aux2);

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
        while(!Vazia(*Fila2)){
            Desenfileirar(Fila2, &y);
            if(x.codigo == y.codigo){
                Enfileirar(x, Fila3);
            }
            Enfileirar(y, &Aux2);
        }
        Enfileirar(x, &Aux1);
        while(!Vazia(Aux2)){
            Desenfileirar(&Aux2, &y);
            Enfileirar(y, Fila2);
        }
    }
    while(!Vazia(Aux1)){
        Desenfileirar(&Aux1, &x);
        Enfileirar(x, Fila);
    }
}

void Diferenca(TFila *Fila, TFila *Fila2, TFila *Fila3){
    TProduto x, y;
    TFila Aux1, Aux2;
    FFVazia(&Aux1);
    FFVazia(&Aux2);
    int cmp = 0;

    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
        while(!Vazia(*Fila2)){
            Desenfileirar(Fila2, &y);
            if(x.codigo != y.codigo){
                Enfileirar(x, Fila3);
            } else {
                if(!cmp) {
                    Enfileirar(y, &Aux2);
                    cmp = 1;
                } else {
                    Enfileirar(y, Fila2);
                }
            }
        }
        Enfileirar(x, &Aux1);
        while(!Vazia(Aux2)){
            Desenfileirar(&Aux2, &y);
            Enfileirar(y, Fila2);
        }
        cmp = 0;
    }
    while(!Vazia(Aux1)){
        Desenfileirar(&Aux1, &x);
        Enfileirar(x, Fila);
    }
}
