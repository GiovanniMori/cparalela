// 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.
// 
// Duvidas:
#include <iostream>
using namespace std;

int main(){
    string frase, procurar;
    cout << "Insira a string" << endl;
    getline(cin, frase);
    cout << "Qual caracter deseja procurar" << endl;
    getline(cin, procurar);
    std::size_t found = frase.find(procurar);
    if(found != std::string::npos)
        cout << "O caracter " << frase << "foi encontrado na posicao: "  << found << endl;
    else
        cout << "Nao encontrado\n";
}
