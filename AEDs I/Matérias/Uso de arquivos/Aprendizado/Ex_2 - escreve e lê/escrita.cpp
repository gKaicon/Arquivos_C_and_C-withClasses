#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

// Uso de arquivo
// <fstream>
// ifstream - leitura
// ofstream - escrita
// cerr - cout só que de console

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    ofstream filSaida; // - vamos escrever no arquivo

    filSaida.open("testeEscrita.txt");

    if(!filSaida.is_open()){
        cerr << "Erro ao abrir o arquivo";
        return -1;
    }
    if(filSaida.is_open()){
        cerr << "Arquivo Aberto \n\n";
        string nome;
        cout << "Nome: ";
        cin >> nome;

        filSaida << "Nome: " << nome;
    }
        filSaida.close();
    cout << endl;
    return 0;
}