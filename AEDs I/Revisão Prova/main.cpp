#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "lista.cpp"

using namespace std;

void Menu()
{
    system("cls");
    cout << "------------------------------------\n";
    cout << "|    Lista Duplamente Encadeada    |\n";
    cout << "------------------------------------\n";
    cout << "1. Concatenar duas listas\n";
    cout << "2. Dividir lista em dois\n";
    cout << "3. Intercalar lista em dois\n";
    cout << "4. Inverter lista em dois\n";
    cout << "0. Sair\n\n";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista, lista2, lista3, lista4, lista5, lista6, lista7;
    TipoItem item;
    int opcao, ret, id;
    CriaListaVazia(&lista);
    CriaListaVazia(&lista2);
    CriaListaVazia(&lista3);
    CriaListaVazia(&lista4);
    CriaListaVazia(&lista5);
    CriaListaVazia(&lista6);
    CriaListaVazia(&lista7);

    insereLista(&lista);
    insereLista(&lista2);

    do{
        system("cls");
        Menu();
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        case 0:
            cout << "Saindo...";
            Sleep(1000);
            break;
        default:
            break;
        }

    } while (opcao != 0);

    return 0;
}
