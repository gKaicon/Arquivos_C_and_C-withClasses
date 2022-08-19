#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int n, i, op;
    double a1, an, soma, r, q;
    //Menu de escolhas
    cout <<" 1-Progressão Arímetica\n"<<
            "2-Progressão Geométrica\n"<<
            "3-Sair\n"<<
            "Escolha uma das opções acima para realizar: ";
    cin >> op;
    switch (op){
        case 1:
            system("cls");
            cout << "Digite a quantidade de termos que terão na PA: ";
            cin >> n;
            cout << "Digite o 1° termo da PA(a1): ";
            cin >> a1;
            cout << "Digite a razão da PA: ";
            cin >> r;
            
            an = (a1 + (n - 1) * r); //formula para descobrir o an, para usar no cálculo da soma

            cout << "O termo da posição a" << n << " é " << an;
            cout << "\nTermos da PA: \n"; //de brinde a impressão dos n termos

            if (r > 0){ //PA crescente
                for (i = a1; i <= an; i += r){
                    cout << i << "\t";
                }
            }
            if (r < 0){ //PA decrescente
                for (i = a1; i >= an; i += r){
                    cout << i << "\t";
                }
            }

            soma = ((a1 + an) * n) / 2;

            cout << "\n\nSoma dos n termos: " << soma << "\n";
            break;
        case 2:
            system("cls");
            cout << "Digite a quantidade de termos que terão na PG: ";
            cin >> n;
            cout << "Digite o 1° termo da PG(a1): ";
            cin >> a1;
            cout << "Digite a razão da PG: ";
            cin >> q;

            an = a1 * pow(q, (n - 1)); //formula para descobrir o an, para usar no cálculo da soma

            cout << "O termo da posição a" << n << " é " << an;
            cout << "\nTermo da PG: \n"; //de brinde a impressão dos n termos

            if (q > 0){ //PG crescente
                for (i = a1; i <= an; i *= q){
                    cout << i << "\t";
                }
            }
            if (q < 0){ //PG decrescente
                for (i = a1; i >= an; i *= q){
                    cout << i << "\t";
                }
            }

            soma = (a1 * pow(q, n)) / (q - 1);

            cout << "\n\nSoma dos n termos: " << soma << "\n";
            break;

        case 3:
            break;

        }
    cout << "\n";
    return 0;
}