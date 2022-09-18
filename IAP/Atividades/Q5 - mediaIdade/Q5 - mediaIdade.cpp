#include <iostream>

using namespace std;

int main()
{
    int idade, soma = 0, media, cont = 0, op;
    do{
        cout<<"Digite uma idade: ";
        cin>>idade;
        soma = soma + idade;
        cont ++;
    }while (idade > 0);
    media = (soma/(cont-1));
        cout<<"Media das idades: "<<media<<"\tNumero de pessoas: "<<(cont-1);
    return 0;
}