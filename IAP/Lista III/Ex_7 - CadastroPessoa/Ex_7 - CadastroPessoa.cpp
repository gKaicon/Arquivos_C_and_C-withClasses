#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

typedef struct Endereco {
    char rua[30];
    char bairro[30];
    char cidade[30];
    char estado[30];
    char cep[30];
};

typedef struct Cadastro {
    char nome[30];
    Endereco endereco;
    float salario;
    char identidade[15];
    char cpf[15];
    char estadoCivil[8];
    char telefone[15];
    int idade;
    char sexo;
};

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    Cadastro cadastro[5];
    int maiorIdade;
    char maior[30];
    char identidade[15];
    for(int i = 0; i < 5; i++) {
        cout << "Nome: ";
        cin.getline(cadastro[i].nome,30);
        cout << "Rua: ";
        cin.getline(cadastro[i].endereco.rua,30);
        cout << "Bairro: ";
        cin.getline(cadastro[i].endereco.bairro,30);
        cout << "Cidade: ";
        cin.getline(cadastro[i].endereco.cidade,30);
        cout << "Estado: ";
        cin.getline(cadastro[i].endereco.estado,30);
        cout << "CEP: ";
        cin.getline(cadastro[i].endereco.cep,30);
        cout << "Salário: ";
        cin >> cadastro[i].salario;
        cout << "RG: ";
        cin.getline(cadastro[i].identidade,15);
        cout << "CPF: ";
        cin.getline(cadastro[i].cpf,15);
        cout << "Estado Civil: ";
        cin.getline(cadastro[i].estadoCivil,15);
        cout << "Telefone: ";
        cin.getline(cadastro[i].telefone,15);
        cout << "idade: ";
        cin >> cadastro[i].idade;
        cout << "Sexo: ";
        cin >> cadastro[i].sexo;
    }

    cin.getline(identidade,15);

    maiorIdade = cadastro[0].idade;

    for(int i = 0; i < 5; i++) {
        if(cadastro[i].idade > maiorIdade) {
            maiorIdade = cadastro[i].idade;
            strcpy(maior,cadastro[i].nome);
        }
        if(cadastro[i].sexo == 'm' || cadastro[i].sexo == 'M') {
            cout << cadastro[i].nome << endl;
        }
        if(cadastro[i].salario > 1212.0) {
            cout << cadastro[i].nome << endl;
        }
        if(strcmp(cadastro[i].identidade,identidade) == 0) {
            cout << cadastro[i].nome << endl;
        }
    }
    cout << maior;
    return 0;
}