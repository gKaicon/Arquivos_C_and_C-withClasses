#include <iostream>
#include <windows.h>
#include "cabe.hpp"

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    int n = 5, vet[5], mat[5][5];

    PreencheeEImprimeVet(vet, n);
    cout << "\n\n";
    imprimeVet(vet, n);
    cout << "\n\n";
    PreencheeMat(mat, n);
    cout << "\n\n";
    imprimeMat(n, mat);
    cout << "\n\n";
    imprimeMatQuad(n, mat, 2);
    cout << "\n\n";
    calcDiagPrin(n, mat);
    cout << "\n\n";
    FuncMaior(vet, n);
    cout << "\n\n";
    FuncMenor(vet, n);

    return 0;
}