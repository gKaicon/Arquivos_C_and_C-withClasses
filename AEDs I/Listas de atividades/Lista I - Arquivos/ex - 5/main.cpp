#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

typedef struct Produto{
    char nome[35];
    double preco;
} prod;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    ofstream escrita1, escrita2;
    //vou escrever em dois arquivos, porque ficou a minha escolha
    escrita1.open("tabela.xls");
    escrita2.open("lista.txt");

    if (!escrita1.is_open()){
        cerr << "Erro ao abrir o .xls, talvez o arquivo possa estar aberto em outro editor, feche-o.";
        return -1;
    }
    if (!escrita2.is_open()){
        cerr << "Erro ao abrir o .txt, talvez o arquivo esteja aberto em outro editor, feche-o.";
        return -1;
    }
    int qtd; 
    double som;
    cout << "Quantos produtos deseja cadastrar? ";
    cin >> qtd;

    prod p[qtd];
    escrita1 << "Nome\tPreco\n";
    escrita2 << "Nome \t \t| \tPreco\n";
    for(int i = 0 ; i < qtd; i++){
        
        cout << "Nome do Produto: ";
        for(int j = 0; j < 2; j++)cin.getline(p[i].nome, 35);
        cout << "Preço: ";
        cin >> p[i].preco;
        som = som + p[i].preco;
        escrita1 << p[i].nome << "\t" << p[i].preco << "\n";
        escrita2 << p[i].nome << "\t\t | \t" << p[i].preco << "\n";
    }
    escrita1 << "Total \t" << som;
    escrita2 << "Total \t\t | \t" << som;
   
    return 0;
}