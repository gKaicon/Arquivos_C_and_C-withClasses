#include <iostream>
#include <windows.h>
#include "TADs-lista.hpp"
#include "funcoes.cpp"
#include <string.h>
 
using namespace std;
 
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
 
   TipoLista lista1, lista2, lista3, lista4;
   TipoItem item;
   int opcao, ret;
    
    cout << "Lista 1 criada - ";
    CriaListaVazia(&lista1);
    cout << "\nLista 2 criada - ";
    CriaListaVazia(&lista2);
    cout << "\nLista 3 criada - ";
    CriaListaVazia(&lista3);//lista concatenada
    cout << "\nLista 4 criada - ";
    CriaListaVazia(&lista4);//lista concatenada alternadamente
    
    
    for(int i = 0; i < 5; i++){
        item.chave = i+1;
        strcpy(item.nome, "Gabriel lista 1 - " + i);
        InsereListaUltimo(&lista1, &item);
    }
    cout << "\nLista 1 com inserções concluidas\n";
    for(int i = 0; i < 5; i++){
        item.chave = i+1;
        strcpy(item.nome, "Gabriel lista 2 - " + i);
        InsereListaUltimo(&lista2, &item);
    }
    cout << "Lista 2 com inserções concluídas\n";
    Sleep(1500);
    do{
        system("cls");
        menu();
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
         case 1:
            Concatena(&lista1, &lista2, &lista3);
            break;
         case 2:
            if (VerificaListaVazia(&lista1)) cout << "Lista 1 vazia!\t"; //apenas verifica se existe e retorna a mensagem
            if (VerificaListaVazia(&lista2)) cout << "Lista 2 vazia!\t"; //apenas verifica se existe e retorna a mensagem
            if (VerificaListaVazia(&lista3)) cout << "Lista 3 vazia!\t"; //apenas verifica se existe e retorna a mensagem
            if (VerificaListaVazia(&lista4)) cout << "Lista 4 vazia!\t"; //apenas verifica se existe e retorna a mensagem
            else cout << "Não há listas vazias, ou não foram inicializadas";
            Sleep(3000);
            break;
         case 3://inserção no primeiro
            //inserção de dados
            int opi1;
            cout << "Em qual lista deseja inserir? Lista 1 ou Lista 2: ";
            cin >> opi1;
            if(opi1 == 1){
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaPrimeiro(&lista1, &item); //insere o conteudo todo
            }
            if(opi1 == 2){
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaPrimeiro(&lista2, &item); //insere o conteudo todo
            }
            break;
        case 4: //inserção no último
            //inserção de dados
            int opif;
            cout << "Em qual lista deseja inserir? Lista 1 ou Lista 2: ";
            cin >> opif;
            if(opif == 1){
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaUltimo(&lista1, &item); //insere o conteudo todo
            }
            if(opif == 2){
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaUltimo(&lista2, &item); //insere o conteudo todo
            }
            break;
        case 5: //inserção após elemento
            int opiai, idInsert;
            cout << "Em qual lista deseja inserir? Lista 1 ou Lista 2: ";
            cin >> opiai;
            if(opiai == 1){          
                cout << "Deseja inserir após qual ID? ";
                cin >> idInsert;
                cout << "\nDados para inserção:\n";
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaAposElemento(&lista1, &item, idInsert);
            }
            if(opiai == 2){          
                cout << "Deseja inserir após qual ID? ";
                cin >> idInsert;
                cout << "\nDados para inserção:\n";
                cout << "ID: ";
                cin >> item.chave;
                cout << "Nome: ";
                cin >> item.nome;
                InsereListaAposElemento(&lista1, &item, idInsert);
            }
            break;
        case 6: //impressão da lista
            int opI;
            cout << "Qual lista deseja imprimir?\nLista 1\nLista 2\nLista 3\nLista 4\n Opção: ";
            cin >> opI;
            if(opI == 1) ImprimeLista(lista1);
            if(opI == 2) ImprimeLista(lista2);
            if(opI == 3) ImprimeLista(lista3);
            if(opI == 4) ImprimeLista(lista4);
            Sleep(4000);
            break;
        case 7: //pesquisa item
            int idPesqui, opPsq;
            cout << "Qual lista deseja pesquisar? Lista 1 ou Lista 2: ";
            cin >> opPsq;
            if(opPsq == 1){
                cout << "Digite o ID do item que deseja pesquisar: ";
                cin >> idPesqui;
                ret = PesquisaItem(&lista1, idPesqui);
                if (ret == -1){
                    cout << "Item não encontrado!";
                    Sleep(1500);
                }
                ImprimeItem(&lista1, ret); //imprime o item
            }
            if(opPsq == 2){
                cout << "Digite o ID do item que deseja pesquisar: ";
                cin >> idPesqui;
                ret = PesquisaItem(&lista2, idPesqui);
                if (ret == -1){
                    cout << "Item não encontrado!";
                    Sleep(1500);
                }
                ImprimeItem(&lista2, ret); //imprime o item
            }
            system("pause");
            break;
        case 8: //remove item do ínicio
            int opRp;
            cout << "Qual lista remover o primeiro? Lista 1 ou Lista 2: ";
            cin >> opRp;
            if(opRp == 1)RemoveListaPrimeiro(&lista1);
            if(opRp == 2)RemoveListaPrimeiro(&lista2);
            break;
        case 9: //remove item do fim
            int opRU;
            cout << "Qual lista remover o primeiro? Lista 1 ou Lista 2: ";
            cin >> opRU;
            if(opRU == 1)RemoveListaUltimo(&lista1);
            if(opRU == 2)RemoveListaUltimo(&lista2);
            break;
        case 10: //remove por id
            int idRemo, opRI;
            cout << "Qual lista remover? Lista 1 ou Lista 2";
            cin >> opRI;
            if(opRI==1){
                cout << "Digite o ID do item que deseja remover: ";
                cin >> idRemo;
                ret = PesquisaItem(&lista1, idRemo);
                if (ret == -1){
                    cout << "Item não encontrado!";
                    Sleep(1000);
                    break;
                }
                cout << "\n\nRemovendo...";
                RemoveItemPorId(&lista1, idRemo);
            }
            if(opRI==2){
                cout << "Digite o ID do item que deseja remover: ";
                cin >> idRemo;
                ret = PesquisaItem(&lista2, idRemo);
                if (ret == -1){
                    cout << "Item não encontrado!";
                    Sleep(1000);
                    break;
                }
                cout << "\n\nRemovendo...";
                RemoveItemPorId(&lista2, idRemo);
            }
            Sleep(1500);
            break;
        case 11:
            int opInver;
            cout << "Qual lista deseja inverter?\nLista 1\nLista 2\nLista 3\nLista 4\n Opção: ";
            cin >> opInver;
            if(opInver == 1)InverteLista(&lista1);
            if(opInver == 2)InverteLista(&lista2);
            if(opInver == 3)InverteLista(&lista3);
            if(opInver == 4)InverteLista(&lista4);
            Sleep(5000);
            break;
        case 12: //Concatena Alternado
            ConcatenaAlternado(&lista1, &lista2, &lista4);
            break;
        case 13: //Tamanho da lista
            int op;
            cout << "Qual lista deseja ver o tamanho?\nLista 1\nLista 2\nLista 3\nLista 4\n Opção: ";
            cin >> op;
            if(op==1)cout << "Tamanho da lista: " << TamanhoLista(&lista1);
            if(op==2)cout << "Tamanho da lista: " << TamanhoLista(&lista2);
            if(op==3)cout << "Tamanho da lista: " << TamanhoLista(&lista3);
            if(op==4)cout << "Tamanho da lista: " << TamanhoLista(&lista4);
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