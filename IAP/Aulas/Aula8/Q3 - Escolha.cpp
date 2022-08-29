#include <iostream>
using namespace std;

int main()
{
    int op;
    cout << "1-Cadastro\n2-Listar\n3-Excluir\n4-Sair\nEscolha uma das opções:";
    cin>>op;
    switch (op){
    case 1:
        cout << "Cadrastro\n";
        int id;
        cout<<"Informe seu ID:";
        cin>>id;
    case 2:
        cout << "Listar\n";
    case 3:
        cout << "Excluir\n";
    case 4:
        cout << "Sair\n";
        break;
    }
    system("pause");
    return 0;
}