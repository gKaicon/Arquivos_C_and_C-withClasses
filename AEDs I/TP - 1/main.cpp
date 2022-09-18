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
    int op, opP, opF;
    menu();
    cout << "Opção: ";
    cin >> op;
    if(op == 1){
      menuProjeto();
      cout << "Opção: ";
      cin >> opP;
      switch (opP){
         case 1:
            
            break;
         case 2:
            break;
      }
    }
    if(op==2){
      menuFuncionario();
      cout << "Opção: ";
      cin >> opF;
      switch (opF){
         case 1:
            
            break;
         case 2:
            break;
      }
    }
 
   return 0;
}