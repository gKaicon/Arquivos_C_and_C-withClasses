#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ifstream filVer; // - vamos ler no arquivo
    string texto;

    filVer.open("testeLeitura.txt");

    if(!filVer.is_open()){
        cerr << "Erro ao abrir o arquivo";
        filVer.clear();
        return -1;
    }

   while (!filVer.eof()){
        getline(filVer, texto);
       // cout << texto << endl;
    }

    return 0;
}