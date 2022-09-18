#include <iostream>
#include <windows.h>

using namespace std;

    typedef struct Pessoa{
        int idade;
        char nome[45];
        char endereco[45];
    };

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    Pessoa pessoa1;

    cout << "Digite seu nome:";    
    cin.getline(pessoa1.nome, 45);

    cout << "Digite sua idade:";
    cin >> pessoa1.idade;

    cout << "Digite seu Endereço:";
    for (int i = 0 ; i < 2; i++)cin.getline(pessoa1.endereco, 45);

    cout << "\nNome: " << pessoa1.nome;
    cout << "\nIdade: " << pessoa1.idade;
    cout << "\nEndereço: " << pessoa1.endereco;



    return 0;
}