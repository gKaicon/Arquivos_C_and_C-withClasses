#include <iostream>
#include <windows.h>

using namespace std;

int AM_PM(int);
void Imprime(int, int);

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    int hora, min, op;
    do{
        system("cls");
        cout << "Digite as horas (em notação 24 horas): ";
        cin >> hora;
        while (hora > 24 || hora < 0){
            system("cls");
            cout << "Digite um valor entre (0 - 23)\nInforme as horas: ";
            cin >> hora;
        }
        system("cls");
        cout << "Digite os minutos: ";
        cin >> min;
        while ( min > 60 || min < 0){
            system("cls");
            cout << "Digite um valor entre (0 -  59) \nInforme os minutos: ";
            cin >> min;
        }
        system("cls");
        AM_PM(hora);
        Imprime(hora, min);
        cout<<"\n\nSe deseja fazer uma nova conversão, pressione 1 para Sim, caso contrário pressione 0 para Não \nEscolha:";
        cin>>op;
    }while(op == 1);
    return 0;
}
int AM_PM(int h){
    int hC;
    if (h > 12)hC = h - 12;
    if (h <= 12)hC = h;
    if (h == 0)hC = 12;

    return hC;
}
void Imprime(int horaC, int m){
    int hr;
    hr = AM_PM(horaC);
    if (horaC < 12 && horaC >= 0) cout << hr << ":" << m << " A.M.";  // manhã
    if (horaC >= 12) cout << hr << ":" << m << " P.M.";  // tarde/noite
}