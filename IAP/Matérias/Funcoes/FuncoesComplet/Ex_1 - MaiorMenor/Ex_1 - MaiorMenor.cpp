#include <iostream>
#include <windows.h>

using namespace std;

double FuncMaior(double*, int);
double FuncMenor(double*, int);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    double num[3], maior, menor;
    int i, qtd = 3;

    for (i = 0; i < qtd; i++){
        cout<<"Escreva o "<<i+1<<"° número: ";
        cin>>num[i];
        maior = FuncMaior(num, qtd);
        menor = FuncMenor(num, qtd);       
    } 
    cout << "\nO maior : " << maior;
    cout << "\nO menor : " << menor;
    return 0;
}

double FuncMaior(double n[], int qtd){
    double maior;
    for(int i = 0; i < qtd; i++){
        if(n[i] > maior)maior = n[i];
    }
    return maior;
}
double FuncMenor(double n[], int qtd){
    double menor;
    menor = n[0];
    for(int i = 0; i < qtd; i++){
        if(n[i] < menor)menor = n[i];
    }
    return menor;
}