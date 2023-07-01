#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
    TPilha pilha, pilha2;
    TProduto produto;

    TFila fila;
    FFVazia(&fila);

    FPVazia(&pilha);
    FPVazia(&pilha2);

    MENU(&pilha, &fila, &pilha2);

    LiberarPilha(&pilha);
    LiberarFila(&fila);
    LiberarPilha(&pilha2);

    return 0;
}
