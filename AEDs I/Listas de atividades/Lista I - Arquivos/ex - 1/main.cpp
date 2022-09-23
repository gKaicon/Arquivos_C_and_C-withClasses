#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

bool verificaArquivo(string nome){
    ifstream leitura;

    leitura.open(nome);
    if (!leitura.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo. O programa será encerrado.\n";
        return false;
    }
    else{
        cerr << "Arquivo aberto com sucesso.";
        return true;
    }
}


int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    string nomeTexto;

    cout << "Informe o nome do arquivo: ";
    cin >> nomeTexto;
    verificaArquivo(nomeTexto);
    return 0;
}

/*
Fa¸ca um programa que verifique a existˆencia de um arquivo no diret´orio com base no nome
fornecido pelo usu´ario. Exemplo: o usu´ario informou o nome “teste.txt”, vocˆe deve verificar se
existe este arquivo e retornar uma resposta positiva ou negativa.
*/