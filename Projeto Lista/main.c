#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main(int argc, char const *argv[]){

	TLista lista, lista2, lista3;
	TProduto produto;

	FLVazia(&lista);
	FLVazia(&lista2);
	FLVazia(&lista3);

	MENU(&lista, &lista2, &lista3);

	Liberar(&lista);
	Liberar(&lista2);

	return 0;
}
