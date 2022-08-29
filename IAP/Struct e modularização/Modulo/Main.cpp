#include <iostream>
#include <windows.h>
#include "Cabecalho.hpp"

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls"); 
    double a, b;
    cout << "Digite o primeiro valor: ";
    cin >> a;
    cout << "Digite o segundo valor: ";
    cin >> b;
    cout << "\nAdição: " << soma(moduloAB(a),moduloAB(b));
    cout << "\nSubtração: " << sub(moduloAB(a),moduloAB(b));
    cout << "\nMultiplicação: " << mult(moduloAB(a),moduloAB(b));
    cout << "\nDivisão: " << divi(moduloAB(a),moduloAB(b));
    return 0;
}