#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int ano;
    cout << "Indique um ano: ";
    cin >> ano;
    if ((ano % 100 != 0) && (ano % 4 == 0) && (ano % 400 == 0)){
        cout << "É bissexto.";
    }
    else{
        cout << "Não é bissexto\n";
    }

    cout << endl;
    return 0;
}