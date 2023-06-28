#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TLista *Lista){
	Lista -> primeiro = (TCelula*) malloc(sizeof(TCelula));
	Lista -> ultimo = Lista -> primeiro;
	Lista -> primeiro -> prox = NULL;
	Lista -> tamanho = 0;
}
int Vazia(TLista Lista){
	return (Lista.primeiro == Lista.ultimo);
}

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

	printf("\n-------- SAIDA DE DADOS DO PRODUTO PESQUISADO --------\n");

	printf("Codigo: %d\n", x.codigo);
	printf("Nome: %s\n", x.nome);
	printf("Descricao: %s\n", x.descricao);
	printf("Preco: %.2f\n", x.preco);
	printf("Quantidade: %d\n", x.quantidade);
	printf("Peso: %.2f\n", x.peso);

}

void Inserir(TProduto x, TLista *Lista){
	Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
	Lista -> ultimo = Lista -> ultimo -> prox;
	Lista -> ultimo -> item = x;
	Lista -> ultimo -> prox = NULL;
	Lista -> tamanho++;
}


void Imprimir(TLista Lista){
	TCelula* Aux;
	Aux = Lista.primeiro -> prox;
	while(Aux != NULL){
		printf("--------------- PRODUTO ---------------\n");
	    ImprimirProduto(Aux -> item);
		Aux = Aux -> prox;
	}
}

TCelula* Pesquisar(TLista Lista, TProduto Item){
	TCelula* Aux;
	Aux = Lista.primeiro;
	while(Aux -> prox != NULL){
		if(Aux -> prox -> item.codigo == Item.codigo){
			ImprimirProduto(Aux -> prox -> item);
			return 0;
		}
		Aux = Aux -> prox;
	}
	printf("Produto nao foi encontrado!\n");
}

void Excluir(TLista *Lista, TProduto *Item){
	TCelula *Aux1, *Aux2;
	Aux1 = Pesquisar(*Lista, *Item);
	if(Aux1 != NULL){
		Aux2 = Aux1 -> prox;
		Aux1 -> prox = Aux2 -> prox;
		*Item = Aux2 -> item;
		if(Aux1 -> prox == NULL){
			Lista -> ultimo = Aux1;
		}
		free(Aux2);
		Lista -> tamanho--;
	}
}

void ExcluirImpares(TLista *Lista){
    TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;
    while(Aux1->prox != NULL){
        if(Aux1->prox->item.codigo % 2 != 0){
            Aux2 = Aux1->prox;
            Aux1->prox = Aux2->prox;
            if(Aux1->prox == NULL){
                Lista->ultimo = Aux1;
            }
            free(Aux2);
            Lista->tamanho--;
        } else {
          Aux1 = Aux1-> prox;
		}
    }
}

void Liberar(TLista *Lista){
	TCelula *Aux1, *Aux2;
    Aux1 = Lista->primeiro;
    while(Aux1->prox != NULL){
            Aux2 = Aux1->prox;
            Aux1->prox = Aux2->prox;
            if(Aux1->prox == NULL){
                Lista->ultimo = Aux1;
            }
            free(Aux2);
            Lista->tamanho--;
    }
    free(Lista -> primeiro);
}

int Comparar(TLista Lista1, TLista Lista2){
	if(Lista1.tamanho != Lista2.tamanho){
		return 0;

	} else {
		TCelula *Aux1 = Lista1.primeiro->prox;
		TCelula *Aux2 = Lista2.primeiro->prox;
		while(Aux1 != NULL){
			if(Aux1 -> item.codigo != Aux2 -> item.codigo){
				return 0;
			}
			Aux1 = Aux1->prox;
			Aux2 = Aux2->prox;
		}
	}
	return 1;
}

void ConcatenarListas(TLista *Lista1, TLista *Lista2){
    Lista1->ultimo->prox = Lista2->primeiro->prox;
}

void DividirLista(TLista Lista1, TLista *Lista2, TLista *Lista3){
	TCelula *Aux;
	int i, parteUm;
	parteUm = Lista1.tamanho/2;
	Aux = Lista1.primeiro->prox;

	for(i = 0; i < parteUm; i++){
		Inserir(Aux->item, Lista2);
		Aux = Aux->prox;
	}

	while(Aux != NULL){
		Inserir(Aux->item, Lista3);
		Aux = Aux->prox;
	}
}

void ImprimirCelula(TLista *Lista, int numCel){

	TCelula *Aux;
	Aux = Lista->primeiro->prox;
	int i;

	printf("Informe o numero referente a celula que voce deseja imprimir: ");
	scanf("%d", &numCel);

	for(i = 0; i <= numCel && Aux != NULL; i++){

		if(i == numCel){
			printf("\nProduto Encontrado:");
			ImprimirProduto(Aux->item);
		} else{
		    Aux = Aux->prox;
		}
	}
	printf("Celula nao existe!\n");
}

void RemoverCelula(TLista *Lista, int numCel){
	TCelula *Aux;
	Aux = Lista->primeiro->prox;
	int i;

	printf("Informe o numero referente a celula que você deseja excluir: ");
	scanf("%d", &numCel);

	for(i = 0; i <= numCel && Aux != NULL; i++){
		if(i == numCel){
			printf("\nProduto foi encontrado e será excluído!");
			Excluir(Lista, &Aux->item);
		}
		Aux = Aux->prox;
	}
	printf("Celula nao existe!\n");
}
