#include <iostream>
#include <windows.h>

using namespace std;

int dobro(int *v){
    for (int i = 0; i < 5; i++) v[i] = v[i] * 2;
}

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int v[5];
    for (int i = 0; i < 5; i++) cin >> v[i];
    dobro(v);
    for (int i = 0; i < 5; i++) cout << v[i] << "\t";
    return 0;
}