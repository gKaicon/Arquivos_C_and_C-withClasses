#include <iostream>
#include <windows.h>

using namespace std;

double FuncMaior(double*, int);
double FuncMenor(double*, int);

typedef struct Banco{
    int num;
    char titular[35];
    double saldo;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    double maior, menor;
    Banco b[5];

    b[0].saldo = 2000;
    b[1].saldo = 1000;
    b[2].saldo = 10000;
    b[3].saldo = 5000;
    b[4].saldo = 500;

    for(int i = 0; i < 5; i++){
        if(b[i].saldo > maior){
            maior = b[i].saldo;
        }
    }
    
    for(int i = 0; i < 5; i++){
        if(i = 0){
            menor = b[i].saldo;
        }
        if(b[i].saldo < menor){
            menor = b[i].saldo;
        }
    }

    cout << "Maior saldo: " << maior << endl;
    cout << "Menor saldo: " << menor << endl;

    return 0;
}