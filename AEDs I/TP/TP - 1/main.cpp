#include <iostream>
#include <windows.h>
#include "TADs.hpp"
#include "funcoes.cpp"

using namespace std;


int main() {
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);
   system("cls");

   Projeto proj;
   ListaSequencialProjeto listaProj;
   Funcionario func;
   ListaEncadeadaFuncionario listaFunc;
   int op, opP, opF;
   do{    
      menu();//menu
      cout << "Opção: ";
      cin >> op;

      if(op == 1){ //opções para projeto
         menuProjeto();
         cout << "Opção: ";
         cin >> opP;
         switch (opP){
            case 1: //incluir
               
               break; 
            case 2: //listarProjetos
               cout << "\t\t\tPROJETOS\n\n";
               listaDeProjetos(listaProj);
               break;
            case 3: //pesquisar
               int num;
               cout << "Digite o número do projeto que deseja encontrar: ";
               cin >> num;
               pesquisaProjeto(listaProj, num);
               break;
            case 4: //retirar
               break;
            case 5: //voltar - !
               break;
         }
    
      }

      if(op == 2){ //opções para funcionário
         menuFuncionario();
         cout << "Opção: ";
         cin >> opF;
         switch (opF){
            case 1:
               int opfunc;
               menuinclusao();
               switch (opfunc){
                  case 1: //Incluir
                     if (!listaFuncionarioCriada){
                        cout << "Crie a lista de funcionários primeiramente.";
                        Sleep(1000);
                        break;
                     }
               //inserção de dados
                     cout << "Numero: ";
                     func.numero = (listaFunc.ultimo->item.numero) + 1; //evitar números repetidos
                     cout << "Nome: ";
                     cin.getline(func.nome,40);
                     cout << "Endereço: ";
                     cin.getline(func.endereco,40);
                     cout << "Número de dependentes: ";
                     cin >> func.dependentes;
                     for(int i = 0; i < 5; i++){
                        func.projeto[i].itemProjeto->codigo = NULL;
                     }
                     incluirFunc(&listaFunc, &func); //insere o conteudo todo
                     break;
                  case 2://Incluir projeto ao funcionário
                     int num, numP;
                     cout << "Digite o número do funcionário: ";
                     cin >> num;
         
                     break;
                  case 3: //excluir funcionario sem projeto
                     removeFuncionarioSemProjeto(&listaFunc);
                     break;
                  case 4: //excluir projeto do funcionario

                     break;
                  case 5: //Excluir funcionario por ID
                     int idRemo;
                     char ret;
                        listaDeFunc(listaFunc);
                        cout << "\n\nDigite o número do Funcionario que deseja remover: ";
                        cin >> idRemo;
                        do{
                           cout << "Tem certeza? (s/n)";
                           cin >> ret;
                        }while(ret != 's' || ret !='n');
                        if(ret == 's'){
                           cout << "\n\nRemovendo...";
                           Sleep(1500);
                           RemoveItemPorId(&listaFunc, idRemo);
                        }
                     break;
                  case 6: //voltar

                     break;
               }
               break;
            case 2: //lista
            cout << "\t\t\t\tFUNCIONÁRIOS\n\n";
               listaDeFunc(listaFunc);
               break;
            case 3: //qtd de funcionarios
               int qtd = qtdFunc(&listaFunc);
               cout << "Há um total de " << qtd << " funcionários.";
               break;
            case 4: //pesquisa por numero
               int num;
               cout << "Digite o número do funcionário: ";
               cin >> num;
               pesquisaFunc(&listaFunc, num);
               break;
            case 5: //impressão contra-cheques
               ImprimirContraCheque(listaFunc);
               break;
            case 6: //voltar - !
            break;
         }
      }
      if(op==0){
         cout << "Saindo...";
         Sleep(1500);
      }
   }while(op != 0);
   return 0;
}