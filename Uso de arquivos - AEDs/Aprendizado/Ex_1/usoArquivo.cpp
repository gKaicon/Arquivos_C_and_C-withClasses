#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Uso de arquivo
// <fstream>
// ifstream - leitura
// ofstream - escrita

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ofstream filSaida; // - vamos escrever no arquivo

    filSaida.open("teste.txt");

    filSaida << 5 << 10 << 15;

    filSaida.close();
    
    cout << endl;
    return 0;
}