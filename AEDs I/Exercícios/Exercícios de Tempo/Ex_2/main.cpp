#include <iostream>
#include <windows.h>
#include <time.h> 

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int op;

    switch (op){
        case 1: 
        
        break;

        case 2: 
        break;

        case 3: 
        break;

        case 4: 
        break;

        case 5: 
            Sleep(2000);
            cout << "Saindo...";
        break;
    }
    cout << endl;
    return 0;
}