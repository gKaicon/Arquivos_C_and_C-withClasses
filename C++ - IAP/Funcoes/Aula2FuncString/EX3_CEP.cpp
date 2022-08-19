#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    char cep[8];
    int cont = 0;
    cin>>(cep);
    cont = strlen(cep);
    if(cont<8){
        cout<<"Tamanho: "<<cont;
        cout<<"CEP inválido";
    }
    if(cont==8){
        cout<<"CEP: "<<cep<<" é Válido";
    }
    cout << endl;
    return 0;
}