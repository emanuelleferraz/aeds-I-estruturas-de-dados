#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. COMPARAR");
    printf("  \n\t6. CONCATENAR");
    printf("  \n\t7. DIVIDIR");
    printf("  \n\t8. IMPRIMIR CELULA");
    printf("  \n\t9. REMOVER CELULA");
    printf("  \n\t10. SAIR");
}

void MENU(TLista *lista, TLista *lista2, TLista *lista3){
    TProduto produto;
    int opcao=0, codigo;
    int i, n, n2, lerLista, impLista, pesLista;
    int excProd, num, num2, remCel, impCel;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("\n\t----------- Selecione a lista para cadastrar o produto ---------- ");
                printf("\n\n\t\t\t\tLISTA 1 = 1");
                printf("\n\t\t\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &lerLista);
                if(lerLista == 1){
                   printf("\nInforme a quantidade de produtos a serem inseridos: ");
                   scanf("%d", &n);
                   for(i = 0; i < n; i++){
                     LerProduto(&produto);
                     Inserir(produto, lista);
                   }
                }
                if(lerLista == 2){
                   printf("\nInforme a quantidade de produtos a serem inseridos: ");
                   scanf("%d", &n2);
                   for(i = 0; i < n2; i++){
                     LerProduto(&produto);
                     Inserir(produto, lista2);
                   }
                }
                system("PAUSE");
                break;
            case 2:
                printf("\n\t---------- Selecione a lista -----------");
                printf("\n\n\t\tLISTA 1 = 1");
                printf("\n\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &pesLista);
                if(pesLista == 1){
                    printf("\nInforme o codigo do produto: ");
            	    scanf("%d", &codigo);
            	    produto.codigo = codigo;
                    Pesquisar(*lista, produto);
                }
                if(pesLista == 2){
                    printf("Informe o codigo do produto: ");
            	    scanf("%d", &codigo);
            	    produto.codigo = codigo;
                    Pesquisar(*lista2, produto);
                }
                system("PAUSE");
                break;
            case 3:
                printf("\n\t---------- Selecione a lista -----------");
                printf("\n\n\t\tLISTA 1 = 1");
                printf("\n\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &excProd);
                if(excProd == 1){
                    Excluir(lista, &produto);
                }
                if(excProd == 2){
                    Excluir(&lista2, &produto);
                }
                system("PAUSE");
                break;
            case 4:
                printf("\n\t---------- Selecione a lista -----------");
                printf("\n\n\t\tLISTA 1 = 1");
                printf("\n\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &impLista);
                if(impLista == 1){
                    Imprimir(*lista);
                }
                if(impLista == 2){
                    Imprimir(*lista2);
                }
                system("PAUSE");
                break;
            case 5:
                printf("\nLISTAS IGUAIS = 1\n");
                printf("LISTAS DIFERENTES = 0\n");
                printf("RETORNO: %d\n", Comparar(*lista, *lista2));
                system("PAUSE");
                break;
            case 6:
                ConcatenarListas(lista, &lista2);
                Imprimir(*lista);
                system("PAUSE");
                break;
            case 7:
                DividirLista(*lista, &lista2, &lista3);
                printf("\nLISTA 2:\n");
                Imprimir(*lista2);
                printf("\nLISTA 3:\n");
                Imprimir(*lista3);
                system("PAUSE");
                break;
             case 8:
                printf("\n\t---------- Selecione a lista -----------");
                printf("\n\n\t\tLISTA 1 = 1");
                printf("\n\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &impCel);
                if(impCel == 1){
                    ImprimirCelula(lista, num);
                }
                if(impCel == 2){
                    ImprimirCelula(lista2, num);
                }
                system("PAUSE");
                break;
            case 9:
                printf("\n\t---------- Selecione a lista -----------");
                printf("\n\n\t\tLISTA 1 = 1");
                printf("\n\t\tLISTA 2 = 2");
                printf("\nLista: ");
                scanf("%d", &remCel);
                if(remCel == 1){
                    RemoverCelula(lista, num2);
                }
                if(remCel == 2){
                    RemoverCelula(lista2, num2);
                }
                system("PAUSE");
                break;
            case 10:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 10);
}
