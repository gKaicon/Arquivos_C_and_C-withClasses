#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    double nota;
    string aluno, conceito;
    cout<<"Digite o nome do aluno:";
    cin>>aluno;
    cout<<"Digite a nota: ";
    cin>>nota;

    if (nota>89.9){
        conceito = "A";
    }
    if (nota>74.9 && nota<90){
        conceito = "B";
    }
    if (nota>59.9 && nota<75){
        conceito = "C";
    }
    else{
        conceito = "R";
    }
    cout<<"Aluno: "<<aluno<<"\tConceito: "<<conceito<<"\n";
    return 0;
}