#include <iostream>

using namespace std;

int main(){
    int i;
    double nota, soma, media;
    for (i = 0; i < 3; i++){
        cout << "Digite a "<<(i+1)<<"° nota: ";
        cin>>nota;
        soma = soma + nota;
    }
    media = soma/3;
    cout<< "A media das 3 notas = " <<media<<"\n\n";
    return 0;
}