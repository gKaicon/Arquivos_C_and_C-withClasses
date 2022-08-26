#include <iostream>
#include <windows.h>
#define Vcst 0.785

using namespace std;
 
int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double Vol, larg, comp, altmin, altmax, altM, cl;
    cout << "Informe a largura da piscina em metros: ";
    cin >> larg;
    cout << "Informe o comprimento da piscina em metros: ";
    cin >> comp;
    cout << "Informe a altura mínima da piscina em metros: ";
    cin >> altmin;
    cout << "Informe a altura Máxima da piscina em metros: ";
    cin >> altmax;
    altM = (altmin * altmax)/2;
    Vol = larg * comp * altM * Vcst;
    cl = (4 * Vol)/1000;
    cout << "\nVolume: " << Vol << " l";
    cout << "\nDeverá colocar " << cl << "g de cloro na piscina";
    return 0;
}