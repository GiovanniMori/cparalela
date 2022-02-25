// 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.
// 
// Duvidas:
#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int cont;
    char Str[100];
    char caracter;
    cout << "Insira a string" << endl;
    gets(Str);
    cout << "Qual caracter deseja procurar" << endl;
    cin >> caracter;
    while (Str[i] != '\0')
    {
        if (Str[i] == caracter)
        {
            Str[i] = ' ';
            cont++;
        }        
        i++;
    }
    if (cont!=0){
        printf(Str);
    } else {
        cout << "Elemento nao encontrado" << endl;
    }
    
}
