#include <iostream>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <bitset>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));
    system("cls");
    ofstream escrita;
    escrita.open("tabela.txt");

    int v[10];
    for(int i = 0;i < 10;i++){
        v[i] = rand()%100;
        escrita << "Num: " << v[i] << "\t | \tBinário: " << bitset<8>(v[i]) << "\n";
    }
    escrita.close();
    return 0;
}