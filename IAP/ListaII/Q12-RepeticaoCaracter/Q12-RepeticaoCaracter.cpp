#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    char f[100], c;
    int tamanho, cont;
    //do-while para que seja possível limitar o usuario a digitar uma frase de apenas 100 caracteres
    do{
        cout << "Digite uma frase de no máximo 100 caracteres: \n";
        gets(f);
        tamanho = strlen(f);
    } while (tamanho > 100);
    //enquanto ele digitar uma frase maior que 100 caracteres ele ficará no laço
    system("cls");//limpar a tela para caso o usuario erre muitas vezes
    cout << "Tamanho da frase: " << tamanho << "\n";
    cout << "Frase: " << f << "\n";
    cout << "Digite o caracter a ser procurado: ";
    cin >> c;
    for (int i = 0; i <= tamanho; i++){
        if (c == f[i])cont++; //contador de repetições
    }
    system("cls");
    cout << "Tamanho da frase: " << tamanho << "\n";
    cout << "O caracter " << c << " aparece na frase (" << f << "), " << cont << " vezes.";
    return 0;
}
