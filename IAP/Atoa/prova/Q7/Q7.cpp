#include <iostream>
#include <windows.h>
#define Vcst 0.785

using namespace std;

typedef struct Telefone {
    char ddd[3];
    char numero[9];
};
typedef struct Endereco {
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char cep[15];
    char email[50];
    Telefone telefone[2];
};

typedef struct Empresa {
    char razao_social[50];
    char nome_fantasia[50];
    char cnpj[15];
    Endereco endereco;
};

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    Empresa emp[2];
    for(int i = 0; i < 2; i++){
        cin.getline(emp[i].razao_social,50);
        cin.getline(emp[i].nome_fantasia,50);
        cin.getline(emp[i].cnpj,50);
    }
    return 0;
}

/*
Faça um programa que realize o cadastro de duas empresas utilizando os registros acima. Seu
programa deve permitir ao usuário pesquisar uma empresa através do número do telefone. Crie uma
função que receba como parâmetro este número e retorne para o usuário os dados da empresa ao
qual se refere (caso exista) ou uma mensagem informando que o número digitado não corresponde a
nenhuma das empresas cadastradas
*/