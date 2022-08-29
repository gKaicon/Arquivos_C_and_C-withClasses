#include <iostream>

using namespace std;

int main(){
    char sexo;
    cout<<"Digite seu sexo: ";
    cin>>sexo;
    if(sexo == 'm'){
        cout<<"Sexo: Masculino";
    }
    if(sexo == 'f'){
        cout<<"Sexo: Feminino";
    }
    
    return 0;
}