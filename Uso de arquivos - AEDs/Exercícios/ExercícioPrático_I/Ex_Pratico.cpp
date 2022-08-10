#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

//Número 1
int somaTres(int n[]){
    int soma = 0;
    for (int i = 0; i < 3; i++){
        cin >> n[i];
        soma += n[i];
    }
    return soma;
}

void escreve_arquivo(int result)
{
    ofstream file, file2;
    //arquivo 1 em txt
    file.open("resolucao.txt");
    if (!file.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo .txt \n";
    }
    file << "Resultado: " << result;

    //arquivo 2 em dat
    file2.open("resolucao.dat");
    if (!file2.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo .dat \n";
    }
    file2 << "Resultado: " << result;
}

//Número 2
void ler_arquivo(){
    ifstream file;
    file.open("resolucao.txt");
    string result; //pois no arquivo txt tem string, e ele serve para pegar tudo

    if (!file.is_open()){
        cerr << "ERRO! Não foi possível abrir o arquivo.\n";
    }

    while (!file.eof()){ //eof serve para chegar ao fim de um arquivo, e ele se aplica quando tem string
        getline(file, result); //getLine sozinho é do C puro, e cin.getline é do C++
        cout << result << endl;
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int n[3], soma;
    soma = somaTres(n);
    escreve_arquivo(soma);
    ler_arquivo();

    return 0;
}