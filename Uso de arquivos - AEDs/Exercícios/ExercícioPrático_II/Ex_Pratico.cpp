#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

void escreve_arquivo(){
    ofstream file;

    file.open("tabela.txt");

    if (!file.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo .txt \n";
    }
    file << "result";
}
void ler_arquivo(){
    ifstream file;
    string result;
    file.open("tabela.txt");
    if (!file.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo .txt \n";
    }
    file >> result;
    while (!file.eof()){
//        getline(file, result);
        cout << result << endl;
    }
}   

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    cout << sizeof(char) << "Byte(s)";
    cout << sizeof(int) << "Byte(s)";
    cout << endl;
    // char, short, int, long, float, double, long double
    return 0;
}
