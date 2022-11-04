#include <iostream>
#include <windows.h>
#include "funcoes.cpp"
#include "lista.hpp"
 
using namespace std;
 
int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");
 
   TipoLista lista;
   TipoItem item;
   int opcao, ret;

   if (!listaCriada) CriaListaVazia(&lista); //Criar a lista para facilitar os testes
   for(int i = 0 ; i < 4;i++){ //inserir 4 itens na inicialização para facilitar testes
      item.chave = i+1;
      InsereItem(&lista, item);
   }
    do{
        system("cls");
        menu();
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
               int i1, i2;
               cout << "Digite os itens que deseja trocar: ";
               cin >> i1; 
               cin.ignore();
               cout << " por ";
               cin >> i2;
               TrocaElemento(&lista, i1, i2);
               Sleep(1000);
            break;
            case 2:
                  if (VerificaListaVazia(&lista)){
                     cout << "Lista vazia!";
                  }
                  else{
                     cout << "A lista não está vazia ou não foi inicializada.";
                  }
                  Sleep(3000);
               break;
            case 3:
                  if (VerificaListaCheia(&lista)){
                     cout << "Lista cheia!";
                  }
                  else{
                     cout << "A lista não está cheia ou não foi inicializada.";
                  }
                  Sleep(3000);
               break;
            case 4:
                  cout << "Chave: ";
                  cin >> item.chave;
                  ret = InsereItem(&lista, item); //recebe a lista, e adiciona a chave que também é de tipo int, o ret serve para armazernar o valor
                  if (ret == 1){ //se for true = 1, há a possibilidade de inserção
                     cout << "Número inserido com sucesso!";
                     Sleep(500);
                  }
                  else if (ret == -1){ //se for -1 é porque a lista tá cheia =
                     cerr << "ERRO ao inserir o número. Lista cheia.";
                     Sleep(3000);
                  }
                  else{ // se for false = 0 é porque não criei a lista
                     cout << "Crie a lista primeiramente.";
                     Sleep(3000);
                  }
                  break;
            case 5:
                  ImprimeLista(lista);
                  Sleep(4000);
                  break;
            case 6:
                  if (listaCriada){
                     cout << "Chave: ";
                     cin >> item.chave;
                     ret = PesquisaItem(&lista, item.chave);
                     if (ret >= 0){
                        cout << "Número encontrado na posição " << ret;
                        Sleep(1000);
                     }
                     else{
                        cout << "O número não está na lista.";
                        Sleep(1000);
                     }
                  }
                  else{
                     cout << "Crie a lista primeiramente.";
                     Sleep(1000);
                  }
                  break;
            case 7:
                  if (listaCriada){
                     cout << "Chave: ";
                     cin >> item.chave;
                     ret = PesquisaItem(&lista, item.chave);
                     if (ret >= 0){
                        cout << "Número encontrado na posição " << ret;
                        Sleep(1000);
                        cout << "\n\nRemovendo...";
                        RetiraItem(ret, &lista, &item);
                        Sleep(1000);
                     }
                     else{
                        cout << "O número não está na lista.";
                        Sleep(1000);
                     }
                  }
                  else{
                     cout << "Crie a lista primeiramente.";
                     Sleep(1000);
                  }
                  break;
            
            default:
                  break;
            }

    } while (opcao != 0);
 
    return 0;
}