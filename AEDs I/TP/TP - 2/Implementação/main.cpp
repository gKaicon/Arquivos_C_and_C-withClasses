#include <iostream>
#include <fstream>
#include <windows.h>
#include "pilha.cpp"
#include "listaSequencial.cpp"
#include "sistema.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    UINT UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    ListaSequencial lista;
    Lista_Inicializa(&lista);

    bool carregouComSucesso = carregaArquivo(&lista);

    if (!carregouComSucesso)
    {
        cout << "Houve problemas ao carregar os funcionarios do arquivo: " << NOME_ARQUIVO << endl;
        system("pause");
        system("cls");
    }

    cout.precision(2); // Deixa os números com 2 casas após a virgula
    cout << fixed;

    iniciaProdutos(); // Cadastra os Produtos no Cardápio

    Pilha mochila;
    Pilha_Inicializa(&mochila);

    int opcao;
    do
    {
        menu();
        cin >> opcao;
        cin.ignore();
        system("cls");
        switch (opcao)
        {
        case 1:
            incluirPedido(&lista);
            break;
        case 2:
            listarPedidos(lista);
            break;
        case 3:
            verCardapio();
            break;
        case 4:
            consultarPedido(lista);
            break;
        case 5:
            imprimirListaEntrega(&mochila, lista);
            break;
        case 6:
            lancarEntrega(&mochila, &lista);
            break;
        }
        system("cls");
    } while (opcao != OPCAO_SAIDA);

    bool salvouComSucesso = salvaArquivo(&lista);

    if (!salvouComSucesso)
    {
        cout << "Houve problemas ao salvar os funcionarios no arquivo: " << NOME_ARQUIVO << endl;
    }
    return 0;
}
