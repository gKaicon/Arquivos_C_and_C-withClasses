#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

    typedef struct Casado {
        char nome[30];
        char sexo;
        int idade;
    };

    typedef struct Solteiro {
        char nome[30];
        char sexo;
        int idade;
    };

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    char nome[30];
    char sexo;
    int idade;
    char estadoCivil;

    Casado casados[5];
    Solteiro solteiros[5];

    int totalC = 0, totalS = 0;

    for(int i = 0; i < 5; i++) {
        cin.getline(nome,30);
        cin >> sexo;
        cin >> idade;
        cin >> estadoCivil;
        if(estadoCivil == 'C') {
            strcpy(casados[totalC].nome, nome);
            casados[totalC].sexo = sexo;
            casados[totalC].idade = idade;
            totalC++;
        } 
        else if(estadoCivil == 'S') {
            strcpy(solteiros[totalS].nome,nome);
            solteiros[totalS].sexo = sexo;
            solteiros[totalS].idade = idade;
            totalS++;
        }
        int totalSolteirosMachos = 0, totalSolteirosMulher = 0;

        for(int i = 0; i < 5; i++) {
            cout << solteiros[i].nome << endl;
            if(solteiros[i].sexo == 'M') {
                totalSolteirosMachos++;
            } 
            else if(solteiros[i].sexo == 'F') {
                totalSolteirosMulher++;
            }
        }
        cout << totalSolteirosMachos << " " << totalSolteirosMulher;
        for(int i = 0; i < 5; i++) {
            cout << casados[i].nome << endl;
        }
        cout << totalC;
    }
    return 0;
}