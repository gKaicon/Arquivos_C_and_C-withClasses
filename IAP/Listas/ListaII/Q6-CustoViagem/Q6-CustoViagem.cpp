#include <iostream>
#include <windows.h>
#include <math.h>

#define gas 7.29
#define eta 5.56

using namespace std;

int main(){
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    double custoGas, custoEta, dist, kmLGas, kmLEta, litroEta, litroGas;
    int op;
    cout<<"Quantos quilometros por Litro, seu carro faz com Etanol: ";
    cin>>kmLEta;
    cout<<"Quantos quilometros por Litro, seu carro faz com Gasolina: ";
    cin>>kmLGas;
    cout<<"Qual a distância a ser percorrida em km: ";
    cin>>dist;

    //Litros para Etanol
    litroEta = dist/kmLEta;
    custoEta = litroEta*eta;

    //Litros para Gasolina
    litroGas = dist/kmLGas;
    custoGas = litroGas*gas;

    //Escolha do combustível
    cout<<"1-Etanol\n2-Gasolina\nEscolha uma das opções de combustível acima: ";
    cin>>op;
    switch (op){
        case 1:
            cout<<"O preço da viagem com Etanol é: R$ "<<custoEta;
        case 2:
            cout<<"O preço da viagem com Gasolina é: R$ "<<custoGas;
    }
    
    system("cls");
    cout<<"\n\nPreço da Gasolina: R$"<<custoGas<<"\tPreço do Etanol: R$"<<custoEta<<"\n\n";

    //Saber se a escolha foi sábia ou não

    if(custoGas>custoEta && op == 1){
        cout<<"Gasolina sai mais caro que o Etanol, você escolheu etanol, logo, você fez uma boa escolha!";
    }
    if(custoGas>custoEta && op == 2){
        cout<<"Gasolina sai mais caro que o Etanol, você escolheu Gasolina, logo, você não fez uma boa escolha!";
    }
    if(custoGas<custoEta && op == 1){
        cout<<"Etanol sai mais caro que a Gasolina, você escolheu Etanol, logo, você não fez uma boa escolha!";
    }
     if(custoGas<custoEta && op == 2){
        cout<<"Etanol sai mais caro que o Gasolina, você escolheu Gasolina, logo, você fez uma boa escolha!";
    }
    return 0;
}