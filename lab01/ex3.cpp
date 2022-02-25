// Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). Este número deve ser sempre ímpar.
// 1 2 3 4 5 6 7 8 9
//   2 3 4 5 6 7 8
//     3 4 5 6 7
//       4 5 6
//         5
// Duvidas: não consegui colocar o espacamento correto
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Insira um numero (impar): " << endl;
    cin >> n;
    while (n % 2 == 0)
    {
        cout << "Erro: Insira novamente um numero (impar): " << endl;
        cin >> n;
    }
    vector<int> piramide;
    for (int i = 1; i != n + 1; i++)
    {
        piramide.push_back(i);
    }
    for (int x = 0; x != n; x++)
    {
        for (int num : piramide)
        {
            cout << num << " ";
        }
        cout << endl;
        piramide.pop_back();
        piramide.erase(piramide.begin());
    }

    return 0;
}