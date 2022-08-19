#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double catO, catA, hipo;
    cout<<"Dê o valor do Cateto Oposto: ";
    cin>>catO;
    cout<<"Dê o valor do Cateto adjacente: ";
    cin>>catA;
    hipo = hypot(catA, catO);
    cout << "O valor da hipotenusa é: "<<hipo;
    return 0;
}