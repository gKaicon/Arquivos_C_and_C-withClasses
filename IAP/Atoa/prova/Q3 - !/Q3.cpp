#include <iostream>
#include <windows.h>

using namespace std;

void verificaDivisores(int);

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    int num;
    cout <<  "Digite um número: ";
    cin >>  num;
    verificaDivisores(num);
    return 0;
}
void verificaDivisores(int n){
    int cont = 0, divsr[cont], result, num = n;
    for(int i = n; i >= 0; i--){
        result = n/i;
        if(n%i == 0){
            divsr[cont];
            cont++;
        }
    }
    for(int i = 0; i < cont; i++){
        cout << divsr[cont] << "\t";
    }
}