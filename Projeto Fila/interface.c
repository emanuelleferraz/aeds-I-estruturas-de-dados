#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("  \n\t6. REMOVER PRODUTO");
    printf("  \n\t7. INTERSECCAO");
    printf("  \n\t8. DIFERENCA");
    printf("  \n\t9. SAIR");
}

void MENU(TFila *fila, TFila *fila2, TFila *fila3, TFila *fila4){
    TProduto produto, produto2;
    TProduto pesqP;
    int opcao=0;
    int i, n, n2, codigo, num;
    int inserir, imprimir, pesquisar;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("\n------------ CADASTRAR PRODUTO ------------\n\n");
                printf("OPCOES:");
                printf("\nFILA 1: 1");
                printf("\nFILA 2: 2");
                printf("\nInforme a fila desejada: ");
                scanf("%d", &inserir);

                if(inserir == 1){
                    printf("\nInforme a quantidade de produtos a serem inseridos: ");
                    scanf("%d", &n);

                    for(i = 0; i < n; i++){
                       LerProduto(&produto);
                       Enfileirar(produto, fila);
                    }
                }

                if(inserir == 2){
                    printf("\nInforme a quantidade de produtos a serem inseridos: ");
                    scanf("%d", &n2);

                    for(i = 0; i < n2; i++){
                       LerProduto(&produto2);
                       Enfileirar(produto2, fila2);
                    }
                }

                system("PAUSE");
                break;
            case 2:
                printf("OPCOES:");
                printf("\nFILA 1: 1");
                printf("\nFILA 2: 2");
                printf("\nInforme a fila desejada: ");
                scanf("%d", &pesquisar);
                if(pesquisar == 1){
                   printf("\nInforme o nome do produto: ");
                   fflush(stdin);
                   fgets(produto.nome, 80, stdin);
                   PesquisarFila(fila, &produto);
                    if(produto.codigo > 0){
                       printf("\nProduto Encontrado!");
                       ImprimirProduto(produto);
                       free(&produto);

                    }else{
                       printf("\nProduto nao encontrado!");
                       free(&produto);
                    }
                }
                if(pesquisar == 2){
                   printf("\nInforme o nome do produto: ");
                   fflush(stdin);
                   fgets(produto2.nome, 80, stdin);
                   PesquisarFila(fila2, &produto2);
                    if(produto2.codigo > 0){
                       printf("\nProduto Encontrado!");
                       ImprimirProduto(produto2);
                       free(&produto2);

                    }else{
                       printf("\nProduto nao encontrado!");
                       free(&produto2);
                    }
                }

                system("PAUSE");
                break;
            case 3:
                printf("Informe o codigo do produto: ");
			    scanf("%d", &codigo);
			    produto.codigo = codigo;
			    Excluir(fila, produto);
                system("PAUSE");
                break;
            case 4:
                printf("\n------------ IMPRIMIR FILA ------------\n\n");
                printf("OPCOES:");
                printf("\nFILA 1: 1");
                printf("\nFILA 2: 2");
                printf("\nInforme a fila desejada: ");
                scanf("%d", &imprimir);

                if(imprimir == 1){
                   ImprimirFila(fila);
                }

                if(imprimir == 2){
                   ImprimirFila(fila2);
                }
                system("PAUSE");
                break;
            case 5:
                CompararFila(fila, fila2);
                system("PAUSE");
                break;
            case 6:
                printf("Informe o codigo do produto: ");
                scanf("%d", &num);
                Remover(fila, num);
                system("PAUSE");
                break;
            case 7:
                Intersecao(fila, fila2, fila3);
                printf("\nFILA 3:\n");
                ImprimirFila(fila3);
                system("PAUSE");
                break;
            case 8:
                Diferenca(fila, fila2, fila3);
                printf("\nFILA 3:\n");
                ImprimirFila(fila3);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 9);
}
