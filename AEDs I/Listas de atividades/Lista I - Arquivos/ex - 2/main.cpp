#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;

typedef struct Funcinario{
  char nome[40];
  int tel;
} func;


int main(){
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  srand(time(NULL));
  system("cls");
  ofstream escrita;
  escrita.open("arquiv.xls");
  escrita.clear();
  if(!escrita.is_open()){
    cerr << "Erro ao abrir o arquivo";
    return -1;
  }

  func f[2];
  int sort;
  sort = rand()%9000000000;
  for(int i = 0;i < 2; i++){
    system("cls");
    cout << "Nome: ";
    cin.getline(f[i].nome, 40);
    sort = rand()%9000000000;
    f[i].tel = sort;
    cout << "\nTelefone: " << f[i].tel;
    escrita << "Nome: " << f[i].nome << "\tTelefone: " << f[i].tel << "\n";
  }
  escrita.close();
  return 0;
}