#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    string n, p;
    boolean A = false, B = false;
    do{
        system("cls");//limpar a tela na hora da repetição
        //imprimir os estados das lâmpadas
        if(A == false){
            cout<<"Lampada A Apagada\n";
        }
        if(A == true){
            cout<<"Lampada A Acesa\n";
        }
        if(B == false){
            cout<<"Lampada B Apagada\n";
        }
        if(B == true){
            cout<<"Lampada B Acesa\n";
        }
        //realizar um do-while para restringir o usuario a escrever i1 ou i2
        do{
            cout<<"\nQual dos interruptores acionar?\nInterruptor 1(i1)\nInterruptor 2(i2) \nEscolha sua opção: ";
            cin>>n;
        }while(n != "i1" && n != "i2");
        //alterações que serão feitas de acordo com a escolha do usuário
        if(n == "i1"){
            A = !A;
        }
        if(n == "i2"){
            A = !A;
            B = !B;
        }
        //pergunta se o usuário deseja continuar
        cout<<"Deseja continuar?\n Escolha s para Sim, n ou qualquer outro caracter para Não \nEscolha sua opção: ";
        cin>>p;
    }while(p == "s");
    system("cls");//limpa após o laço para exibir apenas o resultado final

    //Fim do laço

    if(A == false){
        cout<<"Lampada A Apagada\n";
    }
    if(A == true){
        cout<<"Lampada A Acesa\n";
    }
    if(B == false){
        cout<<"Lampada B Apagada\n";
    }
    if(B == true){
        cout<<"Lampada B Acesa\n";
    }
    return 0;
}