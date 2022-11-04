#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    system("cls");
    ofstream escrita;
    escrita.open("matriz.xls");

    int qtd;

    cout << "Informe o tamanho da matriz: ";
    cin >> qtd;
    int v[qtd][qtd];

    for(int i = 0; i < qtd; i++){
        for(int j = 0; j < qtd; j++){
            v[i][j] = rand()%20;
            escrita << v[i][j] << "\t";
        }
        escrita << "\n";
    }

 
   return 0;
}