#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double n, sq, cb;
    cout<<"Digite um número: ";
    cin>>n;
    sq = sqrt(n);
    cb = cbrt(n);
    cout << "\nRaiz Quadrada: "<<sq;
    cout << "\nRaiz Cúbica: "<<cb;
    return 0;
}