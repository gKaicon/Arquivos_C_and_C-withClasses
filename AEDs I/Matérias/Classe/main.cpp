#include <iostream>
#include <windows.h>
#include <time.h> 
#include "classe.cpp"

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    Pessoa p1;
    p1.setNome("Kaicon");
    p1.setIdade(18);
    p1.setAltura(1.86);
    p1.mostrarDaddos();
    
    Pessoa p2("Joao", 19, 1.83);
    p2.mostrarDaddos();
    cout << endl;
    return 0;
}