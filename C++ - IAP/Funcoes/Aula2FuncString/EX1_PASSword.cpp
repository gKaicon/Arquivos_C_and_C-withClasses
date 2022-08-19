#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    char user[10], senha[8], senhaC[8];
    int aut;
    cin>>user;
    cin>>senha;
    cin>>senhaC;
    aut = strcmp(senha, senhaC);
    //corpo da impressão
    cout<<"System Authentication\n\n\n";
    cout<<"User: "<<user<<"\n\n";
    cout<<"Password: "<<senha<<"\n";
    cout<<"Confirm Password: "<<senhaC<<"\n";

    if(aut == 0){
        cout<<"Password Confirmed!!\n\n";
    } else{
        cout<<"Password Incorrect!!\n";
    }
    // cout << ;
    return 0;
}