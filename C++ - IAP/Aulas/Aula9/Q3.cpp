#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int i, num[100], sub, cont = 0, quinquagesimo, ultimo;
    for (i = 1; i < 200; i += 2){
        num[cont] = i;
        cont++;
        if (cont == 50){
            quinquagesimo = i;
        }
        ultimo = i;
    }
    for (i = 0; i < 100; i++){
        cout << num[i] << "\n";
    }
    sub = ultimo - quinquagesimo;
    cout << "Diferença: " << sub << "\n";
    return 0;
}