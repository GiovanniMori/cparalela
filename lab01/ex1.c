// 1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.
//  https://www.cplusplus.com/reference/string/string/insert/
//  Duvidas:
//  Exercicio 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, i, j, min, cont;

    printf("Digite a dimensao da matriz quadrada\n");
    scanf("%d", &k);

    int a[k][k];

    printf("Digite os valores da matriz\n");
    for (i = 0; i < k; i++)
    {
        printf("Digite os valores para a %d linha\n", i + 1);
        for (j = 0; j < k; j++)
            scanf("%d", &a[i][j]);
    }
    printf("A matriz digitada e\n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++){
            if (a[i][j] >= min)
            {
                min = a[i][j];
                cont++;
            }
        }
            
        
    }
    printf("Menor numero presente na linha: ", cont);
}