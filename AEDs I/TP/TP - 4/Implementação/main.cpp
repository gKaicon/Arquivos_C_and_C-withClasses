#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "menus.cpp"
//#include "funcoes.cpp"
#include "listaEncadeadaSimples.cpp"
#include "listaCircularDupEncadeada.cpp"

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista;
    TipoListaEC listaEC;
    TipoItem item;
    TipoLinha itemEC;
    int opcao;
    char op;

    CriaListaVazia(&lista);

    do
    {
        system("cls");
        Menu();
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("cls");
            int opcao, codigo;
            char origem[100], destino[100];
            Pesquisa();
            cout << "\nOpção: ";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                cout << "Digite a origem: ";
                cin >> origem;
                if (!PesquisaItem(&lista, origem))
                {
                    cout << "Cidade não encontrada!\n";
                    break;
                }
                cout << "Digite o destino: ";
                cin >> destino;
                if (!PesquisaItem(&lista, destino))
                {
                    cout << "Cidade não encontrada!\n";
                    break;
                }
                cout << endl;
                //ImprimePassagem(&lista, origem, destino);
                ImprimeItem(&lista, origem);
                ImprimeItem(&lista, destino);
                // Edicao(&lista, item);

                break;
            case 2:
                int senha;
                cout << "Codigo: ";
                cin >> codigo;
                if (PesquisaItemPorId(&lista, codigo))
                {
                    cout << endl;
                    ImprimeItemPorId(&lista, codigo);
                    system("cls");
                    do
                {
                    cout <<"Senha do Administrador: " << endl;
                    cin >>senha;
                } while (senha != 1111);
                    Edicao(&lista, item);
                    
                }
                else
                {
                    cout << "Codigo não encontrado!\n";
                }

            default:
                break;
            }

            system("PAUSE");

            break;
        case 2:
            system("cls");
            int quantRotas;
            int senha;
            do
            {
                cout <<"Senha do Administrador: " << endl;
                cin >>senha;
            } while (senha != 1111);
            Escolher();
            cout << "\nOpção: ";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                int resposta;
                do
                {
                    CadastraRota(&lista);
                    cout << "deseja adicionar mais alguma rota? 1-sim 2-nao";
                    cin >> resposta;
                } while (resposta != 2);

                break;
            case 2:
                system("PAUSE");
                break;
            case 3:

                break;
            case 4:

            default:
                break;
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");

            system("PAUSE");
            break;
        case 4:
            system("cls");

            system("PAUSE");
            break;
        }
    } while (opcao != 0);
}