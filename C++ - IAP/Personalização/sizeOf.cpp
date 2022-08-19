#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int v1[] = {0, 1, 2, 3, 4, 5};
    char v3[] = {'a','b','c','d','e','f','g','h','i'};
    string v4[] = {"Joao", "Maria", "Jose"};

    int tamanho = sizeof(v3) / sizeof(v3[0]);

    cout << "v1: " << sizeof(v1) << " bytes\n";
    cout << "v3: " << sizeof(v3) << " bytes\n";
    cout << "v4: " << sizeof(v4) << " bytes\n";

    cout << "Tamanho v3: " << tamanho << endl;

    for (int i=0; i<tamanho; i++) {
        cout << v3[i] << " ";
    }

    cout << endl;
    return 0;
}