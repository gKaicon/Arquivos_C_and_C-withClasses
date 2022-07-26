#include <iostream>
#include <windows.h>
 
using namespace std;

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls");
  int num, fat = 1;
  cout<<"Digite um número: ";
  cin>>num;      
  while (num > 0) { //laço de repetição
    fat = fat * num;//sempre irá sobrescrever o último número, multiplicando pelo seu antecessor
    num--;//incremento do laço
  }
  cout<<"\nFatorial: "<<fat<<"\n\n";
  return 0;
}