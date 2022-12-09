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
    cout << "Opção: ";
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TipoLista lista, lista2, lista3, lista4, lista5, lista6, lista7;
    int opcao;
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
        cin >> opcao;
        switch (opcao){
            case 1:
                cout << "\nLista 1" << endl;
                ImprimeLista(lista);
                cout << "\n\nLista 2" << endl;
                ImprimeLista(lista2);
                concatenarLista(&lista, &lista2, &lista3);
                cout << "\n\nLista 3" << endl;
                ImprimeLista(lista3);
                system("PAUSE");
                break;
            case 2:
                cout << "Lista 3" << endl;
                ImprimeLista(lista3);
                DividirEmDois(&lista3, &lista4, &lista5);
                cout << "Lista 4" << endl;
                ImprimeLista(lista4);
                cout << "Lista 5" << endl;
                ImprimeLista(lista5);
                system("PAUSE");
                break;
            case 3:
                cout << "Lista 1" << endl;
                ImprimeLista(lista);
                cout << "Lista 2" << endl;
                ImprimeLista(lista2);
                intercalarLista(&lista, &lista2, &lista6);
                cout << "Lista 6" << endl;
                ImprimeLista(lista6);
                system("PAUSE");
                break;
            case 4:
                cout << "Lista 3" << endl;
                ImprimeLista(lista3);
                InverteLista(&lista3, &lista7);
                cout << "Lista 7" << endl;
                ImprimeLista(lista7);
                system("PAUSE");
                break;
            case 0:
                cout << "Saindo...";
                Sleep(1000);
                break;
            }
    } while (opcao != 0);
    return 0;
}
