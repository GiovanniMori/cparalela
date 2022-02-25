//11. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz.O resultado deve ser colocado na linha L2.Faça o mesmo com a multiplicação.
#include <iostream>
using namespace std;

int main()
{
    int i, j, linha, coluna, sum;

    cout << "\nInsira a quantidade de linhas e colunas da Matriz =  ";
    cin >> i >> j;

    int sumRCArray[i][j];

    cout << "\nInsira os valores da matriz =  ";
    for (linha = 0; linha < i; linha++)
    {
        for (coluna = 0; coluna < i; coluna++)
        {
            cin >> sumRCArray[linha][coluna];
        }
    }

    for (linha = 0; linha < i; linha++)
    {
        sum = 0;
        for (coluna = 0; coluna < j; coluna++)
        {
            sum = sum + sumRCArray[linha][coluna];
        }
        cout << "\nA soma na linha " << linha + 1 << " = " << sum;
    }

    for (linha = 0; linha < i; linha++)
    {
        sum = 0;
        for (coluna = 0; coluna < j; coluna++)
        {
            sum = sum + sumRCArray[coluna][linha];
        }
        cout << "\nA soma da coluna = " << sum;
    }

    return 0;
}