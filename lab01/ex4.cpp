// 4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++
// Duvidas:
#include <iostream>
#include <cstring>
using namespace std;
void stringnameorder(){
    char name[2][15], order[15];
    int i, j;
    cout << "Insira os 2 nomes : \n";
    for (i = 0; i < 2; i++)
    {
        cout << " ";
        cin >> name[i];
    }
    for (i = 1; i < 2; i++)
    {
        for (j = 1; j < 2; j++)
        {
            if (strcmp(name[j - 1], name[j]) > 0)
            {
                strcpy(order, name[j - 1]);
                strcpy(name[j - 1], name[j]);
                strcpy(name[j], order);
            }
        }
    }
    cout << "\nNomes em ordem alfabetica: \n";
    for (i = 0; i < 2; i++)
    {
        cout << " ";
        cout << name[i] << "\n";
    }
}

int main()
{
    stringnameorder();
    return 0;
}