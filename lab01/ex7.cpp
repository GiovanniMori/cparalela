// 7. Faça um programa que crie um vetor de pessoas. Os dados de uma pessoa devem ser armazenados em um variavel do tipo struct.
// O programa deve permitir que o usuário digite o nome de 3 pessoas e a seguir imprimi os dados de todas as pessoas. A struct deve armazenar os dados de idade, peso e altura.
// Duvidas:
//
#include <iostream>
using namespace std;

struct Serhumaninho
{
    string name;
    int idade;
    int altura;
};

int main()
{
    int cont = 1;
    Serhumaninho ser1;
    Serhumaninho ser2;
    Serhumaninho ser3;
    cout << "Insira os dados da 1 pessoa, nome, idade, altura(cm):" << endl;
    cin >> ser1.name >> ser1.idade >> ser1.altura;
    cout << "Insira os dados da 2 pessoa, nome, idade, altura(cm):" << endl;
    cin >> ser2.name >> ser2.idade >> ser2.altura;
    cout << "Insira os dados da 3 pessoa, nome, idade, altura(cm):" << endl;
    cin >> ser3.name >> ser3.idade >> ser3.altura;
    cout << "\nPessoa 1: \n"
         << "Nome: " << ser1.name << endl
         << "Idade: " << ser1.idade << "anos" << endl
         << "Altura: " << ser1.altura << " cm\n"
         << endl;
    ;
    cout << "Pessoa 2: \n"
         << "Nome: " << ser1.name << endl
         << "Idade: " << ser1.idade << "anos" << endl
         << "Altura: " << ser1.altura << " cm\n"
         << endl;
    ;
    cout << "Pessoa 3: \n"
         << "Nome: " << ser1.name << endl
         << "Idade: " << ser1.idade << "anos" << endl
         << "Altura: " << ser1.altura << " cm\n"
         << endl;
    ;

    return 0;
}
