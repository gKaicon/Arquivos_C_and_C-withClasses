#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

boolean IP(int, int, int);

int main(){

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    srand(time(NULL));

    int op, v, vC, pV = 0, pC = 0, perg;
    boolean jogo;
    string nome;
    
    cout << "Digite seu nome: ";
    cin >> nome;

    do{
        system("cls");
        cout << "___Jogo do Par ou Ímpar___\n\n\t\tPlacar\n\n" << nome << ": " << pV << "\t\tComputador: " << pC;
        do{
            cout << "\n\nEscolha apenas 0 ou 1\n\n0 - Par \n1 -Ímpar \n\nEscolha:";
            cin >> op;
        } while (op != 0 && op != 1);
        do{
            cout << "\nJogue apenas valores de 0 a 10: ";
            cin >> v;
        } while (v < 0 || v > 10);

        vC = rand() % 10;
        jogo = IP(v, vC, op);
        if(jogo == true){
            cout << " e ganhou.";
            pV ++;
        }
        else{
            cout << " e perdeu.";
            pC ++;
        }
        cout << "\n\n"<<nome<<" pôs:  " << v << "\tComputador pôs:  " << vC << "\tSoma: " << (v + vC);
        cout << "\n\nSe deseja continuar pressione 1, se não, pressione 0: ";
        cin >> perg;
    } while (perg == 1);
    return 0;
}

boolean IP(int a, int b, int op){
    int soma = a + b;
    if (op == 0){
        system("cls");
        cout << "Você escolheu par";
        if (soma % 2 == 0)return true;
        if (soma % 2 != 0)return false;
    }
    if (op == 1){
        system("cls");
        cout << "Você escolheu ímpar";
        if (soma % 2 == 0)return false;
        if (soma % 2 != 0)return true;
    }
}
