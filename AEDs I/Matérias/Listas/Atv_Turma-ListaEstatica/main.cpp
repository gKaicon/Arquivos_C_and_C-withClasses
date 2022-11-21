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
 
   TipoListaTurma lista;
   TipoItemAluno item;
   int opcao, ret;
    do{
        system("cls");
        menu();
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                  if (!listaCriada)CriaTurmaVazia(&lista); //se a lista não existe, ele cria lista
               break;
            case 2:
                  if (VerificaListaVazia(&lista))cout << "Turma vazia!";
                  else cout << "A turma não está vazia ou não foi inicializada.";
                  Sleep(3000);
               break;
            case 3:
                  if (VerificaListaCheia(&lista))cout << "turma cheia!";
                  else cout << "A turma não está cheia ou não foi inicializada.";
                  Sleep(3000);
               break;
            case 4:
                  cout << "Matricula: ";
                  cin >> item.matricula;
                  cout << "Nome: ";
                  cin >> item.nome;
                  cout << "Nota 1: ";
                  cin >> item.n1;
                  cout << "Nota 2: ";
                  cin >> item.n2;
                  cout << "Nota 3: ";
                  cin >> item.n3;
                  cout << "Turma: ";
                  cin >> item.turma;
                  ret = InsereItem(&lista, item); //recebe a lista, e adiciona a chave que também é de tipo int, o ret serve para armazernar o valor
                  if (ret == 1){ //se for true = 1, há a possibilidade de inserção
                     cout << "Aluno inserido com sucesso!";
                     Sleep(500);
                  }
                  else if (ret == -1){ //se for -1 é porque a lista tá cheia =
                     cerr << "ERRO ao inserir o Aluno. Turma cheia.";
                     Sleep(3000);
                  }
                  else{ // se for false = 0 é porque não criei a lista
                     cout << "Crie a turma primeiramente.";
                     Sleep(3000);
                  }
                  break;
            case 5:
                  ImprimeLista(lista);
                  Sleep(5000);
                  break;
            case 6:
                  if(listaCriada){
                     cout << "Matricula: ";
                     cin >> item.matricula;
                     ret = PesquisaItem(&lista, item.matricula);
                     if (ret >= 0){
                        cout << "Número encontrado na posição " << ret;
                        Sleep(1000);
                     }
                     else{
                        cout << "O número não está na turma.";
                        Sleep(1000);
                     }
                  }
                  else{
                     cout << "Crie a turma primeiramente.";
                     Sleep(1000);
                  }
                  break;
            case 7:
                  if (listaCriada){
                     cout << "Matricula: ";
                     cin >> item.matricula;
                     ret = PesquisaItem(&lista, item.matricula);
                     if (ret >= 0){
                        cout << "Aluno encontrado na posição " << ret;
                        Sleep(1000);
                        cout << "\n\nRemovendo...";
                        RetiraItem(ret, &lista, &item);
                        Sleep(1000);
                     }
                     else{
                        cout << "O Aluno não está na turma.";
                        Sleep(1000);
                     }
                  }
                  else{
                     cout << "Crie a turma primeiramente.";
                     Sleep(1000);
                  }
                  break;
            default:
                  break;
            }
    } while (opcao != 0);
 
    return 0;
}