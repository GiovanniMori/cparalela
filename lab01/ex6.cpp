// 6. Crie um programa capaz de criar a transposta de uma matriz. A matriz deve ser lida de teclado.
// Duvidas:
#include <iostream>
using namespace std;

int main()
{
    int elem[10][10], transposta[10][10];
    int linha, coluna, i, j;

    cout << "Insira a quantidade de linhas da Matriz: ";
    cin >> linha;
    cout << "Insira a quantidade de colunas da Matriz: ";
    cin >> coluna;
    cout << "\nInsira os elementos da Matriz: " << endl;

    for (int i = 0; i < linha; ++i)
    {
        for (int j = 0; j < coluna; ++j)
        {
            cout << "Insira o elemento " << i + 1 << "x" << j + 1 << ": ";
            cin >> elem[i][j];
        }
    }

    cout << "\nMatriz: " << endl;
    for (int i = 0; i < linha; ++i)
    {
        for (int j = 0; j < coluna; ++j)
        {
            cout << " " << elem[i][j];
            if (j == coluna - 1)
                cout << endl;
        }
    }

    for (int i = 0; i < linha; ++i)
        for (int j = 0; j < coluna; ++j)
        {
            transposta[j][i] = elem[i][j];
        }

    cout << "\nMatriz transposta: " << endl;
    for (int i = 0; i < coluna; ++i)
        for (int j = 0; j < linha; ++j)
        {
            cout << " " << transposta[i][j];
            if (j == linha - 1)
                cout << endl;
        }

    return 0;
}