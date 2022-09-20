#include <iostream>
#include <windows.h>
#include "TADs.hpp"
#include "funcoes.cpp"

using namespace std;

int main()
{
   UINT CPAGE_UTF8 = 65001;
   UINT CPAGE_DEFAULT = GetConsoleOutputCP();
   SetConsoleOutputCP(CPAGE_UTF8);

   Projeto proj;
   ListaSequencialProjeto listaProj;
   Funcionario func;
   ListaEncadeadaFuncionario listaFunc;
   criaListaProj(&listaProj);
   CriaListaFunc(&listaFunc);
   system("cls");

   int op;
   do
   {
      menu(); //menu
      cout << "Opção: ";
      cin >> op;
      switch (op)
      {
      case 1: //Incluir
         if (!listaFuncionarioCriada)
         {
            cout << "Crie a lista de funcionários primeiramente.";
            Sleep(1000);
            break;
         }
         else
         { //inserção de dados
            cout << "Numero: ";
            func.numero = (listaFunc.ultimo->item.numero) + 1; //evitar números repetidos
            cout << "Nome: ";
            cin.getline(func.nome, 40);
            cout << "Endereço: ";
            cin.getline(func.endereco, 40);
            cout << "Número de dependentes: ";
            cin >> func.dependentes;
            incluirFunc(&listaFunc, &func); //insere o conteudo todo
            break;
         }
      case 2: //Incluir projeto ao funcionário - !
         break;
      case 3: //excluir funcionario sem projeto
         //removeFuncionarioSemProjeto(&listaFunc);
         break;
      case 4: //excluir projeto do funcionario
         break;
      case 5: //Excluir funcionario por ID
         int idRemo;
         char ret;
         listaDeFunc(listaFunc);
         cout << "\n\n";
         cout << "Digite o número do Funcionario que deseja remover: ";
         cin >> idRemo;

         do
         {
            cout << "Tem certeza? (s/n)";
            cin >> ret;
         } while (ret != 's' || ret != 'n');

         if (ret == 's')
         {
            cout << "\n\nRemovendo...";
            Sleep(1500);
            RemoveItemPorId(&listaFunc, idRemo);
            break;
         }
         if (ret == 'n')
         {
            break;
         }
      case 6: //lista
         cout << "\t\t\t\tFUNCIONÁRIOS\n\n";
         listaDeFunc(listaFunc);
         break;
      case 7: //qtd de funcionarios
         int qtd;
         qtd = qtdFunc(&listaFunc);
         cout << "Há um total de " << qtd << " funcionários.";
         break;
      case 8: //pesquisa por numero
         int num;
         cout << "Digite o número do funcionário: ";
         cin >> num;
         pesquisaFunc(&listaFunc, num);
         break;
      case 9: //impressão contra-cheques
         ImprimirContraCheque(listaFunc);
         break;

      case 10: //incluir
         if (!listaProjectCriada)
         {
            cout << "Crie a lista de Projetos primeiramente.";
            Sleep(1000);
            break;
         }
         if (listaProjectCriada)
         { //inserção de dados
            cout << "Código: ";
            proj.codigo = (listaProj.itemProjeto->codigo) + 1; //evitar números repetidos
            cout << "Nome: ";
            cin.getline(proj.nome, 40);
            cout << "Horas: ";
            proj.horas = 0;
            incluirNaListaProjeto(&listaProj, proj);
            break;
         }
      case 11: //listarProjetos
         cout << "\t\t\tPROJETOS\n\n";
         listaDeProjetos(listaProj);
         break;
      case 12: //pesquisar
         int num;
         cout << "Digite o número do projeto que deseja encontrar: ";
         cin >> num;
         pesquisaProjeto(listaProj, num);
         break;
      case 13: //retirar
         int idRemo;
         char ret;
         listaDeProjetos(listaProj);
         cout << "\n\nDigite o número do projeto que deseja remover: ";
         cin >> idRemo;
         do
         {
            cout << "Tem certeza? (s/n)";
            cin >> ret;
         } while (ret != 's' || ret != 'n');
         if (ret == 's')
         {
            cout << "\n\nRemovendo...";
            Sleep(1500);
            retiraProjeto(&listaProj, idRemo, &proj);
         }
         break;
      case 14:
         break;
      }
      if (op == 0)
      {
         cout << "Saindo...";
         Sleep(1500);
      }
   } while (op != 0);
   return 0;
}