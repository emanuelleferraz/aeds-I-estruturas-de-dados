#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
   TFila fila, fila2, fila3, fila4;
   TProduto produto;

   FFVazia(&fila);
   FFVazia(&fila2);
   FFVazia(&fila3);
   FFVazia(&fila4);


   MENU(&fila, &fila2, &fila3, &fila4);

   LiberarFila(&fila);
   LiberarFila(&fila2);
   LiberarFila(&fila3);
   LiberarFila(&fila4);

    return 0;
}
