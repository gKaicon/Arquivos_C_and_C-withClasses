#include <iostream>
#include <windows.h>

using namespace std;

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int a = 1, b = 2;
    troca(&a, &b);
    cout <<  "Valor de A:" << a << endl << "Valor de B:" << b;
    return 0;
}