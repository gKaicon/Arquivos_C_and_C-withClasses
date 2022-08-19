#include <iostream>
#include <windows.h>
#include <bitset>
#include "cabec.hpp"

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    int num;

    cout << "Digite um número em decimal para converter para binário: ";
    cin >> num;

    cout << "\nNúmero em binário com a minha função: ";
    int_Bi(num);
    cout << "\nNúmero em binário com a função do bitset : " << bitset<16>(num);

    return 0;
}