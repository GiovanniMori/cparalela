// 14. Faça uma rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.
// https://www.cplusplus.com/reference/string/string/insert/
// Duvidas: é preciso aumentar a Str em 1, ou seja, Str[101]?
// A ideia que tive era achar a posição e jogar todos os elementos pra frente mas não consegui =/
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int cont;
    char Str[100];
    char caracter;
    int posicao;
    cout << "Insira a string: " << endl;
    gets(Str);
    cout << "Qual caracter deseja inserir: " << endl;
    cin >> caracter;
    cout << "Posicao para inserir: " << endl;
    cin >> posicao;
    while (Str[i] != '\0')
    {
        if (i==posicao){
            Str[i] = Str[i+1];
            Str[i] = caracter;
        }
            
        i++;
    }
    if (Str[posicao]!= caracter)
    {
        cout << Str[2] << endl;
        cout << "Elemento nao encontrado" << endl;
    }
    else
    {
        printf(Str);
    }
}
