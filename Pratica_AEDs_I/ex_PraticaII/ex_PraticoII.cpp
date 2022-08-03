#include <iostream>
#include <windows.h>

using namespace std;


typedef struct habitante{
    double salario;
    int idade;
    int numFIlho;
};

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    cout << endl;
    return 0;
}