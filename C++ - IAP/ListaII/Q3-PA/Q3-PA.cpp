#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int a1, n, an, i;
    double soma, r;
    cout<<"Digite a quantidade de termos que terão na PA: ";
    cin>>n;
    cout<<"Digite o 1° termo da PA(a1): ";
    cin>>a1;
    cout<<"Digite a razão da PA: ";
    cin>>r;

    an = (a1+(n-1)*r);//formula para descobrir o an, para usar no cálculo da soma

    cout<<"Termos da PA: \n"; //de brinde a impressão dos n termos

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
    
    soma = ((a1+an)*n)/2;//soma dos n termos
    cout << "\n\nSoma dos n termos: "<<soma<<"\n";
    return 0;
}