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
    file <<  "\t\tTabela";
    file << "Char - " << sizeof(char) << "Byte(s)\n";
    file << "Int - " << sizeof(int) << "Byte(s)\n";
    file << "Short - " << sizeof(short) << "Byte(s)\n";
    file << "Long - " << sizeof(long) << "Byte(s)\n";
    file << "Float - " << sizeof(float) << "Byte(s)\n";
    file << "Double - " << sizeof(double) << "Byte(s)\n";
    file << "Long Double - " << sizeof(long double) << "Byte(s)\n";
    file << "----------------------------";
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
        getline(file, result);
        cout << result << endl;
    }
}   

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    escreve_arquivo();
    ler_arquivo();
    cout << endl;
    // char, short, int, long, float, double, long double
    return 0;
}
