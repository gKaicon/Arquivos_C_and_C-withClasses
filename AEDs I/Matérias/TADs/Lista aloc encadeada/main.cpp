#include <iostream>
#include <windows.h>
#include "lista.hpp"
#include "TADs.cpp"
 
using namespace std;
 
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
 
   TipoLista lista;
   TipoItem item;
   int opcao, ret;

    do{
        system("cls");
        menu();
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
         case 1:
            if (!listaCriada)CriaListaVazia(&lista); //se a lista não existe, ele cria lista
            break;
         case 2:
            if (VerificaListaVazia(&lista)) cout << "Lista vazia!"; //apenas verifica se existe e retorna a mensagem
            else cout << "A lista não está vazia ou não foi inicializada.";
            Sleep(3000);
            break;
         case 3: //inserção no primeiro
            if (!listaCriada){ //se não foi criada, ele manda criar antes
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            //inserção de dados
            cout << "ID: ";
            cin >> item.chave;
            cout << "Nome: ";
            cin >> item.nome;
            InsereListaPrimeiro(&lista, &item); //insere o conteudo todo
            break;
        case 4: //inserção no último
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            //inserção de dados
            cout << "ID: ";
            cin >> item.chave;
            cout << "Nome: ";
            cin >> item.nome;
            InsereListaUltimo(&lista, &item); //insere o conteudo todo
            break;
        case 5: //inserção após elemento
            int idInsert;
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Deseja inserir após qual ID? ";
            cin >> idInsert;
            cout << "\nDados para inserção:\n";
            cout << "ID: ";
            cin >> item.chave;
            cout << "Nome: ";
            cin >> item.nome;

            InsereListaAposElemento(&lista, &item, idInsert);
            break;
        case 6: //impressão da lista
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(3000);
                break;
            }
            ImprimeLista(lista);
            break;
        case 7: //pesquisa item
            int idPesqui;
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(2000);
                break;
            }
            cout << "Digite o ID do item que deseja pesquisar: ";
            cin >> idPesqui;
            ret = PesquisaItem(&lista, idPesqui);
            if (ret == -1){
                cout << "Item não encontrado!";
                Sleep(1500);
            }
            ImprimeItem(&lista, ret); //imprime o item
            system("pause");
            break;
        case 8: //remove item do ínicio
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            RemoveListaPrimeiro(&lista);
            break;
        case 9: //remove item do fim
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            RemoveListaUltimo(&lista);
            break;
        case 10: //remove por id
            int idRemo;
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Digite o ID do item que deseja remover: ";
            cin >> idRemo;
            ret = PesquisaItem(&lista, idRemo);
            if (ret == -1){
                cout << "Item não encontrado!";
                Sleep(1000);
                break;
            }
            cout << "\n\nRemovendo...";
            RemoveItemPorId(&lista, idRemo);
            Sleep(1500);
            break;
        case 11: //Tamanho da lista
            if (!listaCriada){
                cout << "Crie a lista primeiramente.";
                Sleep(1000);
                break;
            }
            cout << "Tamanho da lista: " << TamanhoLista(&lista);
            Sleep(2500);
            break;
        case 0:
            cout << "Saindo...";
            Sleep(1500);
            break;
        default:
            break;
        }

    }while (opcao != 0);
    return 0;
}
